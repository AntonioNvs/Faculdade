#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[100];
    char local[100];
    Date date;
} Event;

void register_events(Event schedule[], int n) {
    for(int i = 0; i < N; i++) {
        scanf("%s", schedule[i].name);
        scanf("%s", schedule[i].local);
        scanf("%d", &schedule[i].date.day);
        scanf("%d", &schedule[i].date.month);
        scanf("%d", &schedule[i].date.year);
    }
}

void print_events(Event schedule[], Date date, int n) {
    for(int i = 0; i < n;)
}

int main() {
    int N;

    scanf("%d", &N);
    
    Event schedule[N];

    register_events(schedule, N);
}