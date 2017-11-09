#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
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
		cout<<alpha<<"is alpha"<<endl;
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
int main(int argc, char const *argv[])
{
	mpz_class p,a,b,g,alice,bob,key1,key2,q,res;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state,time(NULL));
	int check=0;
	mpz_urandomb(p.get_mpz_t(),state,20);
	cout<<p<<endl;
	while(check==0)
	{
		mpz_nextprime(p.get_mpz_t(),p.get_mpz_t());
		check=mpz_probab_prime_p(p.get_mpz_t(),25);
	}
	cout<<"P="<<p<<endl;
	//generate alphA
	mpz_set_ui(q.get_mpz_t(),1);
	int cnt=10000;
	mpz_set_ui(res.get_mpz_t(),5);
	cout<<mpz_probab_prime_p(res.get_mpz_t(),10)<<endl;
	while(cnt>0){
		mpz_mul_ui(q.get_mpz_t(),q.get_mpz_t(),2);
		mpz_mul(res.get_mpz_t(),p.get_mpz_t(),q.get_mpz_t());
		mpz_add_ui(res.get_mpz_t(),res.get_mpz_t(),1);
		cout<<"res="<<res<<"\n";
		cnt--;
		cout<<mpz_probab_prime_p(res.get_mpz_t(),10)<<endl;
		if(mpz_probab_prime_p(res.get_mpz_t(),10)==2){
			break;
		}
		//cout<<cnt<<endl;

	}
	if(cnt==0){
		return 0;
	}
	else
		cout<<"res found\n";
	cout<<"res="<<res<<"\n";
	cout<<"q="<<q<<"\n";
	findGenerator(g.get_mpz_t(),res.get_mpz_t(),p.get_mpz_t());
	cout<<"Generator="<<g<<endl;


	mpz_urandomb(a.get_mpz_t(),state,10);
	mpz_urandomb(b.get_mpz_t(),state,10);
	cout<<"Generated a at Alice="<<a<<endl;
	cout<<"Generated b at Bob="<<b<<endl;
	mpz_powm(alice.get_mpz_t(),g.get_mpz_t(),a.get_mpz_t(),p.get_mpz_t());
	mpz_powm(bob.get_mpz_t(),g.get_mpz_t(),b.get_mpz_t(),p.get_mpz_t());
	mpz_powm(key1.get_mpz_t(),alice.get_mpz_t(),b.get_mpz_t(),p.get_mpz_t());
	mpz_powm(key2.get_mpz_t(),bob.get_mpz_t(),a.get_mpz_t(),p.get_mpz_t());
	cout<<key1<<" "<<key2<<endl;
	cout<<"Key exchange completed\n";
	return 0;
}