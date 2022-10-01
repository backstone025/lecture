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
		printf("첫 번째 노드에 %d을 저장 / 길이는 %d\n", value, len + 1);
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

			printf("%d번째 노드와 %d번째 노드사이에 %d를 첨가 / 길이 : %d\n", pos, pos + 1, new_node->value, len + 1);
		}
		else if (pos == len) {
			node* tmp = list->tail;
			new_node->next = tmp->next;
			new_node->prev = tmp;
			tmp->next = new_node;
			list->tail = new_node;

			printf("맨 마지막 노드에 %d 추가", new_node->value);
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

		printf("%d번 노드 제거\n", pos + 1);

		(list->len)--;
	}

	else if (len > 0) {
		if (pos == 0) {
			node* tmp = list->head;
			tmp->next->prev = tmp->prev;
			list->head = tmp->next;

			printf("%d번 노드 제거\n", pos + 1);
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
			tmp2 = tmp2->next;		//이중으로 -> 쓰면, 오류가 발생 => tmp하나 대신 tmp1, tmp2 씀.
			
			tmp1->next = tmp2->next;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;

			tmp2->prev = tmp1->prev;

			free(tmp1);

			printf("%d번 노드 제거\n", pos + 1);

			(list->len)--;
		}
		else if (pos == len) {
			node* tmp = list->tail;
			tmp->prev->next = NULL;
			list->tail = tmp->prev;
			free(tmp);

			printf("%d번 노드 제거\n", pos + 1);

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
	printf("끝노드: %d\n", list.tail->value);

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