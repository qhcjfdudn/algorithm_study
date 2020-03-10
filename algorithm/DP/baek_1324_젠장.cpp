/* https://www.acmicpc.net/problem/1324 */

/*
	���� ���� ���̵� ��� ����, ù°���� �� �� � ����a��
	��°���� �� �� � ���� b�� ���� �����ϴٸ�, �� ������ ������
	�ݺ��������� �ʾƵ� ����� �׻� ����. �� DP�� �� �� �ִ�.
	cache[ù°�� ��� ����][��°�� ��� ����]���� �޸������̼� �����ϴ�.

	������ �̷��� Ǯ ��� �ҽ��� ���� ������. �ٸ� �ҽ��� �����Ͽ�
	�� ȿ�������� ��������.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, first[1000], second[1000], cache[1000][1000];

int DP(int fi, int si, int beforeNum) {
	if (fi == N || si == N) return 0;

	int &ret = cache[fi][si];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = fi; i < N; i++) {
		if (beforeNum >= first[i]) continue;
		for (int j = si; j < N; j++)
			if (first[i] == second[j])
				ret = max(ret, DP(i + 1, j + 1, first[i]) + 1);
	}

	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> first[i];
	for (int i = 0; i < N; i++) cin >> second[i];

	memset(cache[0], -1, sizeof(cache));

	cout << DP(0, 0, -1) << '\n';
}