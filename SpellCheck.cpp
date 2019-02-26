//Jordan Miller
//CSCI 4270, Assignment Number 5
//Implement a spell check with Wagner, input a word, return 10

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Edited {
	int dist;
	string word;
};	

int editDist(string &str1, string &str2) {
	const size_t size1 = str1.size();
	const size_t size2 = str2.size();
		
	int dist[size1 + 1][size2 + 1];
		
	dist[0][0] = 0;
		
	for (int i = 0; i <= size1; i++) {
		dist[i][0] = i;		
	}
		
	for (int j = 0; j <= size2; j++) {
		dist[0][j]  = j;
	}
		
	for (int j = 1; j <= size2; j++) {
		for (int i = 1; i <= size1; i++) {
			if (str1[i-1] == str2[j-1]) {
				dist[i][j] = dist[i-1][j-1];
			} else {
				dist[i][j] = min( dist[i-1][j] + 1, min(dist[i][j-1] +  1, dist[i-1][j-1] + 2 ));
			}
		}
	}
	return dist[size1][size2];
};

bool distCompare(Edited dist1, Edited dist2) {
	return dist1.dist < dist2.dist;
};
	
ostream& operator<<(ostream& os, const Edited& e) {
	os << e.dist << " - " << e.word;
	return os;
}	
	
int main() {
	Edited edited;
	vector<Edited> file;
	
	string input;
	cout << "Welcome to Spell Check!" << endl;
	cout << "Enter a word check: " << endl;
	cin >> input;
	
	string line;
	ifstream myFile("words.txt");
	if (!myFile) {
		cout << "cannot open" << endl;
		exit(1);
	} 
	while (getline(myFile, line)) {
		edited.word = line;
		edited.dist = editDist(input, edited.word);
		file.push_back(edited);
	}
	 
	sort(file.begin(), file.end(), distCompare);

	cout << "The Top Ten Values are: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << file[i] << endl;
	}
}