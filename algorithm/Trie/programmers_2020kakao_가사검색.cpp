/* https://programmers.co.kr/learn/courses/30/lessons/60060 */

/*
	매번 가사가 들어올 때마다 새로이 검색하는 건 시간이 오래 걸린다.
	동일한 키워드의 개수를 세는 것을 한 번에 해결해야 한다.
	Trie를 사용해 구현 가능하다.
	'fro??', 'f????'와 같은 꼴의 문자는 Trie를 그대로 적용하면되지만, 
	'???do'와 같은 꼴에는 적용할 수 없는 것처럼 보인다. 아이디어가 필요하다.
	접두사로 '?'가 들어올 때의 검색은 뒤의 문자는 정확하다는 의미를 갖는다.
	'???do'를 '?'기호가 뒤로 가도록 문자열을 뒤집어보면, 'od???'로 Trie를 적용할 수 있다.
	이를 위해 preFixTrie와 postFixTrie로 문제를 해결할 수 있을 것이다.
*/

#include <string>
#include <vector>
using namespace std;

struct FixTrie {
	FixTrie *c[26];
	int cnt;

	FixTrie() {
		for (int i = 0; i < 26; i++) c[i] = NULL;
		cnt = 0;
	}
	void add(const char *str) {
		if (*str == NULL) cnt++;
		else {
			if (c[(*str) % 26] == NULL) c[(*str) % 26] = new FixTrie();
			c[(*str) % 26]->add(str + 1);
			cnt++;
		}
	}
	int finding(const char *str) {
		if (*str == '?' || *str == NULL) return cnt;
		if (c[(*str) % 26] == NULL) return 0;
		return c[*str % 26]->finding(str + 1);
	}
};

FixTrie preft[10001], postft[10001];

void reverse_str(char* dst, const char* src, int size) {
	int i = 0;
	while (i < size) {
		dst[i] = src[size - i - 1];
		i++;
	}
	dst[i] = 0;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int w_size = words.size(), q_size = queries.size();

	char r_str[10001];
	for (int i = 0; i < w_size; i++) {
		int wi_size = words[i].size();
		preft[wi_size].add(words[i].c_str());

		reverse_str(r_str, words[i].c_str(), wi_size);
		postft[wi_size].add(r_str);
	}

	for (int i = 0; i < q_size; i++) {
		int qi_size = queries[i].size();
		if (queries[i][0] == '?') {
			reverse_str(r_str, queries[i].c_str(), qi_size);
			answer.push_back(postft[qi_size].finding(r_str));
		}
		else answer.push_back(preft[qi_size].finding(queries[i].c_str()));
	}

	return answer;
}
