/* https://www.acmicpc.net/problem/16943 */

/*
	ó������ �ϳ��ϳ� �������� �ذ��� �� ���� �Ŷ� ����������, �ƴϾ���.
	���� ������ ������ �����ϴ� ���ڰ� �� ���� ���� �Ǵ��ϴ� ���� �������� ������ ��.
	�������ͷ� ���߾�� �ϳ�..
	�׷��� �ᱹ ��Ž!
	�ٵ� next_permutation���� ������ �ҽ��� ��Ʈ��ŷ�� �ҽ����� ������. ����? ����??
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A, B, ret = -1, len, sA[10];
bool visited[10];

void init() {
	while (A) {
		sA[len++] = A % 10;
		A /= 10;
	}
}

void solve(int idx, int v) {
	if (idx == len) {
		if (v <= B)
			ret = max(ret, v);
	}
	else {
		for (int i = 0; i < len; i++) {
			if (visited[i] || (idx == 0 && sA[i] == 0)) continue;
			visited[i] = true;
			solve(idx + 1, v * 10 + sA[i]);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> A >> B;

	init();

	solve(0, 0);
	cout << ret << '\n';
}