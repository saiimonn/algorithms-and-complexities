#include <stdio.h>

int division(int a, int b) {
    int u;
    u = a / b;
    return u;
}

int mod(int a, int b) {
    int u;
    u = a % b;
    return u;
}

int convert(int input){ 
    int hour, min, sec;
    sec = mod(input, 60);
    min = mod(division(input, 60), 60);
    hour = division(input, 3600);
}

