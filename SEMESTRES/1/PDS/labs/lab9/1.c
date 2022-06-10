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
    for(int i = 0; i < n; i++) {
        scanf("%s", schedule[i].name);
        scanf("%s", schedule[i].local);
        scanf("%d", &schedule[i].date.day);
        scanf("%d", &schedule[i].date.month);
        scanf("%d", &schedule[i].date.year);
    }
}

void print_events(Event schedule[], Date date, int n) {
    int count = 0;

    for(int i = 0; i < n; i++) {
        Date sch_date = schedule[i].date;

        if(
            date.day == sch_date.day &&
            date.month == sch_date.month &&
            date.year == sch_date.year
        ) {
            count++;
            printf("%s %s\n", schedule[i].name, schedule[i].local);
        }
    }

    if(count == 0)
        printf("Nenhum evento encontrado!\n");
}

int main() {
    int N;

    scanf("%d", &N);
    
    Event schedule[N];

    register_events(schedule, N);

    Date date;

    scanf("%d %d %d", &date.day, &date.month, &date.year);

    print_events(schedule, date, N);
}