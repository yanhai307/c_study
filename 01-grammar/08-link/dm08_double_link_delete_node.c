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
    struct student *front;
    struct student *next;
} STU;

void double_link_creat_head(STU **p_head, STU *p_new)
{
    STU *p_mov = *p_head;
    //当第一次加入链表为空时，head执行p_new
    if (*p_head == NULL) {
        *p_head = p_new;
        p_new->front = NULL;
        p_new->next = NULL;
    }
        //第二次及以后加入链表
    else {
        while (p_mov->next != NULL) {
            p_mov = p_mov->next;    //找到原有链表的最后一个节点
        }
        p_mov->next = p_new;        //将新申请的节点加入链表
        p_new->front = p_mov;
        p_new->next = NULL;
    }
}

void double_link_print(STU *head)
{
    STU *pb;

    if (head == NULL) {
        printf("链表为空\n");
        return;
    }

    pb = head;
    while (pb->next != NULL) {
        printf("num=%d score=%d name:%s\n", pb->num, pb->score, pb->name);
        pb = pb->next;
    }
    printf("num=%d score=%d name:%s\n", pb->num, pb->score, pb->name);

    printf("\n\n\n\n");
    while (pb != NULL) {
        printf("num=%d score=%d name:%s\n", pb->num, pb->score, pb->name);
        pb = pb->front;
    }
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

void double_link_delete_num(STU **p_head, int num)
{
    STU *pb, *pf;
    pb = *p_head;

    //链表为空，不需要删除
    if (*p_head == NULL) {
        printf("链表为空，没有您要删除的节点\n");
        return;
    }
    while ((pb->num != num) && (pb->next != NULL)) {
        pb = pb->next;
    }
    //找到了一个节点的num和num相同，删除pb指向的节点
    if (pb->num == num) {
        //找到的节点是头节点
        if (pb == *p_head) {
            //只有一个节点的情况
            if ((*p_head)->next == NULL) {
                *p_head = pb->next;
            }
                //有多个节点的情况
            else {
                *p_head = pb->next;//main函数中的head指向下个节点
                (*p_head)->front = NULL;
            }
        }
            //要删的节点是其他节点
        else {
            //删除中间节点
            if (pb->next != NULL) {
                pf = pb->front;//让pf指向找到的节点的前一个节点
                pf->next = pb->next;
                (pb->next)->front = pf;
            }
                //删除尾节点
            else {
                pf = pb->front;
                pf->next = NULL;
            }
        }
        free(pb);//释放找到的节点
    }
        //没找到
    else {
        printf("没有您要删除的节点\n");
    }
}

int main()
{
    STU *head = NULL, *p_new = NULL;
    int num = 5, i;

    srand((unsigned) time(NULL));//采集当前时间做为随机数rand()的开始
    for (i = 0; i < num; i++) {
        p_new = (STU *) malloc(sizeof(STU));//申请一个新节点
        sprintf(p_new->name, "name_%02d", i);
        p_new->num = i;
        p_new->score = rand() % 100;
        p_new->front = NULL;
        p_new->next = NULL;
        double_link_creat_head(&head, p_new);    //将新节点加入链表
    }

    double_link_print(head);

    while (1) {
        printf("请输入您要删除的节点的num\n");
        scanf("%d", &num);

        if (num < 0)
            break;

        double_link_delete_num(&head, num);
        double_link_print(head);
    }

    link_free(&head);
    return 0;
}
