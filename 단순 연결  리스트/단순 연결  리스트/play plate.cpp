#include "NODE_MAKER.h"

int main() {
	node n1;
	node n2;
	node n3;

	n1.value = 1;
	n2.value = 2;
	n3.value = 3;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	printf("%x %x %x\n", n1.value, n2.next, n3);

	return 0;
}