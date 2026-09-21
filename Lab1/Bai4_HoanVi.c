#include <stdio.h>
int main(){
    int a = 10;
    int b = 20;
    printf("Truoc khi hoan vị: a = %d , b = %d\n , a , b");
    a = a + b;
    b = a - b;
    a = a -b;
    printf("sau khi hoan vi: a = %d , b= %d\n" , a , b);
    return 0;
}