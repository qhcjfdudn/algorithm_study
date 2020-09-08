/* https://www.acmicpc.net/problem/1260 */

/*
	DFS 돌고, BFS 돌자. 순서대로 꺼내는 연산은 정렬을 했지만, 1000 * 1000의 카운팅 정렬이 빠를지
	벡터에 관계 넣고 정렬하는 게 빠를지 모르겠다. 우선 벡터에서 바로 정렬한 것은 0ms로 빨랐다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<int> G[1001];
bool visited[1001];

void init() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> V;
	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(G[i].begin(), G[i].end());
}

void DFS(int num) {
	visited[num] = true;
	cout << num << " ";

	for (int it : G[num])
		if (!visited[it])
			DFS(it);
}

void BFS(int num) {
	visited[num] = false;
	queue<int> Q;
	Q.push(num);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << " ";
		for (int it : G[cur])
			if (visited[it]) {
				Q.push(it);
				visited[it] = false;
			}
	}
}

int main() {
	init();

	DFS(V); cout << '\n';
	BFS(V);
}