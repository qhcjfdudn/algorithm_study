/* https://www.acmicpc.net/problem/14427 */

/*
	������ ���� ���ǰ� ������ �� �̸� ������ ���ϱ� ���ؼ��� �κ��� �迭�� ���� ������ ���� �̸� ���� �����
	���س��� ���� �����ϴ� ����� �� �� �ִ�. �� ��쿡 � ����� ���� ����Ǵ� ���, �̸� �����ϴ� �̸�
	���س��Ҵ� ���� ��� ���� ������ �ؾ� �ϱ� ������, �� ������ �ð����⵵�� �ٿ��� �Ѵ�.
	���׸�Ʈ Ʈ���� �̿� ���� ���̴�.
	�κ��� �迭�� ��쿡 �־��� ��� �κ��� �迭 ��ü�� ���� ���� ����ؾ��� �� �ֱ� ������, �ð����⵵�� ���� �ð��̴�.
	���׸�Ʈ Ʈ���� ���, � ��尡 ���� �ٲ�� �̸� �����ϴ� ������ ������ ������ �����ϸ� �Ǳ� ������,
	�ð����⵵�� �α� �ð��� �ȴ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int v, idx;
	Node(int _v = 1e9 + 1, int _idx = 0) : v(_v), idx(_idx) {}
	bool operator < (const Node &rhs) const {
		if (v == rhs.v) return idx < rhs.idx;
		return v < rhs.v;
	}
};

int N, M, A[100001];
Node seg[1 << 18];

Node update(int cur_idx, int idx, int left, int right) {
	if (cur_idx < left || cur_idx > right) return seg[idx];
	if (left == right)
		return seg[idx] = Node(A[cur_idx], cur_idx);

	int mid = (left + right) / 2;
	return seg[idx] = min(update(cur_idx, idx * 2, left, mid),
		update(cur_idx, idx * 2 + 1, mid + 1, right));
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		update(i, 1, 1, N);
	}

	cin >> M;
	for (int i = 0, q, a, b; i < M; i++) {
		cin >> q;
		if (q == 1) {
			cin >> a >> b;
			A[a] = b;
			update(a, 1, 1, N);
		}
		else cout << seg[1].idx << '\n';
	}
}