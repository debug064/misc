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
    bool hasCycle1(ListNode *head) {
        unordered_map<ListNode*, int> visited;
        int pos = -1;
        while(head)
        {
            if(auto it = visited.find(head); it != visited.end())
            {
                pos = it->second;
                return true;
            }
            visited[head] = visited.size();
            head = head->next;
        }
        return false;
    }

    /// Floyd's Linked List Cycle Finding Algorithm
    //     Take two pointers  
    // $slow$  and  
    // $fast$ .
    // Both of them will point to head of the linked list initially.
    // $slow$  will move one step at a time.
    // $fast$  will move two steps at a time. (twice as speed as $slow$  pointer).
    // Check if at any point they point to the same node before any one(or both) reach null.
    // If they point to any same node at any point of their journey, it would indicate that the cycle indeed exists in the linked list.
    // If we get null, it would indicate that the linked list has no cycle.
    bool hasCycle(ListNode *head) {
        int pos = -1;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
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
        n4.next = &n1;
        assert(true == sol.hasCycle(&n1));
    }
    cout << "end" << endl;
    return 0;
}