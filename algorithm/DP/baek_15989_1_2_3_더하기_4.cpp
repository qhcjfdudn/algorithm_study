/* https://www.acmicpc.net/problem/15989 */

/*
	더하는 숫자의 조합을 만들어야 한다. 만들어지는 숫자의 조합을 강제하는 것으로 해결해보자.
	물론 과정 상 동일한 조합이 반복되도록 나타나게 될 경우엔 memoization이 적용될 수 있기 때문에
	DP를 사용한 풀이를 적용하자.
*/

#include <iostream>
#include <cstring>
using namespace std;

int T, N, cache[10001][4];

// 재귀적 풀이
int DP(int v, int e) {
	// 1. base case
	if (v == 0) return 1;
	if (v < 0) return 0;

	// 2. 반복 제거. memoization
	int &ret = cache[v][e];
	if (ret != -1) return ret;

	// 3. 연산하기
	ret = 0;
	for (int i = 1; i <= e; i++)
		ret += DP(v - i, i);

	// 4. 리턴
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));

	cin >> T;

	while (T--) {
		cin >> N;
		cout << DP(N, 3) << '\n';
	}
}