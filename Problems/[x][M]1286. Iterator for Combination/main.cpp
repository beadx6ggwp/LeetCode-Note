#include <bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/iterator-for-combination/solution/dfs-sou-suo-mei-yi-chong-ke-neng-de-qing-kuang-lei/

class CombinationIterator {
   public:
    CombinationIterator(string characters, int combinationLength) {}

    string next() {}

    bool hasNext() {}
};

// (abc,2) =>ab, ac, bc
vector<string> getStr(string str, int len) {
    vector<string> ans;
    for (int i = 0; i < str.size(); i++) {
        string s = "";
        for (int j = i; j < str.size(); j++) {
            
        }
    }
}

int main() {
    cout << "test"
         << "\n";
    return 0;
}