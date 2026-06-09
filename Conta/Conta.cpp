#include "Conta.h"
#include <iostream>
#include <vector>
#include "Movimentacao.h"

using namespace std;

Conta::Conta(
    int id,
    string instituicao,
    string nroConta,
    string chavePix,
    double saldo,
    string tipoConta
) {
    this->id = id;
    this->instituicao = instituicao;
    this->nroConta = nroConta;
    this->chavePix = chavePix;
    this->saldo= saldo;
    this->tipoConta = tipoConta;
}

int Conta::getId() const {return this->id;}
string Conta::getInstituicao() const {return this->instituicao;}
string Conta::getNroConta() const {return this->nroConta;}
string Conta::getChavePix() const {return this->chavePix;}
double Conta::getSaldo() const {return this->saldo;}
string Conta::getTipoConta() const {return this->tipoConta;}

void Conta::setInstituicao(string instituicao) {this->instituicao = instituicao;}
void Conta::setNroConta(string nroConta) {this->nroConta = nroConta;}
void Conta::setChavePix(string chavePix) {this->chavePix = chavePix;}
void Conta::setSaldo(double saldo) {this->saldo = saldo;}
void Conta::setTipoConta(string tipoConta) {this->tipoConta = tipoConta;}