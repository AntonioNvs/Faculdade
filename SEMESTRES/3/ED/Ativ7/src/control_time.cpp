#include "control_time.hpp"

#include <time.h>
#include <fstream>
#include <sys/time.h>
#include <sys/resource.h>

ControlTime::ControlTime(std::string filename) {
    csv.open("output.csv");
    csv << "method,size,user_time,system_time,clock_time,gap" << std::endl;
}

ControlTime::~ControlTime() {
    csv.close();
}

void ControlTime::start(int PID) {
    getrusage(RUSAGE_SELF, &init);
    clock_gettime(PID, &start_clock);
}

void ControlTime::stop(int PID) {
    getrusage(RUSAGE_SELF, &end);
    clock_gettime(PID, &end_clock);
}

Time ControlTime::get_time() {
    double user_time = (end.ru_utime.tv_sec - init.ru_utime.tv_sec) + (end.ru_utime.tv_usec - init.ru_utime.tv_usec) / 10e6;
    double system_time = (end.ru_stime.tv_sec - init.ru_stime.tv_sec) + (end.ru_stime.tv_usec - init.ru_stime.tv_usec) / 10e6;
    double clock_time = (end_clock.tv_sec - start_clock.tv_sec) + (end_clock.tv_nsec - start_clock.tv_nsec) / 10e9;

    return {user_time, system_time, clock_time};
}

void ControlTime::write_csv(std::string method, int size, Time time, float gap) {
    csv << method << "," << size << "," << time.user_time << "," << time.system_time << "," << time.clock_time << "," << gap << std::endl;
}