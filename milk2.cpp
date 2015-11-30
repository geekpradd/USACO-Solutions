/*
ID: pradd1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.first < b.first;
}

int main(int argc, char const *argv[])
{
	ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");
	int n;
	fin >> n;

	vector< pair<int, int> > states(n);

	int present = 0;
	int not_present = 0;
	for (int i=0; i<n; ++i){
		int a,b;
		fin >> a;
		fin >> b;

		states[i] = make_pair(a, b);

	}

	sort(states.begin(), states.end(), comparator);

	present = states[0].second - states[0].first;
	if (n==1)
		fout << present << " " << 0 << endl;
	else{
		for (int i=1;i<n;++i){
			if (states[i].first<=states[i-1].second){
				if (states[i].second>=states[i-1].second)
					states[i].first = states[i-1].first;
				else {
					states[i].first = states[i-1].first;
					states[i].second = states[i-1].second;
				}

				present = max(present, states[i].second - states[i].first);
			}
			else{
				not_present = max(not_present, states[i].first - states[i-1].second);
			}
		}
	
		
	fout << present << " " << not_present << endl;
}

	return 0;
}