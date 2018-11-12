#include <cstdio>

void merge(int a[], int b[],int low, int mid, int high) {
    int i, j, k;    /* 将 a 的 low~mid、mid+1~high 归并到 b 的 low~high */
    i = low; j = mid+1; k = low;
    while(i <= mid && j <= high) {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid ) b[k++] = a[i++];
    while(j <= high) b[k++] = a[j++];
}

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 归并排序
 */
void mergeSort(int R[], int low, int high) {
    int mid, temp[high+1];
    if(low >= high) return;
    mid = (low + high) / 2;
    mergeSort(R, low, mid);
    mergeSort(R, mid+1, high);
    merge(R, temp, low, mid, high);     /* R 归并到 temp */
    merge(temp, R, low, mid, high);     /* temp 归并（复制）回 R */
}

int main() {
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    // int a[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    mergeSort(a, 0, n-1);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
