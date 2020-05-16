/* https://www.acmicpc.net/problem/2492 */

/*
	���� ������ ä���� �簢���� �����ϱ⿡�� ������ ������ �ʹ� �д�.
	�׷��Ƿ� ������ �ִ� ��ġ�� �������� �簢���� �����ϵ��� �Ѵ�.
	�� ��, �ϳ��� �簢���� ��ġ�� ã�Ƴ��� ���ؼ�,
	������ �� ������ �׵θ��� ����� �� �ִ�. �̴� ������ ��� ������ ������ �� �����κ���
	�ϳ��� �簢���� ������ �� �ֱ� �����̴�.
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