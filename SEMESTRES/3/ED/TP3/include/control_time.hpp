/*
    Trabalho Prático - Estrutura de Dados - UFMG, control_time.hpp
    Propósito: Definir estruturas gerais da classe ControlTime;

    @author Antônio Neves
    @version 1.0 12/06/2023
*/

#ifndef CONTROL_TIME
#define CONTROL_TIME

#include <time.h>
#include <fstream>
#include <sys/time.h>
#include <sys/resource.h>

// Estrutura para armazenar os tempos de usuário, sistema e relógio
struct Time {
    double user_time;
    double system_time;
    double clock_time;
};

class ControlTime {
    public:
        /*
            @brief Construtor da classe ControlTime
            @param Nome do arquivo de saída em .csv
        */
        ControlTime(std::string filename = "output.csv");
        ~ControlTime();

        /*
            @brief Inicia a contagem de tempo
            @param PID do processo que será contabilizado
        */
        void start(int PID);

        /*
            @brief Para a contagem de tempo
            @param PID do processo que será contabilizado
        */
        void stop(int PID);

        /*
            @brief Retorna o tempo de usuário, sistema e relógio armazenado internamente na classe
            @return Tempo de usuário, sistema e relógio
        */
        Time get_time();

        /*
            @brief Escreve o tempo de usuário, sistema e relógio em um arquivo .csv
            @param Método de ordenação
            @param Método de cálculo da envoltória convexa
            @param Tamanho da entrada
            @param Tempo de usuário, sistema e relógio
        */
        void write_csv(long compacted_size, long original_size, std::string func, std::string mode, Time time);
        
    private:
        // Estruturas para armazenar os tempos de usuário, sistema e relógio
        struct rusage init, end;
        struct timespec start_clock, end_clock;
        std::ofstream csv;
};

#endif
