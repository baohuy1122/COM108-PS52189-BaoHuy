#include <stdio.h>
#include <string.h>
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};
void xoaBoDem(void);
void loaiBoXuongDong(char str[]);
void nhapVatXuatDanhSach(struct SinhVien ds[], int *n);
void sapXepTheoDiem(struct SinhVien ds[], int n);
void timKiemTheoMSSV(struct SinhVien ds[], int n);
void xuatHocBongTheoNganh(struct SinhVien ds[], int n);

int main() {
    struct SinhVien dsSV[50];
    int n = 0; 
    int chon;

    do {
        printf("+--------------------------------------------+\n");
        printf("|          MENU CHUONG TRINH LAB 8           |\n");
        printf("+--------------------------------------------+\n");
        printf("| 1. Nhap va xuat danh sach sinh vien        |\n");
        printf("| 2. Sap xep sinh vien theo diem tang dan    |\n");
        printf("| 3. Tim kiem sinh vien theo MSSV            |\n");
        printf("| 4. Xuat sinh vien nhan hoc bong theo nganh |\n");
        printf("| 5. Thoat chuong trinh                      |\n");
        printf("+--------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                nhapVatXuatDanhSach(dsSV, &n);
                break;
            case 2:
                if (n == 0) {
                    printf("\nDanh sach chua co sinh vien nao! Vui long chon chuc nang 1 de nhap danh sach.\n\n");
                } else {
                    sapXepTheoDiem(dsSV, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nDanh sach chua co sinh vien nao! Vui long chon chuc nang 1 de nhap danh sach.\n\n");
                } else {
                    timKiemTheoMSSV(dsSV, n);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nDanh sach chua co sinh vien nao! Vui long chon chuc nang 1 de nhap danh sach.\n\n");
                } else {
                    xuatHocBongTheoNganh(dsSV, n);
                }
                break;
            case 5:
                printf("\nDa thoat chuong trinh.\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon lai tu 1 den 5.\n\n");
        }
    } while (chon != 5);

    return 0;
}

// Hàm hỗ trợ xóa bộ đệm bàn phím
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void loaiBoXuongDong(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Bai 1: Nhap va xuat danh sach sinh vien
void nhapVatXuatDanhSach(struct SinhVien ds[], int *n) {
    do {
        printf("\nNhap so luong sinh vien (1 - 50): ");
        scanf("%d", n);
        if (*n <= 0 || *n > 50) {
            printf("So luong sinh vien khong hop le! Vui long nhap lai.\n");
        }
    } while (*n <= 0 || *n > 50);

    for (int i = 0; i < *n; i++) {
        printf("\n--- Nhap thong tin sinh vien thu [%d] ---\n", i + 1);
        
        printf("MSSV: ");
        xoaBoDem();
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        loaiBoXuongDong(ds[i].mssv);

        printf("Ten SV: ");
        fgets(ds[i].tenSV, sizeof(ds[i].tenSV), stdin);
        loaiBoXuongDong(ds[i].tenSV);

        printf("Nganh hoc: ");
        fgets(ds[i].nganhHoc, sizeof(ds[i].nganhHoc), stdin);
        loaiBoXuongDong(ds[i].nganhHoc);

        do {
            printf("Diem TB (0.0 - 10.0): ");
            scanf("%f", &ds[i].diemTB);
            if (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0) {
                printf("Diem TB khong hop le! Nhap lai trong khoang 0.0 den 10.0.\n");
            }
        } while (ds[i].diemTB < 0.0 || ds[i].diemTB > 10.0);
    }

    printf("\n================ DANH SACH SINH VIEN ================\n");
    for (int i = 0; i < *n; i++) {
        printf("Sinh vien thu [%d]:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n\n", ds[i].diemTB);
    }
}

// Bai 2: Sap xep sinh vien theo diem tang dan
void sapXepTheoDiem(struct SinhVien ds[], int n) {
    struct SinhVien svTemp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diemTB > ds[j].diemTB) {
                svTemp = ds[i];
                ds[i] = ds[j];
                ds[j] = svTemp;
            }
        }
    }

    printf("\n===== DANH SACH SAU KHI SAP XEP TANG DAN THEO DIEM TB =====\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien thu [%d]:\n", i + 1);
        printf("MSSV: %s\n", ds[i].mssv);
        printf("Ten SV: %s\n", ds[i].tenSV);
        printf("Nganh hoc: %s\n", ds[i].nganhHoc);
        printf("Diem TB: %.2f\n\n", ds[i].diemTB);
    }
}

// Bai 3: Tim kiem sinh vien theo MSSV
void timKiemTheoMSSV(struct SinhVien ds[], int n) {
    char mssvTim[50];
    printf("\nNhap ma so sinh vien can tim: ");
    xoaBoDem();
    fgets(mssvTim, sizeof(mssvTim), stdin);
    loaiBoXuongDong(mssvTim);

    int timThay = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].mssv, mssvTim) == 0) {
            printf("\nTim thay sinh vien:\n");
            printf("MSSV: %s\n", ds[i].mssv);
            printf("Ten SV: %s\n", ds[i].tenSV);
            printf("Nganh hoc: %s\n", ds[i].nganhHoc);
            printf("Diem TB: %.2f\n\n", ds[i].diemTB);
            timThay = 1;
            break;
        }
    }

    if (!timThay) {
        printf("\nKhong tim thay sinh vien co MSSV: %s\n\n", mssvTim);
    }
}

// Bai 4: Xuat danh sach sinh vien nhan hoc bong theo nganh
void xuatHocBongTheoNganh(struct SinhVien ds[], int n) {
    int coHocBong = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            coHocBong = 1;
            break;
        }
    }

    if (!coHocBong) {
        printf("\nKhong co sinh vien nao dat hoc bong.\n\n");
        return;
    }

    printf("\n======== DANH SACH SINH VIEN NHAN HOC BONG THEO NGANH ========\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTB >= 8.0) {
            int daInNganh = 0;
            for (int k = 0; k < i; k++) {
                if (ds[k].diemTB >= 8.0 && strcmp(ds[i].nganhHoc, ds[k].nganhHoc) == 0) {
                    daInNganh = 1;
                    break;
                }
            }
            if (!daInNganh) {
                printf("\nNganh: %s\n", ds[i].nganhHoc);
                for (int j = 0; j < n; j++) {
                    if (ds[j].diemTB >= 8.0 && strcmp(ds[j].nganhHoc, ds[i].nganhHoc) == 0) {
                        printf("- [%s] - [%s] - Diem TB: %.2f\n", ds[j].mssv, ds[j].tenSV, ds[j].diemTB);
                    }
                }
            }
        }
    }
    printf("\n");
}