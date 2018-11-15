#include <cstdio>

struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
};

void visit(BTNode *p) {
    printf("%c ", p->data);
}

/**
 * 前序遍历
 */
void preorder(BTNode *p) {
    if(p == NULL) return;
    visit(p);
    preorder(p->lchild);
    preorder(p->rchild);
}

/**
 * 中序遍历
 */
void inorder(BTNode *p) {
    if(p == NULL) return;
    inorder(p->lchild);
    visit(p);
    inorder(p->rchild);
}

/**
 * 后序遍历
 */
void postorder(BTNode *p) {
    if(p == NULL) return;
    postorder(p->lchild);
    postorder(p->rchild);
    visit(p);
}

/**
 * 前序遍历-非递归
 */
void preorderNonrecursive(BTNode *bt) {
    if(bt == NULL) return;
    BTNode *stack[100]; int top = -1;   /* 定义并初始化栈 */
    BTNode *p;
    stack[++top] = bt;      /* 根结点入栈 */
    while(top != -1) {      /* 栈空循环退出，遍历结束 */
        p = stack[top--];   /* 出栈并输出栈顶结点 */
        visit(p);
        if(p->rchild != NULL) stack[++top] = p->rchild;     /* 右孩子 存在则进栈 */
        if(p->lchild != NULL) stack[++top] = p->lchild;
    }
}

/**
 * 中序遍历-非递归
 */
void inorderNonrecursive(BTNode *bt) {
    if(bt == NULL) return;
    BTNode *stack[100]; int top = -1;   /* 定义并初始化栈 */
    BTNode *p;
    p = bt;
    while(p != NULL || top != -1) {
        while(p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }
        if(top != -1) {
            p = stack[top--];
            visit(p);
            p = p->rchild;
        }
    }
}

/**
 * 后序遍历-非递归
 */
void postorderNonrecursive(BTNode *bt) {
    if(bt == NULL) return;
    BTNode *stack[100]; int top = -1;   /* 定义并初始化栈 */
    BTNode *p;
    p = bt;
    while(p != NULL || top != -1) {
        while(p != NULL) {
            stack[++top] = p;
            if(p->lchild != NULL) p = p->lchild;
            else p = p->rchild;
        }   /* 循环到当前要处理的结点 */
        if(top != -1) {
            p = stack[top--];
            visit(p);
            if(top != -1 && stack[top]->lchild == p) {  /* 栈不空，且为从左子树回来 */
                p = stack[top]->rchild;
            }
            else p = NULL;  /* 从右子树回来，退回上一层处理 */
        }
    }
}

/**
 * 广度优先
 */
void levelOrder(BTNode *bt) {

}

int main() {
    BTNode a[6];
    a[0].data = '1'; a[0].lchild = &a[1]; a[0].rchild = &a[2];
    a[1].data = '2'; a[1].lchild = &a[3]; a[1].rchild = &a[4];
    a[2].data = '3'; a[2].lchild = NULL; a[2].rchild = NULL;
    a[3].data = '4'; a[3].lchild = NULL; a[3].rchild = NULL;
    a[4].data = '5'; a[4].lchild = NULL; a[4].rchild = NULL;
    printf("[深度优先]");
    printf("\n前序: ");
    preorder(&a[0]);
    printf("\n中序: ");
    inorder(&a[0]);
    printf("\n后序: ");
    postorder(&a[0]);
    printf("\n前序非递归: ");
    preorderNonrecursive(&a[0]);
    printf("\n中序非递归: ");
    inorderNonrecursive(&a[0]);
    printf("\n后序非递归: ");
    postorderNonrecursive(&a[0]);
    printf("\n[广度优先]\n");
    levelOrder(&a[0]);
    return 0;
}
