/* https://www.acmicpc.net/problem/1305 */

/*
	�����ǿ� ���̴� ������ ������ �ݺ��Ǵ� �κ��� �ִ��� ����
	���� ���̴� ������ ���λ�� ���̻簡 ���� ���� ���� ���̴�.
*/

#include <iostream>
using namespace std;

int L, failure_function[1000000];
char src[1000001];

int solve() {
	int idx = 1, m = 0;

	while (idx + m < L) {
		if (src[m] == src[idx + m]) {
			failure_function[idx + m] = m + 1;
			m++;
		}
		else {
			if (m > 0) {
				idx += m - failure_function[m - 1];
				m = failure_function[m - 1];
			}
			else idx++;
		}
	}

	return L - failure_function[L - 1]; // ��ü ���̿��� ���� ������ �����Լ��� ���� ���ش�.
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> L >> src;

	cout << solve() << '\n';
}