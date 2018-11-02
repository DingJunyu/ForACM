#include"stdafx.h"
#include"HeadfileAll.h"
using namespace std;

void MergeExecution(int *Unsort,int Length) {
	if (Length < 2)
		return;

	/*中点を取る*/
	int Mid;
	Mid = Length / 2;

	/*前半と後半を別ける、数字をコピーする*/
	int *L = new int[Mid];//動的にオブジェクトを生成
	int *R = new int[Length - Mid];

	for (int i = 0; i < Mid; ++i) L[i] = Unsort[i];
	for (int i = Mid; i < Length; ++i) R[i - Mid] = Unsort[i];

	/*別けた部分をソート*/
	MergeExecution(L, Mid);
	MergeExecution(R, Length - Mid);

	int LeftArray = 0, RightArray = 0, Count = 0;
	/*ソートされた配列を整理する*/
	while (LeftArray < Mid&&RightArray < Length - Mid) {
		/*小さいのは左置き*/
		if (L[LeftArray] < R[RightArray]) 
			Unsort[Count++] = L[LeftArray++];
		else
			Unsort[Count++] = R[RightArray++];
	}
	/*いずれが残ったら、そのまま配列の最後に追加する*/
	while (LeftArray < Mid)
		Unsort[Count++] = L[LeftArray++];
	while (RightArray < Length - Mid)
		Unsort[Count++] = R[RightArray++];

	delete[] R;//メモリ解放
	delete[] L;
}