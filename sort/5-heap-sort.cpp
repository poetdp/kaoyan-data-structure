#include <cstdio>

void shift(int R[], int size, int p) {
    int temp = R[p];
    int child = 2*p + 1;    /* R[child] 是 R[p] 的左孩子 */
    while(child <= size-1) {
        if(child < size-1 && R[child] < R[child+1]) {  /* 如果有右孩子，选择比较大的子结点 */
            child++;
        }
        if(temp < R[child]) {
            R[p] = R[child];    /* 将大的子结点与父结点交换（上移） */
            p = child;
            child = 2*p + 1;    /* 跳到子结点上继续调整 */
        }
        else break;     /* 调整结束 */
    }
    R[p] = temp;
}

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1]
 * 按 递增次序
 * 进行 堆排序
 */
void heapSort(int R[], int n) {
    int i, temp;
    for(i = n/2 - 1; i >= 0; i--) {     /* i 从最后一个结点的父节点开始调整，构造第一个堆 */
        shift(R, n, i);
    }
    for(i = n-1; i >= 1; i--) {      /* 把最小元素与最后一个元素进行交换 */
        temp = R[0]; R[0] = R[i]; R[i] = temp;
        shift(R, i, 0);     /* 在 i 个记录中重新建堆 */
    }
}

int main() {
    int a[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    heapSort(a, n);
    for(i = 0; i <= n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
