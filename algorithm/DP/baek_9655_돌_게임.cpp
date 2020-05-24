/* https://www.acmicpc.net/problem/9655 */

/*
	'�Ϻ��ϰ� ������ �Ѵ�'�� ǥ���� �Ǽ� ���� ������ �Ѵٴ� ��. �̴� ������ ���¿��� 
	���� �̱� �� �ִ� �����θ� ���� ���� �����Ѵٴ� �ǹ��̴�.
	�̴� ���� ���� ���� � ������ �����ؿԵ� ��� ���� ���� N��ŭ�� ���� �ִٸ�,
	�� ���д� ���� �� ������ ���Ѵ�. �̿� DP�� ������ �� �ִ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, cache[1001];

int DP(int cnt) {
	if (cnt <= 0) return cnt < 0 ? 1 : -1;
	if (cache[cnt]) return cache[cnt];

	return cache[cnt] = (-1) * min(DP(cnt - 1), DP(cnt - 3));
}

int main() {
	cin >> N;
	cout << (DP(N) == 1 ? "SK\n" : "CY\n");
}