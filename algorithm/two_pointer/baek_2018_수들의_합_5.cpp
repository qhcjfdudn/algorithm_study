/* https://www.acmicpc.net/problem/2018 */

/*
	�� �����͸� ����Ͽ� �������� ������ �� �� �ִ�.
	�Ǵ� ���������� �������� �� �� �ִ� ��츸 ������ ���� �ִ�.
*/

#include <iostream>
using namespace std;

int N;

int solve() {
	int ret = 0, pSum = 0, l = 1, r = 1;
	while (r <= N || pSum >= N) {
		if (pSum < N) pSum += r++;
		else {
			if (pSum == N) ret++;
			pSum -= l++;
		}
	}
	return ret;
}

int main() {
	cin >> N;

	cout << solve() << '\n';
}