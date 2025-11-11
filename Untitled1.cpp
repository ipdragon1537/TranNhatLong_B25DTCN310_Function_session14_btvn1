#include <stdio.h>
int tinh_tong(int a, int b) {
    int ket_qua = a + b; 
    return ket_qua;
}

int main() {
    int num1 = 10;
    int num2 = 25;
    int sum;
    sum = tinh_tong(num1, num2);
    printf("Tong cua %d va %d la: %d\n", num1, num2, sum);

    return 0;
}
