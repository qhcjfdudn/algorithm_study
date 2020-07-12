/* https://www.acmicpc.net/problem/2903 */

/*
	전체 점은 한 변의 제곱이기에 한 변에 포함되는 점의 개수를 알면 된다.
	조건을 통해 간단히 점의 개수를 등차수열로 구할 수 있다.
*/

#include <cstdio>

int N, ret = 2;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) ret += ret - 1;
	printf("%d\n", ret * ret);
}