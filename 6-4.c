#include<stdio.h>
#include<stdlib.h>

int main() {
	int * data;
	int histgram[10]; // ヒストグラム数値範囲を格納
	int size = 10; // 領域数を格納
	int count = 0; // 入力数を格納

	data = (int *)malloc(sizeof(int) * size) // 動的領域の確保

	while(1) {
		printf("数値を入力して下さい: ");

		// 入力処理

		// 中断処理

		if(count >= size) { // 入力数 >= 領域数
			// 再確保処理:
