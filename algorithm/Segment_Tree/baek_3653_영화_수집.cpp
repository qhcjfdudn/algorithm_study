/* https://www.acmicpc.net/problem/3653 */

/*
	�迭�� Ž���Ͽ� ������ �ϳ��� ���� ������ �ð��ʰ���.
	������ ������ �� ���� ���´ٸ�, ���� ������ ������ �������� ��ġ����� ����������.
	���׸�Ʈ Ʈ���� �̿�����. ���� ������ �ٽ� ��� ����, ���� ���� ��ġ�� �ִ� ��������
	�� ���� ���� ���ο� ������ �߰��Ǵ� �Ͱ� ����. ���׸�Ʈ Ʈ���� �ε����� �ϳ��� �÷�����
	����� �ϸ� ���� ���� �� �ִ�. �� �̴� ���ӵ� ������ ���� ���ϴ� �Ͱ� ���Ƽ�, ����Ʈ����
	�̿��� �� �ִ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int C, N, M;
int fenwick[200001], no2pos[100001];

void update(int pos, int delta) {
	while (pos <= 200000) {
		fenwick[pos] += delta;
		pos += pos & (-pos);
	}
}

int pSum(int pos) {
	int ret = 0;
	while (pos > 0) {
		ret += fenwick[pos];
		pos &= pos - 1;
	}
	return ret;
}

void init() {
	memset(fenwick, 0, sizeof(fenwick));
	for (int i = 1; i <= N; i++) {
		no2pos[i] = N + 1 - i;
		update(no2pos[i], 1);
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		init();
		for (int i = 1, a; i <= M; i++) {
			cin >> a;
			cout << N - pSum(no2pos[a]) << " ";

			update(no2pos[a], -1);
			no2pos[a] = N + i;
			update(no2pos[a], 1);
		}
		cout << '\n';
	}
}