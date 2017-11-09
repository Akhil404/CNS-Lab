#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;
class polynomial{
public:
	int degree;
int prime;
vector<mpz_class>coeffs;
	polynomial()
	{
		degree=0;prime=0;
		coeffs.clear();

	}

friend istream& operator>>(istream&,polynomial&);
friend ostream& operator<<(ostream&,polynomial&);
friend polynomial operator+(polynomial& a,polynomial& b);
friend polynomial operator*(polynomial& a,polynomial& b);
};

istream& operator>>(istream& in,polynomial &a)
{
	cout<<"Enter degree:";in>>a.degree;
	cout<<"Enter prime:";in>>a.prime;
	a.coeffs.resize(a.degree+1);
	cout<<"Enter coefficients:";
	for(int i=0;i<=a.degree;i++)
	{
		in>>a.coeffs[i];
	}
	return in;
}

ostream& operator<<(ostream& out,polynomial& a)
{
	out<<"degree:"<<a.degree<<endl;
	for (int i = 0; i <=a.degree; ++i)
	{
		out<<a.coeffs[i]<<"x^"<<i<<" ";
		/* code */
	}
	out<<endl;
	return out;
}
polynomial operator+(polynomial& a,polynomial &b)
{

	polynomial c;
	if(a.prime!=b.prime)
	{
		cout<<"Addition not possible";return c;
	}
	c.degree=max(a.degree,b.degree);
	c.coeffs.resize(c.degree+1);
	int i;
	for (i = 0; i <= min(a.degree,b.degree); ++i)
	{
		c.coeffs[i]=(a.coeffs[i]+b.coeffs[i])%a.prime;
	}
	for(;i<=a.degree;++i)
	{
		c.coeffs[i]=(a.coeffs[i])%a.prime;
	}
	for(;i<=b.degree;++i)
	{
		c.coeffs[i]=(b.coeffs[i])%a.prime;
	}
	return c;
}
polynomial operator*(polynomial& a,polynomial &b)
{

	polynomial c;
	if(a.prime!=b.prime)
	{
		cout<<"Multiplication not possible";return c;
	}
	c.degree=(a.degree+b.degree);
	c.coeffs.resize(c.degree+1);
	
	for (int i = 0; i <= a.degree; ++i)
	{
		for (int j= 0; j<=b.degree; ++j)
		{
			c.coeffs[i+j]=(c.coeffs[i+j]+a.coeffs[i]*b.coeffs[j])%a.prime;
		}
		
	}
	return c;
}
int main(int argc, char const *argv[])
{
	polynomial pol1,pol2,pol3;
	cin>>pol1>>pol2;
	cout<<"Addition:\n";
	pol3=pol1+pol2;
    
	cout<<pol3;
	cout<<"Multiplication:\n";
	pol3=pol1*pol2;
	cout<<pol3;
	return 0;
}