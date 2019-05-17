#include<stdio.h>
#include <stdlib.h>

int main(void) {
	char* word; // 50領域を確保
	int word_number;

	printf("入力する文字列の文字数を入力して下さい\n");
	scanf("%d", &word_number);

	// メモリの動的確保
	word = (char*)malloc(sizeof(char) * word_number);

	printf("文字列を入力して下さい\n");
	scanf("%s", word); // 50文字以上の入力は不可
	printf("入力した文字列は、%sです.\n", word);

	// メモリ解放
	free(word);

	return 0;
}
