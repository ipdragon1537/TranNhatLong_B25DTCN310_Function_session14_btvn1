#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int arr[MAX];    
int n = 0;
void nhap_mang() {
    printf("Nhap so phan tu (1 - %d): ", MAX);
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("So phan tu khong hop le!\n");
        n = 0;
        return;
    }
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Nhap thanh cong!\n");
}
void in_mang() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    printf("Cac phan tu trong mang (%d phan tu):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%6d", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    if (n % 10 != 0) printf("\n");
}
void them_phan_tu() {
    if (n >= MAX) {
        printf("Mang da day! Khong the them.\n");
        return;
    }
    int pos, value;
    printf("Nhap vi tri can them (0 - %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    printf("Them thanh cong!\n");
}
void sua_phan_tu() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    int pos, value;
    printf("Nhap vi tri can sua (0 - %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    printf("Nhap gia tri moi: ");
    scanf("%d", &value);
    arr[pos] = value;
    printf("Sua thanh cong!\n");
}
void xoa_phan_tu() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    int pos;
    printf("Nhap vi tri can xoa (0 - %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Xoa thanh cong!\n");
}
void sap_xep_giam_dan() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Da sap xep giam dan!\n");
}

void sap_xep_tang_dan() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Da sap xep tang dan!\n");
}

void menu_sap_xep() {
    int chon;
    do {
        printf("\n--- SAP XEP ---\n");
        printf("a. Giam dan\n");
        printf("b. Tang dan\n");
        printf("c. Quay lai\n");
        printf("Chon: ");
        char c = getchar();
        while (getchar() != '\n');
        chon = c;

        switch (chon) {
            case 'a': sap_xep_giam_dan(); in_mang(); break;
            case 'b': sap_xep_tang_dan(); in_mang(); break;
            case 'c': break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 'c');
}
void tim_kiem_tuyen_tinh() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int found = 0;
    printf("Ket qua tim kiem tuyen tinh: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d (tai vi tri %d) ", x, i);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay!\n");
    else printf("\n");
}
void tim_kiem_nhi_phan() {
    if (n == 0) {
        printf("Mang rong!\n");
        return;
    }
    int temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i]; temp[i] = temp[j]; temp[j] = t;
            }
        }
    }

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (temp[mid] == x) {
            printf("Tim thay %d tai vi tri %d trong mang da sap xep.\n", x, mid);
            found = 1;
            break;
        } else if (temp[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) printf("Khong tim thay %d!\n", x);
}
void menu_tim_kiem() {
    int chon;
    do {
        printf("\n--- TIM KIEM ---\n");
        printf("a. Tim kiem tuyen tinh\n");
        printf("b. Tim kiem nhi phan (mang da sap xep)\n");
        printf("c. Quay lai\n");
        printf("Chon: ");
        char c = getchar();
        while (getchar() != '\n');
        chon = c;
        switch (chon) {
            case 'a': tim_kiem_tuyen_tinh(); break;
            case 'b': tim_kiem_nhi_phan(); break;
            case 'c': break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 'c');
}
void hien_menu() {
    printf("\n");
    printf("============================ MENU ============================\n");
    printf("1. Nhap so phan tu va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n");
    printf("7. Tim kiem phan tu nhap vao\n");
    printf("8. Thoat\n");
    printf("=============================================================\n");
    printf("Lua chon cua ban: ");
}
int main() {
    int lua_chon;
    do {
        hien_menu();
        scanf("%d", &lua_chon);
        while (getchar() != '\n');
        switch (lua_chon) {
            case 1: nhap_mang(); break;
            case 2: in_mang(); break;
            case 3: them_phan_tu(); break;
            case 4: sua_phan_tu(); break;
            case 5: xoa_phan_tu(); break;
            case 6: menu_sap_xep(); break;
            case 7: menu_tim_kiem(); break;
            case 8: printf("Tam biet!\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (lua_chon != 8);
    return 0;
}
