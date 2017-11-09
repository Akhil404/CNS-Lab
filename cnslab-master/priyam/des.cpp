#include <bits/stdc++.h>
using namespace std;

unsigned long int l,r,kl,kr;
unsigned long int lkey[16],rkey[16],subkey[16];

int pc1[56] = {
	1,2,3,4,5,6,7,9,10,11,12,13,14,15,
	17,18,19,20,21,22,23,25,26,27,28,29,30,
	31,33,34,35,36,37,38,39,41,42,43,44,45,
	46,47,49,50,51,52,53,54,55,57,58,59,60,61,
	62,63
};

int pc2[48] = {

};

void dispbits(unsigned long int x)
{
	unsigned long int mask;
	mask=1;
	mask=mask<<63;
	for(int i=0;i<64;i++)
	{
		if(x&mask) { cout<<"1"; }
		else { cout<<"0"; }
		x = x<<1;
	}
	cout<<"\n";
}

unsigned long int combine(unsigned long int a, unsigned long int b,int size)
{
	unsigned long int x=0;
	x = (a<<size)^b;
	return x;
}

unsigned long int permute(int p[],int size, unsigned long int a)
{
	unsigned long int x=0,one=1;
	for(int i=size-1;i>=0;i--)
	{
		x = x<<1;
		unsigned long int y = (unsigned long int)pow(2,p[i]-1);
		if(a&y) { x = x^one; }
	}
	return x;
}

unsigned long int shiftleft(unsigned long int  a)
{
	unsigned long int mask,x,f=0;
	mask = (unsigned long int )pow(2,27);
	if(a&mask) { f=1; }
	mask = ~mask;
	x = a&mask;
	x = x<<1;
	if(f) { x = x^f; }
	return x;
}

void genKeys()
{
	unsigned long int key,x,a,mask,one;
	a=0;
	for(int i=0;i<30;i++)
	{
		int y = rand()%64;
		x = (unsigned long int)pow(2,y);
		a = a^x;
	}
	key = permute(pc1,56,a);

	x=a;
	kl=kr=0;
	mask=1;
	mask=mask<<55;
	one=1;

	for(int i=0;i<28;i++)
	{
		kl = kl<<1;
		if(x&mask) { kl = kl^one; }
		x = x<<1;
	}
	for(int i=0;i<28;i++)
	{
		kr = kr<<1;
		if(x&mask) { kr = kr^one; }
		x = x<<1;
	}

	for(int i=0;i<16;i++)
	{
		kl[i] = shiftleft(kl);
		kr[i] = shiftleft(kr);
		subkey[i] = permute(pc2,48,combine(kl[i],kr[i],28));
		kl = kl[i];
		kr = kr[i];
	}

}

void round(unsigned long int lpart,unsigned long int rpart,int num)
{
	l = rpart; //L1

	unsigned long int x,y;
	x = permute(expandPerm,48,lpart);
	x = x^subkey[num];
	y = sbox(x);
	y = permute(contractPerm,32,y);
	r = lpart^y; //R1

}

int main()
{
	unsigned long int a,L,R,x,mask,one,result,org;
	srand(time(NULL));
	a=0;
	for(int i=0;i<30;i++)
	{
		int y = rand()%64;
		x = (unsigned long int)pow(2,y);
		a = a^x;
	}

	org = a;
	a = permute(ip,64,org);

	x=a;
	L=R=0;
	mask=1;
	mask=mask<<63;
	one=1;

	for(int i=0;i<32;i++)
	{
		L = L<<1;
		if(x&mask) { L = L^one; }
		x = x<<1;
	}
	for(int i=0;i<32;i++)
	{
		R = R<<1;
		if(x&mask) { R = R^one; }
		x = x<<1;
	}

	dispbits(a);
	dispbits(L);
	dispbits(R);

	genKeys();

	unsigned long int interL,interR;

	interL = L;
	interR = R;

	for(int i=0;i<16;i++)
	{
		round(interL,interR,i);
		interL = l;
		interR = r;
	}

	result = combine(interR,interL,32);
	result = permute(ipinv,64,result);

	return 0;
}