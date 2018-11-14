#include <cstdio>

/**
 * 在递增的记录 R[] 中
 * 进行 二分查找 查找 k
 */
int binSearch(int R[], int n, int k) {  /* 当子表 >= 1 时进行循环 */
    int low, mid, high;
    low = 0; high = n-1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(k == R[mid]) return mid;
        if(k <  R[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int main() {
    int a[] = {13, 27, 38, 49, 49, 65, 76, 97};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("%d\n", binSearch(a, n, 49));
    return 0;
}
