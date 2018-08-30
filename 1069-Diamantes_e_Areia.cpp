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

int main () {
  int N = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int amount = 0;
    string diamond;
    cin >> diamond;
    diamond.erase(remove(diamond.begin(), diamond.end(), '.'), diamond.end());
    string::iterator it;
    gamb:
      for(it = diamond.begin(); it != diamond.end() - 1; it++) {
        if (*it == '<' && *(it+1) == '>') {
          amount++;
          diamond.erase(it);
          diamond.erase(it);
          if (diamond.size() == 0)
            break;
          goto gamb;
        }
      }
      cout << amount << endl;
  }

  return 0;
}
