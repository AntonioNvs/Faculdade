/*
    Trabalho Prático - Estrutura de Dados - UFMG, control_time.cpp
    Propósito: Definir as funcionalidades da classe ControlTime;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#include "control_time.hpp"

#include <time.h>
#include <fstream>
#include <sys/time.h>
#include <sys/resource.h>

ControlTime::ControlTime(std::string filename) {
    std::ifstream file("output.csv");

    int count = 0;
    std::string line;
    while(getline(file, line)) count++;
    file.close();

    csv.open("output.csv", std::ios_base::out | std::ios_base::app);

    // Se o arquivo estiver vazio, escreve o cabeçalho
    if(!count)
        csv << "method_sort,method_convex_hull,size,user_time,system_time,clock_time" << std::endl;
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
    // Tempo de usuário e sistema em segundos
    double user_time = (end.ru_utime.tv_sec - init.ru_utime.tv_sec) + (end.ru_utime.tv_usec - init.ru_utime.tv_usec) / 10e6;
    double system_time = (end.ru_stime.tv_sec - init.ru_stime.tv_sec) + (end.ru_stime.tv_usec - init.ru_stime.tv_usec) / 10e6;

    // Tempo de relógio em segundos
    double clock_time = (end_clock.tv_sec - start_clock.tv_sec) + (end_clock.tv_nsec - start_clock.tv_nsec) / 10e9;

    return {user_time, system_time, clock_time};
}

void ControlTime::write_csv(std::string method_sort, std::string method_convex_hull, int size, Time time) {
    // Escreve no arquivo CSV
    csv << method_sort << "," << method_convex_hull << "," << size << "," << time.user_time << "," << time.system_time << "," << time.clock_time << std::endl;
}