
#include <stdio.h>
#include <stdlib.h>
#include "linklist2.h"
// �������
// ��ʵ��
// ��Ⱦ,��������
// x����
// y����
// 0��ʾ�ҵ��ڵ㣬-1��ʾû�ҵ���Ӧ�Ľڵ�
int linklist_find(struct Snack *head, int x, int y)
{
    struct Snack *p;

    p = head;
    while(p != NULL)
    {
        // �ҵ��ڵ�
        if (p->x ==x && p->y == y)
        {
            return 0;
        }

        p = p->next;
    }

    return -1;
}

// ͷ�巨
// x �½ڵ��x����
// y �½ڵ��y����
// head ͷ�ڵ�
//struct Snack **head;
//
//  ���� : ����
// head  : struct Snack **  ����ָ��
// *head : struct Snack *   һ��ָ��
// **head: struct Snack     ����
//
void linklist_insert(struct Snack **head, int x, int y)
{
    struct Snack *node = (struct Snack *)malloc(sizeof(struct Snack));
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) ��������
    node->next = *head;

    // 3) ͷ�ڵ�ָ��ָ���½ڵ�
    *head = node;
}

// �����½ڵ�󣬷����µ�ͷ�ڵ�
struct Snack *linklist_insert2(struct Snack *head, int x, int y)
{
    struct Snack *node = (struct Snack *)malloc(sizeof(struct Snack));
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) ��������
    node->next = head;

    // 3) �����µ�ͷ�ڵ�
    return node;
}

void linklist_delete(struct Snack *head)
{
    struct Snack *p;
    struct Snack *tmp;

    p = head;
    while(NULL != p && NULL != p->next) {
        if (NULL == p->next->next) {
            // �����ɾ���ڵ�
            tmp = p->next;
            // ������ɾ���ڵ�
            p->next = NULL;
            // �ͷŽڵ�
            free(tmp);
            break;
        }
        p = p->next;
    }
}

void linklist_print(struct Snack *head)
{
    struct Snack *p;
    p = head;
    while (NULL != p) {
        printf("%d,%d\n", p->x, p->y);
        p = p->next;
    }
}

