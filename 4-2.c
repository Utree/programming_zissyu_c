#include<stdio.h>

typedef struct numbers {
  int num1, num2, result;
} NUM;

void addstruct(NUM *tmp);

int main(void) {
  // 変数の宣言
  NUM number1;
  number1.num1 = 10;
  number1.num2 = 15;

  // 足し算関数の呼び出し
  addstruct(&number1);

  // 標準出力
  printf("num1=%d\nnum2=%d\nresult=%d\n", number1.num1, number1.num2, number1.result);

  return 0;
}

// addstruct関数
void addstruct(NUM *tmp) {
  tmp->result = tmp->num1 + tmp->num2;
}
