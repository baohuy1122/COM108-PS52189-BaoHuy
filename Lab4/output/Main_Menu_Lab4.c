#include <stdio.h>
#include <stdbool.h>

static int docSoNguyen(int *giaTri) {
    if (scanf("%d", giaTri) != 1) {
        int kyTu;
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        return 0;
    }
    int kyTu;
    while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
    }
    return 1;
}

void bai2_tinhTrungBinhCong(void) {
    int min, max;
    printf("\n--- CHUC NANG 1: Tinh trung binh cong cac so chia het cho 2 ---\n");
    printf("Nhap min: ");
    if (!docSoNguyen(&min)) {
        printf("Gia tri min khong hop le.\n");
        return;
    }
    printf("Nhap max: ");
    if (!docSoNguyen(&max)) {
        printf("Gia tri max khong hop le.\n");
        return;
    }


    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    long long dauChan = (long long)min + (min % 2 != 0);
    long long cuoiChan = (long long)max - (max % 2 != 0);
    long long bienDem = dauChan <= cuoiChan ? (cuoiChan - dauChan) / 2 + 1 : 0;


    if (bienDem == 0) {
        printf("Khong co so nao chia het cho 2 trong khoang [%d, %d]\n", min, max);
    } else {
        long long tong = bienDem * (dauChan + cuoiChan) / 2;
        long double trungBinh = (long double)tong / bienDem;
        printf("Tong cac so chia het cho 2: %lld\n", tong);
        printf("So luong cac so chia het cho 2: %lld\n", bienDem);
        printf("Trung binh cong: %.2Lf\n", trungBinh);
    }
}


void bai3_kiemTraSoNguyenTo(void) {
    int x;
    printf("\n--- CHUC NANG 2: Kiem tra so nguyen to ---\n");
    printf("Nhap vao mot so nguyen x: ");
    if (!docSoNguyen(&x)) {
        printf("So nguyen khong hop le.\n");
        return;
    }

    if (x < 2) {
        printf("%d khong phai la so nguyen to.\n", x);
    } else {
        bool laSoNguyenTo = true;
        for (int i = 2; i <= x / i; i++) {
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


void bai4_kiemTraSoChinhPhuong(void) {
    int x;
    printf("\n--- CHUC NANG 3: Kiem tra so chinh phuong ---\n");
    printf("Nhap vao mot so nguyen x: ");
    if (!docSoNguyen(&x)) {
        printf("So nguyen khong hop le.\n");
        return;
    }


    if (x < 0) {
        printf("%d khong phai la so chinh phuong.\n", x);
    } else if (x == 0) {
        printf("%d la so chinh phuong.\n", x); // 0 = 0 * 0
    } else {
        bool laSoChinhPhuong = false;
        for (int i = 1; i <= x / i; i++) {
            if (i == x / i && x % i == 0) {
                laSoChinhPhuong = true;
                break; // Thoát vòng lặp sớm
            }
        }

        if (laSoChinhPhuong) {
            printf("%d la so chinh phuong.\n", x);
        } else {
            printf("%d khong phai la so chinh phuong.\n", x);
        }
    }
}

int main(void) {
    int chon;

    while (1) {
        printf("\n+------------------------------------------------+\n");
        printf("|              MENU CHUONG TRINH LAB             |\n");
        printf("+------------------------------------------------+\n");
        printf("| 1. Tinh trung binh tong cac so chia het cho 2 |\n");
        printf("| 2. Kiem tra So nguyen to                      |\n");
        printf("| 3. Kiem tra So chinh phuong                    |\n");
        printf("| 4. Thoat chuong trinh                          |\n");
        printf("+------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-4): ");
        if (!docSoNguyen(&chon)) {
            if (feof(stdin)) {
                break;
            }
            printf("\nLua chon khong hop le! Vui long chon tu 1 den 4.\n");
            continue;
        }

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
                return 0;
            default:
                printf("\nLua chon khong hop le! Vui long chon tu 1 den 4.\n");
                break;
        }
    }

    return 0;
}