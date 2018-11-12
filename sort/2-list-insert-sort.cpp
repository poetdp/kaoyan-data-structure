#include <cstdio>
#include <malloc.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode, *LinkList;

/**
 * 对 n 个记录 R[0],R[1],...,R[n-1] 的链表
 * 按 递增次序
 * 进行 表插入排序
 */
void listInsertSort(LinkList *plist) {
    ListNode *now, *pre, *p, *q, *head;
    head = *plist;
    pre = head->next;   if(pre == NULL) return;
    now = pre->next;    if(now == NULL) return;
    while(now != NULL) {
        q = head;   p = head->next;
        while(p != now && p->data < now->data) {
            q = p;  p = p->next;
        }/* 循环结束找到插入位置 */
        if(p == now) {
            pre = pre->next;
            now = pre->next;
            continue;
        }
        else {
            pre->next = now->next;          /* 使 now 记录脱链 */
            now->next = p; q->next = now;   /* 将 now 记录插入到 p 位置 */
            now = pre->next;                /* 使 now 指向下一个待插入元素 */
        }
    }

}

int main() {
    LinkList L = (ListNode *)malloc(sizeof(ListNode));
    L->next = NULL;
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int n = sizeof(a)/sizeof(int), i;
    for(i = 0; i <= n-1; i++) {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
    ListNode *p = L->next;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    listInsertSort(&L);

    p = L->next;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
