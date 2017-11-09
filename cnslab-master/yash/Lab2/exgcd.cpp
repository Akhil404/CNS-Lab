#include<gmp.h>
void find_exgcd(mpz_t gcd,mpz_t a,mpz_t b,mpz_t x,mpz_t y)
{
	if(mpz_sgn(a)==0)
	{
		mpz_set_si(x,0);
		mpz_set_si(y,1);
		mpz_set(gcd,b);
		return;
	}
	// else if(mpz_sgn(b)==0)
	// {
	// 	mpz_set(gcd,a);
	// 	return;
	// }
	mpz_t x1,y1,bmoda;
	mpz_init(x1);
	mpz_init(y1);
	mpz_init(bmoda);
	mpz_mod(bmoda,b,a);
	find_exgcd(gcd,bmoda,a,x1,y1);

	mpz_t temp1,temp2;
	mpz_init(temp1);
	mpz_init(temp2);
	mpz_div_q(temp1,b,a);
	mpz_mul(temp2,temp1,x1);
	mpz_sub(x,y1,temp2);
	mpz_set(y,x1);
}
int main(int argc, char const *argv[])
{
	mpz_t a,b,gcd,x,y;
	mpz_init(a);
	mpz_init(b);
	mpz_init(gcd);
	mpz_init(x);
	mpz_init(y);
	gmp_printf("Input  numbers:");
	gmp_scanf("%Zd %Zd",a,b);
	find_exgcd(gcd,a,b,x,y);
	mpz_abs(gcd,gcd);
	gmp_printf("Gcd is: %Zd\n",gcd);
	gmp_printf("X and Y are:%Zd %Zd\n",x,y);
	return 0;
}