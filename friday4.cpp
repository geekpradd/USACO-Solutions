/*
ID: pradd1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

bool is_leap_year(int year){
	if (year%400==0){
		return true;
	}
	if (year%100==0 && year%400!=0){
		return false;
	}
	if (year%4==0){
		return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");
	int n;
	fin >> n;
	
	int count_of_days[7] = {0};
	int counter_for_months = 0;
	for (int year=1900; year<1900+n;year++){

		int days[] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3}; 
		if (is_leap_year(year))
			days[1]++;
		
		for (int month=0;month<12;++month){

			int present_counter = (counter_for_months + 6)%7;
			counter_for_months = (counter_for_months + days[month])%7;
			++count_of_days[present_counter];
		}

	

	}

	fout << count_of_days[6] << " ";
	for (int i=0;i<6;++i){
		if (i==5)
			fout << count_of_days[i] << endl;
		else
			fout << count_of_days[i] << " ";
	}	

	return 0;
}