#include<stdio.h>
struct person {
	float height;	/* メンバ変数heightの定義(身長) */
	float weight;	/* メンバ変数weightの定義(体重) */
};

int main() {
	struct person a; /* 変数(定義した構造体型の宣言 */

	a.height = 175.0;
	a.weight = 63.5;
	printf("身長:%.1f 体重:%.1f\n", a.height, a.weight);

	return 0;
}
