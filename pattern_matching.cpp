#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
using namespace std;

#define ALGORITHM 0 //0 for Naive and 1 for Suffix array

int main() {
		
	//Variables
	string str_add, pattern;
	ifstream fp;
	int MODE, SUBOPTION, num_book;
	num_book = 5; //Change 5 to another number depending how many files you want to read
	string text[5]; //Change 5 to another number depending how many files you want to read
	
	//Read file
	for (int i=1;i<num_book+1;i++) {
		stringstream ss;
		ss << i;
		string str = ss.str();
		string filename = "Book_" + str + ".txt";
		fp.open(filename.c_str());
		if (fp.is_open()) {
			while (!fp.eof()) {
				getline(fp,str_add);
				text[i-1] = text[i-1] + str_add;
			}
		}
		fp.close();
	}

	//Get pattern
	cout << "Type input pattern: ";
	getline(cin,pattern);

	
	//Select options
	cout << "Choose mode (Press 1 for SEARCH and 2 for STAT): ";
	cin >> MODE;
	cout << "Choose suboption (1 or 2)?: ";
	cin >> SUBOPTION;
	
	//Naive algorithm
	#if ALGORITHM == 0
	cout << "Naive algorithm selected." << endl;
	
	//Variables
	int ii,j;
	int occur_ind[5][100]; //Change 5 to another number depending how many files you want to read
	int num_occur[5] = {0,0,0,0,0}; //Change 5 to another number depending how many files you want to read, also increase the number of 0's based on that value
	int total_num_occur = 0;
	int num_file = 0;
	
	//Main Naive searching code
	for (int k=0;k<num_book;k++) {
		for (int i=0;i<text[k].length()-pattern.length()+1;i++) {
			j = 0;
			ii = i;
			while (j<pattern.length()) {
				if (pattern[j]==text[k][ii]) {
					ii++;
					j++;
				}
				else 
					break;
			}
			if (j==pattern.length()) {
				num_occur[k]++;
				occur_ind[k][num_occur[k]-1] = i+1;
			}
		}
	}
	for (int i=0;i<num_book;i++) {
		total_num_occur = total_num_occur + num_occur[i];
	}
	
	//Output
	//If the mode is Search
	if (MODE==1) {
		cout << "Search mode selected." << endl;
		//If SUBOPTION is 1
		if (SUBOPTION==1) {
			if (total_num_occur==0)
				cout << "No. Pattern does not appear in textfiles" << endl;
			else 
				cout << "Yes. Pattern does appear in textfiles" << endl;
		}
		//If SUBOPTION is 2
		else { 
			if (total_num_occur==0)
				cout << "Not found." << endl;
			else {
				for (int i=0;i<num_book;i++) {
					if (num_occur[i]>0) {
						stringstream ss;
						ss << i+1;
						string str = ss.str();
						string line = "Appears in Book_" + str + ".txt. Starting positions: ";
						cout << line;
						for (int j=0;j<num_occur[i];j++) {
							if (j>0)
								cout << ", "; 
							cout << occur_ind[i][j];
						}
						cout << "." << endl;
					}
				}
			}
		}
	}
	//If the mode is Stat
	else {
		cout << "Stat mode selected." << endl;
		//If SUBOPTION is 1
		if (SUBOPTION==1) {
			for (int i=0;i<num_book;i++) {
				stringstream ss;
				ss << i+1;
				string str = ss.str();
				string line = "Number of occurences of pattern in Book_" + str + ".txt: ";
				cout << line << num_occur[i] << "." << endl;
			}
		}
		//If SUBOPTION is 2
		else {
			for (int i=0;i<num_book;i++) {
				if (num_occur[i]>0)
					num_file++;
			}
			cout << "The number of files that contain at least one occurence of the pattern: " << num_file << "." << endl;
			if (num_file>0) {
				num_file = 0;
				cout << "These files are: ";
				for (int i=0;i<num_book;i++) {
					if (num_occur[i]>0) {
						num_file++;
						stringstream ss;
						ss << i+1;
						string str = ss.str();
						string line = "Book_" + str + ".txt";
						if (num_file>1)
							cout << ", "; 
						cout << line;
					}
				}
				cout << "." << endl;
			}
		}
	}
	#endif
	
	//Suffix array algorithm
	#if ALGORITHM == 1
		cout << "Suffix array algorithm selected." << endl;
		//To be implemented ...
	#endif
	return 0;
}
