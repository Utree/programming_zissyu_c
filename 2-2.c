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
	printf("追加する成績情報を入力して下さい.\n");
	printf("学籍コード:");
	scanf("%d", &target);

	/* 検索 */
	for(;counter>0;) {
		counter--;
		if(students[counter].student_id == target) {
			/* 出力 */
			printf("学籍コード:%d\n", students[counter].student_id);
			printf("名前:%s\n", students[counter].name);
			printf("性別:%c\n", students[counter].gender);
			printf("評価点:%d\n", students[counter].point);

			return 0;
		}
	}

	/* エラー処理 */
	return -1;
}
