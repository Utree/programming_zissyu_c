#include<stdio.h>
#include<stdlib.h>

int main() {
	int * data;
	int histgram[10]; // ヒストグラム数値範囲を格納
	int size = 10; // 領域数を格納
	int count = 0, i; // 入力数を格納

	data = (int *)malloc(sizeof(int) * size); // 動的領域の確保

	while(1) {
		printf("数値を入力して下さい: ");

		// 入力処理
		scanf("%d", &data[count]);

		// 中断処理
		if(data[count] == 0) {
			break;
		}

		// 残りのメモリ数を確認 
		if(count >= size) { // 入力数 >= 領域数
			// 10ずつメモリを確保する
			size = 10 * (count/10 + 1);
			// メモリ確保
			data = (int *)realloc(data, sizeof(int) * size);
		}
		count++;
	}

	// 入力値(data)群 -> ヒストグラム数値範囲(histgram)群変換処理
	for(count=10;count>0;count--) {
		// 凡例を表示(インデント有)
		if(count<10)
			printf("%d - %d0\t : ", (count-1)*10+1, count);
		else
			printf("%d - %d0 : ", (count-1)*10+1, count);

		// *の表示
		for(i=0;data[i]!=0;i++) {
			if(data[i] >= (count-1)*10+1)
				if(data[i] <= count*10)
					printf("*");
		}

		// 改行
		printf("\n");
	}	

	// 解放処理
	free(data);

	return 0;
}	
