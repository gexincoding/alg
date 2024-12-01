#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int s_max(int deep) { return 0; }

int get_times(int deep, int num) { return 0; }

void down(int deep, int max) {}

void sort(int deep) {
  if (s.empty()) {
    return;
  }
  // 1. max
  int max = s_max(deep);
  // 2. time
  int time = get_times(deep, max);
  down(deep, max);
  sort(deep - time);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    s.push(c);
  }
  sort(s.size());
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}