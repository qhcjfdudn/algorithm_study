/* https://www.acmicpc.net/problem/1365 */

/*
	�������� ���� �ִ�. ���� �͵� �� �ּ��� ������ �������� �����ؾ� �Ѵ�.
	�ٲ� �����ϸ� �������� ���� ���� ��ġ�� �� �ִ� ����� ���� �����.
	LIS�� Ǯ�� �����ϴ�. �� O(NlgN)�� �ð����⵵�� �����ؾ� �ϹǷ�, ����Ž������ �ذ��Ѵ�.
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