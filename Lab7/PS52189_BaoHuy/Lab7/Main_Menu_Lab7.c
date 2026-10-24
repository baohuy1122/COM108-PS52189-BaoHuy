#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>

// Khai báo nguyên mẫu hàm (Function Prototype)
void bai1_DemNguyenAmPhuAm(void);
void bai2_DangNhap(void);
void bai3_SapXepChuoi(void);
void bai4_ThapPhanSangHex(void);


int getPassword(char *password, int max_len) {
    struct termios oldt, newt;
    int i = 0;
    int c;

    if (max_len <= 0 || !isatty(STDIN_FILENO) ||
        tcgetattr(STDIN_FILENO, &oldt) == -1) {
        return 0;
    }
    newt = oldt;
    
    newt.c_lflag &= ~(ECHO | ICANON);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) == -1) {
        return 0;
    }

    fflush(stdout);
    while (i < max_len - 1) {
        c = getchar();
        if (c == EOF) {
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            return 0;
        }
        if (c == '\n' || c == '\r') {
            break;
        }
        else if (c == 127 || c == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
                fflush(stdout);
            }
        } 
        else if (c >= 32 && c <= 126) {
            password[i++] = c;
            printf("*");
            fflush(stdout);
        }
    }
    password[i] = '\0';

    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) == -1) {
        return 0;
    }
    printf("\n");
    return 1;
}

int main(void) {
    int choice;
    int ch;
    do {
        printf("\n+-------------------------------------------------------+\n");
        printf("|               MENU CHUONG TRINH LAB 7                 |\n");
        printf("+-------------------------------------------------------+\n");
        printf("| 1. Dem nguyên am va phu am cua chuoi                  |\n");
        printf("| 2. Dang nhap bang Username va Password                |\n");
        printf("| 3. Sap xep chuoi theo chu cai                         |\n");
        printf("| 4. Doi so thap phan sang thap luc phan                |\n");
        printf("| 5. Thoat chuong trinh                                 |\n");
        printf("+-------------------------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Loi: Vui lòng nhập số nguyên hợp lệ!\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            if (ch == EOF) {
                break;
            }
            continue;
        }
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch (choice) {
            case 1:
                bai1_DemNguyenAmPhuAm();
                break;
            case 2:
                bai2_DangNhap();
                break;
            case 3:
                bai3_SapXepChuoi();
                break;
            case 4:
                bai4_ThapPhanSangHex();
                break;
            case 5:
                printf("Thoát chương trình. Hẹn gặp lại!\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ! Vui lòng chọn từ 1 đến 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// ==================== BÀI 1 ====================
void bai1_DemNguyenAmPhuAm(void) {
    char s[256];
    int nguyen_am = 0, phu_am = 0;

    printf("Nhập vào một chuỗi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                nguyen_am++;
            } else {
                phu_am++;
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n", s, nguyen_am, phu_am);
}

// ==================== BÀI 2 ====================
void bai2_DangNhap(void) {
    char username[50];
    char password[50];
    
    char correct_user[] = "admin";
    char correct_pass[] = "12345";

    printf("Nhap username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Nhap password: ");
    if (!getPassword(password, sizeof(password))) {
        printf("Khong doc duoc mat khau. Hay chay chuong trinh trong Terminal.\n");
        return;
    }

    if (strcmp(username, correct_user) == 0 && strcmp(password, correct_pass) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

// ==================== BÀI 3 ====================
void bai3_SapXepChuoi(void) {
    char s[5][20];
    char temp[20];

    printf("Nhập 5 chuỗi bất kỳ:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0';
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

// ==================== BÀI 4 ====================
void bai4_ThapPhanSangHex(void) {
    int n;
    printf("Nhập vào một số nguyên không âm ở hệ thập phân: ");
    if (scanf("%d", &n) != 1) {
        printf("So nhap vao khong hop le!\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    if (n == 0) {
        printf("So thap luc phan cua 0 la: 0\n");
        return;
    }
    char hex[100];
    char ref[] = "0123456789ABCDEF";
    int index = 0;
    int temp_n = n;
    while (temp_n > 0) {
        int remainder = temp_n % 16;
        hex[index++] = ref[remainder];
        temp_n /= 16;
    }
    hex[index] = '\0';
    int len = strlen(hex);
    for (int i = 0; i < len / 2; i++) {
        char t = hex[i];
        hex[i] = hex[len - 1 - i];
        hex[len - 1 - i] = t;
    }
    printf("So thap luc phan cua %d la: %s\n", n, hex);
}