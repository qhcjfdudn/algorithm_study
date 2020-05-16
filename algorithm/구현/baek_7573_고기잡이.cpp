/* https://www.acmicpc.net/problem/7573 */

/*
	������ �� ������ �����ϴ� ������, ������ ��� ���� �׹��� �������� ������ �� �ִ�.
	�̷κ��� �׹��� ����� �����ϸ� Ž�� �����ϴ�.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
	int y, x;
	Node(int _y, int _x) : y(_y), x(_x) {}
	bool operator < (const Node &rhs) const {
		return y != rhs.y ? y < rhs.y : x < rhs.x;
	}
};

int N, I, M, ans;
vector<Node> fishes;
map<Node, bool> check;

int main() {
	cin >> N >> I >> M;
	I >>= 1;
	for (int i = 0, y, x; i < M; i++) {
		cin >> y >> x;
		fishes.push_back({ y, x });
	}

	for (int i = 0; i < M; i++) {
		for (int j = i; j < M; j++) {
			int startY = min(fishes[i].y, fishes[j].y);
			int startX = min(fishes[i].x, fishes[j].x);

			for (int k = 1; k < I; k++) {
				int curY = startY + k > N ? N - k : startY;
				int curX = startX + (I - k) > N ? N - (I - k) : startX;
				if (curY < 1 || curX < 1) continue;

				int ret = 0;
				for (int p = 0; p < M; p++) {
					int y = fishes[p].y;
					int x = fishes[p].x;
					if (curY <= y && curY + k >= y &&
						curX <= x && curX + (I - k) >= x)
						ret++;
				}
				ans = max(ans, ret);
			}
		}
	}
	cout << ans << '\n';
}