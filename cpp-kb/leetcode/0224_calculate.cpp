#include "Problems.h"
#include <string_view>

using namespace std;

// https://leetcode.com/problems/basic-calculator/?envType=problem-list-v2&envId=rab78cw1

class Solution {
    inline int get_num(const char*& str)
    {
        int res{};
        for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
        {
            int digit = *str - '0';
            res *= 10;
            res -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
        }
        return -res;
    }

    inline void skip_space(const char*& str)
    {
        while (std::isspace(static_cast<unsigned char>(*str)))
            ++str;
    }

    inline bool is_negative(const char*& str)
    {
        if (*str == '+')
            ++str;
        else if (*str == '-')
        {
            ++str;
            return true;
        }
        return false;
    }

    int calculate_sv(const char*& str)
    {
        int res = 0;
        bool negative = false;
        while(str && *str) 
        {
            if(*str == ')')
            {
                ++str;
                break;
            }
            skip_space(str);
            negative = is_negative(str);
            skip_space(str);
            if (*str == '(')
            {
                res += negative ? -calculate_sv(++str) : calculate_sv(++str);
            }
            else
            {
                res += negative?-get_num(str):get_num(str);
            }
            
        }
        
        return res;
    }
public:
    

    int calculate(string s) {
        auto str = s.c_str();
        return calculate_sv(str);
    }
};

int main()
{
    Solution sol;
    //sol.calculate("  ");
    assert(2 == sol.calculate("1 + 1"));
    assert(0 == sol.calculate("-1 + 1"));
    assert(3 == sol.calculate(" 2-1 + 2 "));
    assert(23 == sol.calculate("(1+(4+5+2)-3)+(6+8)"));
    return 0;
}
