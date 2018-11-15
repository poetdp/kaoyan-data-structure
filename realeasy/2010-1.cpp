#include <cstdio>

struct Node {
    int data;
    struct Node *pre;
    struct Node *next;
};

void addPre(Node *L) {
    Node *p = L;
    do {
        p->next->pre = p;
        p = p->next;
    }while(p != L);
}

int main() {
    Node a[8];
    for(int i = 0; i <= 7; i++) {
        a[i].data = i;
        a[i].next = &a[(i+1)%8];
    }
    Node *p;
    p = &a[0];
    do {
        printf("%d->", p->data);
        p = p->next;
    }while(p != &a[0]);
    printf("\n");
    addPre(&a[0]);
    p = &a[7];
    do {
        printf("%d->", p->data);
        p = p->pre;
    }while(p != &a[7]);
    return 0;
}
