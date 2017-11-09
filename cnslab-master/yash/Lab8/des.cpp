#include<bits/stdc++.h>
using namespace std;
int shift_no[]={1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
void print(int a[],int s)
{
	cout<<"-----------------------------------\n";
	for (int i = 0; i < s; ++i)
	{
		cout<<a[i]<<"";
	}
		cout<<endl;
	cout<<"-----------------------------------\n";	

}
void initial_perm(int a[],int b[] )
{
	int c[]={58, 50, 42, 34, 26, 18, 10, 2,
			60, 52, 44, 36, 28, 20, 12, 4,
			62, 54, 46, 38, 30, 22, 14, 6,
			64, 56, 48, 40, 32, 24, 16, 8,
			57, 49, 41, 33, 25, 17, 9, 1,
			59, 51, 43, 35, 27, 19, 11, 3,
			61, 53, 45, 37, 29, 21, 13, 5,
			63, 55, 47, 39, 31, 23, 15, 7};

	for(int i=0;i<64;i++)
	{
		b[i]=a[c[i]-1];
	}
}
void inv_initial_perm(int z1[],int z2[])
{
	int c[]={40, 8, 48, 16, 56, 24, 64, 32,
			39, 7, 47, 15, 55, 23, 63, 31,
			38, 6, 46, 14, 54, 22, 62, 30,
			37, 5, 45, 13, 53, 21, 61, 29,
			36, 4, 44, 12, 52, 20, 60, 28,
			35, 3, 43, 11, 51, 19, 59, 27,
			34, 2, 42, 10, 50, 18, 58, 26,
			33, 1, 41, 9, 49, 17, 57, 25};
	for(int i=0;i<64;i++)
	{
		z2[i]=z1[c[i]-1];
	}
}





void perm_choice1(int k1[],int k2[])
{
	int c[]={57, 49, 41, 33, 25, 17, 9,
			1, 58, 50, 42, 34, 26, 18,
			10, 2, 59, 51, 43, 35, 27,
			19, 11, 3, 60, 52, 44, 36,
			63, 55, 47, 39, 31, 23, 15,
			7, 62, 54, 46, 38, 30, 22,
			14, 6, 61, 53, 45, 37, 29,
			21, 13, 5, 28, 20, 12, 4};
	for(int i=0;i<56;i++)
	{
		k2[i]=k1[c[i]-1];
	}
}
void expansion(int R[],int R1[])
{
	int c[]={32,1,2,3,4,5,
			4,5,6,7,8,9,
			8,9,10,11,12,13,
			12,13,14,15,16,17,
			16,17,18,19,20,21,
			20,21,22,23,24,25,
			24,25,26,27,28,29,
			28,29,30,31,32,1};
	for(int i=0;i<48;i++)
	{
		R1[i]=R[c[i]-1];
	}
}
void shift(int no,int C[],int C1[])
{
	int k=shift_no[no];
	for(int i=0;i<28;i++)
	{
		C1[i]=C[(i+k)%28];
	}
}
void shift_right(int no,int C[],int C1[])
{
	int k=shift_no[no];
	for(int i=27;i>=0;i--)
	{
		C1[i]=C[(i-k+28)%28];
	}
}
void perm_choice2(int key1[],int key2[])
{
	int c[]={14,17,11,24,1,5,3,28,
			15,6,21,10,23,19,12,4,
			26,8,16,7,27,20,13,2,
			41,52,31,37,47,55,30,40,
			51,45,33,48,44,49,39,56,
			34,53,46,42,50,36,29,32};
	for(int i=0;i<48;i++)
	{
		key2[i]=key1[c[i]-1];
	}
}
void S_box(int R1[],int R2[])
{
	int s1[]={14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7,
			0,	15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8,
			4,	1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0,
			15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13};
	int s2[]={15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10,
			3,	13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5,
			0,	14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15,
			13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9};
	int s3[]={10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8,
			13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1,
			13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7,
			1,	10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12};
	int s4[]={7,	13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15,
			13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9,
			10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4,
			3,	15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14};
	int s5[]={2,	12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9,
			14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6,
			4,	2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14,
			11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3};
	int s6[]={12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11,
			10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8,
			9,	14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6,
			4,	3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13};
	int s7[]={4,	11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1,
			13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6,
			1,	4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2,
			6,	11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12};
	int s8[]={13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7,
			1,	15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2,
			7,	11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8,
			2,	1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11};
	for(int i=0;i<8;i++)
	{
		int r[6],k=0;
		for(int j=i*6;j<i*6+6;j++)
		{
			r[k]=R1[j];k++;
		}
		int p=r[0]*2+r[5];
		int q=r[1]*8+r[2]*4+r[3]*2+r[4];
		int z=p*16+q;
		if(i==0) z=s1[z];
		if(i==1) z=s2[z];
		if(i==2) z=s3[z];
		if(i==3) z=s4[z];
		if(i==4) z=s5[z];
		if(i==5) z=s6[z];
		if(i==6) z=s7[z];
		if(i==7) z=s8[z];
		int w[4]={0};
		k=3;
		while(z)
		{
			w[k]=z%2;
			z=z/2;
			k--;
		}
		int t=0;
		for(int j=i*4;j<i*4+4;j++)
		{
			R2[j]=w[t];t++;
		}
	}
}
void round(int no,int text[],int key[],int k3[])
{
	int L[32],R[32],R1[48],R2[32];
	for(int i=0;i<64;i++)
	{
		if(i<32)
		{
			L[i]=text[i];
		}
		else
		{
			R[i-32]=text[i];
		}
	}
	expansion(R,R1);
	int C[28],D[28],C1[28],D1[28];
	for(int i=0;i<56;i++)
	{
		if(i<28)
		{
			C[i]=key[i];
		}
		else
		{
			D[i-28]=key[i];
		}
	}
	shift(no,C,C1);
	shift(no,D,D1);
	int key1[56],key2[48];
	for(int i=0;i<56;i++)
	{
		if(i<28)
		{
			key1[i]=C1[i];
		}
		else
		{
			key1[i]=D1[i-28];
		}
	}
	perm_choice2(key1,key2);
	for(int i=0;i<48;i++)
	{
		R1[i]=R1[i] ^ key2[i];
	}
	S_box(R1,R2);
	for(int i=0;i<32;i++)
	{
		k3[i]=R[i];
	}
	for(int i=0;i<32;i++)
	{
		L[i]=L[i] ^ R2[i];
	}
	for(int i=32;i<64;i++)
	{
		k3[i]=L[i-32];
	}
	key=key1;
}/*
void round_decrypt(int no,int text[],int key[],int k3[])
{
	int L[32],R[32],R1[48],R2[32];
	for(int i=0;i<64;i++)
	{
		if(i<32)
		{
			L[i]=text[i];
		}
		else
		{
			R[i-32]=text[i];
		}
	}
	expansion(L,R1);
	int C[28],D[28],C1[28],D1[28];
	for(int i=0;i<56;i++)
	{
		if(i<28)
		{
			C[i]=key[i];
		}
		else
		{
			D[i-28]=key[i];
		}
	}
	shift_right(no,C,C1);
	shift_right(no,D,D1);
	int key1[56],key2[48];
	for(int i=0;i<56;i++)
	{
		if(i<28)
		{
			key1[i]=C1[i];
		}
		else
		{
			key1[i]=D1[i-28];
		}
	}
	perm_choice2(key,key2);
	for(int i=0;i<48;i++)
	{
		R1[i]=R1[i] ^ key2[i];
	}
	S_box(R1,R2);
	
	for(int i=0;i<32;i++)
	{
		k3[i]=R[i] ^ R2[i];
	}
	for(int i=32;i<64;i++)
	{
		k3[i]=L[i-32];
	}
	key=key1;
}
*/
int main()
{
	srand(time(NULL));

	int a[64]={0},b[64]={0},k1[64],k2[56]={0};
	for(int i=0;i<64;i++)
	{

		a[i]=rand()%2;
		k1[i]=rand()%2;
	}
	cout<<"Plain Text:\n";
	print(a,64);
	initial_perm(a,b);
	perm_choice1(k1,k2);


	int k3[64],d[64];
	for(int i=1;i<=16;i++)
	{
		round(i-1,b,k2,k3);
		for(int j=0;j<64;j++) b[j]=k3[j];
	}
	inv_initial_perm(b,d);
	cout<<"Encrypted text:\n";
	print(d,64);
	
}