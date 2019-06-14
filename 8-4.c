#include <stdio.h>

// プロトタイプ宣言
void sort_main(char *);
void swap(char*, char*);

/** 入れ替え関数
* 2つのポインタを受け取り, お互いを入れ替える
*
* @param x1 変数1(int型)
* @param x2 変数2(int型)
*/
void swap(char* x1, char* x2) {
  char tmp;

  tmp = *x1;
  *x1 = *x2;
  *x2 = tmp;
}

/** 非再帰版　クイックソート関数
* 手法: スタックに分割すべき範囲の添字を積み、各範囲においてピボットを基準に分割を繰り返す
*
* @param array ソート対象のデータ(int*型)
*/
void sort_main(char *array){
  /** ソート範囲
  * left - right
  */
  int left = 0;

  int right=0;
  // 文字数をカウント
  while(array[right] != '\0') right++;
  right--;
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
    char string1[100], string2[100];

    printf("1つ目の単語を入力してください\n");
    scanf("%s", string1);

    printf("2つ目の単語を入力してください\n");
    scanf("%s", string2);

    // ソート関数の呼出し
    sort_main(string1);
    sort_main(string2);

    // 文字数をカウント
    int x1, x2;
    while(string1[x1] != '\0') x1++;
    while(string2[x2] != '\0') x2++;

    if(x1 != x2) {
      printf("アナグラムではありません\n");
      return 0;
    }

    // 内容を比較
    while(x1 >= 0) {
      if(string1[x1] != string2[x2]) {
        printf("アナグラムではありません\n");
        return 0;
      }
      x1--;
      x2--;
    }
    printf("アナグラムです\n");

    return 0;
}
