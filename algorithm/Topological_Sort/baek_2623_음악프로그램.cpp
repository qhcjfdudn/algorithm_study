/* https://www.acmicpc.net/problem/2623 */

/*
	간단한 위상정렬. indegree를 구하고 싸이클 판단을 조심하자.
*/

#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

int N, M, indegree[1001] = {};
vector<int> singer[1001];
queue<int> Q;
int seq[1000], cnt = 0;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int PD, first;
		cin >> PD >> first;
		for (int j = 1; j < PD; j++) {
			int num;
			cin >> num;
			indegree[num]++;
			singer[first].push_back(num);
			first = num;
		}
	}

	for (int i = 1; i < N + 1; i++) if (!indegree[i]) Q.push(i);

	while (!Q.empty()) {
		int n = Q.front(); Q.pop();
		seq[cnt++] = n;
		for (auto &it : singer[n]) {
			indegree[it]--;
			if (!indegree[it]) Q.push(it);
		}
	}
	for (int i = 1; i < N + 1; i++) {
		if (indegree[i]) {
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i < N; i++) printf("%d\n", seq[i]);
}