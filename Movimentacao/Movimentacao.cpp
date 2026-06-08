#include "Movimentacao.h"
#include <iostream>

using namespace std;

Movimentacao::Movimentacao(
    int id,
    string moeda,
    string tipoMovimentacao,
    double valor,
    string contraparte,
    string descricao,
    string data
) {
    this->id = id;
    this->moeda = moeda;
    this->tipoMovimentacao = tipoMovimentacao;
    this->valor = valor;
    this->contraparte = contraparte;
    this->descricao = descricao;
    this->data = data;
}
 
int Movimentacao::getId() const {return this->id;}
string Movimentacao::getMoeda() const {return this->moeda;}
string Movimentacao::getTipoMovimentacao() const {return this->tipoMovimentacao;}
double Movimentacao::getValor() const {return this->valor;}
string Movimentacao::getContraparte() const {return this->contraparte;}
string Movimentacao::getDescricao() const {return this->descricao;}
string Movimentacao::getData() const {return this->data;}

void Movimentacao::setMoeda(string moeda) {this->moeda = moeda;}
void Movimentacao::setTipoMovimentacao(string tipoMovimentacao) {this->tipoMovimentacao = tipoMovimentacao;}
void Movimentacao::setValor(double valor) {this->valor = valor;}
void Movimentacao::setContraparte(string contraparte) {this->contraparte = contraparte;}
void Movimentacao::setDescricao(string descricao) {this->descricao = descricao;}
void Movimentacao::setData(string data) {this->data = data;}
