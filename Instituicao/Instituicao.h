#ifndef INSTITUICAO_H
#define INSTITUICAO_H

#include <iostream>

using namespace std;

class Instituicao {
    private:
        int id;
        string nroConta;
        double saldo;
        string tipoConta;
        string nome;
        string chavePix;

        public:
            Instituicao();

            Instituicao(
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