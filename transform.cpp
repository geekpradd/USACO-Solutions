/*
ID: pradd1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#define vc vector< vector<char> > 

using namespace std;

vc transform(int code, vc vec){
	int size = vec.size();
	vc initial  = vec;
	switch(code){
		case 1:
			for (int i=0; i<size; ++i){
				for (int j=0; j<size; ++j){
					vec[j][size-i-1] = initial[i][j];
				}
			}
			return vec;
			break;
		case 4:
			for (int i=0; i<size; ++i){
				for (int j=0; j<size; ++j){
					vec[i][size-j-1] = initial[i][j];
				}
			}
			return vec;
			break;
		case 3:
			for (int i=0; i<size; ++i){
				for (int j=0; j<size; ++j){
					vec[size-j-1][i] = initial[i][j];
				}
			}
			return vec;
			break;
		case 2:
			for (int i=0; i<size; ++i){
				for (int j=0; j<size; ++j){
					vec[size-i-1][size-j-1] = initial[i][j];
				}
			}
			return vec;
			break;
	}
}


int main(int argc, char const *argv[])
{
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");
	int n;
	fin >> n;
	vc input_matrix(n, vector<char>(n, '0'));
	vc output_matrix(n, vector<char>(n, '0'));
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			char c;
			fin >> c;
			input_matrix[i][j] = c;
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			char c;
			fin >> c;
			output_matrix[i][j] = c;
		}
	}
	
		bool did = false;
		for (int i=1; i<5; ++i){
			vc x = transform(i, input_matrix);
			if (output_matrix==x){
				fout << i << endl;
				did = true;
				break;
			}
		}
		if (!did){
			bool didi = false;
			vc reflected = transform(4, input_matrix);
			for (int i=1; i<4; ++i){
				vc x = transform(i, reflected);
				if (output_matrix==x){
					fout << 5 << endl;
					didi = true;
					break;
				}
			}
			if (input_matrix==output_matrix){
				fout << 6 << endl;
				didi = true;
			}
			if (!didi){
				fout << 7 << endl;
			}
		}

	return 0;
}