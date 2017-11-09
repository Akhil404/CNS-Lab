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
int main(int argc, char const *argv[])
{
  mpz_t a,n,ans;
  mpz_inits(a,n,ans,NULL);
  gmp_scanf("%Zd%Zd",a,n);
  int inverse=find_inverse(ans,a,n);
  gmp_printf("%Zd\n",ans );
  return 0;
}