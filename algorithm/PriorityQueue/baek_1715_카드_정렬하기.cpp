/* https://www.acmicpc.net/problem/1715 */

/*
	�ּ������� ���ϱ� ���ؼ�, ī�幭���� ���� ���� �ͺ��� ���ؾ� �ϴ� ����
	�����ؾ� �Ѵ�.

*/

#include <iostream>
#include <queue>
using namespace std;

int N, num;
priority_queue<int> PQ;

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int i = 0, num; i < N; i++) {
		cin >> num;
		PQ.push(-num);
	}
}

int solve() {
	int ret = 0;
	for (int i = 1, a, b; i < N; i++) {
		a = PQ.top(); PQ.pop();
		b = PQ.top(); PQ.pop();
		ret += a + b;
		PQ.push(a + b);
	}
	return -ret;
}

int main() {
	init();

	cout << solve() << '\n';
}