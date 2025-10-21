#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int val = l1->val + l2->val;
        int carry = (val) / 10;
        val = (val) % 10;
        ListNode* newList = new ListNode(val);
        ListNode* lastNode = newList;

        
        ListNode* current_l1 = l1->next;
        ListNode* current_l2 = l2->next;


        while (current_l1 != nullptr && current_l2 != nullptr) {
            val = current_l1->val + current_l2->val + carry;
            carry = (val) / 10;
            val = (val) % 10;
            ListNode* current = new ListNode(val);
            lastNode->next = current;
            lastNode = current;


            current_l1 = current_l1->next;
            current_l2 = current_l2->next;
        }

        while (current_l1 != nullptr) {
            val = current_l1->val + carry;
            carry = (val) / 10;
            val = (val) % 10;
            ListNode* current = new ListNode(val);
            lastNode->next = current;
            lastNode = current;
            current_l1 = current_l1->next;
        }

        while (current_l2 != nullptr) {
            val = current_l2->val + carry;
            carry = (val) / 10;
            val = (val) % 10;
            ListNode* current = new ListNode(val);
            lastNode->next = current;
            lastNode = current;
            current_l2 = current_l2->next;
        }

        if (carry) {
            lastNode->next = new ListNode(carry);
        }

        return newList;
    }
};

int main() {
    Solution solution;

    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3, new ListNode(9, new ListNode(9)))));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(6)));

    ListNode* list = solution.addTwoNumbers(l1, l2);
    while (list != nullptr) {
        cout << list->val;
        if (list->next != nullptr) cout << " -> ";
        list = list->next;
    }
    cout << endl;

    return 0;
}