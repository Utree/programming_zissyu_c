#include <stdio.h>
#include <time.h>


// 定数宣言
#define  COUNT  100000         		// データ数を指定
#define  INFILE    "08sort.txt"		// 入力ファイルを指定
#define  SORTFILE  "out.txt"   		// 出力ファイルを指定


// プロトタイプ宣言
void sort_main(int *);
void getFile(int *);
void outFile(int *);
double getFuncTime(clock_t, clock_t);


// ソート（並び替え）メイン関数
void sort_main(int *array){

    // ソート（並び替え）の処理を本関数で実現すること
    // 処理をまとめたい場合は，別関数を定義すること

	// *(array) = 10;			<--   data[0] = 10;　	と同じ
	// *(array + 10) = 100;		<--   data[10] = 100;	と同じ

  // 挿入ソートを実装する
  int i, j, tmp;

  // 左から順に数値を見ていく
  for(i=1;i<COUNT;i++) {
    j=i;

    // array[0]からarray[i]の範囲が(左) < (右) の関係になるまで、array[i]を左に移動
    while((j>0) && (array[j-1] > array[j])) {
      // 入れ替え
      tmp = array[j-1];
      array[j-1] = array[j];
      array[j] = tmp;

      j--;
    }
  }
}


// プログラムのメイン関数
int main(){
    // 変数宣言
    clock_t start,end;      // 開始＆終了時間を格納
    int data[COUNT];        // ファイル内のデータを格納

    // ファイルからデータの読み込み
    getFile(data);

    // 処理開始時間の設定
    start = clock();

    // ソート関数の呼出し
    sort_main(data);

    // 処理終了時間の設定
    end = clock();

    /// 処理にかかった時間の出力
    printf("--- Sort Time is  %.2f sec. ---¥n", getFuncTime(start, end));

    // 配列に保存されたデータの格納
    outFile(data);
}


void getFile(int *cur){
    FILE *fp;

    fp = fopen(INFILE, "r");
    while(fscanf(fp,"%d", cur) != EOF){
        cur++;
    }

    fclose(fp);
}

void outFile(int *cur){
    FILE *fp;
    int i;

    fp = fopen(SORTFILE, "w");

    for(i=0; i<COUNT; i++){
        fprintf(fp, "%d\n", *(cur+i));
    }

    fclose(fp);
}


double getFuncTime(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}
