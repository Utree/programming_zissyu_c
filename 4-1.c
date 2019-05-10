#include<stdio.h>

#define COUNT 3 // 配列数の定数宣言

void input(int *array); // 入力用関数
void sort(int *array); // 並び替え用関数
void output(int *array); // 出力用関数

int main(void) {
  //配列の宣言
  int data[COUNT];

  // 入力処理
  input(data);

  // 並び替え処理
  sort(data);

  // 出力処理
  output(data);

  return 0;
}

// 入力用関数
void input(int *array) {
  printf("3つの数字を入力して下さい\n");

  scanf("%d %d %d", &array[0], &array[1], &array[2]);
}

// 並び替え用関数
void sort(int *array) {
  int i, j, tmp;

  for(i=0;i<COUNT-1;i++) {
    for(j=i+1;j<COUNT;j++) {
      if(array[i] > array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

// 出力用関数
void output(int *array) {
  printf("並び替え結果\n");

  printf("%d %d %d\n", array[0], array[1], array[2]);
}
