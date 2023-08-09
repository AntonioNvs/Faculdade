/*
    Trabalho Prático - Estrutura de Dados - UFMG, convex_hull.cpp
    Propósito: Definir as funcionalidades da classe ConvexHullAlgorithms e métodos chaves;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "set_of_points.hpp"
#include "linear_equation.hpp"
#include "order_algorithms.hpp"

#include "convex_hull/graham.hpp"
#include "convex_hull/jarvis.hpp"
#include "convex_hull/convex_hull.hpp"

#include <math.h>
#include <iostream>

int distance(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); 
}

int orientation(Point p, Point q, Point r) {
    /*
        0 = colinear
        1 = horário
        2 = anti-horário
    */
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if(val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

double polarAngle(const Point& p1, const Point& p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return std::atan2(dy, dx);
}

ConvexHullAlgorithms::ConvexHullAlgorithms(Animation &animation) {
    this->animation = animation;
}

ConvexHullAlgorithms::~ConvexHullAlgorithms() {}

Vector<Point> ConvexHullAlgorithms::execute(Point* points, int n_points, std::string algorithm, std::string method_sort, bool animate) {
    return  (algorithm == "graham" ? this->graham(points, n_points, method_sort, animate) : this->jarvis(points, n_points, method_sort, animate));
}

Vector<Point> ConvexHullAlgorithms::graham(Point* points, int n_points, std::string method_sort, bool animate) {
    // TODO: Implement Graham's algorithm
    Graham graham = Graham(this->animation);
    return graham.execute(points, n_points, method_sort, animate);
}

Vector<Point> ConvexHullAlgorithms::jarvis(Point* points, int n_points, std::string method_sort, bool animate) {
    // TODO: Implement Jarvis' algorithm
    Jarvis jarvis = Jarvis(this->animation);
    return jarvis.execute(points, n_points, method_sort, animate);
}