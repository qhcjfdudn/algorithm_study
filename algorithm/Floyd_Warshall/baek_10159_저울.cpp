/* https://www.acmicpc.net/problem/10159 */

/*
	모든 저울의 관계를 확인한다고 생각해보자. 플로이드 와샬 알고리즘을 사용한다.
	입력으로부터 나보다 무거우면 양수, 가벼우면 음수를 부여한다고 가정했을 때 아래를 예상할 수 있다.
	[i][[j] : [i][k], [k][j]가 같은 방향이라면 부호가 같을 것이다.
	따라서, [i][k] * [k][j] > 0일 경우에, 두 무게 관계는 확정된다.
*/

#include <iostream>
using namespace std;

int N, M, dist[101][101];

void solve() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (dist[i][k] * dist[k][j] > 0)
					dist[i][j] = dist[i][k] + dist[k][j];
}

void printAns() {
	for (int i = 1, cnt; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++)
			if (dist[i][j] == 0)
				cnt++;

		cout << cnt - 1 << '\n';
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = -1;
	}

	solve();

	printAns();
}