#include <stdio.h>
int tim_so_lon_nhat(int mang[], int kich_co) {
    if (kich_co <= 0) {
        printf("Loi: Mang khong hop le hoac rong.\n");
        return -1; 
    }
    int so_lon_nhat = mang[0];
    int i;
    for (i = 1; i < kich_co; i++) {
        if (mang[i] > so_lon_nhat) {
            so_lon_nhat = mang[i];
        }
    }
    
    return so_lon_nhat;
}
int main() {
    int mang_so_nguyen[] = {12, 5, 45, 9, 21, 30};
    int kich_co = sizeof(mang_so_nguyen) / sizeof(mang_so_nguyen[0]);
    int ket_qua;
    ket_qua = tim_so_lon_nhat(mang_so_nguyen, kich_co);
    if (ket_qua != -1) {
        printf("Phan tu lon nhat trong mang la: %d\n", ket_qua);
    }
    
    return 0;
}
