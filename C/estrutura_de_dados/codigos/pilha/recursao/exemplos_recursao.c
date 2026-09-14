#include <stdio.h>

float fatorial (int n) {

    if(n <= 1) return 1;
    return n * fatorial(n-1);

}

unsigned int fibonacci (int n) {
    if(n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int i;

    // for(i=0; i < 14; i++)
    //     printf("Fatorial de %d = %.0f\n", i, fatorial(i));
    for(i=0; i<=46; i++)
        printf("fibonacci em %d = %u\n", i, fibonacci(i));
    return 0;
}