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
polynomial m;
istream& operator>>(istream& in,polynomial &a)
{
	cout<<"Enter degree:";
	in>>a.degree;
	cout<<"Enter prime:";
	in>>a.prime;

	a.coeffs.resize(max(a.degree+1,m.degree));
	cout<<"Enter coefficients starting from x^0:";
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
	c.prime=a.prime;
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
polynomial add_to_temp(polynomial temp,polynomial a,int times)
{
	for (int i = 0; i <=min(a.degree,temp.degree); ++i)
	{
		temp.coeffs[i]=a.coeffs[i];
		/* code */
	}
	for (int i = 0; i < times; ++i)
	{
		bool flag=false;
		if(temp.coeffs[temp.degree]==1)flag=true;
		for (int j=temp.degree-1;j>=0; j--)
		{
			temp.coeffs[j+1]=temp.coeffs[j];
			/* code */
		}
		temp.coeffs[0]=0;
		//cout<<times<<"\n";
		//cout<<temp;
		if(flag)
		{
			for (int j=0;j<=temp.degree; ++j)
			{
				temp.coeffs[j]=temp.coeffs[j]^m.coeffs[j];
				/* code */
			}
			//do xor
			//cout<<"After xor:\n";
			//cout<<temp;
		}

		//shift coeffs

		/* code */
	}
	return temp;
}
polynomial operator*(polynomial& a,polynomial &b)
{

	polynomial c;
	if(a.prime!=b.prime)
	{
		cout<<"Multiplication not possible";return c;
	}
	polynomial temp;
	temp.degree=m.degree-1;
	temp.prime=2;
	temp.coeffs.resize(temp.degree+1);
	for (int i = 0; i <=temp.degree; ++i)
	{
		temp.coeffs[i]=0;
		/* code */
	}
	polynomial answer;
	answer.degree=m.degree-1;
	answer.prime=2;
	answer.coeffs.resize(answer.degree+1);
	for (int i = 0; i <=answer.degree; ++i)
	{
		answer.coeffs[i]=0;
		/* code */
	}
	for (int i = 0; i <=b.degree; ++i)
	{
		if(b.coeffs[i]==1)
		{
			
			polynomial temp2=add_to_temp(temp,a,i);
			answer=answer+temp2;
			//cout<<"Added\n";
			//cout<<answer;
		}
		/* code */
	}
	return answer;

}
void input_mx()
{
	cout<<"Enter m(x):\n";
	cin>>m;
}
int main(int argc, char const *argv[])
{

	cout<<"Multiplication over GF(2^n):"<<endl;
	input_mx();
	polynomial pol1,pol2,pol3;
	cout<<"Enter f(x):\n";
	cin>>pol1;
	cout<<"Enter g(x):\n";
	cin>>pol2;
	cout<<"Multiplication:\n";
	pol3=pol1*pol2;
	cout<<"Final Answer:\n";
	cout<<pol3;
	return 0;
}