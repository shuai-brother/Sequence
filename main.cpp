#include<cstdio>
#include<iostream>
#include"Sequence.h"
#include<time.h>

using namespace std;

int main()
{
	clock_t start_time=clock();
	string sbbb="dna.txt";
	Sequence S(sbbb);
	cout<<S.length()<<endl;
	cout<<S.numberOf('A')<<" "<<S.numberOf('T')<<" "<<S.numberOf('C')<<" "<<S.numberOf('G')<<endl;
	cout<<S.longestConsecutive()<<endl;
	cout<<S.longestRepeated()<<endl;
	clock_t end_time=clock();
	cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	return 0;
}

