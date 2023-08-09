/*
    Trabalho Prático - Estrutura de Dados - UFMG, graham.cpp
    Propósito: Definir as funcionalidades da classe Graham;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "animation.hpp"
#include "exceptions.hpp"
#include "set_of_points.hpp"
#include "order_algorithms.hpp"
#include "convex_hull/graham.hpp"
#include "convex_hull/convex_hull.hpp"

#include <iostream>

Point point_compare = {0, 0};

Graham::Graham(Animation &animation) {
    this->animation = animation;
    this->order_algorithms = new OrderAlgorithms<Point>();
}

Graham::~Graham() {
    delete this->order_algorithms;
}

void Graham::swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

Point Graham::next_to_top(Vector<Point> &arr) {
    Point p = arr.top();
    arr.pop_back();
    Point res = arr.top();
    arr.push_back(p);
    return res;
}

bool compare(Point p1, Point p2) {
    int o = orientation(point_compare, p1, p2);

    // Se os pontos forem colineares com o de comparação, pegar o mais distante
    if(o == 0) {
        return (distance(point_compare, p2) >= distance(point_compare, p1)) ? true : false;
    }

    // Se não forem colineares, verifica se são no sentido anti-horário
    return (o == 2) ? true : false;
}

Vector<Point> Graham::execute(Point* points, int n_points, std::string method_sort, bool animate) {
    if(n_points < 3)
        throw NotEnoughEntryPoints();
    
    // Encontra o ponto mais baixo e mais a esquerda
    int ymin = points[0].y, min = 0;
    for(int i = 1; i < n_points; i++) {
        int y = points[i].y;
        if((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    this->swap(points[0], points[min]);
    this->p0 = points[0];

    extern Point point_compare;
    point_compare = this->p0;

    // Ordena os pontos de acordo com o ângulo formado com o ponto de comparação
    this->order_algorithms->sort(&points[1], n_points-1, method_sort, compare);

    int m = 1;
    // Remove pontos colineares
    for(int i = 1; i < n_points; i++) {
        while(i < n_points - 1 && orientation(this->p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    Vector<Point> arr = Vector<Point>();

    if(m < 3)
        throw ColiniearPoints();

    arr.push_back(points[0]);
    arr.push_back(points[1]);
    arr.push_back(points[2]);

    if(animate) {
        animation.clearScreen();
        animation.draw_title_screen("Graham Scan");
        animation.draw_points(points, n_points, Color{1.0, 1.0, 1.0}, 8.0, 0);
        animation.draw_point(points[0], Color{1.0, 0.0, 0.0}, 8.0);
        animation.wait(1000);
    }

    int execs = 0;
    
    for(int i = 3; i < m; i++) {
        if(animate) {
            if(n_points < 2000 || execs % (n_points/2000 + 1) == 0)
                animation.draw_iteration_lines(points, n_points, arr);
        }
        // Remove pontos que não estão no sentido anti-horário do último ponto do convex hull
        while(arr.get_size() > 1 && orientation(this->next_to_top(arr), arr.top(), points[i]) != 2)
            arr.pop_back();
        arr.push_back(points[i]);
        execs++;
    }

    if(animate)
        animation.draw_iteration_lines(points, n_points, arr, "graham", false);

    return arr;
}