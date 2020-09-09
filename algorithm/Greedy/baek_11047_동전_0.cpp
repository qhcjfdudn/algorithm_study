/* https://www.acmicpc.net/problem/11047 */

/*
	������ ����� ���踦 ������ Ŀ���� ������, �׸����ϰ� Ǯ �� �ִ�.
*/

#include <iostream>
using namespace std;

int N, K, coins[10];

void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coins[i];
}

int solve() {
	int ret = 0;

	while (K) {
		N--;
		if (coins[N] > K) continue;
		ret += K / coins[N];
		K -= (K / coins[N]) * coins[N];
	}

	return ret;
}

int main() {
	init();

	cout << solve() << '\n';
}