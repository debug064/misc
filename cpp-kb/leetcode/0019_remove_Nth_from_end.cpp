#include "Problems.h"

using namespace std;

namespace RemoveNthFromEnd
{
  struct Solution
  {
    struct ListNode
    {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode* next) : val(x), next(next) {}
      ~ListNode() { if (next) delete next; }
    };

    static ListNode* removeNthFromEnd(ListNode* head, int n)
    {
      if (!head)
        return head;

      ListNode* node1 = head;
      while (n > 0 && node1)
      {
        --n;
        node1 = node1->next;
      }
      if (n > 0)
        return head;

      ListNode* node2 = head;
      if (node1 == nullptr)
      {
        head = head->next;
        node2->next = nullptr;
        delete node2;
        return head;
      }
      node1 = node1->next;
      while (node1)
      {
        node1 = node1->next;
        node2 = node2->next;
      }

      auto tmp = node2->next;
      node2->next = tmp->next;
      tmp->next = nullptr;
      delete tmp;
      return head;
    }
    static void test()
    {
      auto print = [](ListNode* list) {
        for (ListNode* node = list; node; node = node->next)
          cout << node->val << " ";
        cout << endl;
      };
      ListNode* list;
      list = new ListNode(1);
      list = removeNthFromEnd(list, 1);
      print(list);
      delete list;
      list = new ListNode(1);
      list = removeNthFromEnd(list, 2);
      print(list);
      delete list;
      list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5,new ListNode(6))))));
      list = removeNthFromEnd(list, 2);
      print(list);
      delete list;
    }
  };

  void test()
  {
    Solution::test();
  }
}