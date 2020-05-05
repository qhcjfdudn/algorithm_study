/* https://www.acmicpc.net/problem/2568 */

/*
	�����ٷ� ������ ��츦 ã�� ���� �̺�Ž���� �̿��Ͽ� ���� ���� �� �ִ�.
	������ ������ ��츦 �����ϴ� ���� ����. ����Ž���� ����Ͽ� �迭�� ���� ������ ���,
	����ϴ� �������� ������ �������� ��ġ�� �ٲ����� ������ ������ �� ����.
	��, ������ ������ �迭���� ��ġ�� Ȯ���� ����, ��� �ٷ� ���� ��ġ�� �ִ� ���� ������
	���� ��ġ�� ���̱� ������, �� ��ġ���� point�� ���δ� ������ ���� ����� �� �ִ�.
	�̸� ������ ������ �������ذ��� ���� ���� �� �ִ�.
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