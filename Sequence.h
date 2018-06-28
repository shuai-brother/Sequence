#ifndef SEQUENCCCCCCCCCCCCCCCC_H
#define SEQUENCCCCCCCCCCCCCCCC_H
#define MAXN 1300000

#include<cstdio>
#include<iostream>

using namespace std;

class Sequence{
	private:
		int num[40],Leng,seq[1300000],lgC,lgCpos,lgR,pos;
	public:
		Sequence(string s1);
		~Sequence();
		int length();
		int numberOf(char base);
		string longestConsecutive();
		string longestRepeated();
};

#endif


