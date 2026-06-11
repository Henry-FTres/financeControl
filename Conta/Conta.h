#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <vector>
#include "Movimentacao.h"

using namespace std;

class Conta {
    private:
        int id;
        string instituicao;
        string numeroConta;
        string chavePix;
        double saldo;
        string tipoConta;
        vector<Movimentacao> movimentacoes;

        public:
            Conta();

            Conta(
                int id,
                string instituicao,
                string numeroConta,
                string chavePix,
                double saldo,
                string tipoConta,
                vector<Movimentacao> movimentacoes = {}
            );

            int getId() const;
            string getInstituicao() const;
            string getNumeroConta() const;
            string getChavePix() const;
            double getSaldo() const;
            string getTipoConta() const;

            void setInstituicao(string instituicao);
            void setNumeroConta(string numeroConta);
            void setChavePix(string chavePix);
            void setSaldo(double saldo);
            void setTipoConta(string tipoConta);

            void exibirDados() const;
            void adicionarMovimentacao(const Movimentacao& m);
            void removerMovimentacao(int id);
            double totalPorCategoria(const Categoria& categoria, const string& tipoMovimentacao) const;
            void transferir(Conta& destino, double valor);
            void listarMovimentacoes() const;

};


#endif

