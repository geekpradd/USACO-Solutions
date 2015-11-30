/*
ID: pradd1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

bool is_palindrome(string x, int b, int e){
	if (b==e)
		return true;
	if (b-e==1)
		return x[b]==x[e];
	if (x[b]==x[e])
		return is_palindrome(x, b+1, e-1);
	return false;
}
string to_base(int num, int base){
	ostringstream s;
	int a= num;
	char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	while (a>=1){
		if (a%base>=10)
			s << letters[(a%base)%10];
		else
			s << a%base;
		a = a/base;

	}
	return s.str();
}
int main(){
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");
	int base;
	fin >> base;
	for (int a=1; a<=300; ++a){
		string r = to_base(a*a, base);
		reverse(r.begin(), r.end());
		if (is_palindrome(r, 0, r.size()-1)){
			string s1 = to_base(a, base);
			reverse(s1.begin(), s1.end());
			fout << s1 << " " << r << endl;
		}
	}
	return 0;
}