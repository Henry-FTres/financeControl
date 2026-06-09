#include "Pessoa.h"
#include <iostream>

using namespace std;

// Construtor
Pessoa::Pessoa(int id, string nome, string email) {
    this->id = id;
    this->nome = nome;
    this->email = email;
}

// Destrutor
Pessoa::~Pessoa() {}

// Getters
int Pessoa::getId() const { return id; }
string Pessoa::getNome() const { return nome; }
string Pessoa::getEmail() const { return email; }

// Setters
void Pessoa::setNome(string nome) { this->nome = nome; }
void Pessoa::setEmail(string email) { this->email = email; }

void Pessoa::exibirDados() const {
    cout << "ID: " << getId() << "\n"
         << "Nome: " << getNome() << "\n"
         << "Email: " << getEmail() << "\n";
}