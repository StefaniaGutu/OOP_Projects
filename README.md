# OOP_Projects
### Project 1
Clasa ”Multime” (multimi finite de numere intregi reprezentate ca tablouri unidimensionale)\
\
Cerinte:
- membri privati pentru vectorul propriuzis si numarul de elemente;
- constructori pentru initializare si copiere;
- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);
- metoda publica pentru transformare a unui vector in multime, prin eliminarea duplicatelor din respectivul vector;
- reuniune a doua multimi, implementata prin supraincarcarea operatorului +;
- intersectie a doua multimi, implementata prin supraincarcarea operatorului *;
- diferenta a doua multimi, implementata prin supraincarcarea operatorului -.

### Project 2
Se dau urmatoarele clase: \
 Clasa Persoana(int id, string nume)\
 Clasa Abonat:Persoana(string nr_telefon)\
 Clasa Abonat_Skype: Abonat (string id_skype)\
 Clasa Abonat_Skype_Romania (string adresa_mail) : Abonat_Skype\
 Clasa Abonat_Skype_Extern(string tara) : Abonat_Skype\
 \
Cerinte:
- sa se construiasca clasa Agenda ce contina o lista de abonati si sa se supraincarce operatorul [ ] (indexare) care returneaza abonatul cu numele precizat;
- utilizarea de variabile și de funcții statice;
- conceptele de upcasting, downcasting, funcții virtuale.


### Project 3
Dintr-un parc auto se poate cumpăra o gama variată de automobile din următoarele clase: MINI (mașina de oraș de mic litraj, de obicei sub 4m lungime), MICA (mașini de oraș, cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1), COMPACTA (mașini ușor de folosit atât de oraș cât și la drum lung, de dimensiune 4.2 – 4.5m; modelele vin sub forma de hatchback, combi sau sedan) și MONOVOLUME (automobile sub forma de van ce pot transporta 5-7 persoane). Monovolumele pot și achiziționate atât noi cât și second hand. La cele achizitionate sh se percepe un discount proporțional cu numărul de ani vechime și, în lunile de vară, beneficiază de zile promotionale cu reducere fixa de 10% din preț.
Structura de date: set<pair<tip_automobil, bool nou>> (nou = false pentru cele sh)

Cerințe:
- să se adauge toate campurile relevante pentru modelarea acestei probleme;
- să se adauge campurile și metodele necesare pentru implementarea corecta;
- să se construiască clasa template Vanzare care sa conțină nr total de mașini în stoc (decrementat automat la vanzarea unei mașini), nr de mașini vândute (incrementat automat) și două structuri de obiecte, alocate dinamic, prin care să se gestioneze automobilele din stoc și cele vandute. Sa se supraincarce operatorul -= care sa actualizeze datele din clasa la vanzarea unei mașini;
- să se construiască o specializare pentru tipul MONOVOLUM care sa conțină și să afișeze gestioneze doar MONOVOLUMELE;
- utilizarea sabloanelor;
- utilizarea STL;
- utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const;
- utilizarea conceptelor de RTTI (ex: upcast & dynamic_cast);
- tratarea excepțiilor.
