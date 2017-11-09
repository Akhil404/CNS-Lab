#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
mpz_class gcd(mpz_class a, mpz_class b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int main()
{
	int n;
	cout<<"Enter array size:\n";
	cin>>n;
	mpz_class num[n],rem[n],pp[n],product,inverse[n],ans;
	product=1;ans=0;
	cout<<"Number remainder format:\n";
	for (int i = 0; i < n; ++i)
	{
		cin>>num[i]>>rem[i];
		product=product*num[i];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j=0;j<n; ++j)

		{
			if(i!=j&&gcd(rem[i],rem[j])!=1){cout<<"Coprimes condition failed\n";return 0;}
			/* code */
		}
		/* code */
	}
	for (int i = 0; i < n; ++i)
	{
		pp[i]=product/num[i];
		mpz_invert(inverse[i].get_mpz_t(),num[i].get_mpz_t(),rem[i].get_mpz_t()); 
		cout<<inverse[i]<<" ";
		ans=ans+pp[i]*inverse[i]*rem[i];
	}
	//cout<<ans<<endl;
	cout<<ans%product<<endl;
}