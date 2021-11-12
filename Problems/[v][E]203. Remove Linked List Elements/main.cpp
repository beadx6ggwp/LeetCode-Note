#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* prev = dummy;
        while (head) {
            if (head->val == val) {
                prev->next = head->next;
            } else {
                prev = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};

void pln(string s) { cout << s << "\n"; }

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
    ListNode* ans1 = Solution().removeElements(list1, 6);
    cout << "test3"
         << "\n";
    return 0;
}