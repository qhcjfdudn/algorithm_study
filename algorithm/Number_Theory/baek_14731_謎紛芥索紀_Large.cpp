/* https://www.acmicpc.net/problem/14731 */

/*
	도함수를 구하는 것은 간단하지만, 계산해야 하는 2의 지수승의 크기가 너무 커서, 이를 빠르게
	구할 방법을 찾아야 한다. 2^x로 표현되는 값은, x를 표현하는 이진 bit의 값을 구해서
	각 bit별로 1이 있는 자리의 2의 지수승을 곱해 답을 구할 수 있다.
*/

#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

int N;
long long powerList[33];

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	powerList[0] = 2;
	for (int i = 1; i < 33; i++)
		powerList[i] = (powerList[i - 1] * powerList[i - 1]) % MOD;
}

long long calc(int k) {
	if (k < 2) return k;

	long long ret = k--;
	for (int idx = 0; k; idx++, k >>= 1) {
		if (k % 2) {
			ret *= powerList[idx];
			ret %= MOD;
		}
	}

	return ret;
}

long long solve() {
	long long ans = 0;

	for (int i = 0, C, K; i < N; i++) {
		cin >> C >> K;
		ans += (C * calc(K)) % MOD;
		ans %= MOD;
	}

	return ans;
}

int main() {
	init();

	cout << solve() << '\n';
}