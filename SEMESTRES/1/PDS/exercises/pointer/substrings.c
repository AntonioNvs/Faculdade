/*
    Elabore uma func ̧  ̃ao que receba duas strings como par ˆametros e verifique se a segunda
    string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres
    das strings.
*/

#include <stdio.h>
#include <stdlib.h>

int substr(char *text, char *pattern) {
    
    while(*text != '\0') {
        int j = 0;
        int isSubstring = 1;

        while(*(pattern + j*sizeof(char)) != '\0') {
            if(*(pattern + j*sizeof(char)) != *(text + j*sizeof(char))) {
                isSubstring = 0;
                break;
            }
            j++;
        }
        if(isSubstring)
            return 1;

        text += sizeof(char);
    }

    return 0;
}

int main() {
    char text[] = "I'm writing a text just for verify if my code works.";
    char pattern[] = "just";

    printf("%d\n", substr(text, pattern));

    return 0;
}