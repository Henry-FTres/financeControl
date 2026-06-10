#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
 
#include "Pessoa.h"
#include <string>
 
using namespace std;
 
class PessoaFisica : public Pessoa {
    private:
        string cpf;
        string dataNascimento;
 
    public:
        PessoaFisica() {};

        PessoaFisica(
            int id,
            string nome,
            string email,
            string telefone,
            string cpf,
            string dataNascimento,
            vector<Conta> contas = {},
            vector<Meta> metas = {}
        );
        
        //getters
        string getCpf() const;
        string getDataNascimento() const;

        //setters
        void setCpf(string cpf);
        void setDataNascimento(string dataNascimento);
 
        void exibirDados() const override;
 
};
 
#endif