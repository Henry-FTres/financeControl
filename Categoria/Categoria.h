#ifndef CATEGORIA_H
#define CATEGORIA_H
 
#include <iostream>
  
class Categoria {
    private:
        int idCategoria;
        std::string nome;
        bool fixo;

    public:
        Categoria();
 
        Categoria(
            int idCategoria,
            std::string nome,
            bool fixo
        );
 
        int getIdCategoria() const;
        std::string getNome() const;
        bool getFixo() const;
 
        void setNome(std::string nome);
        void setFixo(bool fixo);

        void exibirDados() const;
        void inverterFixo();
};
 
#endif