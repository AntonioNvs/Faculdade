/*
    Trabalho Prático - Estrutura de Dados - UFMG, handle_test.cpp
    Propósito: Definir as funcionalidades da classe HandleTest;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include "exceptions.hpp"
#include "handle_test.hpp"
#include "control_time.hpp"
#include "linear_equation.hpp"
#include "convex_hull/convex_hull.hpp"

#define UPPER(X) transform(X.begin(), X.end(), X.begin(), ::toupper)
#define LOWER(X) transform(X.begin(), X.end(), X.begin(), ::tolower)

using namespace std;

HandleTest::HandleTest(Animation &animation) {
    this->animation = animation;
    this->control_time = new ControlTime();
    this->convex_hull = new ConvexHullAlgorithms(this->animation);
}

HandleTest::~HandleTest() { 
    delete this->control_time;
    delete this->convex_hull;
}

void HandleTest::execute(Point *points, int n_points, bool animate) {
    Point *points_copy = new Point[n_points];

    for(int i = 0; i < n_points; i++)
        points_copy[i] = points[i];

    // Implementa a precisão de 3 casas decimais
    cout << setprecision(3) << fixed;

    Vector<LinearEquation> lines;

    try {
        Vector<Point> set = this->convex_hull->execute(points, n_points, "graham", "merge", animate);
        
        cout << "FECHO CONVEXO:" << endl;
        cout << set[0].x << ' ' << set[0].y << endl;

        // Cria as equações das retas que ligam os pontos do fecho convexo e imprime o ponto atual do fecho
        for(int k = 1; k < set.get_size(); k++) {
            cout << set[k].x << ' ' << set[k].y << endl;
            lines.push_back(LinearEquation::create_equation(set[k-1], set[k]));
        }
        lines.push_back(LinearEquation::create_equation(set[set.get_size()-1], set[0]));

        cout << endl;
    } catch(NotEnoughEntryPoints &e) {
        cout << e.what() << endl;
        return;
    } catch(ColiniearPoints &e) {
        cout << e.what() << endl;
        return;
    }

    if(animate) {
        animation.wait(1000);
        this->convex_hull->execute(points, n_points, "jarvis", "merge", animate);
        animation.wait(1000);
    }

    string sorts[] = {"merge", "insertion", "linear"};

    for(int i = 0; i < n_points; i++)
        points[i] = points_copy[i];

    // Executa os algoritmos de ordenação e calcula o tempo de execução
    for(auto sort : sorts) {
        this->control_time->start(CLOCK_MONOTONIC);
        this->convex_hull->execute(points, n_points, "graham", sort);
        this->control_time->stop(CLOCK_MONOTONIC);
        this->control_time->write_csv(sort, "graham", n_points, this->control_time->get_time());

        UPPER(sort);
        cout << "GRAHAM" << "+" << sort << "SORT" << ": " << this->control_time->get_time().clock_time << endl;
        LOWER(sort);

        for(int i = 0; i < n_points; i++)
            points[i] = points_copy[i];
    }

    this->control_time->start(CLOCK_MONOTONIC);
    this->convex_hull->execute(points, n_points, "jarvis", "merge");
    this->control_time->stop(CLOCK_MONOTONIC);
    this->control_time->write_csv("none", "jarvis", n_points, this->control_time->get_time());
    
    cout << "JARVIS" << ": " << this->control_time->get_time().clock_time << endl;
    cout << endl;
    cout << "EQUAÇÕES DAS RETAS:" << endl;

    for(int i = 0; i < lines.get_size(); i++) 
        cout << lines[i].print_equation() << endl;

    delete [] points_copy;
}