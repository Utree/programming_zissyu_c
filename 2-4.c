#include<stdio.h>
typedef struct numbers {
	int odd[20];
	char even[20];
} NUMBERS;

int main() {
	NUMBERS number;
	int tmp;
	FILE * fp;
	int i, e=0, o=0;

	/* ファイルを読み込む */
	fp = fopen("./01number.txt", "r");
	/* エラー処理 */
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

	/* ストリームから取り出し */
	while(fscanf(fp, "%d", &tmp) != EOF) {
		/* 偶数・奇数の判別 */
		if(tmp%2 == 0) {
			number.even[e] = tmp;
			e++;
		} else {
			number.odd[o] = tmp;
			o++;
		}
	}

	/* ファイルクローズ */
	fclose(fp);

	/* 出力 */
	printf("奇数 : ");
	for(i=0;i<o;i++)
		printf("%d ", number.odd[i]);
	printf("\n");

	printf("偶数 : ");
	for(i=0;i<e;i++)
		printf("%d ", number.even[i]);
	printf("\n");

	return 0;
}
