/* https://www.acmicpc.net/problem/11866 */

/*
	조세푸스 수열 문제. 벡터도 이상하고 리스트도 이상하고.. 어떻게 푸는 게 제일 나을까??
	heap을 사용하면 O(lgN)으로 나올까??
*/

#include <cstdio>
#include <vector>

int N, K;
std::vector<int> seq;

int main() {
	scanf("%d %d", &N, &K);
	seq.resize(N);

	for (int i = 0; i < N; i++)
		seq[i] = i + 1;

	printf("<");
	for (int idx = -1; N--;) {
		idx += K;
		idx %= N + 1;
		printf("%d", seq[idx]);
		seq.erase(seq.begin() + idx);
		idx--;
		if (N) printf(", ");
	}
	printf(">");
}