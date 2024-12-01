#include <iostream>
#include <string>
using namespace std;

void print_trace(int num, string from, string to, string other) {
  if (num == 1) {
    cout << "num " << num << " from " << from << " to " << to << endl;
    return;
  }
  print_trace(num - 1, from, other, to);
  cout << "num " << num << " from " << from << " to " << to << endl;
  print_trace(num - 1, other, to, from);
}

int main() {
  int n;
  cin >> n;
  print_trace(n, "left", "right", "middle");
  return 0;
}