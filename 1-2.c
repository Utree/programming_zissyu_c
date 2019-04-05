#include <stdio.h>

int main() {
	FILE * fp;
	int number[15];
	int i = 0;

	// ファイルオープン
	fp = fopen("./01number.txt", "r");
	// エラー処理
	if(fp == NULL) {
		printf("ファイルを開けません\n");
		return -1;
	}

	// ストリームから取り出し
	while(fscanf(fp, "%d", &number[i]) != EOF) {
		// 保存
		i++; 
	}

	// ファイルクローズ
	fclose(fp);
	
	// 出力
	for(;i>0;) {
		i--;
		printf("%d ", number[i]);
	}

	printf("\n");

	return 0;
}
