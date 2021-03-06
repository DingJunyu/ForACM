// Sort.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
using namespace std;

/*関数の宣言*/
void swap(string*, string*);//交換関数
void quick_sort_recursive(string List[10], int Start, int End);//クイックソート実行関数
void quick_sort(string List[10], int len);//クイックソート呼び出す関数


int main()
{	
	string StringList[10] = {
		"One","Two","Three",
		"Four","Five","Six",
		"Seven","Eight","Nine",
		"Ten"
	};

	for (int i = 0; i < 10; ++i)//もとの文字列を表示
		cout << StringList[i] << endl;

	printf("\n");

	quick_sort(StringList, 10);//ソート

	for (int i = 0; i < 10; ++i)//ソート終わった文字列を表示
		cout << StringList[i] << endl;

    return 0;
}

/*交換関数：アドレスを交換する*/
void swap(string* a, string* b) {
	string *Temp = a;//アドレスを一時保存
	a = b;
	b = Temp;
}

void quick_sort_recursive(string *List, int Start, int End) {
	if (Start >= End)//StartとEndは同じところに指す時は終わる
		return;
	string *Mid = &List[End];//最後の文字列を中間値にする
	int Left = Start, Right = End - 1;//左は開始点にする、右は終点の前の一つの位置にする
	while (Left < Right) {
		while (List[Left].compare(0, sizeof(List[Left]), *Mid, 0, sizeof(*Mid)) < 0 && Left < Right)//左からmidより小さいな文字列を探す
			Left++;
		while (List[Right].compare(0, sizeof(List[Right]), *Mid, 0, sizeof(*Mid)) >= 0 && Left < Right)//右からmidより大きいな文字列を探す
			Right--;
		swap(List[Left], List[Right]);//交換
	}
	if (List[Left].compare(0, sizeof(List[Left]), *Mid, 0, sizeof(*Mid)) > 0)//中間値は最後交換された値より小さい時は中間値を正しい位置に移動する
		swap(List[Left], List[End]);
	else
		Left++;

//	for (int i = 0; i < 10; ++i)//処理手順を説明するためのループ
	//	cout << List[i] << endl;
	//getchar();
	if (Left)
		quick_sort_recursive(List, Start, Left - 1);//左側をもう一度ソート
	quick_sort_recursive(List, Left + 1, End);//右側をもう一度ソート
}

void quick_sort(string *List, int len) {
	quick_sort_recursive(List, 0, len - 1);
}