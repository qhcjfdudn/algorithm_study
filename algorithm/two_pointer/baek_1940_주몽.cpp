/* https://www.acmicpc.net/problem/1940 */

/*
	1. 재료를 정렬한다.
	양쪽에서부터 값을 더하고 기준값과 비교하여 l, r 포인터를 조정하며 M이 되는 경우의 개수를 찾는다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, board[15000];

int solve() {
	int ret = 0, l = 0, r = N - 1;
	while (l < r) {
		int Sum = board[l] + board[r];
		if (Sum == M) l++, r--, ret++;
		else if (Sum < M) l++;
		else r--;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> board[i];

	sort(board, board + N);

	cout << solve() << '\n';
}