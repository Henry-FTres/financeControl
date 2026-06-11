#include <iostream>
#include <vector>
#include "./Movimentacao/Movimentacao.h"
#include "./Conta/Conta.h"
#include "./Meta/Meta.h"
#include "./PessoaFisica/PessoaFisica.h"
#include "./PessoaJuridica/PessoaJuridica.h"
#include "./Categoria/Categoria.h"

using namespace std;

void menuPessoa(PessoaFisica& pf, vector<Categoria>& categorias);
void menuPessoa(PessoaJuridica& pj, vector<Categoria>& categorias);
void menuContasPessoa(Pessoa& p, vector<Categoria>& categorias);
void menuMovimentacoesConta(Conta* conta, vector<Categoria>& categorias);

void menuMovimentacoesConta(Conta* conta, vector<Categoria>& categorias) {
    if (conta == nullptr) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    int opcao = 0;
    while (opcao != 1000) {
        cout << "\n--- Movimentacoes da Conta " << conta->getNumeroConta() << " ---\n";
        cout << "1   - Adicionar Movimentacao\n";
        cout << "2   - Listar Movimentacoes\n";
        cout << "3   - Remover Movimentacao\n";
        cout << "1000 - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                if (categorias.empty()) {
                    cout << "Nenhuma categoria cadastrada.\n";
                    break;
                }

                int id, categoriaIdx;
                double valor;
                string data, tipoMovimentacao, descricao, contraparte;

                cout << "ID: "; cin >> id;
                cout << "Valor: "; cin >> valor;
                cout << "Data (DD/MM/YYYY): "; cin >> data;
                cout << "Tipo (entrada/saida): "; cin >> tipoMovimentacao;
                cout << "Descricao: "; cin >> descricao;
                cout << "Contraparte: "; cin >> contraparte;

                cout << "Categorias disponiveis:\n";
                for (int i = 0; i < (int)categorias.size(); i++) {
                    cout << i + 1 << " - " << categorias[i].getNome() << "\n";
                }
                cout << "Categoria (numero): "; cin >> categoriaIdx;

                if (categoriaIdx < 1 || categoriaIdx > (int)categorias.size()) {
                    cout << "Categoria invalida.\n";
                    break;
                }

                conta->adicionarMovimentacao(Movimentacao(
                    id,
                    valor,
                    data,
                    tipoMovimentacao,
                    descricao,
                    contraparte,
                    categorias[categoriaIdx - 1]
                ));
                cout << "Movimentacao adicionada!\n";
                break;
            }
            case 2:
                conta->listarMovimentacoes();
                break;
            case 3: {
                int id;
                cout << "ID da movimentacao a remover: "; cin >> id;
                conta->removerMovimentacao(id);
                break;
            }
            case 1000:
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}

void menuContasPessoa(Pessoa& p, vector<Categoria>& categorias) {
    int opcao = 0;

    while (opcao != 6) {
        cout << "\n--- Contas de " << p.getNome() << " ---\n";
        cout << "1   - Adicionar Conta\n";
        cout << "2   - Listar Contas\n";
        cout << "3   - Selecionar Conta\n";
        cout << "4   - Ver Saldo Total\n";
        cout << "5   - Ver Saldo por Categoria\n";
        cout << "6 - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int id;
                string instituicao, numeroConta, chavePix, tipoConta;
                double saldo;
                cout << "ID: "; cin >> id;
                cout << "Instituicao: "; cin >> instituicao;
                cout << "Numero da Conta: "; cin >> numeroConta;
                cout << "Chave Pix: "; cin >> chavePix;
                cout << "Saldo inicial: "; cin >> saldo;
                cout << "Tipo da Conta: "; cin >> tipoConta;
                p.adicionarConta(Conta(id, instituicao, numeroConta, chavePix, saldo, tipoConta));
                cout << "Conta adicionada!\n";
                break;
            }
            case 2: {
                p.listarContas();
                break;
            }
            case 3: {
                int idConta;
                cout << "ID da conta: ";
                cin >> idConta;

                Conta* conta = p.encontrarContaPorId(idConta);
                if (conta == nullptr) {
                    cout << "Conta nao encontrada.\n";
                    break;
                }

                menuMovimentacoesConta(conta, categorias);
                break;
            }
            case 4: {
                p.exibirSaldoTotal();
                break;
            }
            case 5: {
                if (categorias.empty()) {
                    cout << "Nenhuma categoria cadastrada.\n";
                    break;
                }
                cout << "Categorias disponiveis:\n";
                for (int i = 0; i < (int)categorias.size(); i++) {
                    cout << i + 1 << " - " << categorias[i].getNome() << "\n";
                }
                int idx;
                string tipo;
                cout << "Selecione a categoria (numero): "; cin >> idx;
                cout << "Tipo (entrada/saida): "; cin >> tipo;
                if (idx >= 1 && idx <= (int)categorias.size()) {
                    p.exibirSaldoCategoria(categorias[idx - 1], tipo);
                } else {
                    cout << "Categoria invalida.\n";
                }
                break;
            }
            case 1000:
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}

void menuPessoa(PessoaFisica& pf, vector<Categoria>& categorias) {
    int opcao = 0;
    while (opcao != 1000) {
        cout << "\n--- " << pf.getNome() << " ---\n";
        cout << "1   - Exibir Dados\n";
        cout << "2   - Gerenciar Contas\n";
        cout << "3   - Adicionar Meta\n";
        cout << "4   - Listar Metas\n";
        cout << "5   - Remover Meta\n";
        cout << "1000 - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pf.exibirDados();
                break;
            case 2:
                menuContasPessoa(pf, categorias);
                break;
            case 3: {
                int id;
                double orcamento, valorAtual;
                string prazo, descricao;
                cout << "ID: "; cin >> id;
                cout << "Descricao: "; cin >> descricao;
                cout << "Orcamento: "; cin >> orcamento;
                cout << "Valor Atual: "; cin >> valorAtual;
                cout << "Prazo: "; cin >> prazo;
                pf.adicionarMeta(Meta(id, orcamento, prazo, descricao, valorAtual));
                cout << "Meta adicionada!\n";
                break;
            }
            case 4:
                pf.listarMetas();
                break;
            case 5: {
                int id;
                cout << "ID da meta a remover: "; cin >> id;
                pf.removerMeta(Meta(id, 0, "", "", 0));
                cout << "Meta removida (se existia).\n";
                break;
            }
            case 1000:
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}

void menuPessoa(PessoaJuridica& pj, vector<Categoria>& categorias) {
    int opcao = 0;
    while (opcao != 1000) {
        cout << "\n--- " << pj.getNome() << " ---\n";
        cout << "1   - Exibir Dados\n";
        cout << "2   - Gerenciar Contas\n";
        cout << "3   - Adicionar Meta\n";
        cout << "4   - Listar Metas\n";
        cout << "5   - Remover Meta\n";
        cout << "1000 - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                pj.exibirDados();
                break;
            case 2:
                menuContasPessoa(pj, categorias);
                break;
            case 3: {
                int id;
                double orcamento, valorAtual;
                string prazo, descricao;
                cout << "ID: "; cin >> id;
                cout << "Descricao: "; cin >> descricao;
                cout << "Orcamento: "; cin >> orcamento;
                cout << "Valor Atual: "; cin >> valorAtual;
                cout << "Prazo: "; cin >> prazo;
                pj.adicionarMeta(Meta(id, orcamento, prazo, descricao, valorAtual));
                cout << "Meta adicionada!\n";
                break;
            }
            case 4:
                pj.listarMetas();
                break;
            case 5: {
                int id;
                cout << "ID da meta a remover: "; cin >> id;
                pj.removerMeta(Meta(id, 0, "", "", 0));
                cout << "Meta removida (se existia).\n";
                break;
            }
            case 1000:
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }
}

int main() {
    vector<PessoaFisica> pessoasFisicas;
    vector<PessoaJuridica> pessoasJuridicas;
    vector<Categoria> categorias;

    //categorias padrão
    categorias.push_back(Categoria(1, "Alimentacao", true));
    categorias.push_back(Categoria(2, "Transporte", true));
    categorias.push_back(Categoria(3, "Moradia", true));
    categorias.push_back(Categoria(4, "Lazer", true));
    categorias.push_back(Categoria(5, "Saude", true));

    int n = 0;
    while (n != 6) {
        cout << "\n-------------------------------\n";
        cout << "      Controle Financeiro\n";
        cout << "-------------------------------\n";
        cout << "1   - Criar Pessoa Fisica\n";
        cout << "2   - Criar Pessoa Juridica\n";
        cout << "3   - Listar Pessoas\n";
        cout << "4   - Selecionar Pessoa\n";
        cout << "5   - Gerenciar Categorias\n";
        cout << "6 - Sair\n";
        cout << "Digite sua opcao: ";
        cin >> n;

        switch (n) {
            case 1: {
                int id;
                string nome, email, telefone, cpf, dataNascimento;
                cout << "ID: "; cin >> id;
                cout << "Nome: "; cin >> nome;
                cout << "Email: "; cin >> email;
                cout << "Telefone: "; cin >> telefone;
                cout << "CPF: "; cin >> cpf;
                cout << "Data de Nascimento (DD/MM/YYYY): "; cin >> dataNascimento;
                pessoasFisicas.push_back(PessoaFisica(id, nome, email, telefone, cpf, dataNascimento));
                cout << "Pessoa " << pessoasFisicas.back().getNome() << " criada!\n";
                break;
            }
            case 2: {
                int id;
                string nome, email, telefone, cnpj, razaoSocial;
                cout << "ID: "; cin >> id;
                cout << "Nome: "; cin >> nome;
                cout << "Email: "; cin >> email;
                cout << "Telefone: "; cin >> telefone;
                cout << "CNPJ: "; cin >> cnpj;
                cout << "Razao Social: "; cin >> razaoSocial;
                pessoasJuridicas.push_back(PessoaJuridica(id, nome, email, telefone, cnpj, razaoSocial));
                cout << "Pessoa " << pessoasJuridicas.back().getNome() << " criada!\n";
                break;
            }
            case 3: {
                cout << "\n--- Pessoas Fisicas ---\n";
                for (auto& pf : pessoasFisicas) {
                    pf.exibirDados();
                    cout << "---\n";
                }
                cout << "\n--- Pessoas Juridicas ---\n";
                for (auto& pj : pessoasJuridicas) {
                    pj.exibirDados();
                    cout << "---\n";
                }
                break;
            }
            case 4: {
                cout << "\n--- Pessoas Fisicas ---\n";
                for (auto& pf : pessoasFisicas) {
                    cout << "ID: " << pf.getId() << " | Nome: " << pf.getNome() << "\n";
                }
                cout << "\n--- Pessoas Juridicas ---\n";
                for (auto& pj : pessoasJuridicas) {
                    cout << "ID: " << pj.getId() << " | Nome: " << pj.getNome() << "\n";
                }

                int tipo, idPessoa;
                cout << "\n1 - Pessoa Fisica | 2 - Pessoa Juridica\nTipo: "; cin >> tipo;
                cout << "ID da pessoa: "; cin >> idPessoa;

                if (tipo == 1) {
                    bool encontrou = false;
                    for (auto& pf : pessoasFisicas) {
                        if (pf.getId() == idPessoa) {
                            menuPessoa(pf, categorias);
                            encontrou = true;
                            break;
                        }
                    }
                    if (!encontrou) cout << "Pessoa nao encontrada.\n";
                } else if (tipo == 2) {
                    bool encontrou = false;
                    for (auto& pj : pessoasJuridicas) {
                        if (pj.getId() == idPessoa) {
                            menuPessoa(pj, categorias);
                            encontrou = true;
                            break;
                        }
                    }
                    if (!encontrou) cout << "Pessoa nao encontrada.\n";
                }
                break;
            }
            case 5: {
                int opcaoCat = 0;
                while (opcaoCat != 3) {
                    cout << "\n--- Categorias ---\n";
                    cout << "1   - Adicionar Categoria\n";
                    cout << "2   - Listar Categorias\n";
                    cout << "3 - Voltar\n";
                    cout << "Opcao: "; cin >> opcaoCat;

                    if (opcaoCat == 1) {
                        int id;
                        string nome;
                        cout << "ID: "; cin >> id;
                        cout << "Nome: "; cin >> nome;
                        categorias.push_back(Categoria(id, nome, false));
                        cout << "Categoria adicionada!\n";
                    } else if (opcaoCat == 2) {
                        for (auto& c : categorias) {
                            c.exibirDados();
                            cout << "---\n";
                        }
                    }
                }
                break;
            }
            case 6:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    }

    return 0;
}