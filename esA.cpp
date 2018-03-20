#include<iostream>
#include<cstdlib>
#include<typeinfo>
#include<cmath>
using namespace std;
class A{
private:
    string w;
protected:
    short par=0;
public:
    A(string s,short n):w(s),par(n){}

int getsum()
{int sum=0;int sumv=0;
    for(int i=0;i<w.length();i++)
{if(w[i]=='a' || w[i]=='e' || w[i]=='i' ||w[i]=='o' || w[i]=='u' || w[i]=='A' || w[i]=='E' || w[i]=='I' ||w[i]=='O' || w[i]=='U' )
sumv=w[i]+sumv;

sum=w[i]+sum;

}

return sum-sumv;
}
virtual float*val(short *len)=0;
virtual ostream& put(ostream& stream) const{
			return stream << "w=" << w << ", par=" << par;
		}
};
class B:public A{
private:
string str;
public :
    B(string s,short n):A(s,n){
        str="";
        string g="@aeiou0123456789";
  for(int i=0;i<g.length();i++)
    {
        if(s.find(g[i])!=-1)
        {s.erase(s.find(g[i]),1);
        i=0;}
    }str=s;


    }
    float *val(short *len )
    {
        float *v=new float[str.length()];
        for(int i=0;i<str.length();i++)
        {
            v[i]=(float)str[i]/par;
        }
        *len=str.length();
        return v;
    }
ostream& put(ostream& stream) const{
			A::put(stream);
			return stream << " { str=" << str << "}";
		}

};
class C:public A{
private:
    float x;
private:
    string sc;
public:
    C(string s,short n):A(s,n),x(abs(sin((float)s.length()/par))),sc(s.substr(0,(int)(x*n+0.5))){
    }
    float * val(short *len)
    {float *v=new float[sc.length()];
        for(int i=0;i<sc.length();i++)
        {v[i]=log((int)sc[i]/x);

        }
    return v;}
    bool morethan(float y)
    {return x>=y;}
    ostream& put(ostream& stream) const{
			A::put(stream);
			return stream << " { x=" << x << ", sc=" << sc << "}";
		}

};
ostream& operator<<(ostream& stream, const A& a){
	return a.put(stream);}
	int main(){

	const int DIM=30;

	srand(111222333);
  A *vett[DIM];
  short r, r1, select;
  int l;
  string str;

  for(int i=0; i<DIM; i++){
    str = "";
    r = rand()%5+5;
    r1 = rand()%2;
    l = rand()%8 + 5;
    for(int j=0; j<l; j++){
      select = rand()%3;
      switch(select){
	case 0:
	  str+=(char) ('a' + rand()%25);
	  break;
	case 1:
	  str+=(char) ('0' + rand()%10);
	  break;
	case 2:
	  str+=(char) ('A' + rand()%25);
	  break;
      }

    if(r1)
      vett[i] = new B(str, r);
    else
      vett[i] = new C(str, r);
    }

    cout << i << ")Class " << typeid(*vett[i]).name() << ": " << *vett[i] << " getSum()=" << vett[i]->getsum() << endl << endl;
  }

	cout << "Punto II (valori medi degli array): ";
for(int i=0;i<DIM;i++)
    {for(int j=0;j<str.length();j++)
        {cout<<(vett[i]->val(&r))[j]<<" ";
        }cout<<endl;
}

return 0;
}

