#include <bits/stdc++.h>
using namespace std;
int permutation_table[64],inverse_permutation_table[64];
void initial_permutation(int in[],int out[])
{
	for (int i = 0; i < 64; ++i)
	{
		permutation_table[i]=i;
	}
	for (int i = 0; i < 64; ++i)
	{
		int a=rand()%64;
		int b=rand()%64;
		swap(permutation_table[a],permutation_table[b]);
	}
	cout<<"Permutation table:";
	for (int i = 0; i < 64; ++i)
	{	if(i%8==0)cout<<"\n";
		cout<<permutation_table[i]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 64; ++i)
	{
		out[i]=in[permutation_table[i]];
		/* code */
	}
}
void print(int a[])
{
	cout<<endl;
	for (int i = 0; i < 64; ++i)
	{
		cout<<a[i]<<" ";
		/* code */
	}
	cout<<endl;
}
void inverse_permutation(int in[],int out[])
{
	for (int i = 0; i < 64; ++i)
	{
		inverse_permutation_table[permutation_table[i]]=i;
		/* code */
	}
	cout<<"Inverse Permutation table:";
	for (int i = 0; i < 64; ++i)
	{	if(i%8==0)cout<<"\n";
		cout<<inverse_permutation_table[i]<<" ";
	}
	cout<<endl;
	for (int i = 0; i < 64; ++i)
	{
		out[i]=in[inverse_permutation_table[i]];
		/* code */
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int plain_text[64];
	for (int i = 0; i < 64; ++i)
	{
		plain_text[i]=i;		/* code */
	}
	int plain_text_permuted[64],plain_text_inverse_permuted[64];
	initial_permutation(plain_text,plain_text_permuted);
	//print(plain_text_permuted);
	inverse_permutation(plain_text_permuted,plain_text_inverse_permuted);
	//print(plain_text_inverse_permuted);
	return 0;
}