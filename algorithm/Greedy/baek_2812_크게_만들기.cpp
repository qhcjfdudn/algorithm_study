/* https://www.acmicpc.net/problem/2812 */

/*
	�տ������� �־��� ���� ���鼭 �׸����ϰ� �ذ� ����
	ret, src�� ���� ��, ret�� ������ ���� src�� �̹��� �� ���� ���ϸ鼭,
	1. ret�� ���� ���ų� ũ�ٸ� src�� ���ϴ� ���� �̾���δ�.
	2. ret�� ���� �۴ٸ� ret�� ���� ���� ������ K�� ���ҽ�Ų��.
	�� �۾��� �ݺ��ϴ� ������ �ذ� ����. 2���� ���ܵ� �ݵ�� ó�����ش�.
	1. ret�� ���� ����� �� K���� 0�� �� ��
	2. ret�� ���� ��� ������µ�, K���� ���� ���� ��
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