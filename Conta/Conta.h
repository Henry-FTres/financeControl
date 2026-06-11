#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <vector>
#include "../Movimentacao/Movimentacao.h"
#include "../Categoria/Categoria.h"

class Conta {
    private:
        int id;
        std::string instituicao;
        std::string numeroConta;
        std::string chavePix;
        double saldo;
        std::string tipoConta;
        std::vector<Movimentacao> movimentacoes;

        public:
            Conta();

            Conta(
                int id,
                std::string instituicao,
                std::string numeroConta,
                std::string chavePix,
                double saldo,
                std::string tipoConta,
                std::vector<Movimentacao> movimentacoes = {}
            );

            int getId() const;
            std::string getInstituicao() const;
            std::string getNumeroConta() const;
            std::string getChavePix() const;
            double getSaldo() const;
            std::string getTipoConta() const;

            void setInstituicao(std::string instituicao);
            void setNumeroConta(std::string numeroConta);
            void setChavePix(std::string chavePix);
            void setSaldo(double saldo);
            void setTipoConta(std::string tipoConta);

            void exibirDados() const;
            void adicionarMovimentacao(const Movimentacao& m);
            void removerMovimentacao(int id);
            double totalPorCategoria(const Categoria& categoria, const std::string& tipoMovimentacao) const;
            void transferir(Conta& destino, double valor);
            void listarMovimentacoes() const;

};


#endif

