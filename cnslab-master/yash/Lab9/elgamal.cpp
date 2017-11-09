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
	mpz_class g,q,x=0,y,k1=0,k,c1,c2,m,dk,dm,kinverse,gcd=0,p,res;
	// cout<<"Enter g and q\n";
	// cin>>g>>q;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state,time(NULL));
int check=0;
	mpz_urandomb(q.get_mpz_t(),state,8);
	cout<<q<<endl;
	while(check==0)
	{
		mpz_nextprime(q.get_mpz_t(),q.get_mpz_t());
		check=mpz_probab_prime_p(q.get_mpz_t(),25);
	}
	cout<<"Q="<<q<<endl;
	//generate alphA
	mpz_set_ui(p.get_mpz_t(),1);
	int cnt=10000;
	mpz_set_ui(res.get_mpz_t(),5);
	cout<<mpz_probab_prime_p(res.get_mpz_t(),10)<<endl;
	while(cnt>0){
		mpz_mul_ui(p.get_mpz_t(),p.get_mpz_t(),2);
		mpz_mul(res.get_mpz_t(),q.get_mpz_t(),p.get_mpz_t());
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
	cout<<"p="<<p<<"\n";
	findGenerator(g.get_mpz_t(),res.get_mpz_t(),p.get_mpz_t());
	cout<<"Generator="<<g<<endl;



	
	while(x==0)	
	{
		mpz_urandomb(x.get_mpz_t(),state,256);
		x=x%q;
	}
	mpz_powm(y.get_mpz_t(),g.get_mpz_t(),x.get_mpz_t(),q.get_mpz_t());
	cout<<"X="<<x<<endl;
	cout<<"Y="<<y<<endl;

 while(gcd!=1)
 {
	while(k1==0)	
	{
		mpz_urandomb(k1.get_mpz_t(),state,256);
		k1=k1%q;
	}
	mpz_powm(k.get_mpz_t(),y.get_mpz_t(),k1.get_mpz_t(),q.get_mpz_t());
	cout<<"K="<<k<<endl;
	mpz_gcd(gcd.get_mpz_t(),k.get_mpz_t(),q.get_mpz_t());
}
	mpz_powm(c1.get_mpz_t(),g.get_mpz_t(),k1.get_mpz_t(),q.get_mpz_t());
	cout<<"Enter message:\n";
	cin>>m;
	c2=(k*m)%q;
	cout<<"Cipher text:\n";
	cout<<c1<<" "<<c2<<endl;
	mpz_powm(dk.get_mpz_t(),c1.get_mpz_t(),x.get_mpz_t(),q.get_mpz_t());
	cout<<dk<<endl;
	mpz_invert(kinverse.get_mpz_t(),k.get_mpz_t(),q.get_mpz_t());
	cout<<"kinverse="<<kinverse<<endl;
	dm=(c2*kinverse)%q;
	cout<<"Decrypted text:\n";
	cout<<dm<<endl;
	return 0;
}