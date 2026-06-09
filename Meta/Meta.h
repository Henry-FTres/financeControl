#ifndef META_H
#define META_H
 
#include <iostream>
 
using namespace std;
 
class Meta {
    private:
        int idMeta;
        double orcamento;
        string prazo;
        string descricao;
 
    public:
        Meta();
 
        Meta(
            int idMeta,
            double orcamento,
            string prazo,
            string descricao
        );
 
        int getIdMeta() const;
        double getOrcamento() const;
        string getPrazo() const;
        string getDescricao() const;
 
        void setOrcamento(double orcamento);
        void setPrazo(string prazo);
        void setDescricao(string descricao);
 
};
 
#endif