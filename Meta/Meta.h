#ifndef META_H
#define META_H
 
#include <iostream>
  
class Meta {
    private:
        int idMeta;
        double orcamento;
        std::string prazo;
        std::string descricao;
        double valorAtual;
        bool atingida;
 
    public:
        Meta();
 
        Meta(
            int idMeta,
            double orcamento,
            std::string prazo,
            std::string descricao,
            double valorAtual,
            bool atingida = false
        );
 
        int getIdMeta() const;
        double getOrcamento() const;
        std::string getPrazo() const;
        std::string getDescricao() const;
        double getValorAtual() const;
        bool getAtingida() const;
 
        void setOrcamento(double orcamento);
        void setPrazo(std::string prazo);
        void setDescricao(std::string descricao);
        void setValorAtual(double valorAtual);
        void setAtingida(bool atingida);

        void exibirDados() const;
        double calcularProgresso()const;
        void acrescerValorAtual(double valor);
        void diminuirValorAtual(double valor);
        void exibirQuantoFalta()const;
        void exibirProgresso()const;
 
};
 
#endif