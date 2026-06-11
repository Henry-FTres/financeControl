#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include "Categoria.h"

using namespace std;

class Movimentacao {
    private:
        int id;
        string data;
        double valor;
        string tipoMovimentacao;
        string descricao;
        string contraparte;
        Categoria categoria;

    public:
        Movimentacao();

        Movimentacao(
            int id,
            double valor,
            string data,
            string tipoMovimentacao,
            string descricao,
            string contraparte,
            Categoria categoria
        );

        int getId() const;
        double getValor() const;
        string getData() const;
        string getTipoMovimentacao() const;
        string getDescricao() const;
        string getContraparte() const;
        Categoria getCategoria() const;

        void setValor(double valor);
        void setData(string data); 
        void setTipoMovimentacao(string tipoMovimentacao);
        void setDescricao(string descricao);
        void setContraparte(string contraparte);
        void setCategoria(Categoria categoria);

        void exibirDados() const;
        void atualizarCategoria(Categoria categoria);
        void editarValor(double valor);
};

#endif