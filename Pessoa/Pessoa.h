#ifndef PESSOA_H //para não compilar múltiplas vezes
#define PESSOA_H //definir

#include <string>
#include <vector>
#include "Conta.h"
#include "Meta.h"
#include "Categoria.h"

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
        
        //virtual quer dizer que pode ser sobrescrita e const = 0 diz que cada classe filha deve implementar essa função de uma forma, tornando a classe pessoa abstrata
        virtual void exibirDados() const = 0;

        void adicionarConta( Conta conta);
        void removerConta(Conta conta);
        void adicionarMeta(Meta meta);
        void removerMeta(Meta meta);
        double calcularSaldoTotal();
        double calcularSaldoCategoria(Categoria categoria);
        void listarMetas();
};

#endif