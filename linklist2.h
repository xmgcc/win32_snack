#ifndef LINKLIST2_H
#define LINKLIST2_H
//
// �������
//

struct Snack {
    // x����
    int x;

    // y����
    int y;

    // ������ڵ�
    struct Snack *next;
};



// ���ҽڵ�
int linklist_find(struct Snack *head, int x, int y);

// ͷ�巨����ڵ�
void linklist_insert(struct Snack **head, int x, int y);

// ͷ�巨����ڵ�
struct Snack *linklist_insert2(struct Snack *head, int x, int y);

// ɾ�����һ���ڵ�
void linklist_delete(struct Snack *head);

// ��ӡ���нڵ�
void linklist_print(struct Snack *head);
#endif // LINKLIST2_H
