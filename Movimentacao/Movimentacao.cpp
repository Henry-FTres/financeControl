#include "Movimentacao.h"
#include <iostream>

using namespace std;

Movimentacao::Movimentacao() {};

Movimentacao::Movimentacao(
    int id,
    double valor,
    string data,
    string tipoMovimentacao,
    string descricao,
    string contraparte,
    Categoria categoria
) {
    this->id = id;
    this->valor = valor;
    this->data = data;
    this->tipoMovimentacao = tipoMovimentacao;
    this->descricao = descricao;
    this->contraparte = contraparte;
    this->categoria = categoria;
}
 
int Movimentacao::getId() const {return this->id;}
double Movimentacao::getValor() const {return this->valor;}
string Movimentacao::getData() const {return this->data;}
string Movimentacao::getTipoMovimentacao() const {return this->tipoMovimentacao;}
string Movimentacao::getDescricao() const {return this->descricao;}
string Movimentacao::getContraparte() const {return this->contraparte;}
Categoria Movimentacao::getCategoria() const {return this->categoria;}

void Movimentacao::setValor(double valor) {this->valor = valor;}
void Movimentacao::setData(string data) {this->data = data;}
void Movimentacao::setTipoMovimentacao(string tipoMovimentacao) {this->tipoMovimentacao = tipoMovimentacao;}
void Movimentacao::setDescricao(string descricao) {this->descricao = descricao;}
void Movimentacao::setContraparte(string contraparte) {this->contraparte = contraparte;}
void Movimentacao::setCategoria(Categoria categoria) {this->categoria = categoria;}

void Movimentacao::exibirDados() const {
    cout << "ID: " << getId() << "\n"
         << "Valor: " << getValor() << "\n"
         << "Data: " << getData() << "\n"
         << "Tipo da Movimentação: " << getTipoMovimentacao() << "\n"
         << "Descrição: " << getDescricao() << "\n"
         << "Contraparte: " << getContraparte() << "\n"
         << "Categoria: " << getCategoria().getNome() << "\n";
}

void Movimentacao::atualizarCategoria(Categoria categoria) {
    this->setCategoria(categoria);
}

void Movimentacao::editarValor(double valor) {
    if (valor <= 0) {
        cout << "Valor deve ser maior que zero!" << "\n";
        return;
    }

    this->setValor(valor);
}
