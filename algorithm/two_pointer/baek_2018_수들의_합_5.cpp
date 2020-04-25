/* https://www.acmicpc.net/problem/2018 */

/*
	투 포인터를 사용하여 연속합의 개수를 셀 수 있다.
	또는 수학적으로 연속합이 될 수 있는 경우만 세어줄 수도 있다.
*/

#include <iostream>
using namespace std;

int N;

int solve() {
	int ret = 0, pSum = 0, l = 1, r = 1;
	while (r <= N || pSum >= N) {
		if (pSum < N) pSum += r++;
		else {
			if (pSum == N) ret++;
			pSum -= l++;
		}
	}
	return ret;
}

int main() {
	cin >> N;

	cout << solve() << '\n';
}