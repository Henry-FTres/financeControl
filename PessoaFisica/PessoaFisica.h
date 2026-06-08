#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
 
#include "Pessoa.h"
#include <string>
 
using namespace std;
 
class PessoaFisica : public Pessoa {
    private:
        string cpf;
 
    public:
        PessoaFisica(
            int id,
            string nome,
            string email,
            string cpf
        );
 
        string getCpf() const;
        void setCpf(string cpf);
 
        void exibirDados() const override;
 
};
 
#endif