/* https://www.acmicpc.net/problem/2903 */

/*
	��ü ���� �� ���� �����̱⿡ �� ���� ���ԵǴ� ���� ������ �˸� �ȴ�.
	������ ���� ������ ���� ������ ���������� ���� �� �ִ�.
*/

#include <cstdio>

int N, ret = 2;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) ret += ret - 1;
	printf("%d\n", ret * ret);
}