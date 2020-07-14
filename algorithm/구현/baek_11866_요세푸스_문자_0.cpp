/* https://www.acmicpc.net/problem/11866 */

/*
	����Ǫ�� ���� ����. ���͵� �̻��ϰ� ����Ʈ�� �̻��ϰ�.. ��� Ǫ�� �� ���� ������??
	heap�� ����ϸ� O(lgN)���� ���ñ�??
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