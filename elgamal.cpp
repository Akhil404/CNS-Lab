#include<bits/stdc++.h>

#include<gmp.h>

using namespace std;

int main()
{
	int k;

	cout<<"enter the bit length of the prime"<<endl;

	cin>>k;

	unsigned long int  seed;

        gmp_randstate_t r_state;

        seed = time(NULL);

        gmp_randinit_default (r_state);
 
        gmp_randseed_ui(r_state, seed);

	mpz_t a,q,r,p,two,one,twenty;

	mpz_init(a); mpz_init(q); mpz_init(r); mpz_init(p); mpz_init(two); mpz_init(one); mpz_init(twenty);

	mpz_set_ui(two,2); mpz_set_ui(one,1); mpz_set_ui(twenty,20);

	do
	{
		mpz_urandomb(a,r_state,k);	

		mpz_nextprime(q,a);

		mpz_mul (r , q , two );

		mpz_add (p , r , one );

		if( mpz_probab_prime_p (p , 25 )==2) break;

	}while(1);	

	mpz_t g;

	mpz_init(g);

	mpz_set_ui(g,0);

	while(mpz_cmp(g,twenty)!=0)
	{
		
		mpz_add(g, g, one);
		
		mpz_powm (r ,g ,q , p);

		if(mpz_cmp(r,one)==0) continue;

		mpz_powm (r,g ,two, p);

		if(mpz_cmp(r,one)==0) continue;

		break;

	}

	gmp_printf("prime is %Zd and generator is %Zd \n",p,g);

	mpz_t XA,XB,YA,YB,k1,k2,M,kinv;

	mpz_init(XA); mpz_init(XB); mpz_init(YA); mpz_init(YB); mpz_init(k1); mpz_init(k2); mpz_init(M); mpz_init(kinv);

	mpz_urandomb (XA, r_state , k-1 );

	mpz_urandomb (XB, r_state , k-1 );

	gmp_printf("Alice secret key XA is %Zd and bob secret key YA is %Zd \n",XA,XB);

	mpz_powm(YA , g, XA, p);

	mpz_powm(YB, g, XB, p);
	
	gmp_printf("YA is %Zd and YB is %Zd \n",YA,YB);

	mpz_powm(k1, YB, XA, p);

	mpz_powm(k2,YA,XB,p);

	gmp_printf("shared key for alice is %Zd and bob is %Zd \n",k1,k2);

	mpz_urandomb(M, r_state, k-1);

	gmp_printf("message by bob is %Zd \n",M);

	mpz_mul(M,M,k2);
	
	mpz_mod(M,M,p);

	gmp_printf("message sent to alice is %Zd \n",M);

	mpz_invert (kinv, k1, p);

	mpz_mul(M,M,kinv);

	mpz_mod(M,M,p);

	gmp_printf("message decrypted by alice is %Zd \n",M);

	return 0;
}

		

		


