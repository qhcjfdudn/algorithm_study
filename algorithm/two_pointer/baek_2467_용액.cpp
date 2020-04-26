/* https://www.acmicpc.net/problem/2467 */

/*
	������ �� �ֱ� ������, ����Ž���� ������ �� �ִ�. ������ ���ʿ��� ������ ���� ���� ���� 0�� �Ǵ� �� ���� ã��
	���� O(NlogN)�� ����Ž������ O(N)���� �� ���� ��. �� �����͸� �̿�����.
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