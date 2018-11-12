#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 Shell 排序
 */
void shellSort(int R[], int n, int increment) {
    int i, j, inc, temp;
    for(inc = increment; inc > 0; inc /= 2) {   /* inc 为本趟排序增量 */
        for(i = inc; i <= n-1; i++) {
            temp = R[i];    /* 保存待插入记录 R[i] */
            j = i - inc;
            while(j >= 0 && temp < R[j]) {
                R[j + inc] = R[j];  /* 比 R[i] 大的记录后移 */
                j -= inc;
            }
            R[j + inc] = temp;  /* 插入 R[i] */
        }
    }
}

int main() {
    int a[] = {49, 38, 65, 97, 13, 76, 27, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    shellSort(a, n, 4);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
