#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

int strsize(char str[MAXN]) {
    return strlen(str) - 1;
}

int similarity(char str1[MAXN], char str2[MAXN]) {
    if (strsize(str1) < strsize(str2)) {
        return similarity(str2, str1);
    }

    if (strsize(str1) == strsize(str2)) {
        int diff = 0;

        for(int i = 0; i < strsize(str2); i++)
            if(str1[i] != str2[i])
                diff++;

        return diff;
    }

    int prev_row[strsize(str2)+1];

    for(int i = 0; i <= strsize(str2); i++) 
        prev_row[i] = i;

    
    for(int i = 0; i < strsize(str1); i++) {
        char c1 = str1[i];
        int curr_row[strsize(str2)+1];

        curr_row[0] = i+1;

        for(int j = 0; j < strsize(str2); j++) {
            char c2 = str2[j];

            int ins = prev_row[j + 1] + 1;
            int del = curr_row[0] + 1;
            int subs = prev_row[j] + (c1 != c2 ? 1 : 0);

            if (ins < del && ins < subs)
                curr_row[j+1] = ins;
            else if (del < ins && del < subs)
                curr_row[j+1] = del;
            else
                curr_row[j+1] = subs;
        }

        for(int k = 0; k <= strsize(str2); k++)
            prev_row[k] = curr_row[k];
    }

    return prev_row[strsize(str2)];
}


int main() {
    char str1[MAXN], str2[MAXN];

    fgets(str1, sizeof str1, stdin);
    fgets(str2, sizeof str2, stdin);

    printf("%d\n", similarity(str1, str2));

    return 0;
}