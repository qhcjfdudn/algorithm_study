/* https://www.acmicpc.net/problem/17608 */

/*
	������ ���� ����. ���ο� ���� ���ÿ� �߰��� ��, ������ �۰ų� ���� ���� ���ÿ��� �̾Ƴ���.
	���ÿ� ���� �ִ� �͵��� ��.
*/

#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> ST;

int main() {
	cin >> N;
	for (int i = 0, a; i < N; i++) {
		cin >> a;
		while (!ST.empty()) {
			if (ST.top() <= a) ST.pop();
			else break;
		}
		ST.push(a);
	}
	cout << ST.size() << '\n';
}