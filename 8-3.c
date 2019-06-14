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
void swap(int*, int*);

/** 入れ替え関数
* 2つのポインタを受け取り, お互いを入れ替える
*
* @param x1 変数1(int型)
* @param x2 変数2(int型)
*/
void swap(int* x1, int* x2) {
  int tmp;

  tmp = *x1;
  *x1 = *x2;
  *x2 = tmp;
}

/** 非再帰版　クイックソート関数
* 手法: スタックに分割すべき範囲の添字を積み、各範囲においてピボットを基準に分割を繰り返す
*
* @param array ソート対象のデータ(int*型)
*/
void sort_main(int *array){
  /** ソート範囲
  * left - right
  */
  int left = 0;
  int right = COUNT-1;
  /** スタックカウンタ
  * 現在積まれているスタックの層の数
  * 0 <= stack_counter <= 100-1
  */
  int  stack_counter = 0;
  /** スタック本体
  * lstack[i] - rstack[i]の範囲を分割する
  */
  int  lstack[100];
  int  rstack[100];

  // 初期値として, データの右端と左端の添字をぞれぞれスタックに積む
  lstack[stack_counter] = left;
  rstack[stack_counter] = right;
  // スタックカウンタを更新
  stack_counter++;

  // スタックカウンタが負になるまで、処理を繰り返す
  while (stack_counter-- > 0) {
    /** 左カーソル
    * ソート範囲内にある、pivotより小さい値の添字を保存しておくための変数
    *
    * left  = lstack[stack_counter]
    *   でスタックの最上層の値をソート範囲として定義し、
    * l_cursor = left
    *   でpivotより小さい値を探す初期位置を定義
    */
    int  l_cursor = left  = lstack[stack_counter];
    /** 右カーソル
    * ソート範囲内にある、pivotより大きい値の添字を保存しておくための変数
    *
    * right  = rstack[stack_counter]
    *   でスタックの最上層の値をソート範囲として定義し、
    * r_cursor = right
    *   でpivotより大きい値を探す初期位置を定義
    */
    int  r_cursor = right = rstack[stack_counter];
    /** ピボット
    * ソート範囲の(位置的に)中央の値
    */
    int  pivot = array[(left + right) / 2];

   // pivotを基準として、大きいものを右、小さいものを左に置く
   while (l_cursor <= r_cursor) {
      // leftからrightの範囲内で左側から順にpivotより値が大きい値の添字をl_cursorに入力
      // left | (l_cursor)-> ... pivot ... | right
      while (array[l_cursor] < pivot) l_cursor++;
      // leftからrightの範囲内で右側から順にpivotより値が小さい値の添字をr_cursorに入力
      // left | ... pivot ... <-(r_cursor) | right
      while (array[r_cursor] > pivot) r_cursor--;

      // l_cursorが左側で、r_cursorが右側にあれば入れ替える
      // array[... (l_cursor) ... (r_cursor) ...]
      if (l_cursor <= r_cursor) {
        swap(&array[l_cursor], &array[r_cursor]);
        l_cursor++;
        r_cursor--;
      }
    }

    // leftからr_cursorの範囲に値があればstackにプッシュし、次回以降のループ処理でソートを実行
    // array[... (left) ... (r_cursor) ...]
    if (left < r_cursor) {
      lstack[stack_counter] = left;
      rstack[stack_counter] = r_cursor;
      stack_counter++;
    }
    // l_cursorからrightの範囲に値があればstackにプッシュする、次回以降のループ処理でソートを実行
    // array[... (l_cursor) ... (right) ...]
    if (l_cursor < right) {
      lstack[stack_counter] = l_cursor;
      rstack[stack_counter] = right;
      stack_counter++;
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
