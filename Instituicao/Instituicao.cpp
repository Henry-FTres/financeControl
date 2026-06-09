#include "Instituicao.h"
#include <iostream>

using namespace std;

Instituicao::Instituicao(
    int id,
    string nroConta,
    double saldo,
    string tipoConta,
    string nome,
    string chavePix
) {
    this->id = id;
    this->nroConta = nroConta;
    this->saldo= saldo;
    this->tipoConta = tipoConta;
    this->nome= nome;
    this->chavePix = chavePix;
}

int Instituicao::getId() const {return this->id;}
string Instituicao::getNroConta() const {return this->nroConta;}
double Instituicao::getSaldo() const {return this->saldo;}
string Instituicao::getTipoConta() const {return this->tipoConta;}
string Instituicao::getNome() const {return this->nome;}
string Instituicao::getChavePix() const {return this->chavePix;}

void Instituicao::setNroConta(string nroConta) {this->nroConta = nroConta;}
void Instituicao::setSaldo(string nroConta) {this->saldo = saldo;}
void Instituicao::setTipoConta(string nroConta) {this->tipoConta = tipoConta;}
void Instituicao::setNome(string nroConta) {this->nome = nome;}
void Instituicao::setChavePix(string chavePix) {this->chavePix = chavePix;}