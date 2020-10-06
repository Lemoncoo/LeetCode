#ifndef Offer9_hpp
#define Offer9_hpp

#include <stdio.h>
#include<stack>
#include <iostream>

#endif /* Offer9_hpp */
using namespace std;
class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    int deleteHead() {
        if(stack1.size() == 0) return -1;
        int res = 0;
        int size = stack1.size();
        for(int i = 0;i < size;i++){
            stack2.push(stack1.top());
            stack1.pop();
        }
        res = stack2.top();
        stack2.pop();
        size = stack2.size();
        for(int i = 0;i <size;i++){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return res;
    }
    void Test(){
        appendTail(5);
        appendTail(2);
        cout<<deleteHead()<<deleteHead();
    }
};
