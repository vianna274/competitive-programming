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

typedef struct _CAR {
  int low;
  int high;
  string name;
} CAR;

vector<CAR> vecCar;
int test;

void solve() {
  vector<CAR>::iterator it;
  int op = 0;
  string opName;
  for(it = vecCar.begin(); it != vecCar.end(); it++) {
    if(test >= it->low && test <= it->high) {
      op++;
      opName = it->name;
    }
    if(op > 1)
      break;
  }
  if(op == 1)
    cout << opName << endl;
  else
    cout << "UNDETERMINED" <<endl;
}

int main ()
{
  int T, D, Q, P;

  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> D;
    for(int j = 0; j < D; j++) {
      CAR newCar;
      cin >> newCar.name;
      cin >> newCar.low;
      cin >> newCar.high;
      vecCar.push_back(newCar);
    }
    cin >> Q;
    for(int j = 0; j < Q; j++) {
      cin >> test;
      solve();
    }
    if ((i+1) < T)
      cout << endl;
    vecCar.clear();

  }
  return 0;
}
