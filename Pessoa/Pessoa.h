#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <vector>
#include "Conta.h"
#include "Meta.h"

using namespace std;

class Pessoa {
    private:
        int id;
        string nome;
        string email;
        string telefone;
        vector<Conta> contas;
        vector<Meta> metas;

    public:
        // Construtor
        Pessoa() {};

        Pessoa(int id, 
            string nome, 
            string email,
            string telefone,
            vector<Conta> contas = {},
            vector<Meta> metas = {}
        );

        // Destrutor
        virtual ~Pessoa();

        // Getters
        int getId() const;
        string getNome() const;
        string getEmail() const;
        string getTelefone() const;

        // Setters
        void setNome(string nome);
        void setEmail(string email);
        void setTelefone(string telefone);
        
        // Metodo abstrato, informa ao compilador que não deve ser instanciada
        virtual void exibirDados() const = 0;
};

#endif