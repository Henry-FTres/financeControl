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
        string nroConta;
        string chavePix;
        double saldo;
        string tipoConta;
        vector<Movimentacao> movimentacoes;

        public:
            Conta();

            Conta(
                int id,
                string instituicao,
                string nroConta,
                string chavePix,
                double saldo,
                string tipoConta
            );

            int getId() const;
            string getInstituicao() const;
            string getNroConta() const;
            string getChavePix() const;
            double getSaldo() const;
            string getTipoConta() const;

            void setInstituicao(string instituicao);
            void setNroConta(string nroConta);
            void setChavePix(string chavePix);
            void setSaldo(double saldo);
            void setTipoConta(string tipoConta);

};


#endif