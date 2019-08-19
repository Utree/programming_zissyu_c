#include <stdio.h>

typedef struct cell {
  int val; // int型変数: セルの値を格納
  struct cell *next; // 構造体への自己参照型: 次のセルを指定
}CELL;

void printList(CELL *list);

int main() {
  CELL list4={20, NULL}, list3={15, &list4}, list2={10, &list3}, list1={5, &list2};

  printList(&list1);

	return 0;
}

void printList(CELL *list) {
  while(list != NULL) {
    printf("%d\n", list->val);

    list = list->next;
  }
}
