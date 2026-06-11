#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include "../Categoria/Categoria.h"

class Movimentacao {
    private:
        int id;
        std::string data;
        double valor;
        std::string tipoMovimentacao;
        std::string descricao;
        std::string contraparte;
        Categoria categoria;

    public:
        Movimentacao();

        Movimentacao(
            int id,
            double valor,
            std::string data,
            std::string tipoMovimentacao,
            std::string descricao,
            std::string contraparte,
            Categoria categoria
        );

        int getId() const;
        double getValor() const;
        std::string getData() const;
        std::string getTipoMovimentacao() const;
        std::string getDescricao() const;
        std::string getContraparte() const;
        Categoria getCategoria() const;

        void setValor(double valor);
        void setData(std::string data); 
        void setTipoMovimentacao(std::string tipoMovimentacao);
        void setDescricao(std::string descricao);
        void setContraparte(std::string contraparte);
        void setCategoria(Categoria categoria);

        void exibirDados() const;
        void editarValor(double valor);
};

#endif