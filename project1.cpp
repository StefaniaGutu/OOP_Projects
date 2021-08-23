#include<iostream>
#include<stdlib.h>
using namespace std;

class multime
{private:
    int nr;    ///nr de elemente din multime
    int elem[100];    ///multimea reprezentata ca tablou unidimensional
public:
    multime(int, int[]);
    multime(const multime&);
    ~multime();
    void eliminare_duplicate();   ///metoda publica de eliminare a duplicatelor din vector
    void set_nr_elemente (int);
    void set_elementele_multimii(int[]);
    int get_nr_elemente();
    int get_element_din_multime(int); ///getter pt elementul de pe o pozitie data
    multime& operator=(const multime &a); ///supraincarcare operator =
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, multime& z);  ///supraincarcare >>
    friend ostream& operator<<(ostream &out, multime& z); ///supraincarcare <<
    friend multime& operator+(multime& a, multime& b); ///supraincarcare operator +   pt reuniune
    friend multime& operator*(multime& a, multime& b); ///supraincarcare operator *   pt intersectie
    friend multime& operator-(multime& a, multime& b); ///supraincarcare operator -   pt diferenta
    friend void citire_n_multimi(multime[], int&);    ///functia prieten de citire a n multimi
};

multime::multime(int n=0, int vec[]=NULL)    ///constructor de initializare cu parametrii impliciti
    {
    if (n==0)
        nr=0;
    else
        {nr=n;
        for (int i=0;i<nr;i++)
            elem[i]=vec[i];
        }
    }
multime::multime(const multime &a)   ///constructor de copiere
    {this->nr=a.nr;
    for (int i=0;i<a.nr;i++)
        this->elem[i]=a.elem[i];
    }
multime::~multime()       ///destructor
   {
    nr=0;
   }

   ///Setter
void multime::set_nr_elemente(int nr)
    {
     this->nr=nr;
    }
void multime::set_elementele_multimii(int vec[])
    {
     for (int i=0;i<nr;i++)
            elem[i]=vec[i];
    }
   ///Getter
int multime::get_nr_elemente()
    {return nr;
    }
int multime::get_element_din_multime(int i)
    {return elem[i-1];
    }

multime& multime::operator=(const multime &a) ///supraincarcare operator atribuire
    {this->nr=a.nr;
    for (int i=0;i<a.nr;i++)
        this->elem[i]=a.elem[i];
    return *this;
    }

void multime::citire(istream &in)
    {
    cout<<"Introduceti numarul de elemente din multime:";
    in>>nr;
    cout<<"Elementele din multime sunt:";
    for (int i=0;i<nr;i++)
        in>>elem[i];
    }

istream& operator>>(istream& in,multime& a)    ///supraincarcare >>
    {
    a.citire(in);
    return in;
    }

void multime::afisare(ostream &out)
    {
    if (nr==0)
        out<<"Multimea este vida";
    else
        if (nr==1)
            out<<"{"<<elem[0]<<"}";
        else
            {out<<"{";
            for (int i=0;i<nr-1;i++)
                out<<elem[i]<<", ";
            out<<elem[nr-1]<<"}";
            }
    }

ostream& operator<<(ostream& out, multime& a)   ///supraincarcare <<
    {
    a.afisare(out);
    return out;
    }

void multime::eliminare_duplicate()
    {int aux,i,j;
    for (i=0;i<nr-1;i++)   ///se ordoneaza vectorul crescator
        for (j=i+1;j<nr;j++)
            if (elem[i]>elem[j])
                {aux=elem[i];
                elem[i]=elem[j];
                elem[j]=aux;
                }
    for (i=0;i<nr-1;i++)    ///se elimina duplicatele
        if (elem[i]==elem[i+1])
            {for (j=i+1;j<nr-1;j++)
                elem[j]=elem[j+1];
            nr=nr-1;
            i=i-1;
            }
    }

inline multime& operator+(multime& a, multime& b)   ///supraincarcare +  pt reuniune
    {
    multime *c = new multime;
    c->nr = a.nr + b.nr;
    for (int i=0;i<a.nr;i++)
        c->elem[i]=a.elem[i];
    for (int i=a.nr;i<a.nr + b.nr;i++)
        c->elem[i]=b.elem[i-a.nr];
    c->eliminare_duplicate();
    return *c;
    }

inline multime& operator*(multime& a, multime& b)   ///supraincarcare *  pt intersectie
    {
    multime *c = new multime;
    for (int i=0;i<a.nr;i++)
        for (int j=0;j<b.nr;j++)
            if (a.elem[i]==b.elem[j])
                {
                c->elem[c->nr]=a.elem[i];
                c->nr++;
                }
    c->eliminare_duplicate();
    return *c;
    }

inline multime& operator-(multime& a, multime& b)    ///supraincarcare -  pt diferenta
    {
    multime *c = new multime;
    int ok;
    for (int i=0;i<a.nr;i++)
        {ok=1;
        for (int j=0;j<b.nr;j++)
            if (a.elem[i]==b.elem[j])
                ok=0;
        if (ok==1)
            {c->elem[c->nr]=a.elem[i];
            c->nr++;
            }
        }
    c->eliminare_duplicate();
    return *c;
    }

void citire_n_multimi(multime a[], int& n)   ///functia prieten de citere a n multimi
    {int i;
    cout<<"Numarul de multimi:";
    cin>>n;
    while (n<1 || n>50)
        {cout<<"Va rugam sa introduceti un numar natural care apartine multimii {1, 2, 3, ... 50} ! \n\n";
        cout<<"Numarul de multimi:";
        cin>>n;
        }
    for (i=0;i<n;i++)
        {cout<<i+1<<". ";
        cin>>a[i];
        }
    cout<<endl<<"Ati introdus: ";
    for (i=0;i<n;i++)
        cout<<endl<<"Multimea "<<i+1<<": "<<a[i];
    }

///Meniu interactiv
void afisare_meniu()
    {
    cout<<"\n Proiect 1 - Multimi: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n=========================================================\n";
    cout<<"\n";
    cout<<"1. Citirea a n multimi (MAXIM 50 de multimi)"; cout<<"\n";
    cout<<"2. Eliminarea duplicatelor din multimile introduse"; cout<<"\n";
    cout<<"3. Reuniunea multimilor introduse"; cout<<"\n";
    cout<<"4. Intersectia multimilor introduse"; cout<<"\n";
    cout<<"5. Diferenta -> elem. care se afla in prima multime si nu se afla in celelalte"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
    }
void meniu()
    {int ok=0,i, n=0;
    int optiune;   ///optiunea aleasa din meniu
    optiune=0;
    multime a[50];       ///maxim 50 de multimi
    do
        {
        afisare_meniu();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>optiune;

        if (optiune==1)
            {
            ///Citirea a n multimi
            citire_n_multimi(a,n);
            ok=1;
            }
        if (ok==0 && optiune>1 && optiune<=5)
                cout<<"Va rugam sa introduceti multimile! Apasati 1!";
        else
            {
            if (optiune==2)
                {///Eliminarea duplicatelor
                for (i=0;i<n;i++)
                    a[i].eliminare_duplicate();
                cout<<"Am efectuat eliminarea duplicatelor";
                for (i=0;i<n;i++)
                    cout<<endl<<"Multimea "<<i+1<<": "<<a[i];
                }
            if (optiune==3)
                {
                ///Reuniunea
                multime c;
                //c=a[0];
                for (i=0;i<n;i++)
                    c=c+a[i];
                cout<<"Reuniunea este: "<<c;
                }
            if (optiune==4)
                {
                ///Intersectia
                multime d;
                d=a[0]*a[1];
                for (i=2;i<n;i++)
                    d=d*a[i];
                if (d.get_nr_elemente()==0)
                    cout<<"Multimile nu au elemente comune";
                else
                    cout<<"Intersectia este: "<<d;
                }
            if (optiune==5)
                {
                ///Diferenta
                multime e;
                e=a[0];
                for (i=1;i<n;i++)
                    e=e-a[i];
                if(e.get_nr_elemente()==0)
                    cout<<"Toate elementele din prima multime se gasesc in celelalte multimi";
                else
                    cout<<"Diferenta este: "<<e;
                }
            if (optiune==0)
                {
                cout<<"\nEXIT!\n";
                }
            if (optiune<0||optiune>5)
                {
                cout<<"\nSelectie invalida\n";
                }
            }
        cout<<"\n\n";
        if (optiune!=0)
            {
            system("pause"); ///Press any key to continue...
            system("cls");   ///Sterge continutul curent al consolei
            }
        }
    while(optiune!=0);
    }


int main()
{
meniu();
return 0;
}
