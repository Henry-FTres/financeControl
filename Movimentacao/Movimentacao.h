#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>

using namespace std;

class Movimentacao {
    private:
        int id;
        string moeda;
        string tipoMovimentacao;
        double valor;
        string contraparte;
        string descricao;
        string data;

    public:
        Movimentacao();

        Movimentacao(
            int id,
            string moeda,
            string tipoMovimentacao,
            double valor,
            string contraparte,
            string descricao,
            string data
        );

        int getId() const;
        string getMoeda() const;
        string getTipoMovimentacao() const;
        double getValor() const;
        string getContraparte() const;
        string getDescricao() const;
        string getData() const;

        void setMoeda(string moeda);
        void setTipoMovimentacao(string tipoMovimentacao);
        void setValor(double valor);
        void setContraparte(string contraparte);
        void setDescricao(string descricao);
        void setData(string data); 
};

#endif