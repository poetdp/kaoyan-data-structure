#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 快速排序
 */
void quickSort(int R[], int l, int r) {
    int i, j, temp;
    if(l >= r) return;      /* 递归出口,只有一个记录或无记录 */
    i = l; j = r; temp = R[l];
    while(i < j) {      /* 寻找 R[l] 的最终位置 */
        while(j > i && R[j] >= temp) j--;   /* 从右向左寻找第一个小于 temp 的记录 */
        if(i < j) R[i++] = R[j];
        while(i < j && R[i] <= temp) i++;   /* 从左向右寻找第一个大于 temp 的记录 */
        if(i < j) R[j--] = R[i];
    }
    R[i] = temp;
    quickSort(R, l, i-1);
    quickSort(R, i+1, r);
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    quickSort(a, 0, n-1);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
