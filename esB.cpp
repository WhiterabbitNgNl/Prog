#include<iostream>
#include<typeinfo>
#include<math.h>
#include<stdlib.h>
#include <time.h>

using namespace std;
class A{
private:
float x;
string st;
public:
    A(int *vec,short n)
    {
        int med=0;st="";
        for(int i=0;i<n;i++)
            {
            med+=vec[i];
            st=st+(char)vec[i];
            }
        x=(float)med/n;
    }
    protected:
    short getfirtvowel()
    {int cont=0;
        for(int i=0;i<st.length();i++)
    {if(st[i]=='a'||st[i]=='e'|| st[i]=='i'|| st[i]=='o'|| st[i]=='u')
      {cont++;
          return i;
      }
    }if(cont==0)
    {
        return -1;
    }


    }
    public:
    virtual int f()=0;
    virtual ostream& put(ostream& stream) const{
			return stream << "x=" << x << ", st=" << st;
		}

};
class B:public A
{private :
    float* values;
    short len;
public :
    B(int* vec,short n):A(vec,n){
        len=n;
        float* v=new float [n];
        values=v;
        for(int i=0;i<len;i++)
            {
                v[i]=log(vec[i]);
            }
        }
        int f()
        {int temp=(int)(values[0]+0.5);
            for(int i=1;i<len;i++)
        {
                if(temp>values[i])
                {temp=(int)(values[i]+0.5);

                }
        }return temp;
        }
        ostream& put(ostream& stream) const{
			A::put(stream);
			stream <<"[";
			for(int i=0;i<len;i++)
			 {stream <<values[i] << " ";}
			 stream<<"]"<<","<<"len ="<<len;
			 return stream;
		}
};
class C:public A{
private:
int i;
public:
    C(int* vec,short n):A(vec,n)
    {
    i=(vec[rand()%n+1]%50);
    }
    int f()
    {return i+getfirtvowel();
    }
    bool morethan(int y)
    {
        return i>=y;
    }

 ostream& put(ostream& stream) const{
			A::put(stream);
			return stream << " { i=" << i<<"}";
		}
};
ostream& operator<<(ostream& stream, const A& a){
	return a.put(stream);}
int main()
{  const int DIM=30;
    srand(111222333);
  A *vett[DIM];
  short l, select;
  int *vec;

  for(int i=0; i<DIM; i++){
    l = rand()%8 + 5;
    select = rand()%2;
    vec = new int[l];

    for(int c=0; c<l; c++)
      vec[c] = 97 + rand()%25;

    if(select)
      vett[i] = new B(vec, l);
     else
      vett[i] = new C(vec, l);


 cout<<"Class"<<typeid(*vett[i]).name()<<':'<<*vett[i]<<"f()="<<vett[i]->f()<<endl;
    }

}
