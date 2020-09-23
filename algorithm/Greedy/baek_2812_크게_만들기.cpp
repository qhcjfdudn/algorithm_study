/* https://www.acmicpc.net/problem/2812 */

/*
	앞에서부터 주어진 수를 보면서 그리디하게 해결 가능
	ret, src가 있을 때, ret의 마지막 수와 src의 이번에 볼 수를 비교하면서,
	1. ret의 수가 같거나 크다면 src의 비교하는 수를 이어붙인다.
	2. ret의 수가 작다면 ret의 작은 수를 버리고 K를 감소시킨다.
	이 작업을 반복하는 것으로 해결 가능. 2가지 예외도 반드시 처리해준다.
	1. ret의 수를 만드는 중 K값이 0이 될 때
	2. ret의 수를 모두 만들었는데, K값이 남아 있을 때
*/

#include <iostream>
using namespace std;

int N, K, sz;
char src[500001];

void init() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> src;
	sz = 1;
}

void solve() {
	for (int i = 1; i < N; i++) {
		while (K && sz && src[sz - 1] < src[i]) {
			sz--;
			K--;
		}
		src[sz++] = src[i];
	}
	sz -= K;
	src[sz] = 0;
}

int main() {
	init();
	solve();
	cout << src << '\n';
}