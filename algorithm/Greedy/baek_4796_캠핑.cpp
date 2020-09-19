/* https://www.acmicpc.net/problem/4796 */

/*
	�־��� �����κ��� ������ ��� ����!
*/

#include <iostream>
#include <algorithm>
using namespace std;

int L, P, V;

void preprocess() {
	cin.sync_with_stdio(0); cin.tie(0);
}

void init() {
	cin >> L >> P >> V;
}

int solve() {
	return V / P * L + min((V % P), L);
}

int main() {
	preprocess();
	for (int c = 1; ; c++) {
		init();
		if (L == 0) break;
		cout << "Case " << c << ": " << solve() << '\n';
	}
}