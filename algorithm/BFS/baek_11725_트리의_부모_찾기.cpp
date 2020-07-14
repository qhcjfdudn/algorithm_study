/* https://www.acmicpc.net/problem/11725 */

/*
	트리의 특성을 이용해 스택으로 풀 수도 있고, 큐로 풀어도 되는 기본적인 탐색 문제.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, parent[100001];
vector<int> edge[100001];

void make_parent() {
	queue<int> Q;
	Q.push(1);
	parent[1] = -1;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		for (auto it : edge[cur]) {
			if (parent[it]) continue;
			parent[it] = cur;
			Q.push(it);
		}
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int i = 1, a, b; i < N; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	make_parent();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}