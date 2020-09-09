/* https://www.acmicpc.net/problem/11047 */

/*
	동전이 배수의 관계를 가지며 커지기 때문에, 그리디하게 풀 수 있다.
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