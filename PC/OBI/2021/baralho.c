#include <stdio.h>
#include <string.h>

int char_to_int(char c) {
    return c - '0';
}

void result(int v[13]) {
    int sum = 0;
    for(int i = 0; i < 13; i++) {
        if(v[i] < 0) {
            printf("erro\n");
            return;
        }
        sum += v[i];
    }
    printf("%d\n", sum);
}

int main() {
    char str[160];

    scanf("%s", str);
    
    int c[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int e[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int u[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int p[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int i = 0; i < strlen(str); i+=3) {
        int value = char_to_int(str[i])*10 + char_to_int(str[i+1]) - 1;
        
        if(str[i+2] == 'C') c[value]--;
        if(str[i+2] == 'E') e[value]--;
        if(str[i+2] == 'U') u[value]--;
        if(str[i+2] == 'P') p[value]--;
    }
    result(c);
    result(e);
    result(u);
    result(p);
}