//............................Shwetang Singh	127157
//Euclidean,Extended Euclidean,Prime Factorization
#include<gmp.h>
#include<stdio.h>
void prime_factorize(mpz_t c)
{
	mpz_t e,d;
	mpz_inits(e,d,NULL);
	mpz_set_ui(d,2);
	while(mpz_cmp(d,c)<=0)
	{
		mpz_mod(e,c,d);
		if(mpz_sgn(e)==0)
		{
			mpz_out_str(stdout,10,d);
			mpz_div(c,c,d);
			printf("\t");
		}
		else
			mpz_nextprime(d,d);	
	}
}
void extended_euclidean_gcd(mpz_t a,mpz_t b)
{
	mpz_t x1,x2,y1,y2,q,temp;
	mpz_inits(x1,x2,y1,y2,q,temp,NULL);
	mpz_set_ui(x2,1);
	mpz_set_ui(y2,0);
	mpz_set_ui(x1,0);
	mpz_set_ui(y1,1);
	
	while((mpz_cmp(a,b)!=0)&&(mpz_sgn(a)!=0)&&(mpz_sgn(b)!=0)){

		if(mpz_cmp(a,b) > 0){
			mpz_div(q,a,b);
			printf("q = ");
			mpz_out_str(stdout,10,q);

			mpz_set(temp,x1);
			mpz_mul(x1,x1,q);
			mpz_sub(x1,x2,x1);
			mpz_set(x2,temp);

			mpz_set(temp,y1);
			mpz_mul(y1,y1,q);
			mpz_sub(y1,y2,y1);
			mpz_set(y2,temp);

			printf("\tx = ");
			mpz_out_str(stdout,10,x1);
			printf("\ty = ");
			mpz_out_str(stdout,10,y1);
			printf("\n");

			mpz_mod(a,a,b);	
		}	
		else{
			mpz_div(q,b,a);
			printf("q = ");
			mpz_out_str(stdout,10,q);

			mpz_set(temp,x1);
			mpz_mul(x1,x1,q);
			mpz_sub(x1,x2,x1);
			mpz_set(x2,temp);

			mpz_set(temp,y1);
			mpz_mul(y1,y1,q);
			mpz_sub(y1,y2,y1);
			mpz_set(y2,temp);

			printf("\tx = ");
			mpz_out_str(stdout,10,x1);
			printf("\ty = ");
			mpz_out_str(stdout,10,y1);
			printf("\n");

			mpz_mod(b,b,a);
		}
	}
	if(mpz_sgn(a))
	mpz_out_str(stdout,10,a);
	else
	mpz_out_str(stdout,10,b);
	printf("\n");	
}
void euclidean_gcd(mpz_t a,mpz_t b)
{
	while((mpz_cmp(a,b)!=0)&&(mpz_sgn(a)!=0)&&(mpz_sgn(b)!=0)){

		if(mpz_cmp(a,b) > 0){
			mpz_sub(a,a,b);	
		}	
		else{
			mpz_sub(b,b,a);
		}
	}
	if(mpz_sgn(a))
	mpz_out_str(stdout,10,a);
	else
	mpz_out_str(stdout,10,b);
	printf("\n");
}
int main(int argc,char *argv[])
{
	mpz_t c,d;
	mpz_inits(c,d,NULL);
	
	mpz_inp_str(c,stdin,10);
	mpz_inp_str(d,stdin,10);
	extended_euclidean_gcd(c,d);
	/*prime_factorize(c);
	printf("\n");*/
	
	return 0;
}
