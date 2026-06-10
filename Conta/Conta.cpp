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

void Conta::exibirDados() const {
    cout << "ID: " << getId() << "\n"
         << "Instituição: " << getInstituicao() << "\n"
         << "Número da Conta: " << getNroConta() << "\n"
         << "Chave Pix: " << getChavePix() << "\n"
         << "Saldo: " << getSaldo() << "\n"
         << "Tipo da Conta: " << getTipoConta() << "\n";
}

void Conta::adicionarMovimentacao(const Movimentacao& m) {
    for (const auto& mov : movimentacoes) {
        if (mov.getId() == m.getId()) {
            cout << "Movimentação já regsitrada!" << "\n";
            return;
        }
    }
    movimentacoes.push_back(m);
}

void Conta::removerMovimentacao(int id) {
    for (auto it = movimentacoes.begin(); it != movimentacoes.end(); it++) {
        if (it->getId() == id) {
            movimentacoes.erase(it);
            cout << "Movimentação número " << id << " foi removida com sucesso!" << "\n";
            return;
        }
    }
    cout << "Movimentação não encontrada!" << "\n";
}

double Conta::totalPorCategoria(const string& categoria, const string& tipoMovimentacao) const {
    double total = 0.0;
    for (const auto& m : movimentacoes) {
        if (m.getCategoria().getNome() == categoria && m.getTipoMovimentacao() == tipoMovimentacao) {
            total += m.getValor();
        }
    }
    return total;
}

void Conta::transferir(Conta& destino, double valor) {
    if (valor <= 0) {
        cout << "Valor deve ser maior que zero!" << "\n";
        return;
    }

    if (this->saldo < valor) {
        cout << "Saldo insuficiente!" << "\n";
        return;
    }


    if (this->nroConta == destino.getNroConta()) {
        cout << "Não é possível fazer uma transferência para si mesmo!" << "\n";
        return;
    }

    this->saldo -= valor;
    destino.setSaldo(destino.getSaldo() + valor);
}

void Conta::listarMovimentacoes() const {
    if (movimentacoes.empty()) {
        cout << "Não há nenhuma movimentação a ser exibida!" << "\n";
        return;
    }
    for (const auto& mov : movimentacoes) {
        mov.exibirDados();
        cout << "\n";
    }
}