/*
    Trabalho Prático - Estrutura de Dados - UFMG, animation.cpp
    Propósito: Definir as funcionalidades da classe Animation;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include <thread>
#include <chrono>
#include <math.h>

// CASO NÃO CONSIGA INSTALAR, COMENTE AS DUAS LINHAS ABAIXO
#include "GL/gl.h"
#include "GL/freeglut.h"

#include "set_of_points.hpp"
#include "animation.hpp"

// CASO NÃO CONSIGA INSTALAR, DESCOMENTE AS LINHAS ABAIXO ATÉ A DEFINIÇÃO DA CLASSE ANIMATION
/*
#define GL_LINES 0x0001
#define GL_POINTS 0x0000
#define GLUT_SINGLE 0x0000
#define GL_COLOR_BUFFER_BIT 0x00004000

void* glutBitmapTimesRoman24;

#define GLUT_BITMAP_TIMES_ROMAN_24 ((void *) &glutBitmapTimesRoman24)

typedef float GLfloat;
typedef float GLclampf;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;

void glutInit(int *argc, char **argv) {};
void glutInitDisplayMode(unsigned int displayMode) {};
void glutInitWindowSize(int width, int height) {};
void glutInitWindowPosition(int x, int y) {};
int glutCreateWindow(const char *title) { return 0; };
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {};
void glClear(GLbitfield mask) {};
void glFlush() {};
void glutMainLoop() {};
void glutDestroyWindow(int window) {};
int glutGetWindow() { return 0; };
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {};
void glPointSize(GLfloat size) {};
void glBegin(GLenum mode) {};
void glVertex2f(GLfloat x, GLfloat y) {};
void glEnd() {};
void glLineWidth(GLfloat width) {};
void glRasterPos2f(GLfloat x, GLfloat y) {};
void glutBitmapCharacter(void *font, int character) {};
*/

Animation::Animation(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1920, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Envoltorio Convexo");
}

Animation::~Animation() {}

void Animation::clearScreen() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Animation::setLoop() {
    glutMainLoop();
}

void Animation::destroyWindow() {
    glutDestroyWindow(glutGetWindow());
}

void Animation::wait(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Animation::draw_point(Point p, Color color, float dot_size, bool flush) {
    // Normalização dos pontos
    double x = (p.x - midX) / (maxX - midX + K);
    double y = (p.y - midY) / (maxY-midY+K);
    
    glColor3f(color.r, color.g, color.b);
    glPointSize(dot_size);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
    if(flush)
        glFlush();
}

void Animation::draw_points(Point *points, int n, Color color, float dot_size, int delay, bool define_params) {
    glColor3f(color.r, color.g, color.b);
    glPointSize(dot_size);

    if(define_params) {
        /*
            Definindo os parâmetros para normalização dos pontos
            maxX, minX, maxY, minY, midX, midY e K
        */
        maxX = getInfo("max", "x", points, n).x;
        minX = getInfo("min", "x", points, n).x;
        maxY = getInfo("max", "y", points, n).y;
        minY = getInfo("min", "y", points, n).y;

        K = (maxX > maxY ? maxX : maxY) * 0.1;

        midX = (double)(maxX - abs(minX)) / 2.0;
        midY = (double)(maxY - abs(minY)) / 2.0;
    }

    for(int i = 0; i < n; i++) {
        // Normalização dos pontos
        double x = (points[i].x - midX) / (maxX - midX + K);
        double y = (points[i].y - midY) / (maxY-midY+K);

        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        if(delay > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            glFlush();
        }
    }
    if(!delay)
        glFlush();
}

void Animation::draw_line(Point p1, Point p2, Color color, double width, bool flush) {
    glColor3f(color.r, color.g, color.b);
    glLineWidth(width);
    glBegin(GL_LINES);
    
    // Normalização dos pontos
    double x1 = (p1.x - midX) / (maxX - midX + K);
    double y1 = (p1.y - midY) / (maxY-midY+K);
    double x2 = (p2.x - midX) / (maxX - midX + K);
    double y2 = (p2.y - midY) / (maxY-midY+K);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    if(flush)
        glFlush();
}

void Animation::draw_title_screen(std::string title, bool flush) {
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(-0.05, 0.9);

    void* font = GLUT_BITMAP_TIMES_ROMAN_24;

    for(char c : title) {
        glutBitmapCharacter(font, c);
    }

    if(flush)
        glFlush();
}

void Animation::draw_iteration_lines(Point *points, int n, Vector<Point> &convex_hull, std::string method, bool delete_lines) {
    int delay;
    // Definindo o delay de acordo com o método
    if(method == "graham") {
        delay = static_cast<int>(10000.0 / ((double)n));
    } else {
        delay = static_cast<int>(3000.0 / (double)log2(n));
    }
    
    Point last = convex_hull[0];

    for(int i = 1; i < convex_hull.get_size(); i++) {
        draw_line(last, convex_hull[i], Color{0.0, 0.0, 1.0}, 5.0, false);
        last = convex_hull[i];
    }
    draw_line(last, convex_hull[0], Color{0.0, 0.0, 1.0}, 5.0, false);
    glFlush();

    wait(delay);

    // Sobrescrevendo as linhas 
    if(delete_lines) {
        last = convex_hull[0];    
        for(int i = 1; i < convex_hull.get_size(); i++) {
            draw_line(last, convex_hull[i], Color{0.0, 0.0, 0.0}, 5.0, false);
            last = convex_hull[i];
        }
        draw_line(last, convex_hull[0], Color{0.0, 0.0, 0.0}, 5.0, false);

        draw_points(points, n, Color{1.0, 1.0, 1.0}, 8.0, 0, false);
    }   

    glFlush();
}