#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
mpz_class gcdf(mpz_class a, mpz_class b)
{
    if (a == 0)
        return b;
    return gcdf(b%a, a);
}
mpz_class gcdExtended(mpz_class a, mpz_class b, mpz_class *x, mpz_class *y)
{
   
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    mpz_class x1, y1;
    mpz_class gcd = gcdExtended(b%a, a, &x1, &y1);
 
    
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int main(int argc, char const *argv[])
{
	mpz_class a,b,gcd;
	cin>>a>>b;
	cout<<gcdf(abs(a),abs(b))<<endl;
	mpz_class x,y;
	gcdExtended(abs(a),abs(b),&x,&y);
	if(a<0)x=-x;
	if(b<0)y=-y;
	cout<<x<<" "<<y<<endl;
	return 0;
}



