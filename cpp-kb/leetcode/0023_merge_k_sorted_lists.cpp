
#include "Problems.h"
#include <chrono>
#include <queue>
#include <set>

/*
* https://leetcode.com/problems/merge-k-sorted-lists/
* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
* Merge all the linked-lists into one sorted linked-list and return it.
*/
using namespace std;
namespace MergekSortedLists
{
  class Solution
  {
  public:
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

    static ListNode* mergeKLists(vector<ListNode*>& lists)
    {
      ListNode* list = nullptr;
      ListNode** node = &list;
      lists.erase(std::remove_if(lists.begin(), lists.end(), [](auto const* v) {return v == nullptr; }), lists.end());
      while (!lists.empty())
      {
        ListNode** min = nullptr;
        for (auto it = lists.begin(); it != lists.end(); ++it)
        {
          if (*it == nullptr)
          {
            it = lists.erase(it);
            if (it == lists.end())
              break;
          }
          if (!min)
          {
            min = &*it;
            continue;
          }
          if ((*min)->val > (*it)->val)
            min = &*it;
        }
        if (!min)
          continue;
        *node = *min;
        *min = (*min)->next;
        (*node)->next = nullptr;
        node = &(*node)->next;
      }
      return list;
    }

    struct ListNodeValCmp
    {
      bool operator()  (ListNode* a, ListNode* b) const
      {
        // if(!a)
        //   return true;
        // if(!b)
        //   return false;
        return a->val < b->val;
      }
    };
    static ListNode* mergeKLists2(vector<ListNode*>& lists)
    {
      ListNode* list = nullptr;
      std::multiset<ListNode*, ListNodeValCmp> vals;
      for (auto it = lists.begin(); it != lists.end(); ++it)
      {
        auto node = *it;
        while (node)
        {
          vals.insert(node);
          node = node->next;
        }
      }
      ListNode** node = &list;
      for (auto& l : vals)
      {
        *node = l;
        (*node)->next = nullptr;
        node = &(*node)->next;
      }
      return list;
    }

    static ListNode* mergeKLists3(vector<ListNode*>& lists)
    {
      struct customLess {
        bool operator()  (ListNode const* a, ListNode const* b) const
        {
          // if(!a)
          //   return true;
          // if(!b)
          //   return false;
          return a->val > b->val;
        }
      };

      ListNode* list = nullptr;
      std::priority_queue<ListNode*, std::vector<ListNode*>, customLess> vals;
      for (auto it = lists.begin(); it != lists.end(); ++it)
      {
        auto node = *it;
        while (node)
        {
          vals.push(node);
          node = node->next;
        }
      }
      /*ListNode** node = &list;
      while (!vals.empty())
      {
        *node = vals.top();
        (*node)->next = nullptr;
        node = &(*node)->next;
        vals.pop();
      }*/
      ListNode* node = list;
      if (!vals.empty())
      {
        list = node = vals.top();
        vals.pop();
        while (!vals.empty())
        {
          node->next = vals.top();
          node = node->next;
          vals.pop();
        }
        node->next = nullptr;
      }
      
      
      return list;
    }

    static ListNode* mergeKLists4(vector<ListNode*>& lists)
    {
      struct customLess {
        bool operator()  (ListNode const* a, ListNode const* b) const
        {
          // if(!a)
          //   return true;
          // if(!b)
          //   return false;
          return a->val > b->val;
        }
      };

      class ListNode_pq :public std::priority_queue<ListNode*, std::vector<ListNode*>, customLess>
      {
      public:
        void swap(std::vector<ListNode*>& v)
        {
          std::swap(v, c);
        }
      };
      ListNode* list = nullptr;
      ListNode_pq vals;
      for (auto it = lists.begin(); it != lists.end(); ++it)
      {
        auto node = *it;
        while (node)
        {
          vals.push(node);
          node = node->next;
        }
      }
      std::vector<ListNode*> vals_srt;
      vals.swap(vals_srt); // it is heap, not sorted array
      ListNode** node = &list;
      for (auto p : vals_srt)
      {
        *node = p;
        (*node)->next = nullptr;
        node = &(*node)->next;
      }
      return list;
    }

    static void test()
    {
      auto print = [](ListNode* list)
      {
        for (ListNode* node = list; node; node = node->next)
          cout << node->val << " ";
        cout << endl;
      };
      ListNode* list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
      ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
      vector<ListNode*> lists = { list1, list2 };
      auto list = mergeKLists3(lists);
      print(list);
      delete list;
      lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6)) };
      list = mergeKLists3(lists);
      print(list);
      delete list;
      lists = { nullptr, nullptr };
      list = mergeKLists3(lists);
      print(list);
      delete list;
    }

    static void speedTest()
    {
      using namespace std::literals;
      namespace chrono = std::chrono;
      using clock_type = chrono::high_resolution_clock;

      std::cout << "Preparing random numbers ";
      std::vector<std::vector<int>> nums2;
      for (int i = 0; i < 4; ++i)
      {
        std::vector<int> nums;
        const int NUMS = 400'000;
        nums.reserve(NUMS);
        for (size_t i = 0; i < NUMS; ++i)
          nums.push_back(rand() % 20'000 - 10'000);
        nums2.emplace_back(std::move(nums));
      }
      std::cout << " - done\n";
      for (int i = 0; i < 3; ++i)
      {
        vector<ListNode*> lists;
        for (auto const& nums : nums2)
        {
          ListNode* list_src = nullptr;
          ListNode** list_node = &list_src;
          for (auto n : nums)
          {
            *list_node = new ListNode(n);
            list_node = &(*list_node)->next;
          }
          lists.push_back(list_src);
        }

        auto first = clock_type::now();

        if (i == 1)
        {
          auto list = mergeKLists3(lists);
          auto last = clock_type::now();
          auto interval = last - first;
          std::cout << "mergeKLists with priority_queue " << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms\n";
          while (list)
          {
            auto tmp = list;
            list = list->next;
            delete tmp;
          }
        }
        else if (i == 0)
        {
          auto list = mergeKLists2(lists);
          auto last = clock_type::now();
          auto interval = last - first;
          std::cout << "mergeKLists with multiset " << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms\n";
          while (list)
          {
            auto tmp = list;
            list = list->next;
            delete tmp;
          }
        }
        else if (i == 2)
        {
          auto list = mergeKLists4(lists);
          auto last = clock_type::now();
          auto interval = last - first;
          std::cout << "mergeKLists4 with priority_queue v " << chrono::duration_cast<chrono::milliseconds>(interval).count() << "ms\n";
          while (list)
          {
            auto tmp = list;
            list = list->next;
            delete tmp;
          }
        }
      }
    }
  };

  void test()
  {
    Solution::test();
    Solution::speedTest();
  }
}