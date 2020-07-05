/* https://www.acmicpc.net/problem/5766 */

/*
	플레이어가 얻은 점수와 오름차순 순서대로 정렬한 후,
	동점자를 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Ranking {
	int num, cnt;
	Ranking(int _n = 0, int _c = 0) : num(_n), cnt(_c) {}

	bool operator < (const Ranking &rhs) const {
		if (cnt == rhs.cnt) return num < rhs.num;
		return cnt > rhs.cnt;
	}
};

int N, M;
Ranking player[10001];

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	while (cin >> N >> M) {
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= 10000; i++) player[i] = { i, 0 };
		for (int i = 0; i < N; i++) {
			for (int j = 0, a; j < M; j++) {
				cin >> a;
				player[a].cnt++;
			}
		}

		sort(player + 1, player + 10001);

		int secondScore = player[2].cnt;
		for (int i = 2; i <= 10000; i++) {
			if (secondScore != player[i].cnt) break;
			cout << player[i].num << " ";
		}
		cout << '\n';
	}
}