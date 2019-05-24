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

STU *reverse(STU *head)
{
    STU *pf, *pb, *r;
    pf = head;

    if (!head || !head->next)
        return head;

    pb = pf->next;

    while (pb != NULL) {
        r = pb->next;
        pb->next = pf;
        pf = pb;
        pb = r;
    }
    head->next = NULL;
    head = pf;
    return head;
}

int main()
{
    STU *head = NULL, *p_new = NULL;
    int num = 10, i;

    srand((unsigned) time(NULL));//采集当前时间做为随机数rand()的开始
    for (i = 0; i < num; i++) {
        p_new = (STU *) malloc(sizeof(STU));//申请一个新节点
        sprintf(p_new->name, "name_%02d", i);
        p_new->num = i;
        p_new->score = rand() % 100;
        p_new->next = NULL;
        link_creat_head(&head, p_new);    //将新节点加入链表
    }

    link_print(head);

    printf("\n\n\n\n\n");
    head = reverse(head);
    link_print(head);
}
