//
//  main.c
//  BiTree
//
//  Created by Benji_Zhu on 12/27/15.
//  Copyright © 2015 Poodar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode{
    char data;
    struct BiTNode *lChild, *rChild;
}BiTNode, *BiTree;

//创建一棵二叉树
//约定用户遵照前序遍历的方式输入数据,叶子节点是nil
void createBiTree(BiTree *T) {
    char c;
    scanf("%c", &c);
    
    if (c == ' ')
        *T = NULL;
    else {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)-> data = c;
        createBiTree(&(*T)->lChild);
        createBiTree(&(*T)->rChild);
    }
}

void visit(ElemType data, int level) {
    printf("%c位于%d层\n", data, level);
}
//遍历二叉树
void preOrderTraverse(BiTNode *T, int level) {
    if (T)
    {
        visit(T->data, level);
        preOrderTraverse(T->lChild, level+1);
        preOrderTraverse(T->rChild, level+1);
    }
}


int main() {
    int level = 1;
    BiTree T = NULL;
    printf("Please input: \n");
    createBiTree(&T);
    preOrderTraverse(T, level);
    
    return 0;
}
