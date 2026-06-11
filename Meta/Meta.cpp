#include "Meta.h"
#include <iostream>
#include <iomanip>

using namespace std;

Meta::Meta() {}

Meta::Meta(
    int idMeta,
    double orcamento,
    string prazo,
    string descricao,
    double valorAtual,
    bool atingida
) {
    this->idMeta = idMeta;
    this->orcamento = orcamento;
    this->prazo = prazo;
    this->descricao = descricao;
    this->valorAtual = valorAtual;
    this->atingida = atingida;
}

//getters
int Meta::getIdMeta() const { 
    return this->idMeta; 
}
double Meta::getOrcamento() const { 
    return this->orcamento; 
}
string Meta::getPrazo() const { 
    return this->prazo; 
}
string Meta::getDescricao() const { 
    return this->descricao; 
}
double Meta::getValorAtual() const { 
    return this->valorAtual; 
}
bool Meta::getAtingida() const { 
    return this->atingida; 
}

//setters
void Meta::setOrcamento(double orcamento) { 
    this->orcamento = orcamento; 
}
void Meta::setPrazo(string prazo) { 
    this->prazo = prazo; 
}
void Meta::setDescricao(string descricao) { 
    this->descricao = descricao; 
}
void Meta::setValorAtual(double valorAtual) { 
    this->valorAtual = valorAtual; 
}

void Meta::exibirDados() const {
    cout << "ID: " << idMeta << "\n"
         << "Descrição: " << descricao << "\n"
         << "Orçamento: R$ " << orcamento << "\n"
         << "Valor Atual: R$ " << valorAtual << "\n"
         << "Prazo: " << prazo << "\n"
         << "Atingida: " << (atingida ? "Sim" : "Não") << "\n";
}


double Meta::calcularProgresso()const {
    double progresso = (valorAtual / orcamento) *100;
    return progresso;
}

void Meta::acrescerValorAtual(double valor) {
    valorAtual += valor;
     if(valorAtual >= orcamento){
        atingida=true;
        cout<< "Meta atingida!\n";
     }
}

void Meta::diminuirValorAtual(double valor) {
    valorAtual -= valor;
    if(valorAtual < orcamento){
        atingida = false;
        exibirProgresso();
        exibirQuantoFalta();
    }
}

void Meta::exibirQuantoFalta() const {
    double falta = orcamento - valorAtual;
    cout<< "Falta R$" << falta << endl;
}

void Meta::exibirProgresso() const{
    double progresso = calcularProgresso();
    cout << fixed << setprecision(2) << "Você progrediu " << progresso << "%\n";
}