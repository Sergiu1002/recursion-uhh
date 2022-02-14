#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
ifstream f("intrare.in.txt");
ofstream g("iesire.out.txt");
int n = 10,v[100];

void citire()
{
 for(int i=1;i<=n;i++)
    f>>v[i];

}
int afis()
{ for(int i=1;i<=n;i++)
    cout<<v[i]<< " ";

}


int recursiv(int v[101], int n)
{
   if(n == 0)
      return 1;
   else
      if(v[n] % 2 != 0)
         return v[n] * recursiv(v, n-1);
      else
         return recursiv(v, n-1);
}


int ordonare()
{ int aux;
for(int i=1;i<=n-1;i++)
{ for(int j=i+1;j<=n;j++)
    if(v[i]>v[j])
    {aux=v[i];
    v[i]=v[j];
    v[j]=aux;
    }
}
}

int dive(int st, int dr)
{int mij;
mij=(st+dr)/2;
if(v[mij]==8)
      {
       g<<"Elementul cautat se afla pe pozitia "<<mij<<endl;
        return mij;
      }
     else
       {if(st<dr)
         { if(v[mij]>8)
            { dr=mij;
              div(st,dr);
            }
           else
             {st=mij;
              div(st,dr);
             }
         }
       else
        g<<"Nu exista";

       }
}




int main()
{  citire();
   afis();
cout<<endl<<endl;

for(int i = 1; i<=n;i++){
    cout<<v[i]<<endl;
}
g<<"Produsul elementelor impare este: "<<recursiv(v,n)<<endl;
cout<<"Produsul elementelor impare este: "<<recursiv(v,n)<<endl;
    ordonare();
    for(int i = 1; i<n;i++){
    cout<<v[i]<<endl;}
    cout<<endl;
    dive(1,n+1);

    return 0;
}
