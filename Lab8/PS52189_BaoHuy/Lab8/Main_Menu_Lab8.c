#include <stdio.h>
#include <string.h>
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};
void nhapVatXuatDanhSach(struct SinhVien ds[], int *n);
void sapXepTheoDiem(struct SinhVien ds[], int n);
void timKiemTheoMSSV(struct SinhVien ds[], int n);
void xuatHocBongTheoNganh(struct SinhVien ds[], int n);
int docSoNguyen(const char *prompt, int *giaTri);
int docSoThuc(const char *prompt, float *giaTri);
int docDong(const char *prompt, char str[], size_t kichThuoc);

int main(void) {
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
        int ketQuaNhap = docSoNguyen(">> Xin moi chon chuc nang (1-5): ", &chon);
        if (ketQuaNhap == 0) {
            break;
        }
        if (ketQuaNhap < 0) {
            printf("\nChuc nang khong hop le! Vui long nhap so tu 1 den 5.\n\n");
            continue;
        }

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

int docSoNguyen(const char *prompt, int *giaTri) {
    printf("%s", prompt);
    if (scanf("%d", giaTri) != 1) {
        int kyTu;
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        return feof(stdin) ? 0 : -1;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 1;
}

int docSoThuc(const char *prompt, float *giaTri) {
    printf("%s", prompt);
    if (scanf("%f", giaTri) != 1) {
        int kyTu;
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
        return feof(stdin) ? 0 : -1;
    }
    int kyTu;
    while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
    }
    return 1;
}

int docDong(const char *prompt, char str[], size_t kichThuoc) {
    printf("%s", prompt);
    if (fgets(str, kichThuoc, stdin) == NULL) {
        return 0;
    }
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    } else if (!feof(stdin)) {
        int kyTu;
        while ((kyTu = getchar()) != '\n' && kyTu != EOF) {
        }
    }
    return 1;
}

// Bai 1: Nhap va xuat danh sach sinh vien
void nhapVatXuatDanhSach(struct SinhVien ds[], int *n) {
    while (1) {
        int ketQuaNhap = docSoNguyen("\nNhap so luong sinh vien (1 - 50): ", n);
        if (ketQuaNhap == 0) {
            *n = 0;
            return;
        }
        if (ketQuaNhap < 0) {
            printf("So luong sinh vien khong hop le! Vui long nhap lai.\n");
            continue;
        }
        if (*n > 0 && *n <= 50) {
            break;
        }
        printf("So luong sinh vien khong hop le! Vui long nhap lai.\n");
    }

    for (int i = 0; i < *n; i++) {
        printf("\n--- Nhap thong tin sinh vien thu [%d] ---\n", i + 1);
        if (!docDong("MSSV: ", ds[i].mssv, sizeof(ds[i].mssv))) {
            *n = 0;
            return;
        }

        if (!docDong("Ten SV: ", ds[i].tenSV, sizeof(ds[i].tenSV))) {
            *n = 0;
            return;
        }

        if (!docDong("Nganh hoc: ", ds[i].nganhHoc, sizeof(ds[i].nganhHoc))) {
            *n = 0;
            return;
        }

        while (1) {
            int ketQuaNhap = docSoThuc("Diem TB (0.0 - 10.0): ", &ds[i].diemTB);
            if (ketQuaNhap == 0) {
                *n = 0;
                return;
            }
            if (ketQuaNhap < 0 || !(ds[i].diemTB >= 0.0f && ds[i].diemTB <= 10.0f)) {
                printf("Diem TB khong hop le! Nhap lai trong khoang 0.0 den 10.0.\n");
            } else {
                break;
            }
        }
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
    if (!docDong("\nNhap ma so sinh vien can tim: ", mssvTim, sizeof(mssvTim))) {
        return;
    }

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