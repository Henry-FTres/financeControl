#include "Meta.h"
#include <iostream>
 
using namespace std;
 
Meta::Meta(
    int idMeta,
    double orcamento,
    string prazo,
    string descricao
) {
    this->idMeta = idMeta;
    this->orcamento = orcamento;
    this->prazo = prazo;
    this->descricao = descricao;
}
 
int Meta::getIdMeta() const {return this->idMeta;}
double Meta::getOrcamento() const {return this->orcamento;}
string Meta::getPrazo() const {return this->prazo;}
string Meta::getDescricao() const {return this->descricao;}
 
void Meta::setOrcamento(double orcamento) {this->orcamento = orcamento;}
void Meta::setPrazo(string prazo) {this->prazo = prazo;}
void Meta::setDescricao(string descricao) {this->descricao = descricao;}