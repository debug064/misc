#include "Problems.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * 
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<string> wordDict;
    Solution sol;
    {
        ListNode n1(3);
        ListNode n2(2);
        ListNode n3(0);
        ListNode n4(-4);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        assert(&n3 == sol.middleNode(&n1));
    }
    {
        ListNode n1(3);
        ListNode n2(2);
        ListNode n3(0);
        ListNode n4(-4);
        ListNode n5(5);
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        n4.next = &n5;
        assert(&n3 == sol.middleNode(&n1));
    }
    cout << "end" << endl;
    return 0;
}