#include <stdio.h>
int kiem_tra_so_hoan_hao(int n) {
    if (n <= 1) return 0;
    
    int tong_uoc = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            tong_uoc += i;
        }
    }
    
    return (tong_uoc == n);
}
int main() {
    int so1, so2;
    printf("Nhap so nguyen thu nhat: ");
    scanf("%d", &so1);
    
    printf("Nhap so nguyen thu hai: ");
    scanf("%d", &so2);
    printf("\n--- Ket qua kiem tra ---\n");
    
    if (kiem_tra_so_hoan_hao(so1)) {
        printf("%d la so hoan hao.\n", so1);
    } else {
        printf("%d khong phai la so hoan hao.\n", so1);
    }
    
    if (kiem_tra_so_hoan_hao(so2)) {
        printf("%d la so hoan hao.\n", so2);
    } else {
        printf("%d khong phai la so hoan hao.\n", so2);
    }
    
    return 0;
}
