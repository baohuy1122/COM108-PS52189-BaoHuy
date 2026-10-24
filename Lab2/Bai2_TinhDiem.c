#include <stdio.h>
int main(void) {
    float toan, ly, hoa;
    float diemTrungBinh;
    printf("Nhap diem Toan: ");
    if (scanf("%f", &toan) != 1 || !(toan >= 0.0f && toan <= 10.0f)) {
        printf("Diem Toan khong hop le (0-10).\n");
        return 1;
    }
    printf("Nhap diem Ly: ");
    if (scanf("%f", &ly) != 1 || !(ly >= 0.0f && ly <= 10.0f)) {
        printf("Diem Ly khong hop le (0-10).\n");
        return 1;
    }
    printf("Nhap diem Hoa: ");
    if (scanf("%f", &hoa) != 1 || !(hoa >= 0.0f && hoa <= 10.0f)) {
        printf("Diem Hoa khong hop le (0-10).\n");
        return 1;
    }
    diemTrungBinh = (toan * 3 + ly * 2 + hoa * 1) / 6.0f;
    printf("Diem trung binh: %.2f\n", diemTrungBinh);
    return 0;
}