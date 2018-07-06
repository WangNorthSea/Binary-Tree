//
//  main.c
//  TreeTest
//
//  Created by 王浩宇 on 2018/7/6.
//  Copyright © 2018 UCAS Developers. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct treeNode {
    double value;
    struct treeNode * p1;
    struct treeNode * p2;
};

struct treeNode * createTreeByRecursion(int level) {
    struct treeNode * motherNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    motherNode -> p1 = NULL;
    motherNode -> p2 = NULL;
    if (level <= 1) {
        return motherNode;
    }
    struct treeNode * Node1 = (struct treeNode *)malloc(sizeof(struct treeNode));
    struct treeNode * Node2 = (struct treeNode *)malloc(sizeof(struct treeNode));
    
    motherNode -> p1 = Node1;
    motherNode -> p2 = Node2;
    Node1 -> p1 = NULL;
    Node1 -> p2 = NULL;
    Node2 -> p1 = NULL;
    Node2 -> p2 = NULL;
    
    if (level == 2) {
        return motherNode;
    }
    
    Node1 -> p1 = createTreeByRecursion(level - 2);
    Node1 -> p2 = createTreeByRecursion(level - 2);
    Node2 -> p1 = createTreeByRecursion(level - 2);
    Node2 -> p2 = createTreeByRecursion(level - 2);
    
    return motherNode;
}

void treeInput(struct treeNode * treeHead) {
    
    double number;
    
    printf("请输入值：");
    scanf("%lf", &number);
    treeHead -> value = number;
    
    if (treeHead -> p1 == NULL) {
        return;
    }
    
    treeInput(treeHead -> p1);
    treeInput(treeHead -> p2);
}

void treeOutput(struct treeNode * treeHead) {
    printf("%g", treeHead -> value);
    
    if (treeHead -> p1 == NULL) {
        printf("\n");
        return;
    }
    
    treeOutput(treeHead -> p1);
    treeOutput(treeHead -> p2);
}

int main() {
    
    int level;
    printf("请输入树的层数：");
    scanf("%d", &level);
    struct treeNode * treeHead = createTreeByRecursion(level);
    treeInput(treeHead);
    treeOutput(treeHead);
    return 0;
}
