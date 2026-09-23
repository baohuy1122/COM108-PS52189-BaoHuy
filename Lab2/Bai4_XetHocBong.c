#include <stdio.h>
int main() {
    float diemTB;
    int hanhKiem;
    printf("Nhap diem trung binh: ");
    scanf("%f", &diemTB);
    printf("Nhap hanh kiem (1 = Tot, 0 = Khac): ");
    scanf("%d", &hanhKiem);
    int dieuKienDiem = (diemTB >= 8.0);
    int dieuKienHanhKiem = (hanhKiem == 1);
    int ketQua = dieuKienDiem && dieuKienHanhKiem;
    printf("Dieu kien diem trung binh >= 8: [%d neu dung, 0 neu sai]\n", dieuKienDiem);
    printf("Dieu kien hanh kiem tot: [%d neu dung, 0 neu sai]\n", dieuKienHanhKiem);
    printf("Ket qua xet hoc bong (1: Dat, 0: Khong dat): %d\n", ketQua);
    return 0;
}