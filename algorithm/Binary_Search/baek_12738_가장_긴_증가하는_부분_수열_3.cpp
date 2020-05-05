/* https://www.acmicpc.net/problem/12738 */

/*
	LIS�� O(NlgN)�� �ð����⵵�� �ذ��ؾ� �ϴ� ���� �⺻���� ����.
	�׸��� ���� �������� ���� Ž���� ���� �ذ��� �� �ִ�.
	�����ϴ� �κм����� ����鼭,
	�κ� ���� ������ ������ ���� ��ġ�� �����Ǿ��� ��, �κ� ������ ������ �ε����� ���� �ٸ� �� ��
	���� ���� ���� �κ� ������ ������ ���Ѵ�. �̷��� �ϸ� LIS�� �Ǵ� �� ������ ū �ٸ� ���� �κ� ������
	�����ϸ鼭 LIS�� Ư���� �����س��� �� �ִ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, sz;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	vector<int> ret;

	for (int i = 0, num; i < N; i++) {
		cin >> num;
		int index = lower_bound(ret.begin(), ret.end(), num) - ret.begin();
		if (sz == index) ret.push_back(num), sz++;
		else ret[index] = num;
	}

	cout << sz << '\n';
}