#include <time.h>
#include <math.h>
#include <iostream>

#include "handle_test.hpp"
#include "control_time.hpp"
#include "order_algorithms.hpp"

HandleTest::HandleTest() {
    this->control_time = new ControlTime();
    this->order_algorithms = new OrderAlgorithms();
}

HandleTest::~HandleTest() {
    this->control_time->~ControlTime();
    delete this->control_time;
    delete this->order_algorithms;
}

void HandleTest::generate_n_rand_numbers(int *array, int N, int mod) {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = rand() % mod;
    }
}

ResultBaterry HandleTest::execute_battery_of_tests(int size, int n_tests, float gap) {
    int MOD = 10000000;

    std::cout << "Generating " << n_tests << " tests with " << size << " numbers and h = " << gap << std::endl;

    Time control_shell = {0.0, 0.0, 0.0};
    Time control_heap = {0.0, 0.0, 0.0};
    Time current;

    int *array = new int[size];

    for(int i = 0; i < n_tests; i++) {
        this->generate_n_rand_numbers(array, size, MOD);

        this->control_time->start(CLOCK_MONOTONIC);
        order_algorithms->sort(array, size, "heap");
        this->control_time->stop(CLOCK_MONOTONIC);
        
        current = this->control_time->get_time();
        control_heap.system_time+= current.system_time;
        control_heap.clock_time += current.clock_time;
        control_heap.user_time += current.user_time;

        this->generate_n_rand_numbers(array, size, MOD);
                
        this->control_time->start(CLOCK_MONOTONIC);
        order_algorithms->sort(array, size, "shell", gap);
        this->control_time->stop(CLOCK_MONOTONIC);
        
        current = this->control_time->get_time();
        control_shell.system_time+= current.system_time;
        control_shell.clock_time += current.clock_time;
        control_shell.user_time += current.user_time;

    }

    return {
        {control_shell.user_time / n_tests, control_shell.system_time / n_tests, control_shell.clock_time / n_tests},
        {control_heap.user_time / n_tests, control_heap.system_time / n_tests, control_heap.clock_time / n_tests}
    };
}

void HandleTest::simulate(int init, int end, int n_tests, float factor_h) {
    for(float alpha = init; alpha <= end; alpha++) {
        int size = pow(10, alpha);
        
        for(float h = 1.5; h <= 3.25; h += factor_h) {
            ResultBaterry result = this->execute_battery_of_tests(size, n_tests, h);
            this->control_time->write_csv("shell", size, result.shell, h);
            this->control_time->write_csv("heap", size, result.heap, h);
        }
    }
}