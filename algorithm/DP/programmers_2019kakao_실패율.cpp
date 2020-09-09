/* https://programmers.co.kr/learn/courses/30/lessons/42889 */

/*
    부분합을 통해 현재 스테이지 이상으로 도달한 인원을 구해 간단히 정렬로 해결.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long dino, numer, stage;
    Node(int _d, int _n, int _s) : dino(_d), numer(_n), stage(_s) {}
    bool operator < (const Node& rhs) const {
        if (numer * rhs.dino == rhs.numer * dino) return stage < rhs.stage;
        return numer * rhs.dino > rhs.numer * dino;
    }
};

int stageCnt[502], pSum[503];

void init(int N, vector<int>& stages) {
    for (int it : stages) stageCnt[it]++;
    for (int i = N + 1; i > 0; i--)
        pSum[i] = pSum[i + 1] + stageCnt[i];
}

vector<int> solution(int N, vector<int> stages) {
    init(N, stages);

    vector<int> answer;
    vector<Node> failureList;
    for (int i = 1; i <= N; i++)
        failureList.push_back(Node({ pSum[i], stageCnt[i], i }));

    sort(failureList.begin(), failureList.end());
    for (Node it : failureList)
        answer.push_back(it.stage);

    return answer;
}