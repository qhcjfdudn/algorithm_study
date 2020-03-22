/* https://www.acmicpc.net/problem/1939 */

/*
	두 가지 풀이가 가능하다.
	1. 직관적으로 다익스트라를 떠올릴 수 있다.
	출발지점으로부터 다음 지점으로 이동할 때, 중량값을 지정해가면서 구해나갈 수 있다.
	2. 이진탐색으로 중량을 제한하고, bfs로 중량을 매길 수 있는지 확인 가능하다.

	아래는 다익스트라를 이용한 풀이이다.
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int v, dist;
	Node(int _v, int _d) : v(_v), dist(_d) {}
	bool operator < (const Node &rhs) const {
		return dist < rhs.dist;
	}
};

int N, M, s, e;
vector<Node> edge[10001];
bool visited[10001];

int solve() {
	priority_queue<Node> PQ;
	for (auto it : edge[s])
		PQ.push(it);

	while (!PQ.empty()) {
		Node cur = PQ.top(); PQ.pop();
		if (cur.v == e) return cur.dist;
		if (visited[cur.v]) continue;

		visited[cur.v] = true;

		for (auto it : edge[cur.v]) {
			if (visited[it.v]) continue;
			if (it.dist < cur.dist) PQ.push(it);
			else PQ.push({ it.v, cur.dist });
		}
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}
	cin >> s >> e;

	cout << solve() << '\n';
}
