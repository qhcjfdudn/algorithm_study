/* https://www.acmicpc.net/problem/5557 */

/*
	���ܸ� �� ã�ƾ� �ϴ� ����. ������ �𸣹Ƿ�, �� ó�� ���� ������ �� �� ����.
	�� ���ܴ�, �� ó���� ���� ���� ���� 0�� ���� �߻��� �� �ִ�. �������� �ذ�����.
*/

#include <iostream>
#include <cstring>
using namespace std;

int	N, seq[100];
long long cache[100][21];

long long DP(int index, int pSum) {
	if (index == N - 1) return pSum == seq[index];
	if (pSum < 0 || pSum > 20) return 0;

	long long &ret = cache[index][pSum];
	if (ret != -1) return ret;

	return ret = DP(index + 1, pSum + seq[index]) + DP(index + 1, pSum - seq[index]);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> seq[i];

	memset(cache, -1, sizeof(cache));
	cout << DP(1, seq[0]) << '\n';
}