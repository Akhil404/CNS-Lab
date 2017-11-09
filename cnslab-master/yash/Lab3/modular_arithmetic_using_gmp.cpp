#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;
void find_exgcd(mpz_t gcd,mpz_t a,mpz_t b,mpz_t x,mpz_t y)
{
   if(mpz_sgn(a)==0)
   {
      mpz_set_si(x,0);
      mpz_set_si(y,1);
      mpz_set(gcd,b);
      //mpz_abs(gcd,gcd);
      return;
   }
   // else if(mpz_sgn(b)==0)
   // {
   //    mpz_set(gcd,a);
   //    return;
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
   mpz_tdiv_q(temp1,b,a);
   mpz_mul(temp2,temp1,x1);
   mpz_sub(x,y1,temp2);
   mpz_set(y,x1);
}
void addition(mpz_t a,mpz_t b,mpz_t n)
{
   cout<<"Addition: ";
   mpz_t amodn,bmodn,amodnoperationbmodn,aoperationb,aoperationbmodn;
   mpz_init(amodn);
   mpz_init(bmodn);
   mpz_init(aoperationb);
   mpz_init(amodnoperationbmodn);
   mpz_init(aoperationbmodn);
   mpz_mod(amodn,a,n);
   mpz_mod(bmodn,b,n);
   mpz_add(amodnoperationbmodn,amodn,bmodn);
   mpz_mod(amodnoperationbmodn,amodnoperationbmodn,n);
   mpz_add(aoperationb,a,b);
   mpz_mod(aoperationbmodn,aoperationb,n);
   cout<<amodnoperationbmodn<<" "<<aoperationbmodn<<endl;
}
void subtraction(mpz_t a,mpz_t b,mpz_t n)
{
   cout<<"Subtraction: ";
   mpz_t amodn,bmodn,amodnoperationbmodn,aoperationb,aoperationbmodn;
   mpz_init(amodn);
   mpz_init(bmodn);
   mpz_init(aoperationb);
   mpz_init(amodnoperationbmodn);
   mpz_init(aoperationbmodn);
   mpz_mod(amodn,a,n);
   mpz_mod(bmodn,b,n);
   mpz_sub(amodnoperationbmodn,amodn,bmodn);
   mpz_mod(amodnoperationbmodn,amodnoperationbmodn,n);
   mpz_sub(aoperationb,a,b);
   mpz_mod(aoperationbmodn,aoperationb,n);
   cout<<amodnoperationbmodn<<" "<<aoperationbmodn<<endl;
}
void multiply(mpz_t a,mpz_t b,mpz_t n)
{
   cout<<"Multiplication: ";
   mpz_t amodn,bmodn,amodnoperationbmodn,aoperationb,aoperationbmodn;
   mpz_init(amodn);
   mpz_init(bmodn);
   mpz_init(aoperationb);
   mpz_init(amodnoperationbmodn);
   mpz_init(aoperationbmodn);
   mpz_mod(amodn,a,n);
   mpz_mod(bmodn,b,n);
   mpz_mul(amodnoperationbmodn,amodn,bmodn);
   mpz_mod(amodnoperationbmodn,amodnoperationbmodn,n);
   mpz_mul(aoperationb,a,b);
   mpz_mod(aoperationbmodn,aoperationb,n);
   cout<<amodnoperationbmodn<<" "<<aoperationbmodn<<endl;
}

int find_inverse(mpz_t binverse,mpz_t b,mpz_t n)
{
      mpz_t x, y,gcd; // used in extended GCD algorithm
      mpz_init(x);
      mpz_init(y);
      mpz_init(gcd);
      find_exgcd(gcd,b,n,x,y);
    //if gcd !=1 return 
     // cout<<gcd<<x<<y<<endl;
      mpz_mod(x,x,n);
      mpz_add(x,x,n);
      mpz_mod(x,x,n);
      mpz_set(binverse,x);
    // m is added to handle negative x
    return 1;
}
void divide_by_finding_inverse(mpz_t ans,mpz_t a,mpz_t b,mpz_t n)
{
    mpz_mod(a,a,n);

	mpz_t binverse;
	mpz_init(binverse);
	mpz_invert(binverse,b,n);
   //int returnval=find_inverse(binverse,b,n);
   //cout<<"Inverse "<<binverse<<endl;
	//if(returnval==0){cout<<"Inverse does not exist";return;}
	mpz_t temp;
	mpz_init(temp);
	mpz_mul(temp,a,binverse);
    mpz_mod(ans,temp,n);
}
void division(mpz_t a,mpz_t b,mpz_t n)
{
cout<<"Division: ";
   mpz_t amodn,bmodn,amodndividebmodnmodn,adividebmodn;
   mpz_init(amodn);
   mpz_init(bmodn);
   mpz_init(amodndividebmodnmodn);
   mpz_init(adividebmodn);
   mpz_mod(amodn,a,n);
   mpz_mod(bmodn,b,n);

   divide_by_finding_inverse(amodndividebmodnmodn,amodn,bmodn,n);
   divide_by_finding_inverse(adividebmodn,a,b,n);

   cout<<amodndividebmodnmodn<<" "<<adividebmodn<<endl;
}
int main()
{
   mpz_t a,b,n;
   mpz_init(a);
   mpz_init(b);
   mpz_init(n);
   cout<<"Enter a,b,n\n";
   cin>>a>>b>>n;
   addition(a,b,n);
   subtraction(a,b,n);
   multiply(a,b,n);
   division(a,b,n);
   
}