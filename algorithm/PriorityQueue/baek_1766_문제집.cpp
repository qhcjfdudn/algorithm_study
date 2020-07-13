/* https://www.acmicpc.net/problem/1766 */

/*
	문제를 순서대로 푸는 것은 위상정렬로 간단히 해결된다. 그 다음 문제 번호가 낮은 순서대로 푸는 것에서
	우선순위 큐를 도입해 간단히 해결할 수 있다.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, p, q, indegree[32001];
priority_queue<int> pq;
vector<int> vec[32001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p >> q;
		indegree[q]++;
		vec[p].push_back(q);
	}
	for (int i = 1; i <= N; i++)
		if (!indegree[i]) pq.push(-i);

	while (!pq.empty()) {
		p = -pq.top(); pq.pop();
		cout << p << " ";
		for (auto it : vec[p])
			if (!(--indegree[it])) pq.push(-it);
	}
}