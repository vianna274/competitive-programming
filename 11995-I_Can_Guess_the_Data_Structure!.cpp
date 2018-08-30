#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef long long       ll;
typedef vector<int>     vi;
typedef pair<int, int>  ii;
typedef vector<ii>      vii;

int main ()
{
  int N = 0;
  int opt = 0, num = 0;
  int c_stackNum = 0, c_queueNum = 0, c_heapNum = 0;
  bool b_stack = true, b_queue = true, b_heap = true;
  stack<int> c_stack;
  queue<int> c_queue;
  priority_queue<int> c_heap;
  while (cin >> N) {
    c_stack = stack<int>();
    c_queue = queue<int>();
    c_heap = priority_queue<int>();
    b_stack = true;
    b_queue = true;
    b_heap = true;
    for (int i = 0; i < N; i++) {
      cin >> opt; cin >> num;
      if (opt == 1) {
        c_stack.push(num);
        c_queue.push(num);
        c_heap.push(num);
      } else if (opt == 2) {
        if (c_stack.empty())
          b_stack = false;
        else {
          c_stackNum = c_stack.top();
          c_stack.pop();
        }
        if (c_queue.empty())
          b_queue = false;
        else {
          c_queueNum = c_queue.front();
          c_queue.pop();
        }
        if (c_heap.empty())
          b_heap = false;
        else {
          c_heapNum = c_heap.top();
          c_heap.pop();
        }

        if (c_stackNum != num)
          b_stack = false;
        if (c_queueNum != num)
          b_queue = false;
        if (c_heapNum != num)
          b_heap = false;
      }
    }
    if ((b_stack && b_queue) || (b_stack && b_heap) || (b_heap && b_queue))
      cout << "not sure" << endl;
    else if (b_stack)
      cout << "stack" << endl;
    else if (b_queue)
      cout << "queue" << endl;
    else if (b_heap)
      cout << "priority queue" << endl;
    else
      cout << "impossible" << endl;
  }
  return 0;
}
