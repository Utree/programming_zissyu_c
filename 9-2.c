#include <stdio.h>
#include<stdlib.h>

typedef struct cell {
  int val; // int型変数: セルの値を格納
  struct cell *next; // 構造体への自己参照型: 次のセルを指定
}CELL;

void createList(CELL *top_node);
void printList(CELL *top_node);
void freeList(CELL *top_node);

int main() {
  CELL * top_node;
  top_node=(CELL *)malloc(sizeof(CELL));
  // 初期化
  top_node->val = 0;
  top_node->next = NULL;

  // リストを作る
  createList(top_node);

  // メモリ解放
  freeList(top_node);

	return 0;
}

void createList(CELL *top_node) {
  int tmp_val;
  CELL * new_node, * bottom_node;

  // 初期化
  bottom_node = top_node;

  while(1) {
    // データ入力
    printf("データを入力してください(0: 終了): ");
    scanf("%d", &tmp_val);

    // 0が入ったら終了
    if(tmp_val == 0) break;

    bottom_node->val = tmp_val;

    // 新しいセルを作成
    new_node = (CELL *)malloc(sizeof(CELL));
    // 初期化
    new_node->val = 0;
    new_node->next = NULL;

    // 最後のノードに追加
    bottom_node->next = new_node;
    bottom_node = bottom_node->next;

    // 出力
    printList(top_node);
  }
}

void printList(CELL *top_node) {
  printf("----------------------\n");
  while(top_node->val != 0) {
    printf("%d\n", top_node->val);

    top_node = top_node->next;
  }
  printf("----------------------\n");
}

void freeList(CELL *top_node) {
  CELL * tmp;

  tmp = top_node;
  while(tmp != NULL) {
    top_node = top_node->next;
    free(tmp);
    tmp = top_node;
  }
}
