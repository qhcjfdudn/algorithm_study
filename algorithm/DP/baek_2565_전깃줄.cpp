/* https://www.acmicpc.net/problem/2565 */

/*
	어떻게 없앨까를 고민하면 어렵다..
	반대로 어떻게하면 최대한 많이 전깃줄을 이을 수 있을까 생각해보면 LIS가 떠오를 것이다.
	전깃줄을 정렬하고 나머지 한 쪽에 대해 LIS를 적용하면 간단히 해결할 수 있는 문제다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, cache[100];
pair<int, int> board[101];

int DP(int index) {
	if (index == N) return 1;

	int &ret = cache[index];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = index + 1; i <= N; i++)
		if (board[index].second < board[i].second)
			ret = max(ret, DP(i));

	return ++ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> board[i].first >> board[i].second;

	sort(board + 1, board + N + 1);

	cout << N - (DP(0) - 1) << '\n';
}