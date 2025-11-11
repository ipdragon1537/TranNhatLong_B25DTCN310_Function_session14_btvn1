#include <stdio.h>
#include <stdbool.h>
bool kiem_tra_so_nguyen_to(int n) {
    if (n <= 1) {
        return false;
    }
    
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
}
    return true;
}

int main() {
    int so = 29;
    
    if (kiem_tra_so_nguyen_to(so)) {
        printf("%d la so nguyen to.\n", so);
    } else {
        printf("%d khong phai la so nguyen to.\n", so);
    }
    
    return 0;
}
