#include<stdio.h>
typedef struct student {
	int student_id;
	char name[20];
	char gender;
	int point;
} STUDENT;

int main() {
  FILE *fp;
  int i;
  STUDENT st[20];
  STUDENT * pt = st;

  // ファイルオープン処理
  fp = fopen("./02student.txt", "r");
	/* エラー処理 */
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

  /* ストリームから取り出し */
  while(fscanf(fp, "%d\t%s\t\t%c\t%d",
      &pt[i].student_id,
      pt[i].name,
      &pt[i].gender,
      &pt[i].point) != EOF) {
    i++;
  }

  /* ファイルクローズ */
  fclose(fp);

  // ポインタ変数ptを利用し、構造体配列の各メンバを参照し出力
  while(pt != &st[i]) {
    printf("%d\t%s\t%c\t%d\n",
      pt->student_id,
      pt->name,
      pt->gender,
      pt->point);
    pt++;
  }

  return 0;
}
