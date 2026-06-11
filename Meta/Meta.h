#ifndef META_H
#define META_H
 
#include <iostream>
 
using namespace std;
 
class Meta {
    private:
        int idMeta;
        double orcamento;
        string prazo;
        string descricao;
        double valorAtual;
        bool atingida;
 
    public:
        Meta();
 
        Meta(
            int idMeta,
            double orcamento,
            string prazo,
            string descricao,
            double valorAtual,
            bool atingida = false
        );
 
        int getIdMeta() const;
        double getOrcamento() const;
        string getPrazo() const;
        string getDescricao() const;
        double getValorAtual() const;
        bool getAtingida() const;
 
        void setOrcamento(double orcamento);
        void setPrazo(string prazo);
        void setDescricao(string descricao);
        void setValorAtual(double valorAtual);

        void exibirDados() const;
        double calcularProgresso()const;
        void acrescerValorAtual(double valor);
        void diminuirValorAtual(double valor);
        void exibirQuantoFalta()const;
        void exibirProgresso()const;
 
};
 
#endif