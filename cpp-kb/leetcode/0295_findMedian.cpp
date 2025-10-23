#include "Problems.h"
#include <set>
#include <queue>

using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/?envType=problem-list-v2&envId=rab78cw1

class MedianFinder1 {
    multiset<int, greater<int> > arr;
public:
    MedianFinder1() {
        
    }
    
    void addNum(int num) {
        arr.insert(num);
    }
    
    double findMedian() {
        size_t med = arr.size() / 2;
        auto it = arr.cbegin();
        for(size_t i = 0; i < med; ++i)
            ++it;
        if(arr.size() % 2)
            return *it;
        else
            return (*it + *(--it)) / 2.;
    }
};

class MedianFinder2 {
    vector<int> arr;
public:
    MedianFinder2() {
        
    }
    
    void addNum(int num) {
        auto it = upper_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num);
    }
    
    double findMedian() {
        if(arr.empty())
            return 0.;
        size_t med = arr.size() / 2;
        auto it = arr.cbegin();
        if(arr.size() % 2)
            return arr[med];
        else
            return (arr[med] + arr[med-1]) / 2.;
    }
};

class MedianFinder {
    priority_queue<int,  vector<int>, greater<int>> largeHeap;                                  // min on top
    priority_queue<int > smallHeap;     // max on top
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(largeHeap.empty())
        {
            largeHeap.push(num);
            return;
        }
        if(smallHeap.empty())
        {
            if(num > largeHeap.top() )
            {
                smallHeap.push(largeHeap.top());
                largeHeap.pop();
                largeHeap.push(num);
            }
            else
                smallHeap.push(num);
            return;
        }
        if(num < smallHeap.top() )
            smallHeap.push(num);
        else
            largeHeap.push(num);

        if(smallHeap.size() > largeHeap.size())
        {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if(smallHeap.size() + 1 < largeHeap.size() )
        {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.empty() && largeHeap.empty())
            return 0.;
        if((smallHeap.size() + largeHeap.size()) % 2)
            return largeHeap.top();
        return (largeHeap.top() + smallHeap.top()) / 2.;
    }
};

int main()
{
    {
        MedianFinder sol;
        sol.addNum(1);
        cout << sol.findMedian() << '\n';
        assert(1 == sol.findMedian());
    }

    {
        MedianFinder sol;
        sol.addNum(2);
        sol.addNum(3);
        sol.addNum(4);
        assert(3 == sol.findMedian());
    }
    {
        MedianFinder sol;
        sol.addNum(1);
        sol.addNum(2);
        sol.addNum(3);
        sol.addNum(4);
        cout << sol.findMedian() << '\n';
        //assert(2.5 == sol.findMedian());
    }
    {
        MedianFinder sol;
        sol.addNum(-1);
        sol.addNum(-2);
        sol.addNum(-3);
        sol.addNum(-4);
        cout << sol.findMedian() << '\n';
        //assert(2.5 == sol.findMedian());
    }
    return 0;
}
