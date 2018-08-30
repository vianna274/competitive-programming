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

using namespace std;

typedef long long       ll;
typedef vector<int>     vi;
typedef pair<int, int>  ii;
typedef vector<ii>      vii;

vi balls;
int T, D, current;

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

void insert() {
  vi::iterator it;
  for(it = balls.begin(); it != balls.end(); it++) {
    if(is_perfect_square(*it + current)) {
      *it = current;
      current++;
      return;
    }
  }
  balls.push_back(current);
  current++;
}

void solve() {
  while(balls.size() <= D) {
    insert();
  }
  current--;
  current--;
}

int main ()
{
  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> D;
    balls.push_back(1);
    current = 2;
    solve();
    balls.clear();
    cout << current << endl;
  }
  return 0;
}
