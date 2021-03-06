#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif
#include "algoritmi.h"
#include <cstdlib>
using namespace std;

const char menu[] =
"1. Fibonacci ricorsivo\n"
"2. Fibonacci polinomiale\n"
"3. Moltiplicazione\n"
"4. Divisione\n"
"5. Euclid (MCD)\n"
"6. Extended Euclid\n"
"7. Instertion Sort\n"
"8. Merge Sort\n";

int main(int argc, const char *argv[])
{
  int *a,x,y,n,temp,num_elem = 0;
  Dresult result_D;
  euclid result_MCD;
  EE result_EE;
  while(true)
  {
    cout<<menu<<endl;
    unsigned int scelta;
    cin>>scelta;
    switch(scelta)
    {
      case 1:
        cout<<"inserisci n ";
        cin>>n;
        temp = fibonacci1(n);
        cout<<temp<<endl;
        break;
      case 2:
        cout<<"inserisci n ";
        cin>>n;
        temp = fibonacci2(n);
        cout<<temp<<endl;
        break;
      case 3:
        do {
          cout<<"inserisci x e y ";
          cin>>x>>y;
          if(y<0)
            cerr<<"y deve essere maggiore di 0";
        } while (y<0);
        cout<< moltiplicazione(x,y)<<endl;
        break;
      case 4:
        cout<<"inserisci x e y ";
        cin>>x>>y;
        result_D = result_D.divisione(x,y);
        cout<<"il quoziente e' "<<result_D.q<<" e il resto e' "<<result_D.r<<endl;
        break;
      case 5:
        do {
          cout<<"inserisci a e b ";
          cin>>x>>y;
          if(x<y)
            cout<<"a deve essere maggiore di b"<<endl;
        } while (x<y && x < 0);
        result_MCD = result_MCD.MCD(x,y);
        cout<<result_MCD.a<<endl;
        break;
      case 6:
        do {
          cout<<"inserisci a e b ";
          cin>>x>>y;
          if (x<y) {
            cout<<"a deve essere maggiore di b"<<endl;
          }
        } while (x<y && x < 0);
        result_EE = result_EE.Extended_Euclid(x,y);
        cout<<"x = "<<result_EE.x<<endl;
        cout<<"y = "<<result_EE.y<<endl;
        cout<<"d = "<<result_EE.d<<endl;
        break;
      case 7:
        do {
          cout<<"Lunghezza array? ";
          cin>>num_elem;
        } while (num_elem<= 0);
        a = new int[num_elem];
        srand(time(0));
        for (int i = 0; i < num_elem; i++) {
          a[i] = rand();
        }
        cout<<"array non ordinato: ";
        for (int i = 0; i < num_elem; i++) {
          cout<<i+1<<" / "<<num_elem<<" "<<a[i]<<endl;
        }
        cout<<"ordino..."<<endl;
        insertion_sort(a,num_elem);
        cout<<"Ordinato!"<<endl;
        for (int i = 0; i < num_elem; i++) {
          cout<<i+1<<" / "<<num_elem<<a[i]<<endl;
        }
        delete [] a;
//        cout<<"premi qualsiasi tasto per continuare."<<endl;
//        cin>>temp;
        break;
      default:
        cerr<<"error\n"<<endl;

    }
  }
  return 0;

}
