#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include "operation.hpp"

Operation::Operation() {};

// Return the system time execution in seconds
float Operation::get_sys_time_exec(rusage end, rusage start) {
    if(end.ru_stime.tv_usec < start.ru_stime.tv_usec) {
        end.ru_stime.tv_usec = 10e6 + end.ru_stime.tv_usec - start.ru_stime.tv_usec;
        end.ru_stime.tv_sec =  end.ru_stime.tv_sec - start.ru_stime.tv_sec;
    }
    return (end.ru_stime.tv_sec - start.ru_stime.tv_sec) + (end.ru_stime.tv_usec - start.ru_stime.tv_usec) / 10e6;
}

// Return the user time execution in seconds
float Operation::get_user_time_exec(rusage end, rusage start) {
    if(end.ru_utime.tv_usec < start.ru_utime.tv_usec) {
        end.ru_utime.tv_usec = 10e6 + end.ru_utime.tv_usec - start.ru_utime.tv_usec;
        end.ru_utime.tv_sec = end.ru_utime.tv_sec - start.ru_utime.tv_sec;
    }

    return (end.ru_utime.tv_sec - start.ru_utime.tv_sec) + (end.ru_utime.tv_usec - start.ru_utime.tv_usec) / 10e6;
}

float Operation::get_clock_time_exec(timespec end, timespec start) {
    if(end.tv_nsec < start.tv_nsec) {
        end.tv_nsec = 10e9 + end.tv_nsec - start.tv_nsec;
        end.tv_sec = end.tv_sec - start.tv_sec;
    }

    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 10e9;
}