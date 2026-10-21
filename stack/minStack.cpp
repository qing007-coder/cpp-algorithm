#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std; 


class MinStack {
    long long minNum;              // 用 long long 存
    stack<long long> st;           // 栈里也存 long long 差值
public:
    MinStack() : minNum(INT_MAX) {}

    void push(int value) {
        st.push((long long)value - minNum);   // 关键：先转 long long
        if (value < minNum) minNum = value;
    }

    void pop() {
        long long d = st.top();
        st.pop();
        if (d < 0) minNum -= d;    // d<0 表示当前元素是"新最小值"，恢复旧 minNum
    }

    int top() {
        long long d = st.top();
        return d < 0 ? (int)minNum : (int)(minNum + d);
    }

    int getMin() {
        return (int)minNum;
    }
};
