#include"stdafx.h"
#include"HeadfileAll.h"
using namespace std;

string LLLPlus(string A, string B) {
	/*������̒����𓝈ꂵ�A����Ȃ������⓪�̈�ʂɂO�����*/
	if (A.size() > B.size()) {
		A.insert(0, 1, '0');
		B.insert(0, A.size() - B.size(), '0');
	}

	else {
		B.insert(0, 1, '0');
		A.insert(0, B.size() - A.size(), '0');
	}

	/*B�̃C�e���[�^��錾*/
	auto MarkB = B.end() - 1;
	/*A�̃C�e���[�^��錾���A���[�v�����Ƃ��Đݒ肷��*/
	for (auto it = A.end() - 1 ; it != A.begin(); --it) {
		*it += *MarkB - '0';//�d���ȕ������폜
		--MarkB;//B�̃C�e���[�^����ʑO�Ɉړ�
		/*10���z�������̏���*/
		if (*it > '9') {
			*it -= 10;
			++*(it - 1);
		}
	}
	/*�ŏ��̈ʂɐ��������Ȃ���΁A�폜����*/
	if (*A.begin() == '0')
		A.erase(0, 1);
	return A;//������A��Ԃ�
}