// 二分图解法：O(N), 264ms

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 2e5 + 26 + 1;

vector<int> nexts[N]; // 邻接表
bool visit[N];

// 建立双向边
void buildEdge (int u, int v) {
    nexts[u].push_back(v);
    nexts[v].push_back(u);
}

// 深搜（着色）
void dfs (int i) {
    visit[i] = true;
    for (auto j : nexts[i]) {
        if (!visit[j]) {
            dfs(j);
        }
    }
}

int main () {
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (auto ch : s) {
            buildEdge(i, ch - 'a' + n); // 单词 <==> 字符
        }
    }

    int res = 0;
    for (int i = 0; i < 26; ++i) {
        if (!visit[i] && !nexts[i].empty()) { // 存在该字符、并且还没被遍历过 => 从它开始遍历
            dfs(i);
            ++res;
        }
    }
    cout << res << endl;

    return 0;
}