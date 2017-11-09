#include<stdio.h>
#include<gmp.h>


int main()
{
mpz_t rand1, rand2, rand3;
unsigned long int seed;
gmp_randstate_t state;
seed =time(NULL);
gmp_randinit_default(state);
gmp_randseed_ui(state,seed);
mpz_init(rand1);
mpz_init(rand2);
mpz_init(rand3);
int r;
gmp_printf("enter the number of bits");
gmp_scanf("%d",&r);
mpz_urandomb(rand1,state,r);
mpz_urandomb(rand2,state,r);
mpz_urandomb(rand3,state,r);
while(mpz_probab_prime_p (rand1 , 25 )!=2)
{
mpz_urandomb(rand1,state,r);
}

mpz_t p;
mpz_init(p);
mpz_set(p,rand1);
mpz_mul_ui(p,p,2);
mpz_add_ui(p,p,1);

while(mpz_probab_prime_p (p, 25 )!=2)
{

mpz_nextprime (rand1,rand1 );
mpz_set(p,rand1);
mpz_mul_ui(p,p,2);
mpz_add_ui(p,p,1);
}

mpz_t base;
mpz_init(base);
mpz_set_ui(base,1);
mpz_t gen;
mpz_init(gen);
int i,j;
for( i=1 ,j=0; i<=20 && j==0; i++)
{

mpz_t x;
mpz_init(x);
mpz_powm (x ,  base , rand1, p );
mpz_t y;
mpz_init(y);
mpz_powm_ui (y ,  base ,  2 , p );
if(mpz_cmp_ui(x,1)!=0 && mpz_cmp_ui(y,1)!=0)
{
j=1;
mpz_set(gen, base);
}

mpz_add_ui(base, base, 1);
}

gmp_printf("\n");
gmp_printf("selected numbers are %Zd %Zd\t %Zd\n", p, gen, rand1);
mpz_mod(rand2, rand2, p);
while(mpz_cmp_ui(rand2,0)==0)
{

mpz_urandomb(rand2,state,r);
mpz_mod(rand2, rand2, p);

}
mpz_mod(rand3, rand3, p);
while(mpz_cmp_ui(rand3,0)==0)
{

mpz_urandomb(rand3,state,r);
mpz_mod(rand3, rand3, p);

}
mpz_t  xb, yb;
mpz_init(xb);
mpz_init(yb);
 mpz_powm (xb ,  gen , rand2, p );
mpz_powm (yb ,  gen , rand3, p );
gmp_printf("the Xa is %Zd\n", rand2);
gmp_printf("the Ya is %Zd\n", rand3);
gmp_printf("the Xb is %Zd\n", xb);
gmp_printf("the Yb is %Zd\n", yb);
mpz_powm(xb, xb, rand3, p);

gmp_printf("the key is %Zd", xb);


return 0;
}
