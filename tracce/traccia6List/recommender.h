#ifndef RECOMMENDER_H
#define RECOMMENDER_H
#include "linked_list.h"
#include <string>
using namespace std;

class recommender;
class rating
{
    friend class recommender;

public:
    rating(){};
    rating(string user, string prod, int voto) : utente(user), prodotto(prod), rate(voto){};

private:
    string utente;
    string prodotto;
    int rate;
};
class recommender
{
public:
    recommender(){};
    ~recommender(){};
    // inserisce nella lista ratings una nuovo rating
    // <user, item, rating>
    void insert(string user, string item, int rating);
    // restituisce la media dei rating dell’utente user
    double meanUser(string user);
    // restituisce la media dei rating per il prodotto item
    double meanItem(string item);
    // restituisce la lista dei prodotti votati dall’utente user
    Linked_list<string> rated(string user);
    // restituisce la lista dei prodotti votati sia dall’utente user1
    // che dall’utente user2
    Linked_list<string> common(string user1, string user2);
    // usando il metodo common, calcola quanti prodotti sono stati votati
    // allo stesso modo sia dall’utente user1 che dall’utente user2
    int commonEqual(string user1, string user2);

private:
    Linked_list<rating> ratings;
};

void recommender::insert(string user, string item, int rate)
{
    if (rate < 1 || rate > 5)
        throw WrongRating();
    rating newRate(user, item, rate);
    Linked_list<rating>::position it;
    it = ratings.begin();
    while (!ratings.end(it))
        it = ratings.next(it);
    ratings.insert(newRate, it);
}

double recommender::meanUser(string user)
{
    double sum = 0, count = 0;
    Linked_list<rating>::position it;
    it = ratings.begin();
    while (!ratings.end(it))
    {
        if (ratings.read(it).utente == user)
        {
            sum += ratings.read(it).rate;
            count++;
        }
        it = ratings.next(it);
    }
    return (sum / count);
}

double recommender::meanItem(string item)
{
    int sum, count = 0;
    Linked_list<rating>::position it;
    it = ratings.begin();
    while (!ratings.end(it))
    {
        if (ratings.read(it).prodotto == item)
        {
            sum += ratings.read(it).rate;
            count++;
        }
        it = ratings.next(it);
    }
    return (sum / count);
}

Linked_list<string> recommender::rated(string user)
{
    Linked_list<string> lista;
    Linked_list<rating>::position it;
    Linked_list<string>::position it2;
    it = ratings.begin();
    while (!ratings.end(it))
    {
        if (ratings.read(it).utente == user)
        {
            it2 = lista.begin();
            while (!lista.end(it2))
                it2 = lista.next(it2);
            lista.insert(ratings.read(it).prodotto, it2);
        }
        it = ratings.next(it);
    }
    return lista;
}

Linked_list<string> recommender::common(string user1, string user2)
{
    Linked_list<string> lista;
    Linked_list<rating>::position it, it2;
    Linked_list<string>::position itP;
    string prod;
    it = ratings.begin();
    while (!ratings.end(it))
    {
        if (ratings.read(it).utente == user1)
        {
            prod = ratings.read(it).prodotto;
            it2 = ratings.begin();
            while (!ratings.end(it2))
            {
                if (ratings.read(it2).prodotto == prod && ratings.read(it2).utente == user2)
                {
                    itP = lista.begin();
                    while (!lista.end(itP))
                        itP = lista.next(itP);
                    lista.insert(ratings.read(it).prodotto, itP);
                }
            }
        }
        it = ratings.next(it);
    }
    return lista;
}

int recommender::commonEqual(string user1, string user2)
{
    Linked_list<string> prodottiInComune = common(user1, user2);
    int count, rate = 0;
    Linked_list<rating>::position it, it2;
    Linked_list<string>::position itP = prodottiInComune.begin();
    string prod;
    while (!prodottiInComune.end(itP))
    {
        it = ratings.begin();
        while (!ratings.end(it))
        {
            if (ratings.read(it).prodotto == prod)
            {
                if (ratings.read(it).utente == user1)
                {
                    rate = ratings.read(it).rate;
                    it2 = ratings.begin();
                    while (!ratings.end(it2))
                    {
                        if (ratings.read(it2).prodotto == prod && ratings.read(it2).utente == user2)
                        {
                            count++;
                        }
                        it2 = ratings.next(it2);
                    }
                }
                if (ratings.read(it).utente == user2)
                {
                    rate = ratings.read(it).rate;
                    it2 = ratings.begin();
                    while (!ratings.end(it2))
                    {
                        if (ratings.read(it2).prodotto == prod && ratings.read(it2).utente == user1)
                        {
                            count++;
                        }
                        it2 = ratings.next(it2);
                    }
                }
            }
            it = ratings.next(it);
        }
        itP = prodottiInComune.next(itP);
    }
    return count;
}
#endif