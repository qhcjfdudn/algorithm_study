/* https://www.acmicpc.net/problem/1766 */

/*
	������ ������� Ǫ�� ���� �������ķ� ������ �ذ�ȴ�. �� ���� ���� ��ȣ�� ���� ������� Ǫ�� �Ϳ���
	�켱���� ť�� ������ ������ �ذ��� �� �ִ�.
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