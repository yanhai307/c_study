//
// Created by YANHAI on 2019/5/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
    //数据域
    int num;        //学号
    int score;      //分数
    char name[20];

    //指针域
    struct student *next;
} STU;

void link_creat_head(STU **p_head, STU *p_new)
{
    STU *p_mov = *p_head;

    //当第一次加入链表为空时，head执行p_new
    if (*p_head == NULL) {
        *p_head = p_new;
        p_new->next = NULL;
    }
        //第二次及以后加入链表
    else {
        while (p_mov->next != NULL) {
            p_mov = p_mov->next;    //找到原有链表的最后一个节点
        }
        p_mov->next = p_new;        //将新申请的节点加入链表
        p_new->next = NULL;
    }
}

void link_print(STU *head)
{
    STU *p_mov;
    p_mov = head;
    while (p_mov != NULL) {
        printf("num=%d score=%d name:%s\n", p_mov->num, p_mov->score, p_mov->name);
        p_mov = p_mov->next;
    }
}

void link_order(STU *head)
{
    STU *pb, *pf, temp;
    pf = head;
    if (head == NULL) {
        printf("链表为空,不用排序\n");
        return;
    }
    if (head->next == NULL) {
        printf("只有一个节点，不用排序\n");
        return;
    }

    //以pf指向的节点为基准节点，
    while (pf->next != NULL) {
        pb = pf->next;  //pb从基准元素的下个元素开始
        while (pb != NULL) {
            if (pf->num > pb->num) {
                temp = *pb;
                *pb = *pf;
                *pf = temp;

                temp.next = pb->next;
                pb->next = pf->next;
                pf->next = temp.next;
            }
            pb = pb->next;
        }
        pf = pf->next;
    }
}

int main()
{
    STU *head = NULL, *p_new = NULL;
    int num = 10, i;

    srand((unsigned) time(NULL));//采集当前时间做为随机数rand()的开始
    for (i = 0; i < num; i++) {
        p_new = (STU *) malloc(sizeof(STU));//申请一个新节点
        sprintf(p_new->name, "name_%02d", i);
        p_new->num = rand() % 10;
        p_new->score = rand() % 100;
        p_new->next = NULL;
        link_creat_head(&head, p_new);    //将新节点加入链表
    }

    link_print(head);

    printf("\n\n\n\n\n");
    link_order(head);
    link_print(head);
}
