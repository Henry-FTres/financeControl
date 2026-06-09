#include "Categoria.h"
#include <iostream>
 
using namespace std;
 
Categoria::Categoria(
    int idCategoria,
    string nome,
    bool fixo
) {
    this->idCategoria = idCategoria;
    this->nome = nome;
    this->fixo = fixo;
};
 
int Categoria::getIdCategoria() const {return this->idCategoria;}
string Categoria::getNome() const {return this->nome;};
bool Categoria::getFixo() const {return this->fixo;}
 
void Categoria::setNome(string nome) {this->nome = nome;}
void Categoria::setFixo(bool fixo) {this->fixo = fixo;}