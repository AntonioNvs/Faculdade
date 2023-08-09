/*
    Trabalho Prático - Estrutura de Dados - UFMG, set_of_points.cpp
    Propósito: Definir as funcionalidades da classe SetOfPoints;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "set_of_points.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#define INT_MAX 1000000000 + 7

using namespace std;

Point getInfo(std::string minMax, std::string axe, Point * points, int size) {
    Point p;
    if(minMax == "min") {
        p = {INT_MAX, INT_MAX};
        if(axe == "x") {
            for(int i = 0; i < size; i ++)
                if(points[i].x < p.x)
                    p = points[i];
        }
        else {
            for(int i = 0; i < size; i++) {
                if(points[i].y < p.y)
                    p = points[i];
            }
        }

    } else {
        p = {-INT_MAX, -INT_MAX};
        if(axe == "x") {
            for(int i = 0; i < size; i ++)
                if(points[i].x > p.x)
                    p = points[i];
        }
        else
            for(int i = 0; i < size; i ++) {
                if(points[i].y > p.y)
                    p = points[i];
            }
    }

    return p;
}

SetOfPoints::SetOfPoints() {}

SetOfPoints::~SetOfPoints() {}

void SetOfPoints::print() {
    for(int i = 0; i < this->points.get_size(); i++) {
        cout << this->points[i].x << " " << this->points[i].y << endl;
    }
}

void SetOfPoints::define_points_by_input_file(std::ifstream & file) {
    int x, y;
    string line;
    
    // Ler o arquivo de entrada e armazenar os pontos
    while(getline(file, line)) {
        stringstream ss(line);

        ss >> x >> y;
        this->points.push_back(Point(x, y));
    }
}

Point* SetOfPoints::get_points() {
    return this->points.begin();
}

int SetOfPoints::get_n_points() {
    return this->points.get_size();
}
