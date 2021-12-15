#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void print(string s) { cout << s << "\n"; }

void appendNode(ListNode** node, int val) {
    // add node to last, if node is nullptr then create a new node
    ListNode* newNode = new ListNode(val);
    ListNode* last = *node;
    if (last == nullptr) {
        *node = newNode;
    } else {
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }
}

ListNode* createList(vector<int> nums) {
    ListNode* head = nullptr;
    for (auto n : nums) {
        appendNode(&head, n);
    }
    return head;
}

int main() {
    vector<int> in1 = {1, 2, 6, 3, 4, 5, 6};
    ListNode* list1 = createList(in1);
    cout << "test3"
         << "\n";
    return 0;
}