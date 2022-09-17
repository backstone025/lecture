#include <stdio.h>
#include <stdlib.h>
#include "NODE_MAKER.h" // 헤더파일 NODE_MAKER.h에서 가져온다(구조체 node, ll을 끄집어 쓰겠다.)

void add(ll* list, int pos, int value) {    // ll*list : 구조체 포인터 변수 pos : 저장할 위치 value : 저장할 값
    int len = list->len;                    // 구조체 포인터는 . (멤버 연산자, 간접참조할 때 쓴다) 대신 ->을 씀
    if (pos > len) return;                  // 노드갯수 > 넣고자 하는 차례(n번째)가 성립해야 함

    node *new_node = (node*)malloc(sizeof(node));   // 구조체 포인터 변수new_node에 heap에 메모리 공간 할당
    new_node->value = value;                        // new_node의 value에 입력할 value값을 저장

    if (len == 0) {                                                 // 만일 새로 만들 노드가 맨처음(head바로 옆)일 때
        new_node->next = list->head;                                // new_node의 다음주소는 head의 다음 주소를 가리키는 노드의 주소
        list->head = new_node;                                      // head는 new_node
        list->len = len + 1;                                        // 리스트의 길이는 1만큼 더 늘어난다.
        printf("added %d at first (len = %d)\n", value, len + 1);   // value의 값을 첫째 노드로 넣는다고 출력
    }
    if (len > 0) {                                          // 만일 새로 만들 노드가 맨 처음이 아닐 때
        node* tmp = list->head;                             // 구조체 변수 tmp를 head에 저장
        for (int i = 0; i < pos - 1; i++) tmp = tmp->next;  // n 번 째(n = pos값) 노드의 주소로 이동(head - > n1(head->next) - >. . . - > n번째 노드 )
        new_node->next = tmp->next;                         // new_node의 다음주소 - > n + 1의 주소
        tmp->next = new_node;                               // n + 1의 주소 - > new_node
    }
}

int main() {
    ll list;            // 구조체 변수 list 선언(list는 노드의 갯수, head를 저장)
    list.head = NULL;   // head는 null리스트이다.그리고 head는 첫 번째 노드를 가리키는 변수이다.
    list.len = 0;       // 노드 개수 0으로 초기화

    add(&list, 0, 3);
    add(&list, 0, 2);
    add(&list, 0, 1);
    add(&list, 2, 4);
                        // add함수로 노드값 입력

    node* tmp = list.head;                  // tmp = head
    for (int i = 0; i < list.len; i++) {    // 노드 갯수(list.len)만븜 반복
        printf("%d\n", tmp->value);         // 해당 노드의 value값을 출력
        tmp = tmp->next;                    // 다음 노드로 이동
    }

    return 0;
}