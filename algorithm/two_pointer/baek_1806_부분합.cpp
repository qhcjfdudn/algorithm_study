/* https://www.acmicpc.net/problem/1806 */

/*
	� �κ� ������ ���� S�� ������ �ִٰ� ����. �� ���Ҵ� �ڿ����̴�.
	�� �κ� �������� ���� �Ǵ� �����ʿ� � ���� �����ָ� �� ���� �κ� ������ ���� S���� �۴�.
	�� ���� �Ǵ� �����ʿ� � ���� �����ָ� �� ���� S���� ũ�� �ȴ�.
	�� ��ü �κ� ������ ���ʿ������� ���������� �� ���� �����ذ��� ����ϴ� ���� S���� Ŀ����
	���ʿ������� �������ָ鼭 �κ� ������ �����س����� ���� ���� �� �ִ�.
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, S, ans = 100000;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	deque<int> DQ;

	cin >> N >> S;

	for (int i = 0, num, pSum = 0; i < N; i++) {
		cin >> num;
		pSum += num;
		DQ.push_back(num);
		while (pSum >= S) {
			ans = min(ans, (int)DQ.size());
			pSum -= DQ.front(); DQ.pop_front();
		}
	}
	if (ans == 100000) ans = 0;

	cout << ans << '\n';
}