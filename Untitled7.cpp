#include <stdio.h>
int ucln(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int so1 = 48;
    int so2 = 18;
    int ketqua = ucln(so1, so2);
    printf("Hai so: %d va %d\n", so1, so2);
    printf("Uoc chung lon nhat (UCLN) = %d\n", ketqua);
    
    return 0;
}
