#include<cstdio>
#include<cstring>
#include<iostream>
#include"Sequence.h"

#define MAXN 1300000

using namespace std;

char s2[101];

int hi[MAXN],sa[MAXN],ra[MAXN],r[MAXN],y[MAXN],wv[MAXN],WS[MAXN],x[MAXN];

int cge(char h)
{
	if(h=='A')return 1;
	else if(h=='T')return 2;
	else if(h=='C')return 3;
	else return 4;
}

char CGE(int h)
{
	char bb;
	if(h==1)bb='A';
	else if(h==2)bb='T';
	else if(h==3)bb='C';
	else bb='G';
	return bb;
}

Sequence::Sequence(string s1)
{
	char s33[201];
	for(int i=0;i<s1.length();i++)
		s33[i]=s1[i];
	Leng=0,lgR=0,lgC=0;
	memset(num,0,sizeof(num));
	memset(seq,0,sizeof(seq));
	freopen(s33,"r",stdin);
	while(~scanf("%s",s2))
	{
		int len=strlen(s2);
		for(int i=0;i<len;i++)
		{
			int dd=cge(s2[i]);
			seq[++Leng]=dd;
			num[dd]++;
		}
		memset(s2,0,sizeof(s2));
	}

	for(int i=1;i<=Leng;i++)
	{
		if(seq[i]==seq[i-1])hi[i]=hi[i-1]+1;
		else hi[i]=1;
		if(hi[i]>lgC)lgC=hi[i],lgCpos=i-lgC+1;
	}

	int p,m;
	for(int i=1;i<=Leng;i++)WS[i]=0;
	for(int i=1;i<=Leng;i++)WS[x[i]=seq[i]]++;
	for(int i=2;i<=4;i++)WS[i]+=WS[i-1];
	for(int i=Leng;i>=1;i--)sa[WS[x[i]]--]=i;
	p=1;
	for(int j=1;p<Leng;j*=2,m=p)
	{
		p=0;
		for(int i=Leng-j+1;i<=Leng;i++)y[++p]=i;
		for(int i=1;i<=Leng;i++)if(sa[i]>j)y[++p]=sa[i]-j;
		for(int i=1;i<=Leng;i++)wv[i]=x[y[i]];
		for(int i=1;i<=m;i++)WS[i]=0;
		for(int i=1;i<=Leng;i++)WS[wv[i]]++;
		for(int i=2;i<=m;i++)WS[i]+=WS[i-1];
		for(int i=Leng;i>=1;i--)sa[WS[wv[i]]--]=y[i];
		swap(x,y);p=1;x[sa[1]]=1;
		for(int i=2;i<=Leng;i++)
		{
			if(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+j]==y[sa[i]+j])x[sa[i]]=p;
			else x[sa[i]]=++p;
		} 
	}
	for(int i=2;i<=Leng;i++)
	{
		int dog=0;
		int j1=sa[i-1],j2=sa[i];
		while(1)
		{
			if(seq[j1]==seq[j2])dog++,j1++,j2++;
			else break;
			if(j1==Leng+1||j2==Leng+1)break;
		}	
		if(dog>lgR)lgR=dog,pos=min(sa[i],sa[i-1]);
		else if(dog==lgR&&min(sa[i],sa[i-1])<pos)pos=min(sa[i],sa[i-1]);
	}
}

Sequence::~Sequence()
{
}

int Sequence::length()
{
	return Leng;
}

int Sequence::numberOf(char base)
{
	return num[cge(base)];
}

string Sequence::longestConsecutive()
{
	string s1;
	for(int i=lgCpos;i<=lgCpos+lgC-1;i++)
		s1+=CGE(seq[i]);
	return s1;
}

string Sequence::longestRepeated()
{
	string s1;
	for(int i=pos;i<=pos+lgR-1;i++)
		s1+=CGE(seq[i]);
	return s1;
}

