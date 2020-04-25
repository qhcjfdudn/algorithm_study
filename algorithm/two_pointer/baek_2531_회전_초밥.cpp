/* https://www.acmicpc.net/problem/2531 */

/*
	�������� ��������. �����ؼ� �Դµ�, �ٸ� �͵�θ� �����ؼ� �Դ� ���� �ƴϴ�.
	���Ŀ��� �����̾� ��Ʈ�� ��� ǥ������ �����ϸ� �ȴ�. ������ ��ⷯ�� ���� ��������.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, d, k, c, belt[30000];
int sushi[3001];

int solve() {
	int ret = 0, cnt = 0;

	for (int i = 0; i < k; i++)
		if (!sushi[belt[i]]++)
			cnt++;

	for (int i = 0; i < N; i++) {
		ret = max(ret, cnt + !sushi[c]);
		if (!--sushi[belt[i]]) cnt--;
		if (!sushi[belt[(i + k) % N]]++) cnt++;
	}

	return ret;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++) cin >> belt[i];

	cout << solve() << '\n';
}
