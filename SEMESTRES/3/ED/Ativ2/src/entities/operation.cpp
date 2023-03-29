#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include "operation.hpp"

Operation::Operation() {};

// Return the system time execution in seconds
double Operation::get_sys_time_exec(rusage end, rusage start) {
    return (end.ru_stime.tv_sec - start.ru_stime.tv_sec) + (end.ru_stime.tv_usec - start.ru_stime.tv_usec) / 10e6;
}

// Return the user time execution in seconds
double Operation::get_user_time_exec(rusage end, rusage start) {
    return (end.ru_utime.tv_sec - start.ru_utime.tv_sec) + (end.ru_utime.tv_usec - start.ru_utime.tv_usec) / 10e6;
}

double Operation::get_clock_time_exec(timespec end, timespec start) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 10e9;
}