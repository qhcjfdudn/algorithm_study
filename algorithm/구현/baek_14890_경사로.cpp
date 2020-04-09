/* https://www.acmicpc.net/problem/14890 */

/*
	구현 문제.
	한 줄 한 줄 경사로가 설치 가능한지 불가능한지 판단할 수 있다.
	경사로를 설치하면서 발생할 수 있는 경우들을 나누어 설치해보자.
	1. 기존의 높이에서 위로 높아지는 경우.(/)
	2. 기존의 높이에서 아래로 낮아지는 경우.(\)
		1. 다음 방향이 다시 낮아지는 경우.(\)
		2. 다음 방향이 높아지는 경우.(\  /)

	위의 경우에서 1.은 이전의 상태를 기억할 필요가 없어 구현이 가장 간단하다.
	2.는 낮아진 상태를 기억해야 한다. 이유는 2.2.를 위해서이다.
		2.1.은 1.과 같은 이유에서 이전의 상태를 기억할 필요가 없다.
		2.2.에서는 높이가 낮아졌다가 다시 올라가는 경우에, 경사로를 2개 설치해야 함을 의미하므로,
		설치해야 하는 길이가 1., 2.1.에 비해서 경사로의 길이 만큼 더 길어야 함을 알 수 있다.

	예외적으로는 경사로의 가장 시작지점과 끝지점이 있고, 이 부분까지 잘 생각하여 처리하면 쉽게 해결할 수 있다.
*/

#include <iostream>
#include <cmath>
using namespace std;

int N, L, board[100][100];

int solve(int cy, int dy, int cx, int dx) {
	int cnt = 1, dir = 0; // dir -1:내리막, 1:오르막
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