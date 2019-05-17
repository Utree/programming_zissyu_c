#include<stdio.h>
#include<stdlib.h>

int main() {
	char * name[5]; // char型ポインタを宣言
	int i;
	FILE * fp;

	// ファイルオープン処理
	fp = fopen("./05write_person.txt", "w");

	// 入力処理
	for(i=0;i<5;i++) {
		printf("%d番目の人名を入力して下さい:", i+1);

		// 動的領域の確保 & nameポインタ配列の各要素と関連付け
		name[i] = (char*)malloc(sizeof(char) * 20);

		scanf("%s", name[i]); // 標準入力
	}

	// ファイル出力処理
	for(i=0;i<5;i++) {
		// 書き込み処理
		fprintf(fp, "name[%d]:%s\n", i, name[i]);
	}

	// ファイルクローズの処理
	fclose(fp);

	// メモリの開放処理
	for(i=0;i<5;i++) {
		free(name[i]);
	}

	printf("\n入力した名前をファイルへ出力しました\n");

	return 0;
}
