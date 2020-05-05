/* https://www.acmicpc.net/problem/1365 */

/*
	전깃줄이 꼬여 있다. 꼬인 것들 중 최소의 개수로 전깃줄을 제거해야 한다.
	바꿔 생각하면 전깃줄을 가장 많이 설치할 수 있는 경우의 수를 남긴다.
	LIS로 풀이 가능하다. 단 O(NlgN)의 시간복잡도로 구현해야 하므로, 이진탐색으로 해결한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int solve(vector<int> &board) {
	vector<int> ret;
	int sz = 0;
	for (int i = 0; i < N; i++) {
		int index = lower_bound(ret.begin(), ret.end(), board[i]) - ret.begin();
		if (sz == index) ret.push_back(board[i]), sz++;
		else ret[index] = board[i];
	}

	return N - sz;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	vector<int> board(N);

	for (int i = 0; i < N; i++) cin >> board[i];

	cout << solve(board) << '\n';
}