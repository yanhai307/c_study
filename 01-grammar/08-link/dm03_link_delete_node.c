//
// Created by YANHAI on 2019/5/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        //找到原有链表的最后一个节点
        while (p_mov->next != NULL) {
            p_mov = p_mov->next;
        }
        p_mov->next = p_new;        //将新申请的节点加入链表
        p_new->next = NULL;
    }
}

void link_print(STU *head)
{
    STU *p_mov;
    p_mov = head;
    printf("当前链表中所有节点为:\n-----------------------\n");
    while (p_mov != NULL) {
        printf("num=%d score=%d name:%s\n", p_mov->num, p_mov->score, p_mov->name);
        p_mov = p_mov->next;
    }
    printf("-------------------------\n");
}

void link_free(STU **p_head)
{
    STU *pb;
    while (*p_head != NULL) {
        pb = *p_head;
        *p_head = (*p_head)->next;
        free(pb);
    }
}

STU *link_search_num(STU *head, int num)
{
    STU *p_mov;
    p_mov = head;
    while (p_mov != NULL) {
        //找到了
        if (p_mov->num == num) {
            return p_mov;
        }
        p_mov = p_mov->next;
    }
    return NULL;//没有找到
}

void link_delete_num(STU **p_head, int num)
{
    STU *pb, *pf;
    pb = pf = *p_head;

    //链表为空，不用删
    if (*p_head == NULL) {
        printf("链表为空，没有您要删的节点");\
        return;
    }

    //循环找，要删除的节点
    while (pb->num != num && pb->next != NULL) {
        pf = pb;
        pb = pb->next;
    }

    //找到了一个节点的num和num相同
    if (pb->num == num) {
        //要删除的节点是头节点
        if (pb == *p_head) {
            *p_head = pb->next;
        } else {
            pf->next = pb->next;
        }
        free(pb);
    } else {
        printf("没有您要删除的节点\n");
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
        p_new->num = i;
        p_new->score = rand() % 100;
        p_new->next = NULL;
        link_creat_head(&head, p_new);    //将新节点加入链表
    }

    link_print(head);

    while (1) {
        printf("请输入您要删除的节点的num\n");
        scanf("%d", &num);

        if (num < 0)
            break;

        link_delete_num(&head, num);
        link_print(head);
    }

    link_free(&head);
    return 0;
}
