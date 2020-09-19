/* https://www.acmicpc.net/problem/2847 */

/*
	�迭�� �ڿ������� ���� �۾������� ����
*/

#include <iostream>
using namespace std;

int N, scores[100];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> scores[i];
}

int solve() {
	int ret = 0;
	for (int i = N - 1; i > 0; i--) {
		if (scores[i - 1] < scores[i]) continue;
		ret += scores[i - 1] - scores[i] + 1;
		scores[i - 1] = scores[i] - 1;
	}
	return ret;
}

int main() {
	init();
	cout << solve() << '\n';
}