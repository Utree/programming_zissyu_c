#include<stdio.h>
int main(void) {
  int array[] = {1, 3, 5, 7, 9};
  int * ptr;
  int i;

  // 配列の先頭アドレスを指定
  ptr = &array[0];

  for(i=0;i<5;i++) {
      printf("array[%d]のアドレス：", i);
      printf("%p\n", &ptr[i]);

      printf("array[%d]：", i);
      printf("%d\n", ptr[i]);
  }

  return 0;

}
