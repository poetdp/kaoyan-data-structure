#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 直接插入排序
 */
void insertSort(int R[], int n) {
    int i, j, temp;
    for(i = 1; i <= n-1; i++) { /* 依次插入 R[1],...,R[n] */
        temp = R[i];
        j = i-1;
        while(j >= 0 && temp < R[j]) {  /* 由后向前 查找插入位置 */
            R[j+1] = R[j];  /* 已排序序列中大于 temp 的记录向后移 */
            j--;
        }
        if(j != i-1) R[j+1] = temp;
    }
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    insertSort(a, n);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
