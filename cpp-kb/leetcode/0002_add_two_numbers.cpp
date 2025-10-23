#include "Problems.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int ten = 0;
        ListNode *root = nullptr; // new ListNode;
        ListNode **res = &root;
        int val = {0};
        while (l1 || l2)
        {
            val = ten;
            if (l1)
            {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                val += l2->val;
                l2 = l2->next;
            }

            *res = new ListNode(val % 10);
            ten = val / 10;
            res = &((*res)->next);
        }
        if (ten != 0)
            *res = new ListNode(ten);
        return root;
    }

    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
    {
        int ten = 0;
        ListNode *root = nullptr; // new ListNode;
        ListNode **res = &root;
        int val = {0};
        while (l1 || l2)
        {
            val = ten;
            if (l1)
            {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                val += l2->val;
                l2 = l2->next;
            }

            *res = new ListNode(val % 10);
            ten = val / 10;
            res = &((*res)->next);
        }
        if (ten != 0)
            *res = new ListNode(ten);
        return root;
    }
};

int main()
{
    Solution sol;
    auto res = sol.addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3)))
                    , new ListNode(5, new ListNode(6, new ListNode(4)))
    );
     while(res) 
     {
        std::cout << res->val << " ";
        auto tmp = res;
        res = res->next;
        delete tmp;
     }
     std::cout << std::endl;
}