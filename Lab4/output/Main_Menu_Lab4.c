#include <stdio.h>
#include <stdbool.h>

void bai2_tinhTrungBinhCong() {
    int min, max;
    printf("\n--- CHUC NANG 1: Tinh trung binh cong cac so chia het cho 2 ---\n");
    printf("Nhap min: ");
    scanf("%d", &min);
    printf("Nhap max: ");
    scanf("%d", &max);


    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    int tong = 0;
    int bienDem = 0;


    for (int i = min; i <= max; i++) {
        if (i % 2 == 0) { // Kiểm tra chia hết cho 2 
            tong += i;
            bienDem++;
        }
    }


    if (bienDem == 0) {
        printf("Khong co so nao chia het cho 2 trong khoang [%d, %d]\n", min, max);
    } else {
        float trungBinh = (float)tong / bienDem; // Ép kiểu float
        printf("Tong cac so chia het cho 2: %d\n", tong);
        printf("So luong cac so chia het cho 2: %d\n", bienDem);
        printf("Trung binh cong: %.2f\n", trungBinh);
    }
}


void bai3_kiemTraSoNguyenTo() {
    int x;
    printf("\n--- CHUC NANG 2: Kiem tra so nguyen to ---\n");
    printf("Nhap vao mot so nguyen x: ");
    scanf("%d", &x);

    if (x < 2) {
        printf("%d khong phai la so nguyen to.\n", x);
    } else {
        bool laSoNguyenTo = true;
        for (int i = 2; i * i <= x; i++) { // Duyệt từ 2 đến sqrt(x)
            if (x % i == 0) {
                laSoNguyenTo = false;
                break;
            }
        }

        if (laSoNguyenTo) {
            printf("%d la so nguyen to.\n", x);
        } else {
            printf("%d khong phai la so nguyen to.\n", x);
        }
    }
}


void bai4_kiemTraSoChinhPhuong() {
    int x;
    printf("\n--- CHUC NANG 3: Kiem tra so chinh phuong ---\n");
    printf("Nhap vao mot so nguyen x: ");
    scanf("%d", &x);


    if (x < 0) {
        printf("%d khong phai la so chinh phuong.\n", x);
    } else if (x == 0) {
        printf("%d la so chinh phuong.\n", x); // 0 = 0 * 0
    } else {
        bool laSoChinhPhuong = false;
        for (int i = 1; i <= x; i++) {
            if (i * i == x) {
                laSoChinhPhuong = true;
                break; // Thoát vòng lặp sớm
            }
            if (i * i > x) {
                break; // Tối ưu: dừng sớm nếu i*i đã vượt quá x
            }
        }

        if (laSoChinhPhuong) {
            printf("%d la so chinh phuong.\n", x);
        } else {
            printf("%d khong phai la so chinh phuong.\n", x);
        }
    }
}

int main() {
    int chon;

    do {
        printf("\n+------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB             |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2 |\n");
        printf("| 2. Kiem tra So nguyen to                      |\n");
        printf("| 3. Kiem tra So chinh phuong                    |\n");
        printf("| 4. Thoat chuong trinh                          |\n");
        printf("+------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                bai2_tinhTrungBinhCong();
                break;
            case 2:
                bai3_kiemTraSoNguyenTo();
                break;
            case 3:
                bai4_kiemTraSoChinhPhuong();
                break;
            case 4:
                printf("\nDa thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 4.\n");
                break;
        }
    } while (chon != 4);

    return 0;
}