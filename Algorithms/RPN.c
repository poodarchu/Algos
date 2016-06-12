//
//  main.c
//  RPN
//
//  Created by Benji_Zhu on 12/26/15.
//  Copyright © 2015 Poodar. All rights reserved.
//

/*
#include <stdio.h>
#include <ctype.h>   //isdigit()
#include <stdlib.h>  //atof()

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct{
    ElemType* base;
    ElemType* top;
    int stackSize;
}sqStack;

void InitStack(sqStack* s) {
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
        exit(0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack* s, ElemType e){
    if(s->top - s->base >= s->stackSize){
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            exit(0);
        }
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }
    *(s->top) = e;   // 存放数据
    s->top++;
}

void Pop(sqStack *s, ElemType *e){
    if (s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);  //将栈顶元素弹出并修改栈顶指针
}

long stackLen(sqStack s) {
    return (s.top - s.base);
}

int main() {
    //从此处开始写代码
    sqStack s;
    char c;
    double d, e;
    char str[MAXBUFFER];   //定义一个缓冲区
    int i = 0;
    
    printf("%s\n", "请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以＃作为结束标志");
    scanf("%c", &c);
    
    InitStack(&s);
    
    while(c != '#')
    {
        while(isdigit(c) || c == '.') {   //用于过滤数字，剩下的就是操作符。
            str[i++] = c;
            str[i] = '\0';
            if (i >= 10)
            {
                printf("(%s)\n", "出错，输入的单个数据过大。");
                return -1;
            }
            scanf("%c", &c);
            if (c == ' ')
            {
                d = atof(str);
                Push(&s, d);
                i = 0;
                break;
            }
        }
        switch (c) {
            case '+':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d + e);
                break;
            case '-':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d - e);
                break;
            case '*':
                Pop(&s, &e);
                Pop(&s, &d);
                Push(&s, d * e);
                break;
            case '/':
                Pop(&s, &e);
                Pop(&s, &d);
                if (e != 0)
                    Push(&s, d / e);
                else
                    return -1;
                break;
                
        }
        scanf("%c", &c);
    }
    
    Pop(&s, &d);
    printf("\n最终的计算结果为： %f\n", d);
    
    return 0;
}
*/