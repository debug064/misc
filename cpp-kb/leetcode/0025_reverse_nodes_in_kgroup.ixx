
#include "Problems.h"
#include <chrono>
#include <queue>
#include <set>

export module ReverseNodesInKGroup;


/*
* https://leetcode.com/problems/reverse-nodes-in-k-group/
* Given the head of a linked list, reverse the nodes of the list k at a time, 
* and return the modified list.
*
* k is a positive integer and is less than or equal to the length of the linked list. 
* If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
*
* You may not alter the values in the list's nodes, only nodes themselves may 
* be changed.
*/
using namespace std;
namespace ReverseNodesInKGroupN
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
    static void delete_all(ListNode* node)
    {
      while (node)
      {
        ListNode* del = node;
        node = node->next;
        delete del;
      }
    }
  };

  class Solution {
  public:
    bool hasKNodes(ListNode* node, int k)
    {
      while  (k > 0)
      {
        if (node == nullptr)
          return false;
        node = node->next;
        --k;
      }
      return true;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      if (!head)
        return head;
      ListNode* prev = new ListNode(0, head);
      ListNode* node = head;
      head = prev;
      while (hasKNodes(node, k))
      {
        for (int i = 1; i < k; ++i)
        {
          if (node->next == nullptr)
            break;
          auto* tmp = prev->next;
          prev->next = node->next;
          node->next = node->next->next;
          prev->next->next = tmp;
        }
        prev = node;
        node = node->next;
      }
      auto* tmp = head->next;
      delete head;
      return tmp;
    }
  };

  export void test()
  {
    auto print = [](ListNode* list) {
      for (ListNode* node = list; node; node = node->next)
        cout << node->val << " ";
      cout << endl;
    };

    Solution s;
    ListNode* list;
    list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    list = s.reverseKGroup(list, 3);
    print(list);
    ListNode::delete_all(list);

    list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    list = s.reverseKGroup(list, 2);
    print(list);
    ListNode::delete_all(list);
  }

}