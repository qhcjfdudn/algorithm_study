/* https://www.acmicpc.net/problem/2568 */

/*
	전깃줄로 가능한 경우를 찾는 것은 이분탐색을 이용하여 쉽게 구할 수 있다.
	하지만 가능한 경우를 나열하는 것이 문제. 이진탐색을 사용하여 배열의 값을 조절할 경우,
	계산하는 과정에서 값들이 제각각의 위치로 바껴버려 순서를 결정할 수 없다.
	단, 임의의 순서에 배열에서 위치가 확정된 값은, 적어도 바로 이전 위치에 있는 값이 무조건
	먼저 배치된 값이기 때문에, 이 위치로의 point를 찍어두는 것으로 값을 출력할 수 있다.
	이를 마지막 노드부터 역추적해가며 답을 구할 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int N;

void solve(vector<pii> &board) {
	vector<int> point(N, -1);
	vector<pii> ret;

	for (int i = 0, index, s; i < N; i++) {
		index = lower_bound(ret.begin(), ret.end(), pii(board[i].second, -1)) - ret.begin();
		s = ret.size();
		if (index) point[i] = ret[index - 1].second;
		if (index == s) ret.push_back({ board[i].second, i });
		else ret[index] = pii(board[i].second, i);
	}

	cout << N - ret.size() << '\n';

	vector<bool> check(N);

	int i = ret.rbegin()->second;
	while (i != -1) {
		check[i] = true;
		i = point[i];
	}

	for (int i = 0; i < N; i++) {
		if (!check[i])
			cout << board[i].first << '\n';
	}
}

int main() {
	cin >> N;
	vector<pii> board(N);

	for (int i = 0; i < N; i++)
		cin >> board[i].first >> board[i].second;

	sort(board.begin(), board.end());

	solve(board);
}