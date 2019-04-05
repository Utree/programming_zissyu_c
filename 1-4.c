#include <stdio.h>

int main() {
	FILE * fp;
	int number[15];
	int i = 0;
	int start, finish; // 開始番号と終了番号

	// 標準入力から数字を取得
	printf("数値1の入力:");
	scanf("%d", &start);

	printf("数値2の入力:");
	scanf("%d", &finish);

	// ファイル出力
	fp = fopen("./01range.txt", "w");
	for(i=start;i<=finish;i++) fprintf(fp, "%d\n", i);
	fclose(fp);

	printf("ファイル「01range.txt」に出力しました.\n");
	return 0;
}
