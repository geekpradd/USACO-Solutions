/*
ID: pradd1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

bool is_valid(string str, string input){

	if (input.size()>str.size()||str.size()>input.size())
		return false;
	
	for (int i=0; i<input.size(); ++i){
		int char_code = str[i] - 'A';
		if (char_code>16)
			char_code--;
		int dc = char_code/3 + 2;
		char v = '0' + dc;
		if (v!=input[i])
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	ifstream dict("dict.txt");


	string input;
	fin >> input; 

	string data;
	int count = 0;
	while (dict >> data){
		if (is_valid(data, input)){
			fout << data << endl;
			++count;
		}
	}
	if (!count)
		fout << "NONE" << endl;
	return 0;
}