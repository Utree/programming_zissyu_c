#include<stdio.h>

#define NUM 50

int count(char *str);
void reverse(char *str);

int main(void) {
  char str1[NUM];

  printf("文字列を入力して下さい(2文字以上)\n");
  scanf("%s", str1);

  // 文字数を計上
  printf("文字数＝%d\n", count(str1));

  printf("入れ替え前\n");
  printf("%s\n", str1);

  // 文字列を逆順に
  reverse(str1);

  printf("入れ替え後\n");
  printf("%s\n", str1);

  return 0;
}

// 文字数を計上する
int count(char *str) {
  int i=0;

  while(str[i] != '\0') i++;

  return i;
}

// 文字列を逆順に入れ替える
void reverse(char *str) {
  char tmp;
  int counter=0, i;

  while(str[counter] != '\0') counter++;

  for(i=0;i<counter/2;i++) {
    tmp = str[i];
    str[i] = str[counter-1-i];
    str[counter-1-i] = tmp;
  }
}
