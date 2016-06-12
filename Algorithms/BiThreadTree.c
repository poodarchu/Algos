#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

//线索存储标志位
//Link(0):表示指向左右孩子的指针
//Thread(1):表示指向前驱后继的线索
typedef enum {Link, Thread} PtrTag;

typedef struct BiThreadNode {
    char data;
    struct BiThreadNode *lChild, *rChild;
    PtrTag ltag;
    PtrTag rtag;
}BiThreadNode, *BiThreadTree;

//创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
void createBiThreadTree(BiThreadTree *T) {
    char c;
    scanf("%c", &c);
    if (c == ' ') {
        *T = NULL;
    }
    else {
        *T = (BiThreadNode *)malloc(sizeof(BiThreadNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        createBiThreadTree(&(*T)->lChild);
        createBiThreadTree(&(*T)->rChild);
    }
}

//全局变量，始终指向刚刚访问过的node
BiThreadTree pre;

void inThreadize(BiThreadTree T) {
    if (T) {
        inThreadize(T->lChild);   //递归左孩子线索化
        //节点处理
        if (!T->lChild) {
            T->ltag = Thread;
            T->lChild = pre;
        }
        if (!pre->rChild) {
            pre->rtag = Thread;
            pre->rChild = T;
        }

        pre = T;

        inThreadize(T->rChild);   //递归右孩子线索化
    }
}

void inOrderThreadize(BiThreadTree *p, BiThreadTree T) {
    *p = (BiThreadTree)malloc(sizeof(BiThreadNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rChild = *p;
    if (!T) {
        (*p)->lChild = *p;
    }
    else {
        (*p)->lChild = T;
        pre = *p;

        inThreadize(T);
        pre->rChild = *p;
        pre->rtag = Thread;
        (*p)->rChild = pre;
    }
}

void visit(ElemType c) {
    printf("%c, ",c);
}

void inOrderTravesal(BiThreadTree T) {
    BiThreadTree P;
    P = T->lChild;

    while (P != T) {
        while (P->ltag == Link) {
            P = P->lChild;
        }

        visit(P->data);

        while (P->rtag == Thread && P->rChild != T) {
            P = P->rChild;
            visit(P->data);
        }

        P = P->rChild;
    }
}

int main() {
    BiThreadTree P, T = NULL;
    createBiThreadTree(&T);

    inOrderThreadize(&P, T);

    printf("中序遍历输出结果为： \n");

    inOrderTravesal(P);  //P是头指针，T是头结点。

    return 0;
}
