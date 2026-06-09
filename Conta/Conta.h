#ifndef CONTA_H
#define CONTA_H

#include <iostream>

using namespace std;

class Conta {
    private:
        int id;
        string nroConta;
        double saldo;
        string tipoConta;
        string nome;
        string chavePix;

        public:
            Conta();

            Conta(
                int id,
                string nroConta,
                double saldo,
                string tipoConta,
                string nome,
                string chavePix
            );

            int getId() const;
            string getNroConta() const;
            double getSaldo() const;
            string getTipoConta() const;
            string getNome() const;
            string getChavePix() const;

            void setNroConta(string nroConta);
            void setSaldo(string saldo);
            void setTipoConta(string tipoConta);
            void setNome(string nome);
            void setChavePix(string chavePix);

};


#endif