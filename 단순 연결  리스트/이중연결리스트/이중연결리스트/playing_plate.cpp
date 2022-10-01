#include"DLL_MAKER.h"

void add(ll*list, int pos, int value) {
	int len = list->len;
	if (pos > len) {
		printf("!\n");
		return;
	}
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;

	if (len == 0) {
		new_node->prev = NULL;
		new_node->next = NULL;
		list->head = new_node;
		list->tail = new_node;
		(list->len)++;
		printf("ù ��° ��忡 %d�� ���� / ���̴� %d\n", value, len + 1);
	}

	else if (len > 0) {
		if (pos < len) {
			node* tmp = list->head;
			for (int i = 0; i < pos; i++)
				tmp = tmp->next;
			new_node->next = tmp;
			new_node->prev = tmp->prev;
			if (tmp->prev != NULL)
				tmp->prev->next = new_node;
			else {
				tmp->prev = new_node;
				list->head = new_node;
			}

			(list->len)++;

			printf("%d��° ���� %d��° �����̿� %d�� ÷�� / ���� : %d\n", pos, pos + 1, new_node->value, len + 1);
		}
		else if (pos == len) {
			node* tmp = list->tail;
			new_node->next = tmp->next;
			new_node->prev = tmp;
			tmp->next = new_node;
			list->tail = new_node;

			printf("�� ������ ��忡 %d �߰�", new_node->value);
			(list->len)++;
		}
	}
}

void remove(ll* list, int pos) {
	int len = list->len;
	if (pos > len) {
		printf("!\n");
		return;
	}
	else if (len == 0) {
		node* tmp = list->head;
		free(tmp);

		printf("%d�� ��� ����\n", pos + 1);

		(list->len)--;
	}

	else if (len > 0) {
		if (pos == 0) {
			node* tmp = list->head;
			tmp->next->prev = tmp->prev;
			list->head = tmp->next;

			printf("%d�� ��� ����\n", pos + 1);
			(list->len)--;
			free(tmp);
		}
		else if (pos < len) {
			node* tmp1 = list->head;
			node* tmp2 = list->head;
			for (int i = 0; i < pos - 1; i++) {
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
			tmp2 = tmp2->next;		//�������� -> ����, ������ �߻� => tmp�ϳ� ��� tmp1, tmp2 ��.
			
			tmp1->next = tmp2->next;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;

			tmp2->prev = tmp1->prev;

			free(tmp1);

			printf("%d�� ��� ����\n", pos + 1);

			(list->len)--;
		}
		else if (pos == len) {
			node* tmp = list->tail;
			tmp->prev->next = NULL;
			list->tail = tmp->prev;
			free(tmp);

			printf("%d�� ��� ����\n", pos + 1);

			(list->len)--;
		}
	}
}

int main() {
	int num, data, order;

	ll list;
	list.head = NULL;
	list.len = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d %d", &order, &data);
		add(&list, order, data);
	}

	node* tmp = list.head;
	for (int i = 0; i < list.len; i++) {
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\b\b \n");
	printf("�����: %d\n", list.tail->value);

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &order);
		remove(&list, order);
	}

	tmp = list.head;
	for (int i = 0; i < list.len; i++) {
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\b\b \n");

	return 0;
}