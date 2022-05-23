#include <stdio.h>

int days_of_month(int m, int y) {
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            return 31;
        else if(m == 2 && bissexto(y))
            return 29;
        else if(m == 2)
            return 28;
        else
            return 30;
}

int bissexto(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int qtd(int d, int m, int y) {
    int res = days_of_month(m, y) - d;

    int i;
    for(i = m+1; i <= 12; i++) {
        res += days_of_month(i, y);
    }

    for(i = y+1; i < 2020; i++) {
        if(bissexto(i))
            res += 366;
        else
            res += 365;
    }

    return res + 261 + 1;
}

int main() {
    int day, month, year;

    while(scanf("%d %d %d", &day, &month, &year) != EOF) {
        printf("%d\n", qtd(day, month, year));
    }

    system("pause");
    return 0;
}
