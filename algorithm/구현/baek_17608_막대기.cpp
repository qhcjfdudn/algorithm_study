/* https://www.acmicpc.net/problem/17608 */

/*
	간단한 스택 문제. 새로운 값이 스택에 추가될 때, 나보다 작거나 같은 값은 스택에서 뽑아낸다.
	스택에 남아 있는 것들이 답.
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