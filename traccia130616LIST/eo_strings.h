#ifndef EO_STRINGS_H
#define EO_STRINGS_H

#include "linked_list.h"
#include <string>

using namespace std;

class eo_strings
{
public:
    void inserisci(const string);
    void rimuovi(const string);
    void rimuovi(const char);
    int freq_pari()const ;
    void visualizza_dispari();

private:
    Linked_list<string> pari;
    Linked_list<string> dispari;
    void OrdInsert(Linked_list<string> &, string);
};

void eo_strings::inserisci(const string s)
{
    if (s.length() % 2 == 0)
        pari.insert(s, pari.begin());
    else
        dispari.insert(s, dispari.begin());
}

void eo_strings::rimuovi(const string s)
{
    typename Linked_list<string>::position p;
    if (s.length() % 2 == 0)
    {
        p = pari.begin();
        while (!pari.end(p))
        {
            if (pari.read(p) == s)
                pari.erase(p);
            p = pari.next(p);
        }
    }
    else
    {
        p = dispari.begin();
        while (!dispari.end(p))
        {
            if (dispari.read(p) == s)
                dispari.erase(p);
            p = dispari.next(p);
        }
    }
}

void eo_strings::rimuovi(const char c)
{
    typename Linked_list<string>::position p;
    p = pari.begin();
    while (!pari.end(p))
    {
        string s = pari.read(p);
        if (pari.read(p).at(0) == c)
            pari.erase(p);
        p = pari.next(p);
    }
}

int eo_strings::freq_pari() const 
{
    typename Linked_list<string>::position p;
    int i = 0;
    p = pari.begin();
    while (!pari.end(p))
    {
        i++;
        p = pari.next(p);
    }
    return i;
    //o meglio, pari.ListLength();
}

void eo_strings::visualizza_dispari() 
{
    Linked_list<string> listaOrdinata;
    typename Linked_list<string>::position p;
    p = dispari.begin();
    while (!dispari.end(p))
    {
        OrdInsert(listaOrdinata, dispari.read(p));
        p = dispari.next(p);
    }
    cout << listaOrdinata;
}

void eo_strings::OrdInsert(Linked_list<string> &L, string s)
{
    typename Linked_list<string>::position p;
    p = L.begin();
    while (!L.end(p))
    {
        if (L.read(p).length() < s.length())
            p = L.next(p);
        else
        {
            L.insert(s, p);
            return;
        }
    }
    L.insert(s, p);
}

#endif