#include <stdio.h>
int main(){
    int a = 10;
    int b = 20;
    printf("Truoc khi hoan vi: a = %d, b = %d\n", a, b);
    int tam = a;
    a = b;
    b = tam;
    printf("Sau khi hoan vi: a = %d, b = %d\n", a, b);
    return 0;
}