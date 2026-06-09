#include "Pessoa.h"
#include <iostream>

using namespace std;

// Construtor
Pessoa::Pessoa(int id, string nome, string email, string telefone, vector<Conta> contas, vector<Meta> metas) {
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->telefone = telefone;
    this->contas = contas;
    this->metas = metas;
}

// Destrutor
Pessoa::~Pessoa() {}

// Getters
int Pessoa::getId() const { return id; }
string Pessoa::getNome() const { return nome; }
string Pessoa::getEmail() const { return email; }
string Pessoa::getTelefone() const { return telefone; }

// Setters
void Pessoa::setNome(string nome) { this->nome = nome; }
void Pessoa::setEmail(string email) { this->email = email; }
void Pessoa::setTelefone(string telefone) { this->telefone = telefone; }

void Pessoa::exibirDados() const {
    cout << "ID: " << getId() << "\n"
         << "Nome: " << getNome() << "\n"
         << "Email: " << getEmail() << "\n"
         << "Telefone: " << getTelefone() << "\n";
}