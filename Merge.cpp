#include"stdafx.h"
#include"HeadfileAll.h"
using namespace std;

void MergeExecution(int *Unsort,int Length) {
	if (Length < 2)
		return;

	int Mid;
	Mid = Length / 2;
	int *L = new int[Mid];
	int *R = new int[Length - Mid];

	for (int i = 0; i < Mid; ++i) L[i] = Unsort[i];
	for (int i = Mid; i < Length; ++i) R[i - Mid] = Unsort[i];

	MergeExecution(L, Mid);
	MergeExecution(R, Length - Mid);
	int LeftArray = 0, RightArray = 0, Count = 0;
	while (LeftArray < Mid&&RightArray < Length - Mid) {
		if (L[LeftArray] < R[RightArray]) 
			Unsort[Count++] = L[LeftArray++];
		else
			Unsort[Count++] = R[RightArray++];
	}
	while (LeftArray < Mid)
		Unsort[Count++] = L[LeftArray++];
	while (RightArray < Length - Mid)
		Unsort[Count++] = R[RightArray++];

	delete[] R;
	delete[] L;
}