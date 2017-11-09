#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;
int NO_OF_BITS=10;
int main(int argc, char const *argv[])
{
	mpz_class p,q,n,phi_n,e,d,gcd,m;
	gmp_randstate_t state;
	gmp_randinit_mt(state);
	gmp_randseed_ui(state, time(NULL));
	int check=0;
	mpz_urandomb(p.get_mpz_t(),state,NO_OF_BITS);
	//cout<<p<<endl;
	while(check==0)
	{
		mpz_nextprime(p.get_mpz_t(),p.get_mpz_t());
		//cout<<p<<endl;
		check=mpz_probab_prime_p(p.get_mpz_t(),50);
	}
	check=0;
	mpz_urandomb(q.get_mpz_t(),state,NO_OF_BITS);
	//cout<<q<<endl;
	while(check==0)
	{
		mpz_nextprime(q.get_mpz_t(),q.get_mpz_t());
		//cout<<q<<endl;
		check=mpz_probab_prime_p(q.get_mpz_t(),50);
	}
	n=p*q;
	phi_n=(p-1)*(q-1);
	cout<<"P="<<p<<endl;
	cout<<"Q="<<q<<endl;
	cout<<"N="<<n<<endl;
	cout<<"PHI_N="<<phi_n<<endl;
	check=0;gcd=2;
	while(gcd!=1)
	{
		mpz_urandomb(e.get_mpz_t(),state,NO_OF_BITS);
		mpz_gcd(gcd.get_mpz_t(),e.get_mpz_t(),phi_n.get_mpz_t());
		
	}
	mpz_invert(d.get_mpz_t(),e.get_mpz_t(),phi_n.get_mpz_t());
	cout<<"E="<<e<<"\n"<<"D="<<d<<endl;
	cout<<(e*d)%phi_n<<endl;
	cout<<"Enter message:\n";
	cin>>m;
	cout<<"Encrypted message:\n";
	mpz_powm(m.get_mpz_t(),m.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
	cout<<m<<endl;
	cout<<"Decrypted message:\n";
	mpz_powm(m.get_mpz_t(),m.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
	cout<<m<<endl;
	return 0;
}