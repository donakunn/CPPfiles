/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _LISTALIN_H
#define _LISTALIN_H

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

// classe astratta listaLinare
template <class T, class P>
class Linear_list
{
public:
    typedef T value_type; // the type of object, T, stored in the list
    typedef P position;

    // operators
    virtual void create() = 0;
    virtual bool empty() const = 0; // true if the list's size is 0
    virtual value_type read(position) const = 0;
    virtual void write(const value_type &x, position p) = 0; // write x at position p
    virtual position begin() const = 0;                      // returns a position pointing to the beginning of the list
    virtual bool end(position) const = 0;                    // true with a position pointing to the end of the list
    virtual position next(position) const = 0;               // returns the next position
    virtual position previous(position) const = 0;           // return the previous position
    virtual void insert(const value_type &, position) = 0;   // insert an element
    virtual void erase(position pos) = 0;                    // ersaes the element at position pos

    // funzioni di servizio
    int size() const;                  // returns the size of the list
    virtual position last() const = 0; //returns a position pointing to last element of the list
    template <class U, class Q>
    friend ostream &operator<<(ostream &, const Linear_list<U, Q> &);
    void push_front(const value_type &); // insert a new element at the beginning
    void push_back(const value_type &);  // insert a new element at the end
    void pop_front();                    // removes the first element
    void pop_back();                     // removes the last element
    void clear();                        // erases all the elements
    void reverse();                      //return a list with elements in inverted order
    bool palindrome() const;             //true if the list palindrome, false otherwise
};

template <class T, class P>
int Linear_list<T, P>::size() const
{
    typename Linear_list<T, P>::position p;
    p = this->begin();
    int sizeList = 0;
    while (!this->end(p))
    {
        sizeList++;
        p = this->next(p);
    }
    return sizeList;
}
/* sovraccarica <<. Attenzione se il tipo restituito da read non Ã¨ primitivo, allora
 * anche per questo tipo bisogna sovraccaricare l'operatore << 
 */
template <class T, class P>
ostream &operator<<(ostream &os, const Linear_list<T, P> &l)
{
    typename Linear_list<T, P>::position p;
    p = l.begin();
    os << "[";
    while (!l.end(p))
    {
        if (p != l.begin())
            os << ", " << l.read(p);
        else
            os << l.read(p);
        p = l.next(p);
    }
    os << "]" << endl;
    return os;
}

template <class T, class P>
void Linear_list<T, P>::push_front(const value_type &a)
{
    this->insert(a, begin());
}

template <class T, class P>
void Linear_list<T, P>::push_back(const value_type &a)
{
    this->insert(a, this->next(last()));
}
template <class T, class P>
void Linear_list<T, P>::pop_front()
{
    this->erase(begin());
}
template <class T, class P>
void Linear_list<T, P>::pop_back()
{
    this->erase(last());
}
template <class T, class P>
void Linear_list<T, P>::clear()
{
    typename Linear_list<T, P>::position p;
    p = this->begin();
    while (!this->end(p))
    {
        this->erase(p);
        p = this->next(p);
    }
}
template <class T, class P>
void Linear_list<T, P>::reverse()
{
    typename Linear_list<T, P>::position pFront,pBack;
    pFront = this->begin();
    pBack = this->last();
    value_type tmp;
    while (pFront != pBack)
    {
        tmp = this->read(pFront);
        this->insert(this->read(pBack),pFront);
        this->insert(tmp,pBack);
        pFront = this->next(pFront);
        pBack = this->previous(pBack);
    }
}
template <class T, class P>
bool Linear_list<T, P>::palindrome() const
{
    typename Linear_list<T, P>::position pFront, pBack;
    pFront = this->begin();
    pBack = this->last();
    while (pFront != pBack)
    {
        if (this->read(pFront) != this->read(pBack))
            return false;
        else {
            pFront = this->next(pFront);
            pBack = this->previous(pBack);
        }
    }
    return true;
}
#endif // _LISTALIN_H
