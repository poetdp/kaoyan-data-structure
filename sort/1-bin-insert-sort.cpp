#include <cstdio>

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 折半插入排序
 */
void binInsertSort(int R[], int n) {
    int i, j, left, mid, right, temp;
    for(i = 1; i <= n-1; i++) {
        temp = R[i];
        left = 0; right = i-1;
        while(left <= right) {
            mid = (left+right)/2;
            if(temp < R[mid]) right = mid-1;
            else left = mid+1;
        }
        for(j = i-1; j >= left; j--) {
            R[j+1] = R[j];
        }
        if(left != i) R[left] = temp;
    }
}

int main() {
    int a[] = {13, 27, 38, 49, 65, 76, 97, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    binInsertSort(a, n);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
