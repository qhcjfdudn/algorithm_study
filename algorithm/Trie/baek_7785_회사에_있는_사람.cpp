/* https://www.acmicpc.net/problem/7785 */

/*
	주어진 입력이 문자열이고, 문자열 자료에 대한 삽입, 삭제, 탐색(사전의 역순)에 관한
	자료구조가 필요하다.

	Trie(트라이)는
	1. 자료를 한 번의 O 선형시간에 삽입, 삭제, 탐색이 가능하기 때문에
	2. 기본 구조가 트리형태이므로 재귀적으로 내부 데이터에 대해 완전탐색이
	가능하다. 특히 사전의 역순과 같이 자료를 순서에 따라 탐색할 때
	이런 트리의 탐색 특성은 자료에 대해 정렬할 필요 없이 정렬된 형태로 접근할 수 
	있으므로 유용하다.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int str2int(char a) {
	return a < 91 ? 116 - a : 122 - a;
}

string ans = "", ret = "";

struct Trie {
	Trie *next[52];
	int cnt[52];
	bool fin;

	Trie() : fin(false) {
		memset(next, 0, sizeof(next));
		memset(cnt, 0, sizeof(cnt));
	}

	void add(const char *str) {
		int idx = str2int(*str);
		if (*str == NULL) fin = true;
		else {
			if (next[idx] == NULL) next[idx] = new Trie();
			cnt[idx]++;
			next[idx]->add(str + 1);
		}
	}

	void del(const char *str) {
		if (*str == NULL) return;

		int idx = str2int(*str);
		next[idx]->del(str + 1);

		if (--cnt[idx] == 0) {
			delete next[idx];
			next[idx] = NULL;
		}
	}

	void print() {
		for (int i = 0; i < 26; i++)
			if (next[i] != NULL) {
				ans += (char)(122 - i);
				next[i]->print();
				ans.pop_back();
			}

		for (int i = 26; i < 52; i++) {
			if (next[i] != NULL) {
				ans += (char)(116 - i);
				next[i]->print();
				ans.pop_back();
			}
		}
		if (fin) {
			ret += ans;
			ret += '\n';
		}
	}
};

int N;
Trie trie;
string name, state;

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> state;
		if (state.compare("enter") == 0)
			trie.add(name.c_str());
		else trie.del(name.c_str());
	}

	trie.print();

	cout << ret;
}