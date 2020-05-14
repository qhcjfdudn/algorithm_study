/* https://www.acmicpc.net/problem/5557 */

/*
	예외를 잘 찾아야 하는 문제. 음수를 모르므로, 맨 처음 수는 음수가 될 수 없다.
	이 예외는, 맨 처음에 오는 수가 오직 0일 때만 발생할 수 있다. 논리적으로 해결하자.
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