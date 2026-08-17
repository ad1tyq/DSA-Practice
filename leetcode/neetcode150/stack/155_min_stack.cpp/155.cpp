#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class MinStack {
private:
  stack<int> values;
  stack<int> min_stack;

public:
  MinStack() {}

  void push(int value) {
    values.push(value);
    if (min_stack.empty() || value <= min_stack.top()) {
      min_stack.push(value);
    }
  }

  void pop() {
    if (values.empty()) {
      return;
    }

    if (values.top() == min_stack.top()) {
      min_stack.pop();
    }

    values.pop();
  }

  int top() { return values.top(); }

  int getMin() { return min_stack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
  cout << "enter input size: ";
  int n;
  cin >> n;
  vector<string> cmd(n);
  vector<int> input(n);
  MinStack *obj = new MinStack();
  cout << "enter commands: ";
  for (int i = 0; i < n; i++) {
    cin >> cmd[i];
  }
  cout << "enter input: ";
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }

  for (int i = 0; i < n; i++) {
    if (i == 0)
      cout << "[";
    int output;
    if (cmd[i] == "push") {
      (*obj).push(input[i]);
      cout << "null";
    } else if (cmd[i] == "getMin") {
      output = (*obj).getMin();
      cout << output;
    } else if (cmd[i] == "pop") {
      (*obj).pop();
      cout << "null";
    } else if (cmd[i] == "top") {
      output = (*obj).top();
      cout << output;
    }
    if (i == n - 1) {
      cout << "]";
    } else {
      cout << ", ";
    }
  }

  return 0;
}
