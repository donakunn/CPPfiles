#include "hash_table.h"
#include "string"
using namespace std;

int main()
{
    hash_table<string, string> dic(9);
    tupla<string, string> t;
    t.key = "test";
    t.value = "ciccio";
    dic.insert(t);
    tupla<string, string> *t1 = dic.find("test");
    std::cout << t1->value << endl;
    dic.modify("test", "modificato");
    std::cout << t1->value << endl;
    dic.print();
    dic.erase("test");
    tupla<string, string> *t2 = dic.find("test");
    if (t2 != nullptr)
    {
        std::cout << t2->value << endl;
    }
    dic.print();
}
