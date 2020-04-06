/* https://www.acmicpc.net/problem/16172 */

/*
	���鼭 �ʱ��� �������� ����� ������ ������.
	����� ���� �����Ϳ��� �ش� ���ڿ��� ã�� �ܼ��� KMP ������ ���� �� �� �ִ�.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string src, key;

void precalc() {
	string temp = "";

	for (auto it : src)
		if (it > '9')
			temp += it;

	src = temp;
}

vector<int> failure_function() {
	int len = key.length();

	vector<int> ret(len);

	int s = 1, matched = 0;

	while (s + matched < len) {
		if (key[s + matched] == key[matched]) {
			ret[s + matched] = matched + 1;
			if (s + ++matched == len) break;
		}
		else {
			if (matched == 0) s++;
			else {
				s += matched - ret[matched - 1];
				matched = ret[matched - 1];
			}
		}
	}
	return ret;
}

bool KMP() {
	vector<int> fail = failure_function();
	int key_len = key.length();
	int src_len = src.length();

	int s = 0, matched = 0;
	while (s + matched < src_len) {
		if (src[s + matched] == key[matched]) {
			if (++matched == key_len) return true;
		}
		else {
			if (matched == 0) s++;
			else {
				s += matched - fail[matched - 1];
				matched = fail[matched - 1];
			}
		}
	}

	return false;
}

int main() {
	cin >> src >> key;

	precalc();

	cout << (KMP() ? 1 : 0) << '\n';
}