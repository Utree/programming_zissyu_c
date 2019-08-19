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
  CELL * top_node, * bottom_node;
  top_node=(CELL *)malloc(sizeof(CELL));
  bottom_node=(CELL *)malloc(sizeof(CELL));

  // 初期化
  bottom_node->val = 100;
  bottom_node->next = NULL;
  top_node->val = 0;
  top_node->next = bottom_node;

  // リストを作る
  createList(top_node);

  // メモリ解放
  freeList(top_node);

	return 0;
}

void createList(CELL *top_node) {
  int tmp_val;
  CELL * new_node, * search_node;


  while(1) {

    // 初期化
    search_node = top_node;

    // データ入力
    printf("データを入力してください(0: 終了): ");
    scanf("%d", &tmp_val);

    // 1-99以外が入ったら終了
    if(tmp_val <= 0 || tmp_val >= 100) break;

    // 新しいセルを作成
    new_node = (CELL *)malloc(sizeof(CELL));
    // 初期化
    new_node->val = tmp_val;
    new_node->next = NULL;

    // 入れるべき場所を検索
    while(search_node->next->val < new_node->val) {
      search_node = search_node->next;
    }

    new_node->next = search_node->next;
    search_node->next = new_node;

    printf("***********\n");
    printf("%d\n", search_node->val);
    printf("***********\n");


    // 出力
    printList(top_node);
  }
}

void printList(CELL *top_node) {
  printf("----------------------\n");
  while(top_node->next != NULL) {
    printf("%d\n", top_node->val);

    top_node = top_node->next;
  }
  printf("%d\n", top_node->val);
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
