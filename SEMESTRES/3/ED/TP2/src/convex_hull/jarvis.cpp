/*
    Trabalho Prático - Estrutura de Dados - UFMG, jarvis.cpp
    Propósito: Definir as funcionalidades da classe Jarvis;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "animation.hpp"
#include "adt/vector.hpp"
#include "exceptions.hpp"
#include "convex_hull/jarvis.hpp"
#include "convex_hull/convex_hull.hpp"

Jarvis::Jarvis(Animation &animation) {
    this->animation = animation;
    this->order_algorithms = new OrderAlgorithms<Point>();
}

Jarvis::~Jarvis() {
    delete this->order_algorithms;
}

Vector<Point> Jarvis::execute(Point* points, int n_points, std::string method_sort, bool animate) {
    Vector<Point> arr;

    if (n_points < 3)
        throw NotEnoughEntryPoints();

    int l = 0;
    // Encontra o ponto mais a esquerda
    for (int i = 1; i < n_points; i++) {
        if (points[i].x < points[l].x) {
            l = i;
        }
    }
    
    if(animate) {
        animation.clearScreen();
        animation.draw_title_screen("Jarvis");
        animation.draw_points(points, n_points, Color{1.0, 1.0, 1.0}, 8.0, 0);
    }

    int p = l, q;
    do {
        arr.push_back(points[p]);
        if(animate) {
            animation.draw_iteration_lines(points, n_points, arr, "jarvis");
        }
        q = (p + 1) % n_points;
        // Encontra o próximo ponto anti-horário
        for (int i = 0; i < n_points; i++) {
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);

    if(animate) {
        animation.draw_iteration_lines(points, n_points, arr, "jarvis", false);
    }

    return arr;
}