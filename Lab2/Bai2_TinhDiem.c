#include <stdio.h>
int main() {
    float toan, ly, hoa;
    float diemTrungBinh;
    printf("Nhap diem Toan: ");
    scanf("%f", &toan);
    printf("Nhap diem Ly: ");
    scanf("%f", &ly);
    printf("Nhap diem Hoa: ");
    scanf("%f", &hoa);
    diemTrungBinh = (toan * 3 + ly * 2 + hoa * 1) / 6.0f;
    printf("Diem trung binh: %.2f\n", diemTrungBinh);
    return 0;
}