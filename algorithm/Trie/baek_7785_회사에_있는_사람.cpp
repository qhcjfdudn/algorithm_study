/* https://www.acmicpc.net/problem/7785 */

/*
	�־��� �Է��� ���ڿ��̰�, ���ڿ� �ڷῡ ���� ����, ����, Ž��(������ ����)�� ����
	�ڷᱸ���� �ʿ��ϴ�.

	Trie(Ʈ����)��
	1. �ڷḦ �� ���� O �����ð��� ����, ����, Ž���� �����ϱ� ������
	2. �⺻ ������ Ʈ�������̹Ƿ� ��������� ���� �����Ϳ� ���� ����Ž����
	�����ϴ�. Ư�� ������ ������ ���� �ڷḦ ������ ���� Ž���� ��
	�̷� Ʈ���� Ž�� Ư���� �ڷῡ ���� ������ �ʿ� ���� ���ĵ� ���·� ������ �� 
	�����Ƿ� �����ϴ�.
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