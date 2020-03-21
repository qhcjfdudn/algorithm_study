/* https://www.acmicpc.net/problem/13505 */

/*
  두 수를 XOR하면서 주어진 수의 개수가 완전 탐색을 하기에는 너무 많기 때문에, Trie 자료구조를 이용한다.
  1. 비트의 특성상 임의의 비트가 1일 때, 그 때의 수는 그보다 하위의 비트가 모두 1이어도 그 값이 작기 때문에,
  탐색 중 이 속성을 이용하여 pruning 할 수 있기 때문이다.
  2. 비트 구간 중 중첩 되는 수(임의의 위치의 0, 1)는 비교할 필요가 없어진다.
  이를 Trie를 사용하면 쉽게 관리할 수 있기 때문에, 연산이 간단해지고 쉬워진다.
*/

#include <iostream>
using namespace std;

int N, maxSum;

struct Trie {
	Trie *next[2];
	Trie() {
		next[0] = next[1] = NULL;
	}

	void add(int num, int pos) {
		if (pos != -1) {
			if (num & (1 << pos)) {
				if (next[1] == NULL) next[1] = new Trie();
				next[1]->add(num, pos - 1);
			}
			else {
				if (next[0] == NULL) next[0] = new Trie();
				next[0]->add(num, pos - 1);
			}
		}
	}
};

void maxXor(Trie &a, Trie &b, int pos, int pSum) {
	if (pos == -1) maxSum = pSum;
	else if ((pSum | ((1 << (pos + 1)) - 1)) > maxSum) { // 탐색 수를 줄이기 위한 낙관적 휴리스틱
    bool checked = false;
    // 1.
		for (int i = 0; i < 2; i++)
			if (a.next[i] != NULL && b.next[(i + 1) % 2] != NULL) {
				maxXor(*a.next[i], *b.next[(i + 1) % 2], pos - 1, pSum | (1 << pos));
        checked = true;
      }
		/* 초기에 잘못 된 판단으로 만들어진 분기문.
    if (!(maxSum & (1 << pos))) 탐색 중 만들어진 maxSum의 현재 pos 비트가 켜져있다면 하위의 계산이 불필요하다고 판단했지만,
                                위의 1.의 탐색 과정 중 i == 1일 때 만들어지는 maxSum의 이전의 비트가 달라질 수가 있다.
                                그렇기 때문에, 만들어질 수 있는 최대값을 계산하지 못하는 경우가 생길 수 있다.
                                따라서 이는 잘못된 분기.
                                현재 재귀 방식의 목적을 그대로 살려 정확한 분기를 만들면 아래와 같다.
    */
    if (!checked) // 정확한 분기의 사용
			for (int i = 0; i < 2; i++)
				if (a.next[i] != NULL && b.next[i] != NULL)
					maxXor(*a.next[i], *b.next[i], pos - 1, pSum);
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	Trie *trie = new Trie();

	for (int i = 0, a; i < N; i++) {
		cin >> a;
		trie->add(a, 29);
	}

	maxXor(*trie, *trie, 29, 0);

	cout << maxSum << '\n';
}
