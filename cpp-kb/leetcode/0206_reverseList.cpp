#include "Problems.h"

using namespace std;

//https://leetcode.com/problems/reverse-linked-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        ListNode* next = nullptr;
        while(head) {
            node = head;
            head = head->next;
            node->next = next;
            next = node;
        }
        return node;
    }

    void print(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout <<  endl;
    }
};


int main()
{
    cout << "begin"<< endl;
    ListNode node5(5);
    ListNode node4(4,&node5);
    ListNode node3(3,&node4);
    ListNode node2(2,&node3);
    ListNode node1(1,&node2);
    Solution sol;

    sol.print(&node1);
    auto res = sol.reverseList(&node1);
    sol.print(res);
    //assert(1 == res);

    cout << "end" << endl;
    return 0;
}