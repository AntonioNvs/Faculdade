#ifndef HANDLE_TEST
#define HANDLE_TEST

#include "control_time.hpp"
#include "order_algorithms.hpp"

struct ResultBaterry {
    Time shell;
    Time heap;
};

class HandleTest {
    public:
        HandleTest();
        ~HandleTest();
        
        static void generate_n_rand_numbers(int *array, int N, int mod);
        
        ResultBaterry execute_battery_of_tests(int size, int n_tests, float gap = -1);
        void simulate(int init, int end, int n_tests, float factor_h);

    private:
        ControlTime *control_time = nullptr;
        OrderAlgorithms *order_algorithms = nullptr;
        
};

#endif