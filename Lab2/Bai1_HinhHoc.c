#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main(void) {
    float chieuDai, chieuRong;
    float banKinh;
    printf("Nhap chieu dai hinh chu nhat: ");
    if (scanf("%f", &chieuDai) != 1 || !isfinite(chieuDai) || !(chieuDai > 0.0f)) {
        printf("Chieu dai khong hop le.\n");
        return 1;
    }
    printf("Nhap chieu rong hinh chu nhat: ");
    if (scanf("%f", &chieuRong) != 1 || !isfinite(chieuRong) || !(chieuRong > 0.0f)) {
        printf("Chieu rong khong hop le.\n");
        return 1;
    }
    float chuViHCN = (chieuDai + chieuRong) * 2;
    float dienTichHCN = chieuDai * chieuRong;
    printf("Nhap ban kinh hinh tron: ");
    if (scanf("%f", &banKinh) != 1 || !isfinite(banKinh) || !(banKinh > 0.0f)) {
        printf("Ban kinh khong hop le.\n");
        return 1;
    }
    float chuViHT = 2 * PI * banKinh;
    float dienTichHT = PI * banKinh * banKinh;
    printf("Chu vi hinh chu nhat: %.2f\n", chuViHCN);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTichHCN);
    printf("Chu vi hinh tron: %.2f\n", chuViHT);
    printf("Dien tich hinh tron: %.2f\n", dienTichHT);
    return 0;
}