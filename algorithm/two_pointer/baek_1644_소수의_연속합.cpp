/* https://www.acmicpc.net/problem/1644 */

/*
	아래의 두 가지 분할된 풀이로 문제를 해결한다.
	1. 자연수로부터 소수를 구한다.(에라토스테네스의 체)
	2. 소수의 리스트로부터 연속된 합을 구한다.(투 포인터)
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool prime[4000001];
int N;
vector<int> prime_vector;

void precalc() {
	memset(prime + 2, true, (N - 1) * sizeof(bool));

	for (int i = 2; i * i <= N; i++) {
		if (prime[i])
			for (int j = i * i; j <= N; j += i)
				if (prime[j])
					prime[j] = false;
	}

	for (int i = 2; i <= N; i++)
		if (prime[i])
			prime_vector.push_back(i);
}

int solve() {
	int ret = 0, pSum = 0, l = 0, r = 0, len = prime_vector.size();
	while (r != len || pSum >= N) {
		if (pSum < N) pSum += prime_vector[r++];
		else {
			if (pSum == N) ret++;
			pSum -= prime_vector[l++];
		}
	}
	return ret;
}

int main() {
	cin >> N;

	precalc();

	cout << solve() << '\n';
}