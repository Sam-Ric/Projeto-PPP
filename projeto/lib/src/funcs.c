#include <stdio.h>

void input(char str[50]){

}

int convertToInteger(char str[20]){
    int len = strlen(str);
    int res = 0;
    printf("-----\nString = %s\n", str);
    for(int i = 0; i < len; ++i){
        res += str[i];
        for(int j = len - i - 1; j > 0; --j)
            res *= 10;
    }
    printf("Int = %d\n-----\n", res);
    return res;
}