/* https://programmers.co.kr/learn/courses/30/lessons/42892 */

/*
	트리를 순회하기 위해 트리를 만들어야 하는 문제. 트리의 재귀적인 속성을 이용해서 트리를 만들고, 답을 구했다.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int left, right;
    Node(int _l = -1, int _r = -1) : left(_l), right(_r) {}
};

int N, root;
Node treeNode[10001];

int create_tree(vector<vector<int>>& ni, int s, int e) {
    if (s == e - 1) return ni[s][2];
    if (s == e) return -1;

    int idx = s;
    for (int i = s + 1; i < e; i++)
        if (ni[i][1] > ni[idx][1])
            idx = i;

    treeNode[ni[idx][2]].left = create_tree(ni, s, idx);
    treeNode[ni[idx][2]].right = create_tree(ni, idx + 1, e);

    return ni[idx][2];
}

void findOrder(vector<vector<int>>& ans, int r) {
    ans[0].push_back(r);
    if (treeNode[r].left != -1) findOrder(ans, treeNode[r].left);
    if (treeNode[r].right != -1) findOrder(ans, treeNode[r].right);
    ans[1].push_back(r);
}

void init(vector<vector<int>>& nodeinfo) {
    N = nodeinfo.size();
    for (int i = 0; i < N; i++)
        nodeinfo[i].push_back(i + 1);
    sort(nodeinfo.begin(), nodeinfo.end());

    root = create_tree(nodeinfo, 0, N);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    init(nodeinfo);

    vector<vector<int>> answer(2);
    findOrder(answer, root);

    return answer;
}