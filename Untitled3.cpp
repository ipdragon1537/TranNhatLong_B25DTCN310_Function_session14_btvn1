#include <stdio.h>
long long tinh_giai_thua(int n) {
    if (n < 0) {
        printf("Loi: Giai thua khong duoc tinh cho so am.\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long ket_qua = 1;
    for (int i = 2; i <= n; i++) {
        ket_qua *= i;
    }
    
    return ket_qua;
}

int main() {
    int so = 5;
    long long giai_thua;
    giai_thua = tinh_giai_thua(so);
    if (giai_thua != -1) {
        printf("Giai thua cua %d la: %lld\n", so, giai_thua);
    }
    return 0;
}
