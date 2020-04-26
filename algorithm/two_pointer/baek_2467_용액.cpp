/* https://www.acmicpc.net/problem/2467 */

/*
	정렬이 돼 있기 때문에, 이진탐색을 적용할 수 있다. 하지만 양쪽에서 범위를 좁혀 오며 합이 0이 되는 두 값을 찾는
	것이 O(NlogN)인 이진탐색보다 O(N)으로 더 빠를 것. 투 포인터를 이용하자.
*/

#include <iostream>
#include <cmath>
using namespace std;

int N, board[100000];

void solve() {
	int l = 0, r = N - 1, pSum = 2 * 1e9 + 1, ret1, ret2;
	while (l < r && pSum) {
		int curSum = abs(board[l] + board[r]);
		if (curSum < pSum) {
			pSum = curSum;
			ret1 = board[l];
			ret2 = board[r];
		}
		if (abs(board[l]) < abs(board[r])) r--;
		else l++;
	}
	cout << ret1 << " " << ret2 << '\n';
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> board[i];

	solve();
}