#include <stdio.h>
#define NUMBER 15

int main() {
	FILE * fp; // ファイルのストリーム
	int number[NUMBER]; // ファイル入力保存用
	int i = 0; // カウンタ
	int max; // 最大値保存用

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


	// 最大値を算出
	max = number[0];

	for(;i>0;) {
		i--;
		if(max < number[i]) max = number[i];
	}

	// ファイル出力
	fp = fopen("./01maxnumber.txt", "w");

	fprintf(fp, "%d\n", max);

	fclose(fp);

	return 0;
}
