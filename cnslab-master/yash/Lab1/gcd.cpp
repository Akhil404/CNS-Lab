#include <gmp.h>
#include <bits/stdc++.h>
using namespace std;
void
mpz_gcd_eucl_usr(mpz_t gcd, mpz_t u, mpz_t v)
{
	mpz_t temp;
	mpz_init(temp);
    if (mpz_sgn(u) == 0)
    {
        mpz_set(gcd, v);
        return;
    }

    if (mpz_sgn(v) == 0)
    {
        mpz_set(gcd, u);
        return; 
    }
    while(mpz_sgn(v) != 0)
    {
        mpz_set(temp, v);
        mpz_fdiv_r(v, u, temp);//mpz_mod(v,u,temp);
        mpz_set(u, temp);
    }
    
    mpz_set(gcd, u);
    return;
}

int main()
{
	mpz_t a,b,gcd;
	mpz_init(a);
	mpz_init(b);
	mpz_init(gcd);
gmp_printf("Please input the value of first number: ");
			gmp_scanf("%Zd", a);
			gmp_printf("Please input the value of second number: ");
			gmp_scanf("%Zd", b);
			//gmp_printf("\nValues has been successfully stored.");

	
	mpz_gcd_eucl_usr(gcd, a, b);
	mpz_abs(gcd,gcd);
	gmp_printf("Gcd is %Zd\n",gcd);
	//cout<<sum;
}