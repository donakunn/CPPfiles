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

#include "linked_list.h"
#include "Ordered_list.h"
#include <iostream>

using namespace std;

int main()
{
    Linked_list<int> list1, list2;
    Linked_list<int>::position iter;

    int x;

    /* inserting three elements into the list list1 */
    x = 1;
    list1.insert(x, list1.begin());
    x = 2;
    list1.insert(x, list1.begin());
    x = 3;
    list1.insert(x, list1.begin());
    x = 2;
    list1.insert(x, list1.begin());
    x = 1;
    list1.insert(x, list1.begin());

    /* visualizing the list list1 */
    cout << "list1= ";
    cout << list1;

    /* assigning the list list1 to the list list2.
	 * Here we are using the operator =
	 */

    list2 = list1;
    /* visualizing the list list2 */
    cout << "After list2=list1, list2= ";
    cout << list2;

    /* comparing for equality the lists list1 and list2 */
    if (list1 == list2)
        cout << "list1 == list2" << endl;
    else
        cout << "list1 != list2" << endl;

    /* erasing the first element from the list list2 */
    list2.erase(list2.begin());
    /* visualizing the list list2 */
    cout << "After erasing the first element, list2=";
    cout << list2;
    /* comparing for equality the lists list1 and list2 */
    if (list1 == list2)
        cout << "list1 == list2" << endl;
    else
        cout << "list1 != list2" << endl;
    list1.reverse();
    cout << "reverse of list1: " << list1;
    if (list1.palindrome())
        cout << "palindrome" << endl;
    else
        cout << "not palindrome" << endl;
    return 0;
    Linked_list<string> l3;
    l3.push_back("abba");
    l3.push_back("cafo");
    l3.push_back("esso");
    Ordered_list<string> l4(l3);
    l4.insert("basso");
}
