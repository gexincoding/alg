#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int s_max(int deep) {
  if (deep == 0) return INT_MIN;
  int t = s.top();
  s.pop();
  int res = s_max(deep - 1);
  if (t > res) res = t;
  s.push(t);
  return res;
}

int get_times(int deep, int num) {
  if (deep == 0) return 0;
  int t = s.top();
  s.pop();
  int res = get_times(deep - 1, num);
  if (t == num) res++;
  s.push(t);
  return res;
}

void down(int deep, int max, int time) {
  if (deep == 0) {
    for (int i = 0; i < time; i++) s.push(max);
    return;
  }
  int t = s.top();
  s.pop();
  down(deep - 1, max, time);
  if (max != t) s.push(t);
}

void sort() {
  if (s.empty()) return;
  int deep = s.size();
  while (deep > 0) {
    int max = s_max(deep);
    int time = get_times(deep, max);
    down(deep, max, time);
    deep -= time;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    s.push(c);
  }
  sort();
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}