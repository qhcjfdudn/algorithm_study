/* https://www.acmicpc.net/problem/1927 */

/*
	우선순위 큐를 사용한 간단한 문제. 직접 구현해서 풀어보자!
*/

#include <cstdio>
using namespace std;

void swap(int* p, int* q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}

struct MinPQ {
	int arr[100001];
	int size;

	MinPQ() { arr[0] = size = 0; }
	void push(int num) {
		arr[++size] = num;
		int pos = size;

		while (pos > 1) {
			if (arr[pos] >= arr[pos / 2]) break;
			swap(&arr[pos], &arr[pos / 2]);
			pos /= 2;
		}
	}
	int pop() {
		if (!size) return 0;

		int ret = arr[1];
		arr[1] = arr[size--];
		int cur = 1;
		while ((cur * 2) <= size) {
			int l = arr[cur * 2];
			int r = l + 1;
			if ((cur * 2 + 1) <= size) r = arr[cur * 2 + 1];
			int minV = l <= r ? l : r;

			if (minV >= arr[cur]) break;
			if (l == minV) {
				swap(&arr[cur], &arr[cur * 2]);
				cur *= 2;
			}
			else {
				swap(&arr[cur], &arr[cur * 2 + 1]);
				cur = cur * 2 + 1;
			}
		}
		return ret;
	}
};

MinPQ pq;
int N;

int main() {
	scanf("%d", &N);

	for (int i = 0, num; i < N; i++) {
		scanf("%d", &num);

		if (num) pq.push(num);
		else printf("%d\n", pq.pop());
	}
}