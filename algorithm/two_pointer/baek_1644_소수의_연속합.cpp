/* https://www.acmicpc.net/problem/1644 */

/*
	�Ʒ��� �� ���� ���ҵ� Ǯ�̷� ������ �ذ��Ѵ�.
	1. �ڿ����κ��� �Ҽ��� ���Ѵ�.(�����佺�׳׽��� ü)
	2. �Ҽ��� ����Ʈ�κ��� ���ӵ� ���� ���Ѵ�.(�� ������)
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