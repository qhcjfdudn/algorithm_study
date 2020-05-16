/* https://www.acmicpc.net/problem/2492 */

/*
	지도 위에서 채굴할 사각형을 결정하기에는 지도의 범위가 너무 넓다.
	그러므로 보석이 있는 위치를 기준으로 사각형을 결정하도록 한다.
	이 때, 하나의 사각형의 위치를 찾아내기 위해서,
	임의의 두 보석을 테두리로 사용할 수 있다. 이는 이차원 평면 위에서 임의의 두 점으로부터
	하나의 사각형을 결정할 수 있기 때문이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, T, K;
vector<pair<int, int>> stones;

int solve(int *ansX, int *ansY) {
	int ret = 0;
	for (int i = 0; i < T; i++) {
		for (int j = i; j < T; j++) {
			int startX = min(min(stones[i].first, stones[j].first), N - K);
			int startY = min(min(stones[i].second, stones[j].second), M - K);

			int cnt = 0;
			for (int k = 0; k < T; k++) {
				int x = stones[k].first;
				int y = stones[k].second;

				if (startY <= y && startY + K >= y &&
					startX <= x && startX + K >= x)
					cnt++;
			}
			if (ret < cnt) {
				*ansX = startX;
				*ansY = startY + K;
				ret = cnt;
			}
		}
	}
	return ret;
}

int main() {
	cin >> N >> M >> T >> K;
	for (int i = 0, x, y; i < T; i++) {
		cin >> x >> y;
		stones.push_back({ x, y });
	}

	int ansX, ansY, ans;
	ans = solve(&ansX, &ansY);
	cout << ansX << " " << ansY << '\n' << ans << '\n';
}