#include"stdafx.h"
#include"HeadfileAll.h"
using namespace std;

string LLLPlus(string A, string B) {
	if (A.size() > B.size()) {
		A.insert(0, 1, '0');
		B.insert(0, A.size() - B.size(), '0');
	}

	else {
		B.insert(0, 1, '0');
		A.insert(0, B.size() - A.size(), '0');
	}

	auto MarkB = B.end() - 1;
	for (auto it = A.end() - 1 ; it != A.begin(); --it) {
		*it += *MarkB - '0';
		--MarkB;
		if (*it > '9') {
			*it -= 10;
			++*(it - 1);
		}
	}
	if (*A.begin() == '0')
		A.erase(0, 1);
	return A;
}