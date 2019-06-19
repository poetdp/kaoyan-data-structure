#include <cstdio>

struct Node {
    int data;
    struct Node *next;
};

/**
 * 将一个无头结点的链表逆置
 */
void reverse(Node **pL) {
    Node *p = *pL, *q = *pL, *r;
    while(p->next != NULL) {    /* 使 p 指向 L 的最后一个元素 */
        p = p->next;
    }
    while(q != p) {
        r = q;
        q = q->next;
        /* 将 r 插入到 p 的后面 */
        r->next = p->next;
        p->next = r;
    }
    *pL = p;    /* 原链表的最后一个结点作为新的头结点 */ 
}

int main() {
    Node a[8];
    for(int i = 0; i <= 6; i++) {
        a[i].data = i;
        a[i].next = &a[i+1];
    }
    a[7].data = 7;
    a[7].next = NULL;
    Node *L = &a[0];

    /* 从前向后遍历链表 */
    Node *p;
    p = L;
    while(p != NULL) {    
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");

    reverse(&L);
    
    /* 从前向后遍历链表 */
    p = L;
    while(p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
