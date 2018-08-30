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

#define OCCUPIED 1
#define NOT_OCCUPIED 0

int T;
int solutions[100][9];
int rows[9];
int tries = 0;
int possibleSolution[9];
int queens[9], customIndex;
int customCase = 0;

bool available(int queenNum, int row) {
	for(int i = 1; i < queenNum; i++) {
		// mathematical expression to find out if the queen is allowed to be
		// placed on that spot, need to iterate through all the queens
		// to validate the diagonal stuff
		if((abs(i - queenNum) == abs(possibleSolution[i] - row)))
			return false;
	}
	return true;
}

void getAllSolutions(int queenNum) {
	// if we reach beyond the final queen, store it in solutions
  if(queenNum == 9) {
    for(int queen = 1; queen < 9; queen++) {
      solutions[tries][queen] = possibleSolution[queen];
    }
		tries++;
    return;
  }
  for(int rowNum = 1; rowNum < 9; rowNum++) {
		// if this row is not occupied and available to be occupied by a new queen
		// so mark it as occupied and recur it with the next queen
    if(rows[rowNum] == NOT_OCCUPIED && available(queenNum, rowNum)) {
      rows[rowNum] = OCCUPIED;
      possibleSolution[queenNum] = rowNum;
      getAllSolutions(queenNum+1);
			// release this row because we've tried all the solutions with this
			// combination
      rows[rowNum] = NOT_OCCUPIED;
    }
  }
}
// ignores the [0] because it would be too messy to handle the zero's
int main () {
	// try every possibility
	getAllSolutions(1);
	while(cin >> T) {
		queens[1] = T;
		// get the case test
		for(int i = 2; i < 9; i++) {
			cin >> T;
			queens[i] = T;
		}
		int quantOfMoves = 10;
		// find our test in the possible solutions
    for(int attempt = 0; attempt <= tries; attempt++) {
      int temp = 0;
      for(int queen = 1; queen < 9; queen++)
				// if the current solution is different from the case entry
				// then add 1 to temp, because to change it is just 1 move
				// through the rows
        if(solutions[attempt][queen] != queens[queen])
            temp++;
      if(temp < quantOfMoves)  quantOfMoves = temp;
    }
		customCase++;
		cout << "Case " + to_string(customCase) + ": " + to_string(quantOfMoves) << endl;
	}
}
