#include<stdio.h>
#include<gmp.h>

void clear(mpz_t *P){
	int i;
	for(i=0;i<1024;i++){
		mpz_init2(P[i],0);
	}
}

int main()
{
	mpz_t *P,*Q;
	P=malloc(1024*sizeof(mpz_t));
	Q=malloc(1024*sizeof(mpz_t));

	mpz_t x,y;
	mpz_init(x);
	mpz_init(y);
	while(1){
		clear(P);
		clear(Q);
		printf("Enter the no of terms in polynomial 1:");
		int n,m;
		scanf("%d",&n);
		printf("Enter the no of terms in polynomial 2:");
		scanf("%d",&m);
		printf("Enter the exp - coeff pairs for poly 1:\n");
		for(i=0;i<n;i++){
			scanf("%d
		
