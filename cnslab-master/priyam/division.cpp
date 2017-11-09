#include <bits/stdc++.h>
using namespace std;
struct poly {
    int n;
    int * arr;
};
void addorsub (poly a ,poly b,poly & res)
{
    int n= a.n;
    if(b.n>n)
        n=b.n;
    res.n=n;
    res.arr=new int[n+1];
    for(int i=0;i<=res.n;i++)
            res.arr[i]=0;
    for(int i=0;i<=a.n;i++)
        res.arr[i]=a.arr[i];
    for(int i=0;i<=b.n;i++)
        res.arr[i]=(res.arr[i]+b.arr[i])%2;

    res.n=-1;
    for(int i=0;i<=n;i++)
        if(res.arr[i]==1)
            res.n=i;
}
void copypol(poly a ,poly &b)
{
    b.n=a.n;
    b.arr=new int[b.n+1];
    for(int i=0;i<=b.n;i++)
        b.arr[i]=a.arr[i];

}
void mul(poly a,poly b,poly m,poly &res)
{

    int n1=a.n;
    int n2=b.n;
    int n3=m.n;
    vector < vector <int >  > coeff(n3+1,vector <int > (n3+1,0) );
    for(int i=0;i<=n1;i++)
        coeff[0][i]=a.arr[i];
    for(int i=1;i<=n2;i++)
    {
        for(int j=n3;j>0;j--)
            coeff[i][j]=coeff[i-1][j-1];
        coeff[i][0]=0;
    }
    int k=n3;
    while(coeff[n2][k]==0)
        k--;
    res.n=k;
    res.arr=new int [n3+1];
    for(int i=0;i<=n3;i++)
        res.arr[i]=0;
    for(int i=0;i<=n2;i++)
    {
        if(b.arr[i]==1)
        {
            for(int j=0;j<=n3;j++)
            {
                res.arr[j]=(res.arr[j]+coeff[i][j])%2;

            }

        }
    }
    res.n=-1;
    for(int i=0;i<=n3;i++)
    {
        if(res.arr[i]==1)
            res.n=i;

    }

}

void mul2(poly a,poly b,poly m,poly &res)
{

    int n1=a.n;
    int n2=b.n;
    int n3=m.n;
    vector < vector <int >  > coeff(n3+1,vector <int > (n3+1,0) );
    for(int i=0;i<=n1;i++)
        coeff[0][i]=a.arr[i];
    for(int i=1;i<=n2;i++)
    {
        for(int j=n3;j>0;j--)
            coeff[i][j]=coeff[i-1][j-1];
        coeff[i][0]=0;
       
        if(coeff[i][n3]==1)
        {
            coeff[i][n3]=0;
            for(int j=(n3-1);j>=0;j--)
            {
                coeff[i][j]=(coeff[i][j]+m.arr[j])%2;

            }

        }
        
    }
    int k=n3;
    while(coeff[n2][k]==0)
        k--;
    res.n=k;
    res.arr=new int [n3+1];
    for(int i=0;i<=n3;i++)
        res.arr[i]=0;
    for(int i=0;i<=n2;i++)
    {
        if(b.arr[i]==1)
        {
            for(int j=0;j<=n3;j++)
            {
                res.arr[j]=(res.arr[j]+coeff[i][j])%2;

            }

        }
    }
    res.n=-1;
    for(int i=0;i<=n3;i++)
    {
        if(res.arr[i]==1)
            res.n=i;

    }

}


void divquorem(poly a ,poly b ,poly & q ,poly & r)
{
    // does a/b
    poly t ;
    t.n=a.n;
    q.arr=new int [a.n+1];
    r.arr=new int [a.n+1];

    t.arr =new int [t.n+1];
    for(int i=0;i<=t.n;i++)
       {
            t.arr[i]=a.arr[i];
            q.arr[i]=0;
            r.arr[i]=0;
       }


int cnt=0;
    while(t.n !=-1  && (t.n >=b.n))
    {
        cnt++;
        int k=t.n-b.n;
        q.arr[t.n-b.n]=1;
        for(int i=0;i<=b.n;i++)
        {
            t.arr[i+k]=(t.arr[i+k]+b.arr[i])%2;

        }
        t.n=-1;
        for(int i=0;i<=a.n;i++)
        {
            if(t.arr[i]==1)
                t.n=i;

        }

    }
    if(t.n!=-1)
        {
            r.n=t.n;
            for(int i=0;i<=r.n;i++)
                r.arr[i]=t.arr[i];

        }
    q.n=0;
    for(int i=0;i<=a.n;i++)
        if(q.arr[i]==1)
            q.n=i;


}
void displaypol(poly a)
{
    for(int i=a.n;i>0;i--)
    {
        if(a.arr[i])
        {
            cout<<"x^"<<i<<" + ";
        }
    }
    cout<<a.arr[0];
    cout<<endl;

}
void extgcd (poly a[],poly b[],poly m1,poly m2)
{
    // m1 is irreducible poly
    //poly a[3],b[3];
    copypol(m1,a[2]);
    copypol(m2,b[2]);
    a[0].n=0;
    a[0].arr=new int [a[0].n+1];
    a[0].arr[0]=1;

    a[1].n=0;
    a[1].arr=new int [a[0].n+1];
    a[1].arr[0]=0;

    b[0].n=0;
    b[0].arr=new int [b[0].n+1];
    b[0].arr[0]=0;

    b[1].n=0;
    b[1].arr=new int [b[0].n+1];
    b[1].arr[0]=1;
   
    int cnt =0;
    while(true){
            cnt++;

            if(b[2].n==0 && (b[2].arr[0]<=1))
            return ;
            poly q,r ;
            divquorem(a[2],b[2],q,r);

            poly t[3];
            poly t2[3];

            mul(q,b[0],m1,t2[0]);
            addorsub(a[0],t2[0],t[0]);

            mul(q,b[1],m1,t2[1]);
            addorsub(a[1],t2[1],t[1]);

            mul(q,b[2],m1,t2[2]);
            addorsub(a[2],t2[2],t[2]);

            copypol(b[0],a[0]);
            copypol(b[1],a[1]);
            copypol(b[2],a[2]);

            copypol(t[0],b[0]);
            copypol(t[1],b[1]);
            copypol(t[2],b[2]);
    }

}
int main()
{
    poly a,b,m,res;
    cout<<" enter degree of 1st polynomial \n";
    cin>>a.n;
    a.arr=new int[a.n+1];
    cout<<" enter the coeff \n ";
    for(int i=a.n;i>=0;i--)
        cin>>a.arr[i];

    cout<<" enter degree of 2nd polynomial \n";
    cin>>b.n;
    b.arr=new int[b.n+1];
    cout<<" enter the coeff for low deg to high degree \n ";
    for(int i=b.n;i>=0;i--)
        cin>>b.arr[i];

    cout<<" enter degree of irrreducible  polynomial \n";
    cin>>m.n;
    m.arr=new int[m.n+1];
    cout<<" enter the coeff for low deg to high degree \n ";
    for(int i=m.n;i>=0;i--)
        cin>>m.arr[i];

    poly t1[3],t2[3];
    extgcd(t1,t2,m,b);
    cout<<" the inverse is \n ";
    displaypol(t2[1]);

    cout<<"divide is \n ";
    poly ans ;
    mul2(a,t2[1],m,ans);
    displaypol(ans);

}