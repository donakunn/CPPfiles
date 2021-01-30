#ifndef _ESAME_H
#define _ESAME_H
#include <string>

using namespace std;

class esame
{
public:
    esame();
    esame(const string&);
    esame(const string&, const int&);
    string getEsame();
    void setEsame(string const &);
    int getVoto();
    void setVoto(const int&);
    bool isSostenuto();
private:
    string nome;
    int voto;
    bool sostenuto = false;
};
#endif // _ESAME_H
