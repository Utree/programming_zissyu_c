#include<stdio.h>
#include<stdlib.h>

typedef struct student {
        int student_id;
        char name[20];
        char gender;
        int point;
} STUDENT;

int main(void) {
	int i;
	STUDENT * st; // malloc関数で動的確保(10領域)
	FILE * fp;

	st = (STUDENT*)malloc(sizeof(STUDENT) * 10);

	// ファイルオープンの処理
	fp = fopen("./02student.txt", "r");
	// エラー処理
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

	for(i=0;i<10;i++) {
		// ファイル入力処理(ポインタ変数stを各領域参照し、格納
		fscanf(fp, "%d\t%s\t\t%c\t%d",
                        &st[i].student_id,
                        st[i].name,
                        &st[i].gender,
                        &st[i].point);
	}

	for(i=0;i<10;i++) {
		// 標準出力処理(ポインタ変数stから各領域を参照し、値を確保
		printf("%d\t%s\t\t%c\t%d\n",
                                st[i].student_id,
                                st[i].name,
                                st[i].gender,
                                st[i].point);
	}

	// ファイルクローズの処理
	fclose(fp);

	// メモリ解放の処理
	free(st);

	return 0;
}
