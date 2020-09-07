/* https://www.acmicpc.net/problem/14731 */

/*
	���Լ��� ���ϴ� ���� ����������, ����ؾ� �ϴ� 2�� �������� ũ�Ⱑ �ʹ� Ŀ��, �̸� ������
	���� ����� ã�ƾ� �Ѵ�. 2^x�� ǥ���Ǵ� ����, x�� ǥ���ϴ� ���� bit�� ���� ���ؼ�
	�� bit���� 1�� �ִ� �ڸ��� 2�� �������� ���� ���� ���� �� �ִ�.
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