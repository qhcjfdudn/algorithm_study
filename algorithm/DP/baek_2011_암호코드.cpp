/* https://www.acmicpc.net/problem/2011 */

/*
	�־��� �ڵ带 �������� ���ڷ� �ؼ��� �� �ִ� ������ � �� �ڸ��� ���ڴ� ������ ���ڷ� ���ų�,
	�ϳ��� ���ڷ� �� �� �ֱ� �����̴�.
	ex) 17�� ���� 1�� 7�� AG�� ���ų�, Q �ϳ��� �� �� �ִ�.
	
	�׷� 1714�� ���?
	�տ������� �ϳ��� ����, AGAD������, 17�� AG�� ���� Q�� ����, �� �ڴ� 14�� �ȴ�. �̸� ����
	DP�� ���� �������� �� �� �ִ�.
*/

#include <iostream>
#include <cstring>
using namespace std;

int N, cache[5000];
char code[5002];

int DP(int index) {
	if (index == N) return 1;
	if (code[index] == '0') return 0;

	int &ret = cache[index];
	if (ret != -1) return ret;

	ret = DP(index + 1);
	if (index + 1 != N && (code[index] == '1' || (code[index] == '2' && code[index + 1] < '7'))) {
		ret += DP(index + 2);
		ret %= 1000000;
	}
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));

	cin >> code;
	N = strlen(code);

	cout << DP(0) << '\n';
}