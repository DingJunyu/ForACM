#include"stdafx.h"
#include"HeadfileAll.h"
using namespace std;

string LLLPlus(string A, string B) {
	/*文字列の長さを統一し、足りない部分や頭の一位に０を入る*/
	if (A.size() > B.size()) {
		A.insert(0, 1, '0');
		B.insert(0, A.size() - B.size(), '0');
	}

	else {
		B.insert(0, 1, '0');
		A.insert(0, B.size() - A.size(), '0');
	}

	/*Bのイテレータを宣言*/
	auto MarkB = B.end() - 1;
	/*Aのイテレータを宣言し、ループ条件として設定する*/
	for (auto it = A.end() - 1 ; it != A.begin(); --it) {
		*it += *MarkB - '0';//重複な部分を削除
		--MarkB;//Bのイテレータを一位前に移動
		/*10を越えた時の処理*/
		if (*it > '9') {
			*it -= 10;
			++*(it - 1);
		}
	}
	/*最初の位に数字がいなければ、削除する*/
	if (*A.begin() == '0')
		A.erase(0, 1);
	return A;//文字列Aを返す
}