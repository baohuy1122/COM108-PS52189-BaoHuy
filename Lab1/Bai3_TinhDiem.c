#include <stdio.h>
int main(){
    char mssv[] = "PS52189";
    char hoTen[] = "Nguyen Bao Huy";
    float diemToan = 8.5;
    float diemLy = 7.0;
    float diemHoa = 9.0;
    float diemTrungBinh = (float) (diemToan * 2 + diemLy + diemHoa) / 4;
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n" , hoTen);
    printf("Diem Trung Binh: %.2f\n", diemTrungBinh);
    return 0;
}