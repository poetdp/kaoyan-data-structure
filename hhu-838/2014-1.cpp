#include <cstdio>

int a[] = {1, 2, 3, 4, 5};
int n = sizeof(a) / sizeof(int);

void powerSet(int S[], int size, int cur) {
    /* 输出当前 S[] */
    printf("{");
    for(int i = 0; i <= size-1; i++) {
        printf("%d ", S[i]);
    }
    printf("}\n");
    /*  */
    for(int i = cur+1; i <= n-1; i++) {
        S[size] = a[i];
        powerSet(S, size + 1, i);
    }
}

int main() {
    int S[100];
    powerSet(S, 0, -1);
    return 0;
}
