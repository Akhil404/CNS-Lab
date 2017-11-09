#include<gmp.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter size of array ";
	cin>>n;
	mpz_t num[n], rem[n], inverse[n], eprod[n], prod, asum, temp, ans;
	mpz_inits(prod, asum, temp, ans, NULL);
	mpz_set_ui(prod, 1);
	mpz_set_ui(asum, 0);
	for(int i=0; i<n; i++)
	{
		mpz_inits(num[i], rem[i], eprod[i], inverse[i], NULL);
		cout<<"Enter number and remainder : ";
		gmp_scanf("%Zd %Zd", num[i], rem[i]);
		mpz_mul(prod, prod, num[i]);
	}
	for(int i=0; i<n; i++)
	{
		mpz_tdiv_q(eprod[i], prod, num[i]);
//		cout<<endl<<i;
//		gmp_printf("  %Zd", eprod[i]);
		mpz_invert(inverse[i], eprod[i], num[i]);
//		gmp_printf("  %Zd", inverse[i]);
		mpz_mul(temp, inverse[i], eprod[i]);
//		gmp_printf("  %Zd", temp);
		mpz_mul(temp, temp, rem[i]);
//		gmp_printf("  %Zd", temp);
		mpz_add(asum, asum, temp);
//		gmp_printf("  %Zd", asum);
	}
	mpz_mod(ans, asum, prod);
	gmp_printf("\nSolution is = %Zd \n", ans);
}
