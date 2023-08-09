#include <time.h>
#include <fstream>
#include <iostream>

#include "handle_test.hpp"

using namespace std;


int main() {
    HandleTest *handle_test = new HandleTest();
    handle_test->simulate(1, 6, 10, 0.5);
    
    delete handle_test;
    
    return 0;   
}