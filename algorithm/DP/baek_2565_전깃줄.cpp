/* https://www.acmicpc.net/problem/2565 */

/*
	��� ���ٱ ����ϸ� ��ƴ�..
	�ݴ�� ����ϸ� �ִ��� ���� �������� ���� �� ������ �����غ��� LIS�� ������ ���̴�.
	�������� �����ϰ� ������ �� �ʿ� ���� LIS�� �����ϸ� ������ �ذ��� �� �ִ� ������.
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