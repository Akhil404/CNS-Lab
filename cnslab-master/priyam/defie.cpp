#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;


void out(string str,mpz_t a){
	cout<<str<<" :";;
	mpz_out_str(stdout,10,a);
	cout<<"\n";

}

void inp(mpz_t a){
	mpz_inp_str(a,stdin,10);
}

void findGenerator(mpz_t res,mpz_t n,mpz_t p){

	gmp_randstate_t r_state;
	gmp_randinit_default(r_state);
	gmp_randseed_ui(r_state,time(NULL));
	int cnt=1000;
	mpz_t act,temp,check,alpha;
	mpz_inits(act,temp,check,alpha,NULL);
	mpz_set_ui(res,-1);
	mpz_sub_ui(act,n,1);
	while(cnt>0){
		mpz_urandomm(alpha,r_state,n);
		mpz_div_ui(temp,act,2);
		mpz_powm(check,alpha,temp,n);
		if(mpz_cmp_ui(check,1)==0){
			continue;
		}
		mpz_div(temp,act,p);
		mpz_powm(check,alpha,temp,n);
		if(mpz_cmp_ui(check,1)==0){
			continue;
		}
		mpz_set(res,alpha);
		return ;


	}
	return ;

}


int main(){

	gmp_randstate_t r_state;
	gmp_randinit_default(r_state);
	gmp_randseed_ui(r_state,time(NULL));
	mpz_t p,q,res,gen,temp,a,b,key;
	mpz_inits(p,q,res,gen,key,temp,a,b,NULL);
	mpz_set_ui(temp,1);
	int cnt=100000;
	mpz_urandomb(p,r_state,8);
	mpz_nextprime(p,p);
	out("p",p);
	mpz_set_ui(q,1);

	mpz_set_ui(res,5);
	cout<<mpz_probab_prime_p(res,10)<<endl;
	while(cnt>0){
		mpz_mul_ui(q,q,2);
		mpz_mul(res,p,q);
		mpz_add_ui(res,res,1);
		out("res" ,res);
		cnt--;
		cout<<mpz_probab_prime_p(res,10)<<endl;
		if(mpz_probab_prime_p(res,10)==2){
			break;
		}
		//cout<<cnt<<endl;

	}
	if(cnt==0){
		cout<<"nhi mila\n";
		return 0;
	}
	else
		cout<<"mila\n";
	out("res",res);
	out("q_val",q);
	findGenerator(gen,res,p);
	cnt=100;
	while(cnt>0){
		mpz_mul(temp,gen,temp);
		mpz_mod(temp,temp,res);
		cnt--;
		out("temp",temp);
	}
	out("generator",gen);

	mpz_urandomb(a,r_state,8);
	mpz_urandomb(b,r_state,8);

	mpz_powm(key,gen,a,res);
	mpz_powm(key,key,b,res);
	out("Diffie Hellman Key",key);
}
