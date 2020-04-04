/* https://www.acmicpc.net/problem/16975 */

/*
	�迭�� ���� �ϳ��� ���Ͽ� ���� ����ϰ� �Ǹ�, �ð��ʰ��� �߻��� ���̴�.
	���� ���ϴ� 1�� ������ lazy propagation�� ����� ���׸�Ʈ Ʈ���� �����ϸ�
	������ Ǯ �� �ִ�.

	�Ʒ��� Ǯ�̴� lazy propagation�� ������ Ǯ��������, �� �����غ��� ����Ʈ�� ������
	������ �� ������ �� �� �ִ�. ����Ʈ���ε� �� �����غ���.
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