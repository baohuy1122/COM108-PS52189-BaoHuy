#include <stdio.h>
#include <math.h>
int main(void) {
    float a, b;
    printf("Nhap he so a: ");
    if (scanf("%f", &a) != 1 || !isfinite(a)) {
        printf("He so a khong hop le.\n");
        return 1;
    }
    printf("Nhap he so b: ");
    if (scanf("%f", &b) != 1 || !isfinite(b)) {
        printf("He so b khong hop le.\n");
        return 1;
    }
    if (a == 0.0f) {
        if (b == 0.0f) {
            printf("Phuong trinh co vo so nghiem.\n");
        } else {
            printf("Phuong trinh vo nghiem.\n");
        }
    } else {
        float x = -b / a;
        printf("Nghiem cua phuong trinh la: x = %.2f\n", x);
    }
    return 0;
}