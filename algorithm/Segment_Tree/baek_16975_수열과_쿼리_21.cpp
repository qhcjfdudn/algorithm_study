/* https://www.acmicpc.net/problem/16975 */

/*
	배열에 수를 하나씩 더하여 값을 출력하게 되면, 시간초과가 발생할 것이다.
	값을 더하는 1번 연산을 lazy propagation이 적용된 세그먼트 트리로 구현하면
	문제를 풀 수 있다.

	아래의 풀이는 lazy propagation을 적용한 풀이이지만, 잘 생각해보면 펜윅트리 만으로
	구현할 수 있음을 알 수 있다. 펜윅트리로도 꼭 구현해보자.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int N, M;
LL A[100001], lazy[1 << 18];

void seg_update(int n_s, int n_e, int cur, int s, int e, int k) {
	if (e < n_s || n_e < s) return;
	if (n_s <= s && e <= n_e) {
		lazy[cur] += k;
		return;
	}

	int mid = (s + e) / 2;
	seg_update(n_s, n_e, cur * 2, s, mid, k);
	seg_update(n_s, n_e, cur * 2 + 1, mid + 1, e, k);
}

LL seg_find(int cur, int s, int e, int v, LL lazy_v) {
	if (s == v && e == v) return A[v] + lazy_v + lazy[cur];
	if (e < v || v < s) return 0;

	int mid = (s + e) / 2;
	LL nv = lazy_v + lazy[cur];
	return seg_find(cur * 2, s, mid, v, nv) + seg_find(cur * 2 + 1, mid + 1, e, v, nv);
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	cin >> M;
	for (int m = 0, op, i, j, k; m < M; m++) {
		cin >> op;
		if (op == 1) {
			cin >> i >> j >> k;
			seg_update(i, j, 1, 1, N, k);
		}
		else {
			cin >> k;
			cout << seg_find(1, 1, N, k, 0) << '\n';
		}
	}
}