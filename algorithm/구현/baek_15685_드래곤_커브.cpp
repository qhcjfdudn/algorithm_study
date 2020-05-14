/* https://www.acmicpc.net/problem/15685 */

/*
	드래곤 커브가 이전 움직임으로부터 무조건 1 크게 움직이는 패턴을 찾지 못하면 난감한 문제.
	이를 알고 나면 나머지는 간단한 구현 문제이다.
*/

#include <iostream>
#include <vector>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

int N, ans;
bool board[101][101];

void dragon(int y, int x, int d, int g) {
	vector<int> V(1, d);

	board[y][x] = true;
	y += dy[d], x += dx[d];
	board[y][x] = true;

	while (g--) {
		for (int i = V.size() - 1, nv; i >= 0; i--) {
			nv = (V[i] + 1) % 4;
			y += dy[nv], x += dx[nv];
			board[y][x] = true;
			V.push_back(nv);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0, x, y, d, g; i < N; i++) {
		cin >> x >> y >> d >> g;
		dragon(y, x, d, g);
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (board[i][j] && board[i][j + 1] &&
				board[i + 1][j] && board[i + 1][j + 1])
				ans++;

	cout << ans << '\n';
}