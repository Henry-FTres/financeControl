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

void Pessoa::adicionarMeta(Meta meta){
    metas.push_back(meta);
}

void Pessoa::removerMeta(Meta meta){
    for (auto it = metas.begin(); it != metas.end(); it++) {
        if (it->getId() == meta.getId()) {
            metas.erase(it);
            break;
        }
    }
}

void Pessoa::listarMetas(){
    for (auto& meta : metas) {
        meta.exibirDados();
    }
}
