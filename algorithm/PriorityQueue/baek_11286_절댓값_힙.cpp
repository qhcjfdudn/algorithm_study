/* https://www.acmicpc.net/problem/11286 */

/*
	�켱����ť�� �̿��� ������ �ذ�
	���ø��� max heap���� ������ �ֱ� ������, ���� ������ ���ϱ� ���� -1�� ���ϴ�
	�ļ��� �η�����.
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