#include<stdio.h>

#define NUM 50

void swapstr(char *str1, char *str2);

int main(void) {
  char string1[NUM], string2[NUM];

  printf("2つの文字列を入力してください\n");
  scanf("%s%*c", string1);
  scanf("%s%*c", string2);

  printf("入れ替え前\n");
  printf("配列str1 = %s\n", string1);
  printf("配列str2 = %s\n", string2);

  swapstr(string1, string2);

  printf("入れ替え後\n");
  printf("配列str1 = %s\n", string1);
  printf("配列str2 = %s\n", string2);

  return 0;
}

void swapstr(char *str1, char *str2) {
  char tmp;
  int i=0;

  while (str1[i] != '\0' || str2[i] != '\0') {
    tmp = str1[i];
    str1[i] = str2[i];
    str2[i] = tmp;

    i++;
  }
}
