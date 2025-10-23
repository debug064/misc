#include "Problems.h"
#include <bitset>

using namespace std;

// https://leetcode.com/problems/string-to-integer-atoi/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    int myAtoi(string s) {
        auto str = s.c_str();
        int max_pre_multiply_value = INT_MAX / 10;
        int min_pre_multiply_value = INT_MIN / 10;
        int max_mod = INT_MAX % 10;
        int min_mod = INT_MIN % 10;
        while (std::isspace(static_cast<unsigned char>(*str)))
            ++str;
        bool n = false;
        if (*str == '+')
            ++str;
        else if (*str == '-')
        {
            ++str;
            n = true;
        }
        while (std::isspace(static_cast<unsigned char>(*str)))
            ++str;
        int res{};
        for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
        {
            int digit = *str - '0';
            if(!n && (-res > max_pre_multiply_value || (-res == max_pre_multiply_value && digit > max_mod)))
                return INT_MAX;
            if(n && (res < min_pre_multiply_value || ( res == min_pre_multiply_value && -digit < min_mod)))
                return INT_MIN;
            
            res *= 10;
            res -= digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
        }
        return n ? res : -res;
    }
    int myAtoiN(string s)
    {
        auto str = s.c_str();
        while (std::isspace(static_cast<unsigned char>(*str)))
            ++str;
        bool n = false;
        if (*str == '+')
            ++str;
        else if (*str == '-')
        {
            ++str;
            n = true;
        }

        unsigned int res{};
        for (; std::isdigit(static_cast<unsigned char>(*str)); ++str)
        {
            unsigned int digit = *str - '0';
            res *= 10u;
            res += digit;
            if(n)
            {
                if(res >= INT_MAX + 1)
                    return INT_MIN;
            }
            else
                if(res >= INT_MAX)
                    return INT_MAX;
            // if(!n && (-res > max_pre_multiply_value || (-res == max_pre_multiply_value && digit > max_mod)))
            //     return INT_MAX;
            // if(n && (res < min_pre_multiply_value || ( res == min_pre_multiply_value && -digit < min_mod)))
            //     return INT_MIN;
            
            
        }
        return n ? -res : res;

    }
};


int main()
{
    Solution sol;
    //sol.calculate("  ");
    cout << atoi("42") << endl;
    cout << sol.myAtoi("-91283472332") << endl;
    cout << sol.myAtoi("-2147483649") << endl;
    cout << sol.myAtoi("-2147483648") << endl;
    cout << sol.myAtoi("2147483646") << endl;
    cout << sol.myAtoi("-2147483646") << endl;
    cout << sol.myAtoi("-2147483647") << endl;
    
    cout << sol.myAtoi("2147483648") << endl;
    cout << sol.myAtoi("-2147483648") << endl;
    assert(42 == sol.myAtoi("42"));
    assert(-42 == sol.myAtoi("   -042"));
    
    return 0;
}
