#include <stdio.h>
#define PI 3.14159
int main() {
    float chieuDai, chieuRong;
    float banKinh;
    printf("Nhap chieu dai hinh chu nhat: ");
    scanf("%f", &chieuDai);
    printf("Nhap chieu rong hinh chu nhat: ");
    scanf("%f", &chieuRong);
    float chuViHCN = (chieuDai + chieuRong) * 2;
    float dienTichHCN = chieuDai * chieuRong;
    printf("Nhap ban kinh hinh tron: ");
    scanf("%f", &banKinh);
    float chuViHT = 2 * PI * banKinh;
    float dienTichHT = PI * banKinh * banKinh;
    printf("Chu vi hinh chu nhat: %.2f\n", chuViHCN);
    printf("Dien tich hinh chu nhat: %.2f\n", dienTichHCN);
    printf("Chu vi hinh tron: %.2f\n", chuViHT);
    printf("Dien tich hinh tron: %.2f\n", dienTichHT);
    return 0;
}