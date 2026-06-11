#ifndef PESSOA_H //para não compilar múltiplas vezes
#define PESSOA_H //definir

#include <string>
#include <vector>
#include "../Conta/Conta.h"
#include "../Meta/Meta.h"
#include "../Categoria/Categoria.h"

class Pessoa {
    private:
        int id;
        std::string nome;
        std::string email;
        std::string telefone;
        std::vector<Conta> contas;
        std::vector<Meta> metas;

    public:
        // Construtor
        Pessoa() {};

        Pessoa(int id, 
            std::string nome, 
            std::string email,
            std::string telefone,
            std::vector<Conta> contas = {},
            std::vector<Meta> metas = {}
        );

        // Destrutor
        virtual ~Pessoa();

        // Getters
        int getId() const;
        std::string getNome() const;
        std::string getEmail() const;
        std::string getTelefone() const;

        // Setters
        void setNome(std::string nome);
        void setEmail(std::string email);
        void setTelefone(std::string telefone);
        
        //virtual quer dizer que pode ser sobrescrita e const = 0 diz que cada classe filha deve implementar essa função de uma forma, tornando a classe pessoa abstrata
        virtual void exibirDados() const = 0;

        void adicionarConta(Conta conta);
        void removerConta(Conta conta);
        void listarContas() const;
        Conta* encontrarContaPorId(int id); //retorna um ponteiro para modificar o objeto verdadeiro e não uma cópia
        void adicionarMeta(Meta meta);
        void removerMeta(Meta meta);
        double calcularSaldoTotal() const;
        double calcularSaldoCategoria(Categoria& categoria, std::string& tipoMovimentacao) const;
        void listarMetas() const;
        void exibirSaldoTotal()const;
        void exibirSaldoCategoria(Categoria& categoria, std::string& tipoMovimentacao)const;
};

#endif