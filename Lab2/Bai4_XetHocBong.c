#include <stdio.h>
int main(void) {
    float diemTB;
    int hanhKiem;
    printf("Nhap diem trung binh: ");
    if (scanf("%f", &diemTB) != 1 || !(diemTB >= 0.0f && diemTB <= 10.0f)) {
        printf("Diem trung binh khong hop le (0-10).\n");
        return 1;
    }
    printf("Nhap hanh kiem (1 = Tot, 0 = Khac): ");
    if (scanf("%d", &hanhKiem) != 1 || (hanhKiem != 0 && hanhKiem != 1)) {
        printf("Hanh kiem khong hop le.\n");
        return 1;
    }
    int dieuKienDiem = (diemTB >= 8.0);
    int dieuKienHanhKiem = (hanhKiem == 1);
    int ketQua = dieuKienDiem && dieuKienHanhKiem;
    printf("Dieu kien diem trung binh >= 8: [%d neu dung, 0 neu sai]\n", dieuKienDiem);
    printf("Dieu kien hanh kiem tot: [%d neu dung, 0 neu sai]\n", dieuKienHanhKiem);
    printf("Ket qua xet hoc bong (1: Dat, 0: Khong dat): %d\n", ketQua);
    return 0;
}