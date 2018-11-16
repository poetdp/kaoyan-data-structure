#include <cstdio>

struct LinkNode {
    int data;
    int freq;   /* data 的访问计数 */
    struct LinkNode *link;  /* 指向后继结点的指针 */
};

void search(LinkNode *L, int x) {
    LinkNode *p, *q, *r;
    p = L; q = NULL;
    /* 查找 data == x 的结点 */
    while(p->link != NULL) {
        if(p->link->data == x) {
            q = p;
            break;
        }
        p = p->link;
    }
    if(q == NULL) return;   /* 没找到则直接退出 */
    /* r 指向找到的结点，并将 r 结点脱链 */
    r = q->link;
    r->freq++;
    q->link = r->link;
    /* 从前向后查找 r 的插入位置 */
    p = L->link;
    while(p != NULL) {
        if(p->freq >= r->freq) q = p;
        p = p->link;
    }
    /* 在 q 的后面插入 r */
    r->link = q->link;
    q->link = r;
}

int main() {
    LinkNode a[6] = {{}, {11, 7}, {12, 6}, {13, 4}, {14, 4}, {15, 2}};
    for(int i = 0; i <= 4; i++) {
        a[i].link = &a[i+1];
    }
    a[5].link = NULL;
    LinkNode *p;
    p = &a[0]; p = p->link;
    while(p != NULL) {
        printf("(%d, %d)->", p->data, p->freq);
        p = p->link;
    }
    printf("\n");
    search(&a[0], 14);
    p = &a[0]; p = p->link;
    while(p != NULL) {
        printf("(%d, %d)->", p->data, p->freq);
        p = p->link;
    }
    return 0;
}
