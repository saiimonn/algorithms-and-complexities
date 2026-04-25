#include <stdio.h>

int sumDigits(int num) {
    int sum = 0;
    
    while (num > 0) {
        sum = sum + num % 10;
        num = num / 10;
    }
}

int main() {
    
}