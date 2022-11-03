#include <iostream>
#include <stack>

int main(){
    std::stack<int> s1;
    std::stack<int> s2;
    std::stack<int> s3;

    s1.push(7);
    s1.push(6);
    s1.push(5);
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);

    std::stack<int> s2_tmp = s2;

    std::cout<<"---- s1 ----  ";
    while (!s1.empty()){
        std::cout<<s1.top()<<" ";
        s2.push(s1.top());
        s1.pop();
    }
    std::cout<<std::endl;

    while (!s2.empty()){
        s3.push(s2.top());
        s2.pop();
    }

    std::cout<<"---- s2 ----  ";
    while (!s2_tmp.empty()){
        std::cout<<s2_tmp.top()<<" ";
        s2_tmp.pop();
    }
    std::cout<<std::endl;
    
    std::cout<<"---- s3 ----  ";
    while (!s3.empty()){
        std::cout<<s3.top()<<" ";
        s3.pop();
    }

    return 0;
}