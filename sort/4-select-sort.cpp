#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 直接选择排序
 */
void selectSort(int R[], int n) {
    int i, j, k, temp;
    for(i = 0; i <= n-2; i++) {
        k = i;      /* k 始终指向当前选取的最小元素 */
        for(j = i+1; j <= n-1; j++) {
            if(R[k] > R[j]) k = j;
        }
        if(k != i) {
            temp = R[i]; R[i] = R[k]; R[k] = temp;
        }
    }
}

int main() {
    int a[] = {49, 38, 65, 97, 49, 13, 27, 76};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    selectSort(a, n);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
