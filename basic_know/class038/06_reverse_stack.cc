// 题目5 : 用递归逆序一个栈。时间复杂度O(n^2)

// [a,b,c -> [c,b,a
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

// 移除并返回栈底元素
int rb() {
  int t = s.top();
  s.pop();
  if (s.empty()) return t;
  int res = rb();
  s.push(t);
  return res;
}

// 逆序一个stack
void reverse() {
  if (s.empty()) return;
  int bottom = rb();
  reverse();
  s.push(bottom);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    s.push(num);
  }
  reverse();
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}