#ifndef PESSOA_H
#define PESSOA_H

#include <string>

using namespace std;

class Pessoa {
    private:
        int id;
        string nome;
        string email;

    public:

        // Construtor
        Pessoa(int id, 
            string nome, 
            string email
        );

        // Destrutor
        virtual ~Pessoa();

        // Getters
        int getId() const;
        string getNome() const;
        string getEmail() const;

        // Setters
        void setNome(string nome);
        void setEmail(string email);
        
        // Metodo abstrato, informa ao compilador que não deve ser instanciada
        virtual void exibirDados() const = 0;
};

#endif