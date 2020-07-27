/* https://www.acmicpc.net/problem/1166 */

/*
	최대값을 구하기 때문에 이진탐색을 쓸 수 있음을 알면 간단한 문제.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

LL N, L, W, H;

LL cntInnerBoxes(double a) {
	LL cnt = 1;
	cnt *= (LL)(L / a);
	cnt *= (LL)(W / a);
	cnt *= (LL)(H / a);
	return cnt;
}

double solve() {
	double low = 0, high = min(L, min(W, H)), mid;
	for (int i = 0; i < 100; i++) {
		mid = (low + high) / 2;
		if (N <= cntInnerBoxes(mid)) low = mid;
		else high = mid;
	}
	return mid;
}

int main() {
	cin >> N >> L >> W >> H;

	cout.precision(10);
	cout.setf(cout.fixed);
	cout << solve() << '\n';
}