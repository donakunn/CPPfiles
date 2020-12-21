#include "hash_table.h"
#include "string"
using namespace std;

int main(){
    hash_table<int,string> dic(9); 
    tupla<int,string> t;
    t.key = 5;
    t.value = "ciccio";
    dic.insert(t);
    return 0;
}