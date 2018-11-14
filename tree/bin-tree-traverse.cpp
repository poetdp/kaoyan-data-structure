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
    preorder(p->lchild);
    visit(p);
    preorder(p->rchild);
}

/**
 * 后序遍历
 */
void postorder(BTNode *p) {
    if(p == NULL) return;
    preorder(p->lchild);
    preorder(p->rchild);
    visit(p);
}

int main() {
    return 0;
}
