//
//  Queens8.c
//  RPN
//
//  Created by Benji_Zhu on 12/26/15.
//  Copyright © 2015 Poodar. All rights reserved.
//

#include <stdio.h>

int count = 0;

int notDanger(int row, int column, int (*chess)[8]) {
    int i, k, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    for (i = 0; i < 8; i++) {
        if ( *(*(chess+i)+column) != 0 ) {
            flag1 = 1;
            break;
        }
    }
    //判断左上方，左下方，右上方，右下方
    for (i = row, k = column; i >= 0 && k >=0; i--, k--) {
        if ( *(*(chess+i)+k) != 0) {
            flag2 = 1;
            break;
        }
    }
    for (i = row, k = column; i < 8 && k< 8; i++, k++) {
        if ( *(*(chess+i)+k) != 0) {
            flag3 = 1;
            break;
        }
    }for (i = row, k = column; i < 8 && k >= 0; i++, k--) {
        if (*(*(chess+i)+k) != 0) {
            flag4 = 1;
            break;
        }
    }for (i = row, k = column; i >= 0 && k < 8; i--, k++) {
        if ( *(*(chess+i)+k) != 0) {
            flag5 = 1;
            break;
        }
    }
    if (flag1 || flag2 || flag3 || flag4 || flag5) {
        return 0;
    }
    else
        return 1;
}

//参数row表示起始行，参数n表示列数
void EightQueens(int row, int n, int (*chess)[8]) {
    int chess2[8][8], i, j;
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            chess2[i][j] = chess[i][j];
        }
    }
    
    if (row == 8) {
        printf("第 %d 种 \n", count + 1);
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%d ", *(*(chess2+i)+j));
            }
            printf("\n");
        }
        printf("\n\n");
        count++;
    }
    else {
         //判断这个位置是否有危险，如果没有危险，继续往下。
        for (j = 0; j < n; j++) {
            if (notDanger(row, j, chess)) {  //判断是否危险
                for (i = 0; i < 8; i++) {
                    *(*(chess2+row)+i) = 0;
                }
                *(*(chess2+row)+j) = 1;
                //递归
                EightQueens(row+1, i, chess2);
            }
        }
    }
}

int main() {
    int chess[8][8], i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            chess[i][j] = 0;
        }
    }
    
    EightQueens(0, 8, chess);
    printf("\n总共有%d中算法\n", count);
    
    return 0;
}