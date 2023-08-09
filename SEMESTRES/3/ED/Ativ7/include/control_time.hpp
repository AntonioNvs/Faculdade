#ifndef CONTROL_TIME
#define CONTROL_TIME

#include <time.h>
#include <fstream>
#include <sys/time.h>
#include <sys/resource.h>

struct Time {
    double user_time;
    double system_time;
    double clock_time;
};

class ControlTime {
    public:
        ControlTime(std::string filename = "output.csv");
        ~ControlTime();
        void start(int PID);
        void stop(int PID);
        Time get_time();
        void write_csv(std::string method, int size, Time time, float gap = 1);
        
    private:
        struct rusage init, end;
        struct timespec start_clock, end_clock;
        std::ofstream csv;
};

#endif
