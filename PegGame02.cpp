//Jordan Miller
//CSCI 4270
//Backtracking to solve the peg game

#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

struct PegGame {
	int source;
	int dest;
};

bool pegGame(int pegs[], int jumps[][3], int remaining, vector<PegGame>& moveList) {
	//if empty set to zero, if there set to 1
	if (remaining == 1) {
		return true;
	}
	//cout << "remaining is what " << remaining << endl;
	
	PegGame move;
	
	for (int i = 0; i < 18; i++) {
		//for (int j = 0; j < 3; j++) {
			//if it is valid
			if (pegs[jumps[i][0]] == 1 &&
				pegs[jumps[i][1]] == 1 && 
				pegs[jumps[i][2]] == 0 ) {				
				//make the move	
		//			cout << "did we make it" << endl;
					pegs[jumps[i][0]] = 0;
					pegs[jumps[i][1]] = 0;
					pegs[jumps[i][2]] = 1;
					move.source = jumps[i][0];
					move.dest = jumps[i][2];
					moveList.push_back(move);
					//if it works add it 
					bool success = pegGame(pegs, jumps, remaining - 1, moveList);
					if (success) {
			//			cout << "urh this seems broke" << endl;
						move.source = jumps[i][0];
						move.dest = jumps[i][2];
						moveList.push_back(move);
			//			cout << "remaining is " << remaining << endl;
						return true;
					} else {
						//undo the move
			//			cout << "dat shit no work" << endl;
						pegs[jumps[i][0]] = 1;
						pegs[jumps[i][1]] = 1;
						pegs[jumps[i][2]] = 0;
						moveList.pop_back();
					}
			} //end if 1
			
			//check the other direction
			if (pegs[jumps[i][2]] == 1 &&
				pegs[jumps[i][1]] == 1 &&
				pegs[jumps[i][0]] == 0 ) {
					//make the move
				//	cout << "LOL" << endl;
					pegs[jumps[i][2]] = 0;
					pegs[jumps[i][1]] = 0;
					pegs[jumps[i][0]] = 1;
					move.source = jumps[i][2];
					move.dest = jumps[i][0];
					moveList.push_back(move);
					
					bool success = pegGame(pegs, jumps, remaining - 1, moveList);
					if (success) {
						move.source = jumps[i][2];
						move.dest = jumps[i][0];
						moveList.push_back(move);
					//	cout << "bruh" << endl;
					//	cout << "remaining is " << remaining << endl;
						return true;
					} else {
						//undo the move
						pegs[jumps[i][0]] = 0;
						pegs[jumps[i][1]] = 1;
						pegs[jumps[i][2]] = 1;
						moveList.pop_back();
					//	cout << "no fucking way" << endl;
					}
			}//end if 2
		//} //end for j
	
	} //end for i
	return false;
} // end the function

ostream& operator<<(ostream& os, const PegGame& m) {
	os << "Source is: " << m.source << " destination is: " << m.dest << endl;
	return os;
}


int main() {
	int emptyHole;
	vector<PegGame> moveList;
	
	cout << "Welcome to the Peg Game!" << endl;
	cout << "Which hole is empty?" << endl;
	cin >> emptyHole;
	
	//start, jumped, dest
	int jumps[18][3] = {
		{0,1,3},
		{0,2,5},
		{1,3,6},
		{1,4,8},
		{2,4,7},
		{2,5,9},
		{3,4,5},
		{3,6,10},
		{3,7,12},
		{4,7,11},
		{4,8,13},
		{5,8,12},
		{5,9,14},
		{6,7,8},
		{7,8,9},
		{10,11,12},
		{11,12,13},
		{12,13,14} 
	};
	
	int pegs[15];
	for (int i = 0; i < 15; i++) {
		if (i == emptyHole) {
			pegs[i] = 0;
		} else {
			pegs[i] = 1;
		}
	}
	
	pegGame(pegs, jumps, 14, moveList);
	
	for (int i = 0; i < 13; i++) {
		cout << moveList[i] << endl;
	}
	
	return 0;
}