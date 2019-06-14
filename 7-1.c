#include <stdio.h>
#include <time.h>


// 定数宣言
#define  COUNT  100000         		// データ数を指定
#define  INFILE    "07search.txt"		// 入力ファイルを指定


// プロトタイプ宣言
int search_main(int *, int);
void getFile(int *);
double getFuncTime(clock_t, clock_t);

// 探索メイン関数
int search_main(int *array, int target){
	// 探索のデータを格納
	int result=0, i;
    	//  探索の処理を本関数で実現すること
    	// 処理をまとめたい場合は，別関数を定義すること

	// *(array) = 10;			<--   data[0] = 10;　	と同じ
	// *(array + 10) = 100;		<--   data[10] = 100;	と同じ

	for(i=0;i<COUNT;i++)
		if(array[i] == target)
			result++;

	return result;
}


// プログラムのメイン関数
int main(){
    // 変数宣言
    int searchNum;        // 探索のデータを格納
    int result;        // データ件数を格納
    clock_t start,end;      // 開始＆終了時間を格納
    int data[COUNT];        // ファイル内のデータを格納

    // ファイルからデータの読み込み
    getFile(data);

    printf("探索したい値を入力して下さい\n");
    // 探索データの入力
		scanf("%d", &searchNum);

    // 処理開始時間の設定
    start = clock();

    // 探索関数の呼出し
    result = search_main(data, searchNum);

    // 処理終了時間の設定
    end = clock();

    // 処理結果の出力
		printf("データ群の中から%dを%d件発見しました。\n", searchNum,result);

    /// 処理にかかった時間の出力
    printf("--- Search Time is  %.2f sec. ---\n", getFuncTime(start, end));

    return 0;
}


void getFile(int *cur){
    FILE *fp;

    fp = fopen(INFILE, "r");
    while(fscanf(fp,"%d", cur) != EOF){
        cur++;
    }

    fclose(fp);
}

double getFuncTime(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}
