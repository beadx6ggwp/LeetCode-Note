#include <bits/stdc++.h>
using namespace std;

// 關鍵字: trie樹
/*
題目指的是當收到一個letter的時候，查看最近收到的letter流的末尾是不是存在指定的單詞
例如收到query('a'), query('b'), query('c')之後
letter流就是"abc", 我們只需要檢測["c","bc","abc"]，並去word查看是否有指定單詞。
*/

class StreamChecker {
    map<char, int> mp;

   public:
    StreamChecker(vector<string>& words) {
        for (auto word : words) {
            for (auto c : word) {
                mp[c]++;
            }
        }
    }

    bool query(char letter) {
        if (mp[letter] != 0) return true;
        return false;
    }
};

int main() {
    vector<string> words1 = {"cd", "f", "kl"};
    StreamChecker* streamChecker = new StreamChecker(words1);

    vector<char> check1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    for (auto c : check1) {
        cout << c << ":" << streamChecker->query(c) << "\n";
    }
    streamChecker->query('a');  // return False
    streamChecker->query('b');  // return False
    streamChecker->query('c');  // return False
    streamChecker->query('d');  // return True, because 'cd' is in the wordlist
    streamChecker->query('e');  // return False
    streamChecker->query('f');  // return True, because 'f' is in the wordlist
    streamChecker->query('g');  // return False
    streamChecker->query('h');  // return False
    streamChecker->query('i');  // return False
    streamChecker->query('j');  // return False
    streamChecker->query('k');  // return False
    streamChecker->query('l');  // return True, because 'kl' is in the wordlist
    cout << "test"
         << "\n";
    return 0;
}