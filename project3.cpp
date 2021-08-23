#include<iostream>
#include<stdlib.h>
#include<set>
#include<utility>
using namespace std;

    ///Clasa Automobil
class Automobil
{protected:
    string producator;
    string model;
    int an_fabricatie;
    int pret;
    static int nr_auto;   ///variabila statica folosita pentru a retine cate automobile avem declarate si pentru a genera id-urile
    const int id;   ///variabila constanta folosita pentru a retine id-ul

public:
    Automobil(string, string, int, int);
    Automobil (const Automobil&);
    virtual ~Automobil();   ///destructor virtual
    Automobil& operator=(const Automobil&);   ///supraincarcare operator atribuire
    virtual void citire(istream &in);  ///citire virtuala
    virtual void afisare(ostream &out); ///afisare virtuala
    friend istream& operator>>(istream&, Automobil&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Automobil&);  ///supraincarcare operator <<
    bool operator<(const Automobil& a) const
    {
        if (this->pret<a.pret)
            return true;
        else
            return false;
    }
    static void numarAutomobile(){ /// metoda statica de afisare a numarului de automobile
        cout<<nr_auto;
    }
    int get_id() const;
};
int Automobil::nr_auto; ///declararea variabilei statice

Automobil::Automobil(string prod="", string m="", int an=0, int p=0):id(++nr_auto)
    {try{
        for (int i=0;i<prod.length();i++)
            if (prod[i]<'A' || prod[i]>'z')
                throw 'a';
        if (an!=0 && (an<1985 || an>2021))
            throw 1;
        if (p<0)
            throw "ab";
        }
    catch(char c)
        {cout<<"Denumirea producatorului poate contine doar litere.";
        exit(EXIT_FAILURE);
        }
    catch(int i)
        {cout<<"Anul fabricatiei trebuie sa fie in intervalul 1985-2021.";
        exit(EXIT_FAILURE);
        }
    catch (string s)
        {cout<<"Pretul nu poate fi negativ.";
        exit(EXIT_FAILURE);
        }
    pret=p;
    producator=prod;
    model=m;
    an_fabricatie=an;
    }
Automobil::Automobil(const Automobil& a):id(a.id)
    {this->producator=a.producator;
    this->model=a.model;
    this->an_fabricatie=a.an_fabricatie;
    this->pret=a.pret;
    }
Automobil::~Automobil()
    {producator="";
    model="";
    an_fabricatie=0;
    pret=0;
    }
Automobil& Automobil::operator=(const Automobil& a)
    {this->producator=a.producator;
    this->model=a.model;
    this->an_fabricatie=a.an_fabricatie;
    this->pret=a.pret;
    return *this;
    }
Automobil::get_id() const
    {return id;
    }
void Automobil::citire(istream &in)
    {string z;
    int an, p;
    cout<<"Producator: ";
    getline(in,z);
    try{
        for (int i=0;i<z.length();i++)
            if (z[i]<'A' || z[i]>'z')
                throw 'a';
        }
    catch(char c)
        {cout<<"Denumirea producatorului poate contine doar litere."<<endl;
        exit(EXIT_FAILURE);
        }
    producator=z;
    cout<<"Model: ";
    getline(in,z);
    model=z;
    cout<<"Anul fabricatiei: ";
    in>>an;
    try{
        if (an<1985 || an>2021)
            throw 1;
        }
    catch(int i)
        {cout<<"Anul fabricatiei trebuie sa fie in intervalul 1985-2021."<<endl;
        exit(EXIT_FAILURE);
        }
    an_fabricatie=an;
    cout<<"Pret: ";
    in>>p;
    try{
        if (p<0)
            throw "ab";
        }
    catch (string s)
        {cout<<"Pretul nu poate fi negativ.";
        exit(EXIT_FAILURE);
        }
    pret=p;
    }
istream& operator>>(istream& in, Automobil& a)    ///supraincarcare operator >>
    {
    a.citire(in);
    return in;
    }
void Automobil::afisare(ostream &out)
    {out<<"ID automobil: "<<id<<endl;
    out<<"Producator: "<<producator<<endl;
    out<<"Model: "<<model<<endl;
    out<<"Anul fabricatiei: "<<an_fabricatie<<endl;
    out<<"Pret: "<<pret<<endl;
    }
ostream& operator<<(ostream& out, Automobil& a)   ///supraincarcare operator <<
    {
    a.afisare(out);
    return out;
    }

    ///Clasa Mini
class Mini: public Automobil
{private:
    float lungime;

public:
    Mini(string, string, int,int, float);
    Mini (const Mini&);
    ~Mini();
    Mini& operator=(const Mini&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Mini&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Mini&);    ///supraincarcare operator <<
};

Mini::Mini(string prod="", string m="", int an=0, int p=0, float l=0):Automobil(prod,m,an,p)
    {try
        {if (l<0 || l>4)
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Mini nu poate fi negativa sau mai mare decat 4m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
Mini::Mini(const Mini& m):Automobil(m)
    {this->lungime=m.lungime;
    }
Mini::~Mini()
    {lungime=0;
    }
Mini& Mini::operator=(const Mini& m)
    {this->producator=m.producator;
    this->model=m.model;
    this->an_fabricatie=m.an_fabricatie;
    this->pret=m.pret;
    this->lungime=m.lungime;
    return *this;
    }
void Mini::citire(istream &in)
    {Automobil::citire(in);
    cout<<"Lungime: ";
    float l;
    in>>l;
    try
        {if (l<0 || l>4)
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Mini nu poate fi negativa sau mai mare decat 4m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
istream& operator>>(istream& in, Mini& m)    ///supraincarcare operator >>
    {
    m.citire(in);
    return in;
    }
void Mini::afisare(ostream &out)
    {Automobil::afisare(out);
    cout<<"Lungime: "<<lungime<<"m"<<endl;
    }
ostream& operator<<(ostream& out, Mini& m)   ///supraincarcare operator <<
    {
    m.afisare(out);
    return out;
    }

    ///Clasa Mica
class Mica: public Automobil
{private:
    float lungime;

public:
    Mica(string, string, int, int, float);
    Mica (const Mica&);
    ~Mica();
    Mica& operator=(const Mica&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Mica&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Mica&);    ///supraincarcare operator <<
};

Mica::Mica(string prod="", string m="", int an=0, int p=0, float l=0):Automobil(prod,m,an,p)
    {try
        {if (l!=0 && (l<3.85 || l>4.1))
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Mica nu poate fi mai mica decat 3.85m sau mai mare decat 4.1m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
Mica::Mica(const Mica& m):Automobil(m)
    {this->lungime=m.lungime;
    }
Mica::~Mica()
    {lungime=0;
    }
Mica& Mica::operator=(const Mica& m)
    {this->producator=m.producator;
    this->model=m.model;
    this->an_fabricatie=m.an_fabricatie;
    this->pret=m.pret;
    this->lungime=m.lungime;
    return *this;
    }
void Mica::citire(istream &in)
    {Automobil::citire(in);
    cout<<"Lungime: ";
    float l;
    in>>l;
    try
        {if (l<3.85 || l>4.1)
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Mica nu poate fi mai mica decat 3.85m sau mai mare decat 4.1m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
istream& operator>>(istream& in, Mica& m)    ///supraincarcare operator >>
    {
    m.citire(in);
    return in;
    }
void Mica::afisare(ostream &out)
    {Automobil::afisare(out);
    out<<"Lungime: "<<lungime<<"m"<<endl;
    }
ostream& operator<<(ostream& out, Mica& m)   ///supraincarcare operator <<
    {
    m.afisare(out);
    return out;
    }

    ///Clasa Compacta
class Compacta: public Automobil
{protected:
    float lungime;

public:
    Compacta(string, string, int, int, float);
    Compacta (const Compacta&);
    ~Compacta();
    Compacta& operator=(const Compacta&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Compacta&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Compacta&);    ///supraincarcare operator <<
};

Compacta::Compacta(string prod="", string m="", int an=0, int p=0, float l=0):Automobil(prod,m,an,p)
    {try
        {if (l!=0 && (l<4.2 || l>4.5))
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Compacta nu poate fi mai mica decat 4.2m sau mai mare decat 4.5m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
Compacta::Compacta(const Compacta& c):Automobil(c)
    {this->lungime=c.lungime;
    }
Compacta::~Compacta()
    {lungime=0;
    }
Compacta& Compacta::operator=(const Compacta& c)
    {this->producator=c.producator;
    this->model=c.model;
    this->an_fabricatie=c.an_fabricatie;
    this->pret=c.pret;
    this->lungime=c.lungime;
    return *this;
    }
void Compacta::citire(istream &in)
    {Automobil::citire(in);
    cout<<"Lungime: ";
    float l;
    in>>l;
    try
        {if (l<4.2 || l>4.5)
            throw 1;
        }
    catch(int i)
        {cout<<"Lungimea masinii Compacta nu poate fi mai mica decat 4.2m sau mai mare decat 4.5m."<<endl;
        exit(EXIT_FAILURE);
        }
    lungime=l;
    }
istream& operator>>(istream& in, Compacta& c)    ///supraincarcare operator >>
    {
    c.citire(in);
    return in;
    }
void Compacta::afisare(ostream &out)
    {Automobil::afisare(out);
    out<<"Lungime: "<<lungime<<"m"<<endl;
    }
ostream& operator<<(ostream& out, Compacta& c)   ///supraincarcare operator <<
    {
    c.afisare(out);
    return out;
    }

    ///Clasa Compacta Hatchback
class Compacta_Hatchback: public Compacta
{private:

public:
    Compacta_Hatchback(string, string, int, int, float);
    Compacta_Hatchback (const Compacta_Hatchback&);
    ~Compacta_Hatchback();
    Compacta_Hatchback& operator=(const Compacta_Hatchback&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Compacta_Hatchback&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Compacta_Hatchback&);    ///supraincarcare operator <<
};

Compacta_Hatchback::Compacta_Hatchback(string prod="", string m="", int an=0, int p=0, float l=0):Compacta(prod,m,an,p,l)
    {
    }
Compacta_Hatchback::Compacta_Hatchback(const Compacta_Hatchback& c):Compacta(c)
    {
    }
Compacta_Hatchback::~Compacta_Hatchback()
    {
    }
Compacta_Hatchback& Compacta_Hatchback::operator=(const Compacta_Hatchback& c)
    {this->producator=c.producator;
    this->model=c.model;
    this->an_fabricatie=c.an_fabricatie;
    this->pret=c.pret;
    this->lungime=c.lungime;
    return *this;
    }
void Compacta_Hatchback::citire(istream &in)
    {Compacta::citire(in);
    }
istream& operator>>(istream& in, Compacta_Hatchback& c)    ///supraincarcare operator >>
    {
    c.citire(in);
    return in;
    }
void Compacta_Hatchback::afisare(ostream &out)
    {Compacta::afisare(out);
    }
ostream& operator<<(ostream& out, Compacta_Hatchback& c)   ///supraincarcare operator <<
    {
    c.afisare(out);
    return out;
    }

    ///Clasa Compacta Combi
class Compacta_Combi: public Compacta
{private:

public:
    Compacta_Combi(string, string, int, int, float);
    Compacta_Combi (const Compacta_Combi&);
    ~Compacta_Combi();
    Compacta_Combi& operator=(const Compacta_Combi&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Compacta_Combi&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Compacta_Combi&);    ///supraincarcare operator <<
};

Compacta_Combi::Compacta_Combi(string prod="", string m="", int an=0, int p=0, float l=0):Compacta(prod,m,an,p,l)
    {
    }
Compacta_Combi::Compacta_Combi(const Compacta_Combi& c):Compacta(c)
    {
    }
Compacta_Combi::~Compacta_Combi()
    {
    }
Compacta_Combi& Compacta_Combi::operator=(const Compacta_Combi& c)
    {this->producator=c.producator;
    this->model=c.model;
    this->an_fabricatie=c.an_fabricatie;
    this->pret=c.pret;
    this->lungime=c.lungime;
    return *this;
    }
void Compacta_Combi::citire(istream &in)
    {Compacta::citire(in);
    }
istream& operator>>(istream& in, Compacta_Combi& c)    ///supraincarcare operator >>
    {
    c.citire(in);
    return in;
    }
void Compacta_Combi::afisare(ostream &out)
    {Compacta::afisare(out);
    }
ostream& operator<<(ostream& out, Compacta_Combi& c)   ///supraincarcare operator <<
    {
    c.afisare(out);
    return out;
    }

    ///Clasa Compacta Sedan
class Compacta_Sedan: public Compacta
{private:

public:
    Compacta_Sedan(string, string, int, int, float);
    Compacta_Sedan (const Compacta_Sedan&);
    ~Compacta_Sedan();
    Compacta_Sedan& operator=(const Compacta_Sedan&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Compacta_Sedan&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Compacta_Sedan&);    ///supraincarcare operator <<
    friend bool operator== (const Compacta_Sedan&, const Compacta_Sedan&);
};

Compacta_Sedan::Compacta_Sedan(string prod="", string m="", int an=0, int p=0, float l=0):Compacta(prod,m,an,p,l)
    {
    }
Compacta_Sedan::Compacta_Sedan(const Compacta_Sedan& c):Compacta(c)
    {
    }
Compacta_Sedan::~Compacta_Sedan()
    {
    }
Compacta_Sedan& Compacta_Sedan::operator=(const Compacta_Sedan& c)
    {this->producator=c.producator;
    this->model=c.model;
    this->an_fabricatie=c.an_fabricatie;
    this->pret=c.pret;
    this->lungime=c.lungime;
    return *this;
    }
void Compacta_Sedan::citire(istream &in)
    {Compacta::citire(in);
    }
istream& operator>>(istream& in, Compacta_Sedan& c)    ///supraincarcare operator >>
    {
    c.citire(in);
    return in;
    }
void Compacta_Sedan::afisare(ostream &out)
    {Compacta::afisare(out);
    }
ostream& operator<<(ostream& out, Compacta_Sedan& c)   ///supraincarcare operator <<
    {
    c.afisare(out);
    return out;
    }
bool operator== (const Compacta_Sedan& m1, const Compacta_Sedan& m2)
    {if(m1.producator==m2.producator && m1.model==m2.model && m1.an_fabricatie==m2.an_fabricatie && m1.pret==m2.pret && m1.lungime==m2.lungime)
            return true;
    return false;
    }

    ///Clasa Monovolum
class Monovolum: public Automobil
{private:
    int nr_locuri;
    bool nou;
    int ani_vechime;

public:
    Monovolum(string, string, int, int, int, bool, int);
    Monovolum (const Monovolum&);
    ~Monovolum();
    Monovolum& operator=(const Monovolum&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Monovolum&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Monovolum&);    ///supraincarcare operator <<
    bool get_nou();
    int get_pret();
    int get_ani_vechime();
    friend bool operator== (const Monovolum&, const Monovolum&);
};

Monovolum::Monovolum(string prod="", string m="", int an=0, int p=0, int nr=0, bool n=true, int ani=0):Automobil(prod,m,an,p)
    {try
        {if (nr!=0 && (nr<5 || nr>7))
            throw 1;
        if (ani<0)
            throw 'a';
        }
    catch(int i)
        {cout<<"Numarul de locuri dintr-o masina Monovolum trebuie sa fie intre 5 si 7."<<endl;
        exit(EXIT_FAILURE);
        }
    catch(int i)
        {cout<<"Vechimea nu poate fi un numar negativ."<<endl;
        exit(EXIT_FAILURE);
        }
    if (n)
        ani_vechime=ani;
    nr_locuri=nr;
    }
Monovolum::Monovolum(const Monovolum& m):Automobil(m)
    {this->nr_locuri=m.nr_locuri;
    this->nou=m.nou;
    this->ani_vechime=m.ani_vechime;
    }
Monovolum::~Monovolum()
    {nr_locuri=0;
    nou=true;
    ani_vechime=0;
    }
Monovolum& Monovolum::operator=(const Monovolum& m)
    {this->producator=m.producator;
    this->model=m.model;
    this->an_fabricatie=m.an_fabricatie;
    this->pret=m.pret;
    this->nr_locuri=m.nr_locuri;
    this->nou=m.nou;
    this->ani_vechime=m.ani_vechime;
    return *this;
    }
bool Monovolum::get_nou()
    {return nou;
    }
int Monovolum::get_pret()
    {return pret;
    }
int Monovolum::get_ani_vechime()
    {return ani_vechime;
    }
void Monovolum::citire(istream &in)
    {Automobil::citire(in);
    cout<<"Nr locuri: ";
    int nr, ani;
    in>>nr;
    try
        {if (nr<5 || nr>7)
            throw 1;
        }
    catch(int i)
        {cout<<"Numarul de locuri dintr-o masina Monovolum trebuie sa fie intre 5 si 7."<<endl;
        exit(EXIT_FAILURE);
        }
    nr_locuri=nr;
    cout<<"Masina este noua? (da/nu) ";
    string x;
    in.get();
    getline(in, x);
    if (x=="da")
        nou=true;
    else
        {nou=false;
        cout<<"Ani vechime: ";
        in>>ani;
        try
            {if (ani<0)
                throw 1;
            }
        catch(int i)
            {cout<<"Vechimea nu poate fi negativa."<<endl;
            exit(EXIT_FAILURE);
            }
        ani_vechime=ani;
        }
    }
istream& operator>>(istream& in, Monovolum& m)    ///supraincarcare operator >>
    {
    m.citire(in);
    return in;
    }
void Monovolum::afisare(ostream &out)
    {Automobil::afisare(out);
    out<<"Nr locuri: "<<nr_locuri<<endl;
    if (nou)
        out<<"Masina este noua"<<endl;
    else
        out<<"Masina nu este noua, are "<<ani_vechime<<" ani vechime"<<endl;
    }
ostream& operator<<(ostream& out, Monovolum& m)   ///supraincarcare operator <<
    {
    m.afisare(out);
    return out;
    }
bool operator== (const Monovolum& m1, const Monovolum& m2)
    {if(m1.producator==m2.producator && m1.model==m2.model && m1.an_fabricatie==m2.an_fabricatie && m1.pret==m2.pret)
        if(m1.nr_locuri==m2.nr_locuri && m1.nou==m2.nou && m1.ani_vechime==m2.ani_vechime)
            return true;
    return false;
    }

    ///Clasa template Vanzare
template <typename T>
class Vanzare
{private:
    int nr_masini_stoc;
    int nr_masini_vandute;
    set<pair<T, bool> > masini_stoc;
    set<pair<T,bool> > masini_vandute;
public:
    Vanzare()
        {nr_masini_stoc=0;
        nr_masini_vandute=0;
        masini_stoc.clear();
        masini_vandute.clear();
        }
    Vanzare(int nr_stoc,int nr_vandute,set<pair<T,bool> > m_stoc,set<pair<T,bool> > m_vandute)
        {nr_masini_stoc=nr_stoc;
        nr_masini_vandute=nr_vandute;
        if (nr_stoc)
            masini_stoc(m_stoc.begin(), m_stoc.end());
        if (nr_vandute)
            masini_vandute(m_vandute.begin(), m_vandute.end());
        }
    Vanzare(const Vanzare& v)
        {this->nr_masini_stoc=v.nr_masini_stoc;
        this->nr_masini_vandute=v.nr_masini_vandute;
        this->masini_stoc(v.masini_stoc.begin(), v.masini_stoc.end());
        this->masini_vandute(v.masini_vandute.begin(), v.masini_vandute.end());
        }
    ~Vanzare()
        {masini_stoc.clear();
        masini_vandute.clear();
        nr_masini_stoc=0;
        nr_masini_vandute=0;
        }
    Vanzare& operator=(const Vanzare& v)
        {this->nr_masini_stoc=v.nr_masini_stoc;
        this->nr_masini_vandute=v.nr_masini_vandute;
        this->masini_stoc(v.masini_stoc.begin(), v.masini_stoc.end());
        this->masini_vandute(v.masini_vandute.begin(), v.masini_vandute.end());
        return *this;
        }

    friend ostream& operator<<(ostream& out, Vanzare<T>& v) ///supraincarcare operator <<
        {out<<"Nr de masini in stoc: "<<v.nr_masini_stoc<<endl;
        int i=1;
        typename set<pair<T,bool> >::iterator it;
        if(v.nr_masini_stoc!=0)
            for(it=v.masini_stoc.begin();it!=v.masini_stoc.end();it++)
                {out<<"Masina nr."<<i<<endl;
                out<<*const_cast<T*>(&it->first);
                if (it->second)
                    out<<"Masina este noua"<<endl;
                else
                    out<<"Masina nu este noua"<<endl;
                out<<endl;
                i++;
                }
        out<<endl;
        out<<"Nr de masini vandute: "<<v.nr_masini_vandute<<endl;
        i=1;
        typename set<pair<T,bool> >::iterator it2;
        if (v.nr_masini_vandute!=0)
            for(it2=v.masini_vandute.begin();it2!=v.masini_vandute.end();it2++)
                {out<<"Masina nr."<<i<<endl;
                out<<*const_cast<T*>(&it2->first);
                if (it2->second)
                    out<<"Masina este noua"<<endl;
                else
                    out<<"Masina nu este noua"<<endl;
                out<<endl;
                i++;
                }
        return out;
        }

    friend istream& operator>>(istream& in, Vanzare<T>& v)  ///supraincarcare operator >>
        {cout<<"Nr de masini in stoc: ";
        in>>v.nr_masini_stoc;
        T m;
        for(int i=0;i<v.nr_masini_stoc;i++)
            {in.get();
            cout<<"Masina nr."<<i+1<<endl;
            in>>m;
            pair<T,bool> p;
            p.first=m;
            p.second=true;
            cout<<endl;
            (v.masini_stoc).insert(p);
            }
        cout<<endl;
        cout<<"Nr de masini vandute: ";
        in>>v.nr_masini_vandute;
        for(int i=0;i<v.nr_masini_vandute;i++)
            {in.get();
            cout<<"Masina nr."<<i+1<<endl;
            in>>m;
            cout<<"Masina este noua? ";
            pair<T,bool> p;
            p.first=m;
            p.second=true;
            cout<<endl;
            v.masini_vandute.insert(p);
            }
        return in;
        }

    Vanzare& operator-=( const pair<T, bool>& m)
        {typename set<pair<T,bool> >::iterator it;
        it=masini_stoc.find(m);
        if (*it==m)
            {this->nr_masini_stoc=this->nr_masini_stoc-1;
            this->nr_masini_vandute=this->nr_masini_vandute+1;
            masini_stoc.erase(m);
            masini_vandute.insert(m);
            }
        else
            cout<<endl<<"Masina introdusa nu a fost gasita"<<endl;
        return *this;
        }
};

template <>
class Vanzare <Monovolum>
{private:
    int nr_masini_stoc;
    int nr_masini_vandute;
    set<pair<Monovolum, bool> > masini_stoc;
    set<pair<Monovolum,bool> > masini_vandute;
    int nr_masini_noi_stoc;
    bool luna; ///1 pt lunile de vara, 0 pentru celelalte
public:
    Vanzare()
        {nr_masini_stoc=0;
        nr_masini_vandute=0;
        nr_masini_noi_stoc=0;
        masini_stoc.clear();
        masini_vandute.clear();
        luna=0;
        }
    Vanzare(int nr_stoc,int nr_vandute, set<pair<Monovolum,bool> > m_stoc,set<pair<Monovolum,bool> > m_vandute, bool l)
        {nr_masini_stoc=nr_stoc;
        nr_masini_vandute=nr_vandute;
        nr_masini_noi_stoc=0;
        if (nr_stoc)
            masini_stoc=m_stoc;
        std::set<std::pair<Monovolum,bool> >::iterator it;
        for(it=masini_stoc.begin();it!=masini_stoc.end();it++)
            if(it->second)
                nr_masini_noi_stoc++;
        if (nr_vandute)
            masini_vandute=m_vandute;
        luna=l;
        }
    ~Vanzare()
        {masini_stoc.clear();
        masini_vandute.clear();
        nr_masini_stoc=0;
        nr_masini_vandute=0;
        nr_masini_noi_stoc=0;
        luna=0;
        }
     Vanzare(const Vanzare& v)
        {this->nr_masini_stoc=v.nr_masini_stoc;
        this->nr_masini_vandute=v.nr_masini_vandute;
        this->nr_masini_noi_stoc=v.nr_masini_noi_stoc;
        this->masini_stoc=v.masini_stoc;
        this->masini_vandute=v.masini_vandute;
        this->luna=v.luna;
        }
    Vanzare& operator=(const Vanzare& v)
        {this->nr_masini_stoc=v.nr_masini_stoc;
        this->nr_masini_vandute=v.nr_masini_vandute;
        this->nr_masini_noi_stoc=v.nr_masini_noi_stoc;
        this->masini_stoc=v.masini_stoc;
        this->masini_vandute=v.masini_vandute;
        return *this;
        }
    friend ostream& operator<<(ostream& out, Vanzare<Monovolum>& v) ///supraincarcare operator <<
        {out<<"Nr de masini in stoc: "<<v.nr_masini_stoc<<" (dintre care "<<v.nr_masini_noi_stoc<<" sunt noi)"<<endl;
        int i=1;
        set<pair<Monovolum,bool> >::iterator it;
        if(v.nr_masini_stoc!=0)
            for(it=v.masini_stoc.begin();it!=v.masini_stoc.end();it++)
                {out<<"Masina nr."<<i<<endl;
                out<<*const_cast<Monovolum*>(&it->first);
                if(it->second==false)
                    {int p=const_cast<Monovolum*>(&it->first)->get_pret();
                    int ani=const_cast<Monovolum*>(&it->first)->get_ani_vechime();
                    if(v.luna)
                        out<<"Deoarece este vara, pretul este redus la "<<p-p/10<<" (reducere de 10%)"<<endl;
                    else
                        out<<"Pretul este redus la "<<p-p*ani/100<<" (reducere proportionala cu nr de ani vechime)"<<endl;
                    }
                out<<endl;
                i++;
                }
        out<<endl;
        out<<"Nr de masini vandute: "<<v.nr_masini_vandute<<endl;
        i=1;
        set<pair<Monovolum,bool> >::iterator it2;
        if (v.nr_masini_vandute!=0)
            for(it2=v.masini_vandute.begin();it2!=v.masini_vandute.end();it2++)
                {out<<"Masina nr."<<i<<endl;
                out<<*const_cast<Monovolum*>(&it2->first);
                out<<endl;
                i++;
                }
        return out;
        }

    friend istream& operator>>(istream& in, Vanzare<Monovolum>& v)  ///supraincarcare operator >>
        {cout<<"Introduceti luna curenta: ";
        string l;
        try
            {in>>l;
            if(l=="iunie" || l=="iulie" || l=="august")
                v.luna=1;
            else
                if(l=="ianuarie" || l=="februarie" || l=="martie" || l=="aprilie" || l=="mai" || l=="septembrie" || l=="octombrie" || l=="noiembrie" || l=="decembrie")
                    v.luna=0;
                else
                    throw 1;
            }
        catch(int c)
            {cout<<"Nu ati introdus o luna valida."<<endl;
            exit(EXIT_FAILURE);
            }
        cout<<"Nr de masini in stoc: ";
        in>>v.nr_masini_stoc;
        Monovolum m;
        if(v.nr_masini_stoc>0)
            {cout<<"Masina nr. 1"<<endl;
            in.get();
            }
        for(int i=0;i<v.nr_masini_stoc;i++)
            {in>>m;
            pair<Monovolum,bool> p;
            p.first=m;
            if(m.get_nou())
                {p.second=true;
                v.nr_masini_noi_stoc++;
                }
            else
                {p.second=false;
                in.get();
                }
            cout<<endl;
            (v.masini_stoc).insert(p);
            if (i+1!=v.nr_masini_stoc)
                cout<<"Masina nr."<<i+2<<endl;
            }
        cout<<endl;
        cout<<"Nr de masini vandute: ";
        in>>v.nr_masini_vandute;
        if(v.nr_masini_vandute>0)
            {cout<<"Masina nr. 1"<<endl;
            in.get();
            }
        for(int i=0;i<v.nr_masini_vandute;i++)
            {in>>m;
            pair<Monovolum,bool> p;
            p.first=m;
            if(m.get_nou())
                p.second=true;
            else
                {p.second=false;
                in.get();
                }
            cout<<endl;
            v.masini_vandute.insert(p);
            if (i+1!=v.nr_masini_vandute)
                cout<<"Masina nr."<<i+2<<endl;
            }
        return in;
        }

    Vanzare& operator-=( const pair<Monovolum, bool>& m)
        {set<pair<Monovolum,bool> >::iterator it;
        it=masini_stoc.find(m);
        if (*it==m)
            {this->nr_masini_stoc=this->nr_masini_stoc-1;
            this->nr_masini_vandute=this->nr_masini_vandute+1;
            masini_stoc.erase(m);
            masini_vandute.insert(m);
            if (m.second)
                nr_masini_noi_stoc--;
            }
        else
            cout<<endl<<"Masina introdusa nu a fost gasita"<<endl;
        return *this;
        }
};

///Meniu interactiv
void afisare_meniu()
    {
    cout<<"\n Proiect 3 - Parc auto: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n=========================================================\n";
    cout<<"\n";
    cout<<"1. Introducerea a n automobile"; cout<<"\n";
    cout<<"2. Contorizarea automobilelor introduse la 1"; cout<<"\n";
    cout<<"3. Vanzare Automobile Mini (template)"; cout<<"\n";
    cout<<"4. Vanzare Automobile Compacte Sedan (template)"; cout<<"\n";
    cout<<"5. Cumpararea unui automobil introdus la 4"; cout<<"\n";
    cout<<"6. Vanzare Automobile Monovolum (specializare)"; cout<<"\n";
    cout<<"7. Cumpararea unui automobil introdus la 6"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
    }
void meniu()
    {
    int ok=0, ok2=0, ok3=0;
    string n,m;
    int optiune=0;   ///optiunea aleasa din meniu
    Automobil** a;
    int nr;
    Vanzare<Compacta_Sedan> y; /// pentru optiunea 4
    Vanzare<Monovolum> z;  ///pentru optiunea 6
    do
        {
        afisare_meniu();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>optiune;

        if (optiune==1)
            {try{
            ///Introducerea a n automobile
            cout<<"Numarul de automobile este:";
            cin>>nr;
            cin.get();
            a=new Automobil*[nr];
            cout<<endl<<"Tipuri posibile de automobile: a. Mini (L mai mica de 4m)"<<endl;
            cout<<"                               b. Mica (L intre 3.85 si 4.1 m)"<<endl;
            cout<<"                               c. Compacta hatchback (L intre 4.2 si 4.5m)"<<endl;
            cout<<"                               d. Compacta combi (L intre 4.2 si 4.5m)"<<endl;
            cout<<"                               e. Compacta sedan (L intre 4.2 si 4.5m)"<<endl;
            cout<<"                               f. Monovolum (5-7 persoane)"<<endl;
            for (int i=0;i<nr;)
                {string tip;
                cout<<endl<<"Introduceti tipul automobilului "<<i+1<<": ";
                getline(cin,tip);
                int ok=0;
                if (tip=="a")
                    {ok=1;
                    a[i]=new Mini;  ///Upcast
                    cin>>*a[i];
                    cin.get();
                    i++;
                    }
                else
                    if (tip=="b")
                        {ok=1;
                        a[i]=new Mica;  ///Upcast
                        cin>>*a[i];
                        cin.get();
                        i++;
                        }
                    else
                        if (tip=="c")
                            {ok=1;
                            a[i]=new Compacta_Hatchback;  ///Upcast
                            cin>>*a[i];
                            cin.get();
                            i++;
                            }
                        else
                            if(tip=="d")
                                {ok=1;
                                a[i]=new Compacta_Combi;    ///Upcast
                                cin>>*a[i];
                                cin.get();
                                i++;
                                }
                                else
                                    if(tip=="e")
                                        {ok=1;
                                        a[i]=new Compacta_Sedan;    ///Upcast
                                        cin>>*a[i];
                                        cin.get();
                                        i++;
                                        }
                                    else
                                        if(tip=="f")
                                            {ok=1;
                                            a[i]=new Monovolum;     ///Upcast
                                            cin>>*a[i];
                                            //cin.get();
                                            i++;
                                            }
                                        else
                                            {
                                            cout<<"Nu ati introdus un tip valid";
                                            }
                }
                }
            catch (bad_alloc var)
                {cout << "Allocation Failure"<<endl;
                exit(EXIT_FAILURE);
                }
            cout<<endl<<"----------------------------------------"<<endl;
            for(int i=0;i<nr;i++)
                {cout<<"Automobilul nr."<<i+1;
                ///pentru a afisa tipul automobilului:
                Mica* v1=dynamic_cast<Mica*>(a[i]); ///cast catre Mica
                Mini* v2=dynamic_cast<Mini*>(a[i]); ///cast catre Mini
                Compacta_Hatchback* v3=dynamic_cast<Compacta_Hatchback*>(a[i]); ///cast catre Compacta_Hatchback
                Compacta_Combi* v4=dynamic_cast<Compacta_Combi*>(a[i]); ///cast catre Compacta_Combi
                Compacta_Sedan* v5=dynamic_cast<Compacta_Sedan*>(a[i]); ///cast catre Compacta_Sedan
                Monovolum* v6=dynamic_cast<Monovolum*>(a[i]); ///cast catre Monovolum
                if (v1)
                    cout<<" (Mica)";
                if (v2)
                    cout<<" (Mini)";
                if (v3)
                    cout<<" (Compacta Hatchback)";
                if (v4)
                    cout<<" (Compacta Combi)";
                if (v5)
                    cout<<" (Compacta Sedan)";
                if (v6)
                    cout<<" (Monovolum)";
                cout<<": "<<endl<<*a[i]<<endl;
                }
            ok=1;
            }
        if (ok==0 && optiune==2)
                cout<<"Va rugam sa introduceti automobilele! Apasati 1!"<<endl;
        else
            {
            if (optiune==2)
                    {
                    ///Contorizarea automobilelor
                    int mica=0, mini=0, comp_h=0, comp_c=0, comp_s=0, mono=0;
                    for(int i=0;i<nr;i++)
                        {
                        Mica* v1=dynamic_cast<Mica*>(a[i]); ///cast catre Mica
                        Mini* v2=dynamic_cast<Mini*>(a[i]); ///cast catre Mini
                        Compacta_Hatchback* v3=dynamic_cast<Compacta_Hatchback*>(a[i]); ///cast catre Compacta_Hatchback
                        Compacta_Combi* v4=dynamic_cast<Compacta_Combi*>(a[i]); ///cast catre Compacta_Combi
                        Compacta_Sedan* v5=dynamic_cast<Compacta_Sedan*>(a[i]); ///cast catre Compacta_Sedan
                        Monovolum* v6=dynamic_cast<Monovolum*>(a[i]); ///cast catre Monovolum
                        if (v1)
                            mica++;
                        if (v2)
                            mini++;
                        if (v3)
                            comp_h++;
                        if (v4)
                            comp_c++;
                        if (v5)
                            comp_s++;
                        if (v6)
                            mono++;
                        }
                    cout<<"Numarul de automobile Mici: "<<mica<<endl;
                    cout<<"Numarul de automobile Mini: "<<mini<<endl;
                    cout<<"Numarul de automobile Compacte Hatchback: "<<comp_h<<endl;
                    cout<<"Numarul de automobile Compacte Combi: "<<comp_c<<endl;
                    cout<<"Numarul de automobile Compacte Sedan: "<<comp_s<<endl;
                    cout<<"Numarul de automobile Monovolum: "<<mono<<endl;
                    }
            }
            if(optiune==3)
                {///Vanzare Automobile Mini
                Vanzare<Mini> x;
                cin>>x;
                cout<<endl<<"----------------------------------------"<<endl;
                cout<<x;
                }
            if(optiune==4 || optiune==5)
                {
                if (optiune==4)
                    {
                    ///Vanzare Automobile Compacte Sedan
                    //Vanzare<Compacta_Sedan> y; - declarare la inceput
                    cin>>y;
                    cout<<endl<<"----------------------------------------"<<endl;
                    cout<<y;
                    ok2=1;
                    }
                if (optiune==5 && ok2==1)
                    {
                    ///Cumpararea unui automobil introdus la 4
                    if(ok2==1)
                        {cout<<endl<<"Oferta noastra:"<<endl;
                        cout<<y;
                        cout<<endl<<"Ce automobil doriti sa cumparati din oferta noastra?"<<endl;
                        cin.get();
                        Compacta_Sedan c;
                        cin>>c;
                        pair <Compacta_Sedan, bool> p1;
                        p1.first=c;
                        p1.second=true;
                        y-=p1;
                        cout<<endl<<"Oferta noastra reactualizata:"<<endl;
                        cout<<y;
                        }
                    else
                        cout<<"Va rugam sa introduceti automobilele! Apasati 4!"<<endl;
                    }
                }
            if(optiune==6 || optiune==7)
                {
                if (optiune==6)
                    {
                    ///Vanzare Automobile Monovolum
                    //Vanzare<Monovolum> z; - declarare la inceput
                    cin>>z;
                    cout<<endl<<"----------------------------------------"<<endl;
                    cout<<z;
                    ok3=1;
                    }
                if (optiune==7 && ok3==1)
                    {
                    ///Cumpararea unui automobil introdus la 4
                    cout<<endl<<"Oferta noastra:"<<endl;
                    cout<<z;
                    cout<<endl<<"Ce automobil doriti sa cumparati din oferta noastra?"<<endl;
                    cin.get();
                    Monovolum m;
                    cin>>m;
                    pair <Monovolum, bool> p2;
                    p2.first=m;
                    p2.second=m.get_nou();
                    z-=p2;
                    cout<<endl<<"Oferta noastra reactualizata:"<<endl;
                    cout<<z;
                    }
                }
            if (optiune==0)
                {
                cout<<"\nEXIT!\n";
                }
            if (optiune<0||optiune>7)
                {
                cout<<"\nSelectie invalida\n";
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
