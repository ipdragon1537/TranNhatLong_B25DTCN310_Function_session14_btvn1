#include <stdio.h>
void in_mang(int mang[], int kich_co) {
    int i;
    printf("Cac phan tu trong mang la: ");
    for (i = 0; i < kich_co; i++) {
        printf("%d ", mang[i]);
    }
    printf("\n");
}

int main() {
    int mang_so_nguyen[] = {10, 20, 30, 40, 50};
    int kich_co_mang = sizeof(mang_so_nguyen) / sizeof(mang_so_nguyen[0]);
    in_mang(mang_so_nguyen, kich_co_mang);

    return 0;
}
