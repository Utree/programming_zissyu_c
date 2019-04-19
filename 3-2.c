#include<stdio.h>
int main(void) {
  char ch[100];
  char * pt;

  /* 文字列の入力処理(配列chに格納) */
  printf("文字列を入力して下さい。\n");
  // scanf("%s", ch);
  // スペース以降も読み込むようfgetsを使う
  if(fgets(ch, 100, stdin) == NULL) {
    return 1;
  }

  // ポインタ変数に配列のアドレスを設定
  pt = &ch[0];

  /* 入力した文字列を逆順に出力 */
  printf("入力文字列を逆順に出力します。");

  // 配列を最後までたどる
  while(*pt != '\0')
    pt++;

  // 後ろから出力する
  while(pt != &ch[0]) {
    pt--;
    printf("%c", *pt);
  }
  printf("\n");

  return 0;
}
