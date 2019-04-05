#include <stdio.h>

int main() {
	FILE * fp;
	int number;

	// ファイルオープン
	fp = fopen("./01number.txt", "r");
	// エラー処理
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

	// ストリームから取り出し
	while(fscanf(fp, "%d", &number) != EOF) {
		// 出力
		printf("%d ", number);
	}
	printf("\n");

	// ファイルクローズ
	fclose(fp);

	return 0;
}
