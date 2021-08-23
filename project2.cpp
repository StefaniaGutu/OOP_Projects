#include<iostream>
#include<stdlib.h>
using namespace std;

    ///Clasa Persoana
class Persoana
{protected:
    int id;
    string nume;
    static int nr_pers;   ///variabila statica folosita pentru a retine cate peroane avem declarate
public:
    Persoana(int,string);
    Persoana (const Persoana&);
    virtual ~Persoana();   ///destructor virtual
    Persoana& operator=(const Persoana&);   ///supraincarcare operator atribuire
    virtual void citire(istream &in);  ///citire virtuala
    virtual void afisare(ostream &out); ///afisare virtuala
    friend istream& operator>>(istream&, Persoana&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Persoana&);    ///supraincarcare operator <<
    static void numarPersoane(){ /// metoda statica de afisare a numarului de persoane
        cout<<nr_pers;
    }
};

int Persoana::nr_pers; ///declararea variabilei statice

Persoana::Persoana(int cod=0, string nume_pers="")
    {nr_pers++;
    id=cod;
    nume=nume_pers;
    }
Persoana::Persoana(const Persoana& pers)
    {this->id= pers.id;
    this->nume= pers.nume;
    }
Persoana::~Persoana()
    {
    id=0;
    nume="";
    }
Persoana& Persoana::operator=(const Persoana& pers) ///supraincarcare operator atribuire
    {this->id=pers.id;
    this->nume=pers.nume;
    return *this;
    }
void Persoana::citire(istream &in)
    {
    cout<<"ID: ";
    in>>id;
    cout<<"Nume: ";
    in.get();
    string z;
    getline(in,z);
    nume=z;
    }
istream& operator>>(istream& in, Persoana& pers)    ///supraincarcare operator >>
    {
    pers.citire(in);
    return in;
    }
void Persoana::afisare(ostream &out)
    {out<<"ID: "<<id<<endl;
    out<<"Nume: "<<nume<<endl;
    }
ostream& operator<<(ostream& out, Persoana& pers)   ///supraincarcare operator <<
    {
    pers.afisare(out);
    return out;
    }

    ///Clasa Abonat
class Abonat: public Persoana
{protected:
    string nr_telefon;
public:
    Abonat(int,string,string);
    ~Abonat();
    Abonat(const Abonat&);
    Abonat& operator=(const Abonat&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Abonat&);  ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Abonat&);  ///supraincarcare operator <<
    string get_nume();
    string get_nr_telefon();
    void set_nr_telefon(string);
    void set_nume(string);
};

Abonat::Abonat(int cod=0, string nume_pers="", string nr_tel=""):Persoana(cod, nume_pers) ///apelam contructorul de initializare din clasa Persoana
    {nr_telefon=nr_tel;
    }
Abonat::~Abonat()
    {
    nr_telefon="";
    }
Abonat::Abonat (const Abonat& ab):Persoana(ab) ///apelam construtorul de copiere din clasa Persoana
    {
    this->nr_telefon = ab.nr_telefon;
    }
Abonat& Abonat::operator=(const Abonat& ab)     ///supraincarcare operator atribuire
    {this->id= ab.id;
    this->nume=ab.nume;
    this->nr_telefon = ab.nr_telefon;
    return *this;
    }
void Abonat::citire(istream &in)
    {Persoana::citire(in);
    cout<<"Nr telefon: ";
    in>>nr_telefon;
    }
istream& operator>>(istream& in, Abonat& ab)    ///supraincarcare operator >>
    {
    ab.citire(in);
    return in;
    }
void Abonat::afisare(ostream &out)
    {Persoana::afisare(out);
    out<<"Nr telefon: "<<nr_telefon<<endl;
    }
ostream& operator<<(ostream& out, Abonat& ab)   ///supraincarcare operator <<
    {
    ab.afisare(out);
    return out;
    }
string Abonat::get_nume()
    {return nume;
    }
string Abonat::get_nr_telefon()
    {return nr_telefon;
    }
void Abonat::set_nr_telefon(string nr)
    {nr_telefon=nr;
    }
void Abonat::set_nume(string name)
    {nume=name;
    }

    ///Clasa Abonat_Skype
class Abonat_Skype: public Abonat
{protected:
    string id_skype;

public:
    Abonat_Skype(int,string,string,string);
    ~Abonat_Skype();
    Abonat_Skype(const Abonat_Skype&);
    Abonat_Skype& operator=(const Abonat_Skype&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Abonat_Skype&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Abonat_Skype&);    ///supraincarcare operator <<
    string get_id_skype();
};

Abonat_Skype::Abonat_Skype(int cod=0, string nume_pers="", string nr_tel="", string cod_skype=""):Abonat(cod, nume_pers, nr_tel)
                                                                                ///apelam contructorul de initializare din clasa Abonat
    {id_skype=cod_skype;
    }
Abonat_Skype::~Abonat_Skype()
    {id_skype="";
    }
Abonat_Skype::Abonat_Skype(const Abonat_Skype& ab):Abonat(ab)  ///apelam construtorul de copiere din clasa Abonat
    {
    this->id_skype = ab.id_skype;
    }
Abonat_Skype& Abonat_Skype::operator=(const Abonat_Skype& ab)   ///supraincarcare operator atribuire
    {this->id= ab.id;
    this->nume=ab.nume;
    this->nr_telefon = ab.nr_telefon;
    this->id_skype = ab.id_skype;
    return *this;
    }
void Abonat_Skype::citire(istream &in)
    {Abonat::citire(in);
    cout<<"ID Skype: ";
    in>>id_skype;
    }
istream& operator>>(istream& in, Abonat_Skype& ab_s)    ///supraincarcare operator >>
    {
    ab_s.citire(in);
    return in;
    }

void Abonat_Skype::afisare(ostream &out)
    {Abonat::afisare(out);
    out<<"ID Skype: "<<id_skype<<endl;
    }
ostream& operator<<(ostream& out, Abonat_Skype& ab_s)   ///supraincarcare operator <<
    {
    ab_s.afisare(out);
    return out;
    }

string Abonat_Skype::get_id_skype()
    {return id_skype;
    }

    ///Clasa Abonat Skype Romania
class Abonat_Skype_Romania: public Abonat_Skype
{private:
    string adresa_mail;
public:
    Abonat_Skype_Romania(int,string,string,string,string);
    ~Abonat_Skype_Romania();
    Abonat_Skype_Romania(const Abonat_Skype_Romania&);
    Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania&);   ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Abonat_Skype_Romania&);    ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Abonat_Skype_Romania&);    ///supraincarcare operator <<
};

Abonat_Skype_Romania::Abonat_Skype_Romania(int cod=0, string nume_pers="", string nr_tel="", string cod_skype="", string mail=""):Abonat_Skype(cod, nume_pers, nr_tel, cod_skype)
                                                                                        ///apelam contructorul de initializare din clasa Abonat_Skype
    {adresa_mail=mail;
    }

Abonat_Skype_Romania::~Abonat_Skype_Romania()
    {adresa_mail="";
    }
Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& ab_ro):Abonat_Skype(ab_ro)  ///apelam construtorul de copiere din clasa Abonat_Skype
    {
    this->adresa_mail=ab_ro.adresa_mail;
    }
Abonat_Skype_Romania& Abonat_Skype_Romania::operator=(const Abonat_Skype_Romania& ab_ro)    ///supraincarcare operator atribuire
    {this->id= ab_ro.id;
    this->nume=ab_ro.nume;
    this->nr_telefon = ab_ro.nr_telefon;
    this->id_skype = ab_ro.id_skype;
    this->adresa_mail=ab_ro.adresa_mail;
    return *this;
    }
void Abonat_Skype_Romania::citire(istream& in)
    {Abonat_Skype::citire(in);
    cout<<"Adresa mail: ";
    in>>adresa_mail;
    }
istream& operator>>(istream& in, Abonat_Skype_Romania& ab_ro)   ///supraincarcare operator >>
    {ab_ro.citire(in);
    return in;
    }
void Abonat_Skype_Romania::afisare(ostream& out)
    {Abonat_Skype::afisare(out);
    out<<"Adresa mail: "<<adresa_mail<<endl;
    }
ostream& operator<<(ostream& out, Abonat_Skype_Romania& ab_ro)  ///supraincarcare operator <<
    {ab_ro.afisare(out);
    return out;
    }

    ///Clasa Abonat Skype Extern
class Abonat_Skype_Extern: public Abonat_Skype
{private:
    string tara;
public:
    Abonat_Skype_Extern(int,string,string,string,string);
    ~Abonat_Skype_Extern();
    Abonat_Skype_Extern(const Abonat_Skype_Extern&);
    Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern&);     ///supraincarcare operator atribuire
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Abonat_Skype_Extern&);   ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Abonat_Skype_Extern&);   ///supraincarcare operator <<
};

Abonat_Skype_Extern::Abonat_Skype_Extern(int cod=0, string nume_pers="", string nr_tel="", string cod_skype="", string tara_ab=""):Abonat_Skype(cod, nume_pers, nr_tel, cod_skype)
                                                                                    ///apelam contructorul de initializare din clasa Abonat_Skype
    {tara=tara_ab;
    }

Abonat_Skype_Extern::~Abonat_Skype_Extern()
    {tara="";
    }
Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern& ab_ex):Abonat_Skype(ab_ex)  ///apelam construtorul de copiere din clasa Abonat_Skype
    {
    this->tara=ab_ex.tara;
    }
Abonat_Skype_Extern& Abonat_Skype_Extern::operator=(const Abonat_Skype_Extern& ab_ex)   ///supraincarcare operator atribuire
    {this->id= ab_ex.id;
    this->nume=ab_ex.nume;
    this->nr_telefon = ab_ex.nr_telefon;
    this->id_skype = ab_ex.id_skype;
    this->tara=ab_ex.tara;
    return *this;
    }
void Abonat_Skype_Extern::citire(istream& in)
    {Abonat_Skype::citire(in);
    cout<<"Tara: ";
    in>>tara;
    }
istream& operator>>(istream& in, Abonat_Skype_Extern& ab_ex)    ///supraincarcare operator >>
    {ab_ex.citire(in);
    return in;
    }
void Abonat_Skype_Extern::afisare(ostream& out)
    {Abonat_Skype::afisare(out);
    out<<"Tara: "<<tara<<endl;
    }
ostream& operator<<(ostream& out, Abonat_Skype_Extern& ab_ex)   ///supraincarcare operator <<
    {ab_ex.afisare(out);
    return out;
    }

    ///Clasa Agenda
class Agenda{
private:
    int nr; ///numarul de abonati din lista
    Abonat **ab;  ///lista de abonati

public:
    Agenda(int, Abonat**);
    ~Agenda();
    Agenda(const Agenda&);
    Agenda& operator=(const Agenda&);   ///supraincarcare operator atribuire
    Abonat& operator[](string n);   ///supraincarcare operator de indexare
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Agenda&);  ///supraincarcare operator >>
    friend ostream& operator<<(ostream&, Agenda&);  ///supraincarcare operator <<
    void eliminare_abonat(Abonat&);  ///metoda de eliminare a abonatului dat ca parametru
};

Agenda::Agenda(int n=0, Abonat** a=NULL)
    {nr=n;
    if(nr!=0)
        {ab=new Abonat*[nr];
        if (a!=NULL)
            for(int i=0;i<nr;i++)
                ab[i]=a[i];
        }
    }
Agenda::~Agenda()
    {for (int i=0;i<nr;i++)
        delete ab[i];
    delete[] ab;
    }
Agenda::Agenda(const Agenda& ag)
    {this->nr=ag.nr;
    this->ab=new Abonat*[ag.nr];
    for (int i=0;i<ag.nr;i++)
        this->ab[i]=ag.ab[i];
    }
Agenda& Agenda::operator=(const Agenda& ag)     ///supraincarcare operator atribuire
    {this->nr=ag.nr;
    this->ab=new Abonat*[ag.nr];
    for (int i=0;i<ag.nr;i++)
        this->ab[i]=ag.ab[i];
    return *this;
    }
Abonat& Agenda::operator[]( string n)  ///supraincarcare operator de indexare
    {for (int i=0;i<nr;i++)
        if (ab[i]->get_nume()==n)
            return *ab[i];    /// se returneaza abonatul cu numele dat
    return *ab[0];  /// in cazul in care abonatul nu este gasit, se returneaza primul abonat din agenda
    }

void Agenda::citire(istream &in)        ///citirea informatiilor complete a n abonati
    {cout<<"Numarul de abonati este:";
    in>>nr;
    in.get();
    ab=new Abonat*[nr];
    cout<<endl<<"Tipuri posibile de abonati: a. Abonat"<<endl;
    cout<<"                            b. Abonat Skype"<<endl;
    cout<<"                            c. Abonat Skype din Romania"<<endl;
    cout<<"                            d. Abonat Skype Exterior"<<endl;
    for (int i=0;i<nr;)
        {string tip;
        cout<<endl<<"Introduceti tipul abonatului "<<i+1<<": ";
        getline(in,tip);
        int ok=0;
        if (tip=="b")
            {ok=1;
            ab[i]=new Abonat_Skype;  ///Upcast
            in>>*ab[i];
            in.get();
            i++;
            }
        else
            if (tip=="c")
                {ok=1;
                ab[i]=new Abonat_Skype_Romania;  ///Upcast
                in>>*ab[i];
                in.get();
                i++;
                }
            else
                if (tip=="d")
                    {ok=1;
                    ab[i]=new Abonat_Skype_Extern;  ///Upcast
                    in>>*ab[i];
                    in.get();
                    i++;
                    }
                else
                    if(tip=="a")
                        {ok=1;
                        ab[i]=new Abonat;
                        in>>*ab[i];
                        in.get();
                        i++;
                        }
                    else
                        {
                        cout<<"Nu ati introdus un tip valid";
                        }
        }
    }
istream& operator>>(istream& in, Agenda& a)   ///supraincarcare operator >>
    {a.citire(in);
    return in;
    }
void Agenda::afisare(ostream &out)
    {if(nr==0)
        out<<endl<<"Nu au fost gasiti abonati in agenda"<<endl;
    else
        if(nr==1)
            out<<endl<<"In agenda a fost gasit un abonat"<<endl;
        else
            out<<endl<<"In agenda au fost gasiti "<<nr<<" abonati"<<endl;
    out<<endl;
    for (int i=0;i<nr;i++)
        out<<"Abonatul nr."<<i+1<<endl<<*ab[i]<<endl;

    }
ostream& operator<<(ostream& out, Agenda& a)    ///supraincarcare operator <<
    {a.afisare(out);
    return out;
    }

void Agenda::eliminare_abonat(Abonat& a)    ///metoda de eliminare a abonatului dat ca parametru
    {int i=0;
    while(ab[i]->get_nume()!=a.get_nume())
        i++;
    delete ab[i]; ///dezalocam memoria unde era retinut abonatul cu numele dat
    for (int j=i;j<nr-1;j++)
        ab[j]=ab[j+1];
    nr--;
    }

    ///Meniu interactiv
void afisare_meniu()
    {
    cout<<"\n Proiect 2 - Agenda abonati: \n";
    cout<<"\n\t MENIU:";
    cout<<"\n=========================================================\n";
    cout<<"\n";
    cout<<"1. Introducerea a n abonati in agenda"; cout<<"\n";
    cout<<"2. Modificarea datelor unui abonat (nume/nr telefon)"; cout<<"\n";
    cout<<"3. Eliminarea unui abonat din agenda"; cout<<"\n";
    cout<<"4. Cautarea unui abonat dupa nume"; cout<<"\n";
    cout<<"5. Afisarea agendei"; cout<<"\n";
    cout<<"0. Iesire."; cout<<"\n";
    }
void meniu()
    {
    int ok=0;
    string n,m;
    int optiune=0;   ///optiunea aleasa din meniu
    Agenda ag;
    do
        {
        afisare_meniu();

        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>optiune;

        if (optiune==1)
            {
            ///Introducerea a n abonati in agenda
            cin>>ag;
            ok=1;
            }
        if (ok==0 && optiune>1 && optiune<=5)
                cout<<"Va rugam sa introduceti abonatii in agenda! Apasati 1!";
        else
            {
            if (optiune==2)
                {
                ///Modificarea datelor unui abonat (nume/nr telefon)
                cout<<"Numele abonatului pe care vreti sa il actualizati este: ";
                cin.get();
                getline(cin,n);
                if(ag[n].get_nume()==n)         ///verificam daca exista abonatul in agenda
                    {string nr,name;
                    cout<<"Ce doriti sa modificati (nume/nr telefon)? ";
                    getline(cin, m);
                    if(m=="nr telefon")
                        {
                        cout<<"Nr de telefon din agenda este: "<<ag[n].get_nr_telefon()<<endl;
                        cout<<"Nr de telefon nou este: ";
                        cin>>nr;
                        ag[n].set_nr_telefon(nr);
                        cout<<endl<<"Numarul de telefon al abonatului a fost modificat!";
                        }
                    else
                        if(m=="nume")
                            {
                            cout<<"Numele din agenda este: "<<ag[n].get_nume()<<endl;
                            cout<<"Numele nou este: ";
                            getline(cin,name);
                            ag[n].set_nume(name);
                            cout<<endl<<"Numele abonatului a fost modificat!";
                            }
                        else
                            cout<<"Nu ati introdus un camp valid";
                    }
                else    ///cazul in care abonatul cu numele dat nu e gasit
                    cout<<"Abonatul cu numele "<<n<<" nu a fost gasit"<<endl;
                }
            if (optiune==3)
                {
                ///Eliminarea unui abonat din agenda
                cout<<"Numele abonatului pe care vreti sa-l eliminati este: ";
                cin.get();
                getline(cin,n);
                if(ag[n].get_nume()==n)        ///verificam daca exista abonatul in agenda
                    {
                    cout<<"Abonatul cu numele "<<n<<" are datele:"<<endl;
                    Abonat *b=(Abonat*)(&ag[n]);  ///Downcast
                    cout<<*b; ///sau ag[n]
                    ag.eliminare_abonat(ag[n]);
                    cout<<endl<<"Abonatul a fost eliminat!";
                    }
                else        ///cazul in care abonatul cu numele dat nu e gasit
                    cout<<"Abonatul cu numele "<<n<<" nu a fost gasit in agenda"<<endl;
                }
            if (optiune==4)
                {
                ///Cautarea unui abonat dupa nume
                string n;
                cout<<"Numele abonatului cautat este: ";
                cin.get();
                getline(cin,n);
                if(ag[n].get_nume()==n)
                    {cout<<"Abonatul cu numele "<<n<<" a fost gasit, iar datele lui sunt:"<<endl;
                    cout<<ag[n];
                    }
                else
                    cout<<"Abonatul cu numele "<<n<<" nu a fost gasit"<<endl;
                }
            if (optiune==5)
                {
                ///Afisarea agendei
                cout<<ag;
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
