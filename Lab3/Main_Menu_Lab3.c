#include <stdio.h>
#include <math.h>

void thoatChuongTrinh(void) {
    printf("Thoat chuong trinh. Tam biet!\n");
}

void tinhHocLuc(void){
    // Điểm ≥ 9.0: Xuất sắc.
    // Từ 8.0 đến dưới 9.0: Giỏi.
    // Từ 6.5 đến dưới 8.0: Khá.
    // Từ 5.0 đến dưới 6.5: Trung bình.
    // Từ 3.5 đến dưới 5.0: Yếu.
    // Dưới 3.5: Kém.
    printf("Tinh hoc luc sinh vien\n");
    float diem;
    do {
        printf("Nhap diem (0-10): ");
        if (scanf("%f", &diem) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            printf("Diem khong hop le.\n");
            return;
        }
    } while (!(diem >= 0.0f && diem <= 10.0f));

    if (diem >= 9.0) {
        printf("Xuat sac\n");
    } else if (diem >= 8.0) {
        printf("Gioi\n");
    } else if (diem >= 6.5) {
        printf("Kha\n");
    } else if (diem >= 5.0) {
        printf("Trung binh\n");
    } else if (diem >= 3.5) {
        printf("Yeu\n");
    } else {
        printf("Kem\n");
    }
}

void giaiPTBacHai(void){
    printf("Giai phuong trinh bac hai\n");
    float a, b, c, x1, x2, delta;
    printf("Nhap a, b, c: ");
    if (scanf("%f %f %f", &a, &b, &c) != 3 ||
        !isfinite(a) || !isfinite(b) || !isfinite(c)) {
        int kyTu;
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        printf("He so khong hop le.\n");
        return;
    }
    printf("Phuong trinh %.0fx2 + %.0fx + %.0f = 0\n", a, b, c);

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Phuong trinh vo so nghiem\n");
            } else {
                printf("Phuong trinh vo nghiem\n");
            }
        } else {
            x1 = -c / b;
            printf("Phuong trinh bac nhat co nghiem x = %.2f\n", x1);
        }
    } else {
        delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phuong trinh vo nghiem\n");
        } else if (delta == 0) {
            x1 = -b / (2 * a);
            printf("Phuong trinh co nghiem kep x1 = x2 = %.2f\n", x1);
        } else {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            printf("Phuong trinh co hai nghiem: x1 = %.2f, x2 = %.2f\n", x1, x2);
        }
    }
}

void tinhTienDien(void){
    printf("Tinh tien dien tieu thu\n");
    printf("Can bang gia theo de bai de tinh chinh xac tien dien.\n");
}

int main(void){
    int chon;

    do {
        printf("===== MENU CHUONG TRINH LAB 3 =====\n");
        printf("0. Thoat chuong trinh\n");
        printf("1. Tinh hoc luc sinh vien\n");
        printf("2. Giai phuong trinh bac hai\n");
        printf("3. Tinh tien dien tieu thu\n");
        printf("Nhap lua chon cua ban: ");
        if (scanf("%d", &chon) != 1) {
            int kyTu;
            while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
            }
            if (feof(stdin)) {
                break;
            }
            printf("Lua chon khong hop le. Vui long nhap so tu 0 den 3.\n");
            continue;
        }

        switch (chon) {
            case 0:
                thoatChuongTrinh();
                break;
            case 1:
                tinhHocLuc();
                break;
            case 2:
                giaiPTBacHai();
                break;
            case 3:
                tinhTienDien();
                break;
            default:
                printf("Ban phai nhap so tu 0 - 3\n");
        }
    } while (chon != 0);

    return 0;
}