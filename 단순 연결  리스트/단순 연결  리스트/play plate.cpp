#include <stdio.h>
#include <stdlib.h>
#include "NODE_MAKER.h" // ������� NODE_MAKER.h���� �����´�(����ü node, ll�� ������ ���ڴ�.)

void add(ll* list, int pos, int value) {    // ll*list : ����ü ������ ���� pos : ������ ��ġ value : ������ ��
    int len = list->len;                    // ����ü �����ʹ� . (��� ������, ���������� �� ����) ��� ->�� ��
    if (pos > len) return;                  // ��尹�� > �ְ��� �ϴ� ����(n��°)�� �����ؾ� ��

    node *new_node = (node*)malloc(sizeof(node));   // ����ü ������ ����new_node�� heap�� �޸� ���� �Ҵ�
    new_node->value = value;                        // new_node�� value�� �Է��� value���� ����

    if (len == 0) {                                                 // ���� ���� ���� ��尡 ��ó��(head�ٷ� ��)�� ��
        new_node->next = list->head;                                // new_node�� �����ּҴ� head�� ���� �ּҸ� ����Ű�� ����� �ּ�
        list->head = new_node;                                      // head�� new_node
        list->len = len + 1;                                        // ����Ʈ�� ���̴� 1��ŭ �� �þ��.
        printf("added %d at first (len = %d)\n", value, len + 1);   // value�� ���� ù° ���� �ִ´ٰ� ���
    }
    if (len > 0) {                                          // ���� ���� ���� ��尡 �� ó���� �ƴ� ��
        node* tmp = list->head;                             // ����ü ���� tmp�� head�� ����
        for (int i = 0; i < pos - 1; i++) tmp = tmp->next;  // n �� °(n = pos��) ����� �ּҷ� �̵�(head - > n1(head->next) - >. . . - > n��° ��� )
        new_node->next = tmp->next;                         // new_node�� �����ּ� - > n + 1�� �ּ�
        tmp->next = new_node;                               // n + 1�� �ּ� - > new_node
    }
}

int main() {
    ll list;            // ����ü ���� list ����(list�� ����� ����, head�� ����)
    list.head = NULL;   // head�� null����Ʈ�̴�.�׸��� head�� ù ��° ��带 ����Ű�� �����̴�.
    list.len = 0;       // ��� ���� 0���� �ʱ�ȭ

    add(&list, 0, 3);
    add(&list, 0, 2);
    add(&list, 0, 1);
    add(&list, 2, 4);
                        // add�Լ��� ��尪 �Է�

    node* tmp = list.head;                  // tmp = head
    for (int i = 0; i < list.len; i++) {    // ��� ����(list.len)���� �ݺ�
        printf("%d\n", tmp->value);         // �ش� ����� value���� ���
        tmp = tmp->next;                    // ���� ���� �̵�
    }

    return 0;
}