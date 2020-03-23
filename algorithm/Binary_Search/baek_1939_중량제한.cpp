/* https://www.acmicpc.net/problem/1939 */

/*
	두 가지 풀이가 가능하다.
	1. 직관적으로 다익스트라를 떠올릴 수 있다.
	출발지점으로부터 다음 지점으로 이동할 때, 중량값을 지정해가면서 구해나갈 수 있다.
	2. 이진탐색으로 중량을 제한하고, bfs로 중량을 매길 수 있는지 확인 가능하다.

	아래는 이진탐색과 BFS를 이용한 풀이이다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
	int v, dist;
	Node(int _v, int _d) : v(_v), dist(_d) {}
};

int N, M, S, E;
vector<Node> edge[10001];
bool visited[10001];

bool BFS(int lim) {
	queue<int> Q;
	Q.push(S);

	memset(visited, 0, sizeof(visited));
	visited[S] = true;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for (auto it : edge[cur]) {
			if (visited[it.v]) continue;

			if (it.dist >= lim) {
				if (it.v == E) return true;
				Q.push(it.v);
				visited[it.v] = true;
			}
		}
	}

	return false;
}

int solve() {
	int l = 1, r = 1e9;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (BFS(mid)) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	cin >> S >> E;

	cout << solve() << '\n';
}