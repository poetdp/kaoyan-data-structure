#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 冒泡排序
 */
void bubbleSort(int R[], int n) {
    int i, j, noswap, temp;
    for(i = n-2; i >= 0; i--) {     /* i 控制调整范围 */
        noswap = 1;
        for(j = 0; j <= i; j++) {
            if(R[j] > R[j+1]) {
                temp = R[j]; R[j] = R[j+1]; R[j+1] = temp;
                noswap = 0;
            }
        }
        if(noswap == 1) break;   /* 未发生交换，记录已经有序，算法结束 */
    }
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    bubbleSort(a, n);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
