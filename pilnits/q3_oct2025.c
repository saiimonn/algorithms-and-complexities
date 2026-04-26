#include <stdio.h>

void reverse_dig(int);

int main() {
    reverse_dig(456);
}

void reverse_dig(int num) {
    int rev = 0;
    int rm = 0;
    int temp = num;
    
    while(temp > 0) {
        rm = temp % 10;
        rev = rev * 10 + rm;
        temp /= 10;
    }
    printf("%d", rev);
}