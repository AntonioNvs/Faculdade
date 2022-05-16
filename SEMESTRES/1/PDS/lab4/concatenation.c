#include <stdio.h>
#include <string.h>

#define MAX 1100

int main() {
    char str1[MAX], str2[MAX], final[MAX];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%s\n", strcat(str1, str2));
}