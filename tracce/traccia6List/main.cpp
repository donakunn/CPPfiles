#include "recommender.h"

int main(){
    recommender r;
r.insert("u1","p1",1);
r.insert("u1","p3",3);
r.insert("u1","p5",4);
r.insert("u2","p1",2);
r.insert("u2","p2",3);
r.insert("u2","p3",3);
r.insert("u3","p1",1);
r.insert("u3","p2",1);
r.insert("u3","p3",1);
r.insert("u3","p5",5);
r.insert("u4","p3",2);
r.insert("u4","p4",4);
r.insert("u5","p2",3);
r.insert("u5","p3",2);
r.insert("u6","p4",2);
cout << " media per i voti dell user u2: " << r.meanUser("u2") << endl;
cout << " media per i voti del prodotto p3: " << r.meanItem("p3") << endl;
Linked_list<string> prod = r.rated("u2");
cout << " prodotti votati da utente u2: " << endl;
cout << prod;
}