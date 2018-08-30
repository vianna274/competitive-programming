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

bool inverseFoo (int i, int j) {
  return i>j;
}

int main () {
  int N = 0, dummy = 0;
  vi odds, even;
  while(cin >> N) {
    for(int i = 0; i < N; i++) {
      cin >> dummy;
      if ((dummy % 2) == 0)
        even.push_back(dummy);
      else
        odds.push_back(dummy);
    }
    sort(even.begin(), even.end());
    sort(odds.begin(), odds.end(), inverseFoo);
    vi::iterator it;
    for (it = even.begin(); it != even.end(); it++)
      cout << *it << endl;
    for (it = odds.begin(); it != odds.end(); it++)
      cout << *it << endl;
  }

  return 0;
}
