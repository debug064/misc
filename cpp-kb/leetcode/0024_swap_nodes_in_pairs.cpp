#include "Problems.h"
#include <chrono>
#include <queue>
#include <set>

/*
* https://leetcode.com/problems/swap-nodes-in-pairs/
* Given a linked list, swap every two adjacent nodes and return its head. 
* You must solve the problem without modifying the values in the list's 
* nodes (i.e., only nodes themselves may be changed.)
*/
using namespace std;
namespace SwapNodesInPairs
{
  struct ListNode
  {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ~ListNode()
    {
      // if (next)
      //   delete next;
    }
  };

  class Solution
  {
  public:
    

    ListNode* swapPairs(ListNode* head) {
      if (!head)
        return head;
      ListNode* prev(nullptr);
      ListNode* node = head;
      if (node->next)
      {
        head = node->next;
        ListNode* f = node;
        ListNode* s = f->next;
        node = f->next = s->next;
        prev = s->next = f;
      }
      while(node)
      {
        ListNode* f = node;
        ListNode* s = f->next;
        if (!s)
          break;
        prev->next = s;
        node = f->next = s->next;
        prev = s->next = f;
      }
      return head;
    }
  };

  void test()
  {
    auto print = [](ListNode* list) {
      for (ListNode* node = list; node; node = node->next)
        cout << node->val << " ";
      cout << endl;
    };

    Solution s;
    ListNode* list;
    list = new ListNode(1);
    list = s.swapPairs(list);
    print(list);
    delete list;
    list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    list = s.swapPairs(list);
    print(list);
    delete list;
  }
}