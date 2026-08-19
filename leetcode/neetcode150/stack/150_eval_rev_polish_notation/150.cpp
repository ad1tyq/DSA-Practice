#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    int n = tokens.size();
    if (n == 0)
      return 0;
    stack<string> eval_stack;
    for (int i = 0; i < n; i++) {
      if (tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" ||
          tokens[i] == "-") {
        int n1 = stoi(eval_stack.top());
        eval_stack.pop();
        int n2 = stoi(eval_stack.top());
        eval_stack.pop();
        int n3;
        if (tokens[i] == "/")
          eval_stack.push(to_string(n2 / n1));
        else if (tokens[i] == "*")
          eval_stack.push(to_string(n2 * n1));
        else if (tokens[i] == "+")
          eval_stack.push(to_string(n2 + n1));
        else if (tokens[i] == "-")
          eval_stack.push(to_string(n2 - n1));
      } else {
        eval_stack.push(tokens[i]);
      }
    }
    return stoi(eval_stack.top());
  }
};

int main() {
  int n;
  cout << "enter size: ";
  cin >> n;
  cout << "enter tokens: ";
  vector<string> tokens(n);
  for (int i = 0; i < n; i++) {
    cin >> tokens[i];
  }
  Solution *sol = new Solution();
  cout << "evaluation: " << (*sol).evalRPN(tokens);
  return 0;
}
