/* https://www.acmicpc.net/problem/1260 */

/*
	DFS ����, BFS ����. ������� ������ ������ ������ ������, 1000 * 1000�� ī���� ������ ������
	���Ϳ� ���� �ְ� �����ϴ� �� ������ �𸣰ڴ�. �켱 ���Ϳ��� �ٷ� ������ ���� 0ms�� ������.
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