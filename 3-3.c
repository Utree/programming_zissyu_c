#include<stdio.h>
typedef struct strings{
  char ch1[20];
  char ch2[20];
} STRINGS;

int main() {
  STRINGS input; char out[40];
  int i=0;

  STRINGS * pt_input = &input;
  char * pt_out = &out[0];

  /* 以降の処理は、pt_input/pt_outから領域を参照 */
  printf("1つ目の文字列：");
  scanf("%s", pt_input->ch1);
  printf("2つ目の文字列：");
  scanf("%s", pt_input->ch2);

  /* ch1, ch2の順に文字列を結合し、ポインタ変数を利用してoutに格納 */
  while(pt_input->ch1[i] != '\0') {
    *pt_out = pt_input->ch1[i];
    i++;
    pt_out++;
  }

  i=0;
  while(pt_input->ch2[i] != '\0') {
    *pt_out = pt_input->ch2[i];
    i++;
    pt_out++;
  }
  *pt_out = '\0';


  printf("結合した文字列：%s\n", &out[0]);

  return 0;
}
