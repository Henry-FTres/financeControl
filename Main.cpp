#include <iostream>
#include "../Categoria/Categoria.h"
#include "../Movimentacao/Movimentacao.h"
#include "../Conta/Conta.h"
#include "../Meta/Meta.h"
#include "../PessoaFisica/PessoaFisica.h"
#include "../PessoaJuridica/PessoaJuridica.h"

using namespace std;

int main() {

    vector<PessoaFisica> pessoasFisicas;
    vector<PessoaJuridica> pessoasJuridicas;
    
    int n = 0;
    while (n != 999) {

        cout << "-------------------------------" << "\n"
             << "      Controle Financeiro" << "\n"
             << "------------------------------" << "\n"
             << "1     - Criar Pessoa Física" << "\n"
             << "2     - Criar Pessoa Juridica" << "\n"
             << "3     - Listar Pessoas" << "\n"
             << "4     - Selecionar Pessoa" << "\n"
             << "Enter - Sair" << "\n"
             << "Digite sua opção: ";
        cin >> n;
        switch (n) {
            case 1: {
                int id;
                string nome;
                string email;
                string telefone;
                string cpf;
                string dataNascimento;
                cout << "Digite o ID: ";
                cin >> id;
                cout << "Digite seu nome: ";
                cin >> nome;
                cout << "Digite seu email: ";
                cin >> email;
                cout << "Digite seu telefone: ";
                cin >> telefone;
                cout << "Digite seu CPF: ";
                cin >> cpf;
                cout << "Digite sua Data de Nascimento (DD/MM/YYYY): ";
                cin >> dataNascimento;
                pessoasFisicas.push_back(PessoaFisica(id, nome, email, telefone, cpf, dataNascimento));
                cout << "Pessoa " << pessoasFisicas.back().getNome() << " criada!" << "\n";
                break;
            }
            case 2: {
                
                int id;
                string nome;
                string email;
                string telefone;
                string cnpj;
                string razaoSocial;
                cout << "Digite o ID: ";
                cin >> id;
                cout << "Digite seu nome: ";
                cin >> nome;
                cout << "Digite seu email: ";
                cin >> email;
                cout << "Digite seu telefone: ";
                cin >> telefone;
                cout << "Digite seu CNPJ: ";
                cin >> cnpj;
                cout << "Digite a Razão Social: ";
                cin >> razaoSocial;
                pessoasJuridicas.push_back(PessoaJuridica(id, nome, email, telefone, cnpj, razaoSocial));
                cout << "Pessoa " << pessoasJuridicas.back().getNome() << " criada!" << "\n";
                break;
                break;
            }
            case 3: {
                for (auto pf : pessoasFisicas) {
                    pf.exibirDados();
                    cout << "-----------------------------------------------" << "\n";
                    cout << "\n";
                }

                for (auto pj : pessoasFisicas) {
                    pj.exibirDados();
                    cout << "-----------------------------------------------" << "\n";
                    cout << "\n";
                }
                break;
            }
            case 4: {
                int tipo, idPessoa;

                cout << "-------------------------" "\n"
                        << "Pessoas Físicas" << "\n"
                        << "-------------------------" "\n";
                
                for (auto pf : pessoasFisicas) {
                    cout << "ID: " << pf.getId() << "\n";
                    cout << "Nome: " << pf.getNome() << "\n";
                }

                cout << "-------------------------" "\n"
                        << "Pessoas Jurídicas" << "\n"
                        << "-------------------------" "\n";
                
                for (auto pj : pessoasJuridicas) {
                    cout << "ID: " << pj.getId() << "\n";
                    cout << "Nome: " << pj.getNome() << "\n";
                }

                cout << "1 - Pessoa Fisica" << "\n"
                     << "2 - Pessoa Jurídica" << "\n"
                     << "Digite sua opção: ";
                cin >> tipo;

                cout << "Digite o ID da pessoa: ";
                cin >> idPessoa;

                break;
            }
            default:
                cout << "Saindo..." << "\n";
                break;
        }
    }

}




// Dentro de Selecionar pessoa, abrir um novo laço while (opcao != 1000), já solicita o id e o tipo, fazer uma verificação se é tipo 1 pf, tipo 2 pj. Verificar o tipo, dependendo do tipo, percorre pessoasFisicas ou pessoasJuridicas, comparando o id com pf.getId(). Se encontrou, fazer outr switch case com as opções de métodos, como exibir dados, adicionarConta, ver saldo, listar contas, ver saldo por categoria, adicionar remover meta, entre outros. Incluir uma opção 1000 para voltar ao menu anterior