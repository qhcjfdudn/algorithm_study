/* https://www.acmicpc.net/problem/1480 */

/*
	배낭 배열을 하나씩 보며 보석을 채운다.
	이 때 보석을 채우는 데에는 순서가 없고, 보석은 하나씩 존재하므로 비트마스크를 이용하여
	메모리를 최적화할 수 있다. 이를 활용한 DP를 적용한다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, C, weight[13], cache[1 << 13][10][21];

int DP(int bit, int numBack, int curWei) {
	if (numBack == M || bit == (1 << N) - 1) return 0;

	int &ret = cache[bit][numBack][curWei];
	if (ret != -1) return ret;

	for (int i = 0; i < N; i++) {
		if ((1 << i) & bit) continue;
		if (curWei + weight[i] <= C)
			ret = max(ret, DP(bit | (1 << i), numBack, curWei + weight[i]) + 1);
	}
	ret = max(ret, DP(bit, numBack + 1, 0));

	return ret;
}

int main() {
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) cin >> weight[i];
	memset(cache, -1, sizeof(cache));

	cout << DP(0, 0, 0) << '\n';
}