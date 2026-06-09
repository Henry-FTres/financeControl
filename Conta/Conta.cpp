#include "Conta.h"
#include <iostream>

using namespace std;

Conta::Conta(
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

int Conta::getId() const {return this->id;}
string Conta::getNroConta() const {return this->nroConta;}
double Conta::getSaldo() const {return this->saldo;}
string Conta::getTipoConta() const {return this->tipoConta;}
string Conta::getNome() const {return this->nome;}
string Conta::getChavePix() const {return this->chavePix;}

void Conta::setNroConta(string nroConta) {this->nroConta = nroConta;}
void Conta::setSaldo(string nroConta) {this->saldo = saldo;}
void Conta::setTipoConta(string nroConta) {this->tipoConta = tipoConta;}
void Conta::setNome(string nroConta) {this->nome = nome;}
void Conta::setChavePix(string chavePix) {this->chavePix = chavePix;}