#include <cstdio>

struct Node {
    int data;
    struct Node *pre;   /* 指向前驱结点的指针 */
    struct Node *next;  /* 指向后继节点的指针 */
};

/**
 * 为单向循环链表中的每个结点添加指向前驱的指针
 */
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
    do {    /* 从前向后遍历链表 */
        printf("%d->", p->data);
        p = p->next;
    }while(p != &a[0]);
    printf("\n");
    addPre(&a[0]);
    p = &a[7];
    do {    /* 从后向前遍历链表 */
        printf("%d->", p->data);
        p = p->pre;
    }while(p != &a[7]);
    return 0;
}
