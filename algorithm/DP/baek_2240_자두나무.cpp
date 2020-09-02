/* https://www.acmicpc.net/problem/2240 */

/*
	자두의 첫 위치가 고정돼 있다고 해서, 무조건 거기부터 시작하는 게 아님의
	예외를 깨달아야 한다..
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, W, plums[1001], cache[1001][3][31];

int DP(int t, int jaduPos, int wCnt) {
	if (t > T) return 0;

	int& ret = cache[t][jaduPos][wCnt];
	if (ret != -1) return ret;

	ret = jaduPos == plums[t];
	int a = DP(t + 1, jaduPos, wCnt);
	int b = wCnt < W ? DP(t + 1, (jaduPos % 2) + 1, wCnt + 1) : 0;

	return ret = ret + max(a, b);
}

int main() {
	cin >> T >> W;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= T; i++) cin >> plums[i];

	cout << DP(0, 1, 0) << '\n';
}
