#include <cstdio>
#include <vector>
#include <cmath>
#include<iostream>

#define FOUND 0
#define NOT_FOUND 1

using namespace std;


bool verify_output(std::vector<int> list) {
	for(int i = 0; i < list.size() - 1; i++) {
		if (list[i] == NOT_FOUND) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	std::vector<int> tempList;
	std::vector<int> gambiarra;
	int num = 0, i = 0, dummy = 0, sub = 0;	
	
	while(cin >> num) {
		for(i = 0; i < num; i++) {
			cin >> dummy;
			tempList.insert(tempList.begin(), dummy);
			gambiarra.insert(gambiarra.begin(), NOT_FOUND);
		}
		
		for(i = 0; i < tempList.size() - 1; i++) {
			sub = abs(tempList[i] - tempList[i+1]) - 1;
			if (sub < gambiarra.size()) {
				gambiarra[sub] = FOUND;
			}
		}
		if (verify_output(gambiarra) == true)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";	
		sub = 0;
		dummy = 0;
		num = 0;
		tempList.clear();
		gambiarra.clear();	
	}  
}

