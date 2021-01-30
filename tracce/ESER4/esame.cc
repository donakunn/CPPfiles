#include "esame.h"

esame::esame() {}

esame::esame(const string &nome)
{
    this->nome = nome;
}
esame::esame(const string &nome, const int &voto)
{
    if (voto < 18 || voto > 30)
        __throw_domain_error("voto deve essere compreso tra 18 e 30");
    else
    {
        this->nome = nome;
        this->voto = voto;
        sostenuto = true;
    }
}
string esame::getEsame()
{
    return this->nome;
}
void esame::setEsame(string const &nome)
{
    this->nome = nome;
    if (voto > 18 && voto <= 30)
        sostenuto = true;
}
int esame::getVoto()
{
    return this->voto;
}
void esame::setVoto(const int &voto)
{
    if (voto < 18 || voto > 30)
        __throw_domain_error("voto deve essere compreso tra 18 e 30");
    else
    {
        this->voto = voto;
        sostenuto = true;
    }
}
bool esame::isSostenuto()
{
    return sostenuto;
}