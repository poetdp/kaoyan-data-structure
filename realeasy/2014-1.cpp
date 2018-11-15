#include <cstdio>

int a[] = {1, 2, 3};
int n = sizeof(a) / sizeof(int);

void outSet(int S[], int size) {
    int i;
    printf("{");
    for(i = 0; i <= size-1; i++) {
        printf("%d ", S[i]);
    }
    printf("}\n");
}

void powerSet(int S[], int size) {
    outSet(S, size);
    for(int i = size; i <= n-1; i++) {
        S[size] = a[i];
        powerSet(S, size + 1);
        printf("-----------------\n");
    }
}

int main() {
    int S[100];
    powerSet(S, 0);
    return 0;
}