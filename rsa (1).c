#include<stdio.h>
#include<gmp.h>
int main()
{
mpz_t p,q,p1,q1,C;
unsigned long int seed,n1;
gmp_randstate_t state;
seed=time(NULL);
gmp_randinit_default(state);
gmp_randseed_ui(state,seed);
mpz_init(p);
mpz_init(C);
mpz_init(p1);
mpz_init(q1);
mpz_init(q);
int r;
gmp_printf("enter the number of bits");
gmp_scanf("%d",&r);
mpz_urandomb(p,state,r);
mpz_urandomb(q,state,r);
while(mpz_probab_prime_p (p , 25 )!=2)
{
mpz_urandomb(p,state,r);
}
while(mpz_probab_prime_p (q , 25 )!=2)
{
mpz_urandomb(q,state,r);
}
gmp_printf("\np:%Zd  q:%Zd\n",p,q);
mpz_t n,phi,e,d,flag,gcd;
mpz_init(n);
mpz_init(gcd);
mpz_init(phi);
mpz_init(e);
mpz_init(d);
mpz_init(flag);
mpz_set_ui(flag,0);

mpz_mul(n,p,q);
mpz_sub_ui(p1,p,1);
mpz_sub_ui(q1,q,1);

mpz_mul(phi,p1,q1);
mpz_mod(e, e, phi);
while(mpz_cmp_ui(flag,0)==0)
{
mpz_urandomb(e,state,r);
mpz_mod(e, e, phi);
mpz_gcd(gcd,phi,e);
if(mpz_cmp_ui(gcd,1)==0) 
{
	mpz_set_ui(flag,1);
}
}
gmp_printf("e:%Zd\n",e);
mpz_t t,D;
mpz_init(t);
mpz_init(D);
mpz_invert(d,e,phi);
gmp_printf("d:%Zd\n",d);
unsigned long int text;
scanf("%lu",&text);
mpz_set_ui(t,text);
mpz_powm(C,t,e,n);
mpz_powm(D,C,d,n);
gmp_printf("\nCipher text:%Zd",C);
gmp_printf("\nPlain text:%Zd\n",D);
}
