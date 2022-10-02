#include"STACKMADER.h"

int main() {
	int n, code;
	
	ll list;
	list.head = NULL;
	list.len = 0;
	
	do {
		printf("(push : 1, pop : 2, get_size : 3, peek : 4, end : 0) = _\b");
		scanf("%d", &code);
		switch (code) {
		case 1:
			printf("값 : ");
			scanf("%d", &n);
			push(&list, n);
			show(list);
			break;
		case 2:
			pop(&list);
			show(list);
			break;
		case 3:
			printf("스택 길이 : %d\n", get_size(&list));
			break;
		case 4:
			printf("꼭대기 값 : %d\n", peek(&list));
			break;
		}
	} while (code);

	return 0;
}