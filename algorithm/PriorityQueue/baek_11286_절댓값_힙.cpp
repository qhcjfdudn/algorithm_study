/* https://www.acmicpc.net/problem/11286 */

/*
	우선순위큐를 이용해 간단히 해결
	템플릿은 max heap으로 구현돼 있기 때문에, 작은 값으로 비교하기 위해 -1을 곱하는
	꼼수를 부려보자.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, num;
priority_queue<pair<int, int>> PQ;

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
}

void solve() {
	while (N--) {
		cin >> num;
		if (num) {
			int n = min(num, -num);
			PQ.push({ n, -num });
		}
		else {
			if (PQ.empty()) cout << 0 << '\n';
			else {
				pair<int, int> v = PQ.top(); PQ.pop();
				cout << -v.second << '\n';
			}
		}
	}
}

int main() {
	init();

	solve();
}