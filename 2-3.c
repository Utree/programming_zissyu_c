#include<stdio.h>
typedef struct student {
	int student_id;
	char name[20];
	char gender;
	int point;
} STUDENT;

int main() {
	STUDENT students[20];
	int target;
	FILE * fp;
	int counter = 0;
	int i;

	/* ファイルを読み込む */
	fp = fopen("./02student.txt", "r");
	/* エラー処理 */
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

	/* ストリームから取り出し */
	while(fscanf(fp, "%d\t%s\t\t%c\t%d",
			&students[counter].student_id,
			students[counter].name,
			&students[counter].gender,
			&students[counter].point) != EOF) {
		counter++;
	}

	/* ファイルクローズ */
	fclose(fp);

	/* 入力を求める */
	printf("削除する成績情報を入力して下さい.\n");
	printf("学籍コード:");
	scanf("%d", &target);

	/* ファイルオープン */
	fp = fopen("./02student.txt", "w");

	/* 検索 */
	for(i=0;i<counter;i++) {
		if(students[i].student_id != target) {
			fprintf(fp, "%d\t%s\t\t%c\t%d\n",
				students[i].student_id,
				students[i].name,
				students[i].gender,
				students[i].point);
		}
	}

	/* ファイルクローズ */
	fclose(fp);

	printf("ファイルから削除しました\n");

	return 0;
}
