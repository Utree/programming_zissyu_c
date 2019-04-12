#include<stdio.h>
typedef struct student {
	int student_id;
	char name[20];
	char gender;
	int point;
} STUDENT;

int main() {
	STUDENT new_student;
	FILE *fp;

	/* 入力を求める */	
	printf("追加する成績情報を入力して下さい.\n");
	printf("学籍コード:");
	scanf("%d", &new_student.student_id);

	printf("名前:");
	scanf("%s%*c", new_student.name); /* %*cでバッファをクリア */

	printf("性別:");
	scanf("%c", &new_student.gender);

	printf("評価点:");
	scanf("%d", &new_student.point);

	/* ファイル書き込み */
	fp = fopen("./02student.txt", "a");
	fprintf(fp, "%d\t%s\t\t%c\t%d",
		new_student.student_id,
		new_student.name,
		new_student.gender,
		new_student.point);
	fclose(fp);

	printf("ファイルに追加書き込みしました.\n");

	return 0;
}
