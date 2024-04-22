#include <stdio.h>
#include <string.h>
#include "../lib/funcs.h"

int convertToInteger(char str[4]){
    int len = strlen(str);
    int res = 0;
    for(int i = 0; i < len; ++i){
        res += str[i] - 48;
        res *= 10;
    }
    printf("Int = %d\n", res);
    return res;
}

/*
int inputFunction(char str[], int size){
    fgets(str, size, stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }
    else {
        int ch;
        while((ch = getchar()) != EOF && ch != '\n')
            ;
    }
    return convertToInteger(str);
}
*/