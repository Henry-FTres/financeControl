#include "Pessoa.h"
#include <iostream>

using namespace std;

//construtor
Pessoa::Pessoa(int id, string nome, string email, string telefone, vector<Conta> contas, vector<Meta> metas) {
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->telefone = telefone;
    this->contas = contas;
    this->metas = metas;
}

//destrutor
Pessoa::~Pessoa(){

}


// Getters
int Pessoa::getId() const {
    return id;
}

string Pessoa::getNome() const {
    return nome;
}

string Pessoa::getEmail() const {
    return email;
}

string Pessoa::getTelefone() const {
    return telefone;
}


// Setters
void Pessoa::setNome(string nome) {
    this->nome = nome;
}

void Pessoa::setEmail(string email) {
    this->email = email;
}

void Pessoa::setTelefone(string telefone){
    this->telefone = telefone;
}

void Pessoa::adicionarConta(Conta conta){
    contas.push_back(conta);
}

void Pessoa::removerConta(Conta conta){
    for (auto it = contas.begin(); it != contas.end(); it++) {
        if (it->getId() == conta.getId()) {
            contas.erase(it);
            break;
        }
    }
}

void Pessoa::listarContas() const {
    if (contas.empty()) {
        cout << "Nenhuma conta cadastrada.\n";
        return;
    }

    for (const auto& conta : contas) {
        conta.exibirDados();
        cout << "---\n";
    }
}

Conta* Pessoa::encontrarContaPorId(int id) {
    for (auto& conta : contas) {
        if (conta.getId() == id) {
            return &conta;
        }
    }

    return nullptr;
}

void Pessoa::adicionarMeta(Meta meta){
    metas.push_back(meta);
}

void Pessoa::removerMeta(Meta meta){
    for (auto it = metas.begin(); it != metas.end(); it++) {
        if (it->getIdMeta() == meta.getIdMeta()) {
            metas.erase(it);
            break;
        }
    }
}

void Pessoa::listarMetas() const {
    for (auto& meta : metas) {
        meta.exibirDados();
    }
}

double Pessoa::calcularSaldoTotal() const {
    double saldoTotal = 0.0;
    for (auto c : contas) {
        saldoTotal += c.getSaldo();
    }

    return saldoTotal;
}

double Pessoa::calcularSaldoCategoria(Categoria& categoria, string& tipoMovimentacao) const {
    double saldoCategoria = 0.0;
    for (auto& c : contas) {
        saldoCategoria += c.totalPorCategoria(categoria, tipoMovimentacao);
    }

    return saldoCategoria;
}

void Pessoa::exibirSaldoTotal() const {
    cout << "Saldo total: R$ " << calcularSaldoTotal() << "\n";
}

void Pessoa::exibirSaldoCategoria(Categoria& categoria, string& tipoMovimentacao) const {
    cout << "Saldo da categoria " << categoria.getNome() << ": R$ " << calcularSaldoCategoria(categoria, tipoMovimentacao) << "\n";
}