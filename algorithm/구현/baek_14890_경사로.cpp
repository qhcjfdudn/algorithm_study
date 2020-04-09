/* https://www.acmicpc.net/problem/14890 */

/*
	���� ����.
	�� �� �� �� ���ΰ� ��ġ �������� �Ұ������� �Ǵ��� �� �ִ�.
	���θ� ��ġ�ϸ鼭 �߻��� �� �ִ� ������ ������ ��ġ�غ���.
	1. ������ ���̿��� ���� �������� ���.(/)
	2. ������ ���̿��� �Ʒ��� �������� ���.(\)
		1. ���� ������ �ٽ� �������� ���.(\)
		2. ���� ������ �������� ���.(\  /)

	���� ��쿡�� 1.�� ������ ���¸� ����� �ʿ䰡 ���� ������ ���� �����ϴ�.
	2.�� ������ ���¸� ����ؾ� �Ѵ�. ������ 2.2.�� ���ؼ��̴�.
		2.1.�� 1.�� ���� �������� ������ ���¸� ����� �ʿ䰡 ����.
		2.2.������ ���̰� �������ٰ� �ٽ� �ö󰡴� ��쿡, ���θ� 2�� ��ġ�ؾ� ���� �ǹ��ϹǷ�,
		��ġ�ؾ� �ϴ� ���̰� 1., 2.1.�� ���ؼ� ������ ���� ��ŭ �� ���� ���� �� �� �ִ�.

	���������δ� ������ ���� ���������� �������� �ְ�, �� �κб��� �� �����Ͽ� ó���ϸ� ���� �ذ��� �� �ִ�.
*/

#include <iostream>
#include <cmath>
using namespace std;

int N, L, board[100][100];

int solve(int cy, int dy, int cx, int dx) {
	int cnt = 1, dir = 0; // dir -1:������, 1:������
	for (int i = 1; i < N; i++, cy += dy, cx += dx) {
		int ny = cy + dy, nx = cx + dx;
		if (abs(board[ny][nx] - board[cy][cx]) > 1) return 0;
		if (board[ny][nx] == board[cy][cx]) cnt++;
		else {
			if (dir == -1 && cnt < L) return 0;
			if (board[ny][nx] - board[cy][cx] == 1) {
				if (dir == -1) {
					if (cnt < 2 * L) return 0;
					cnt = 1;
					dir = 1;
				}
				else {
					if (cnt < L) return 0;
					cnt = 1;
					dir = 1;
				}
			}
			else {
				dir = -1;
				cnt = 1;
			}
		}
	}
	return dir >= 0 ? 1 : cnt < L ? 0 : 1;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer += solve(i, 0, 0, 1) + solve(0, 1, i, 0);

	cout << answer << '\n';
}