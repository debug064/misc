#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/add-binary/?envType=problem-list-v2&envId=rab78cw1

class Solution
{
public:
    string addBinary1(string a, string b)
    {
        string str;
        str.reserve(max(a.size(), b.size()) + 1);
        
        char c = '0';
        size_t i = 0;
        for (; i < a.size() && i < b.size(); ++i)
        {
            size_t ia = a.size() - i - 1;
            size_t ib = b.size() - i - 1;

            char n = (a[ia] - '0') | (b[ib] - '0') + '0';
            if ((a[ia] - '0') & (b[ib] - '0'))
            {
                str.append(1, c);
                c = '1';
            }
            else
            {
                if (c == '1' && n == '1')
                {
                    str.append(1, '0');
                    c = '1';
                }
                else if (c == '1' && n == '0')
                {
                    str.append(1, c);
                    c = '0';
                }
                else
                {
                    str.append(1, n);
                    c = '0';
                }
            }
        }

        string &c1 = a.size() > b.size() ? a : b;
        for (; i < c1.size(); ++i)
        {
            size_t ia = c1.size() - i - 1;
            char n = c1[ia];
            if (c == '1' && n == '1')
            {
                str.append(1, '0');
                c = '1';
            }
            else if (c == '1' && n == '0')
            {
                str.append(1, c);
                c = '0';
            }
            else
            {
                str.append(1, n);
                c = '0';
            }
        }

        if (c == '1')
            str.append(1, c);
        reverse(str.begin(), str.end());
        return str;
    }

    string addBinaryLeet(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += carry % 2 + '0';
            carry /= 2;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }


    string addBinary(string a, string b)
    {
        string str;
        str.reserve(max(a.size(), b.size()) + 1);
        size_t i = 0;
        int sum = 0;
        while( i < a.size() || i < b.size() || sum > 0) {
            if(i < a.size())
                sum += a[a.size() - i - 1] - '0';
            if(i < b.size())
                sum += b[b.size() - i - 1] - '0';
            str.append(1, sum % 2 + '0');
            sum /= 2;
            ++i;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

int main()
{
    cout << "begin" << endl;
    Solution sol;
    {
        assert("11010010011000000000" == sol.addBinary("01110001111100001101", "01100000011011110011"));
        assert("110001" == sol.addBinary("101111", "10"));
        assert("100" == sol.addBinary("11", "1"));
        assert("10101" == sol.addBinary("1010", "1011"));
        assert("111" == sol.addBinary("101", "10"));

        // height = {0,1,0,2,1,0,1,3,2,1,2,1};
        // assert(6 == sol.trap(height));
    }
    cout << "end" << endl;
    return 0;
}
