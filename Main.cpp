#include <iostream>
#include <vector>
#include "./Movimentacao/Movimentacao.h"
#include "./Conta/Conta.h"
#include "./Meta/Meta.h"
#include "./PessoaFisica/PessoaFisica.h"
#include "./PessoaJuridica/PessoaJuridica.h"
#include "./Categoria/Categoria.h"

using namespace std;

void menuPessoaFisica(PessoaFisica& pf, vector<Categoria>& categorias);
void menuPessoaJuridica(PessoaJuridica& pj, vector<Categoria>& categorias);
void menuContasPessoa(Pessoa& p, vector<Categoria>& categorias);
void menuMovimentacoesConta(Conta* conta, vector<Categoria>& categorias);

void menuMovimentacoesConta(Conta* conta, vector<Categoria>& categorias) {
    if (conta == nullptr) {
        cout << "Conta nao encontrada!\n";
        return;
    }

    int opcao = 0;
    while (opcao != 4) {
        cout << "\n--- Movimentações da Conta " << conta->getNumeroConta() << " ---\n";
        cout << "1   - Adicionar Movimentação\n";
        cout << "2   - Listar Movimentações\n";
        cout << "3   - Remover Movimentação\n";
        cout << "4   - Voltar\n";
        cout << "Opção: ";
        cin >> opcao;
        cout << "\n";

        switch (opcao) {
            case 1: {

                //verifica se existem categorias cadastradas
                if (categorias.empty()) {
                    cout << "Nenhuma categoria cadastrada.\n";
                    break;
                }

                int id, categoriaId;
                double valor;
                string data, tipoMovimentacao, descricao, contraparte;

                cout << "ID: "; cin >> id;
                cout << "Valor: "; cin >> valor;
                cout << "Data (DD/MM/YYYY): "; cin >> data;
                cout << "Tipo (entrada/saída): "; cin >> tipoMovimentacao;
                cout << "Descrição: "; cin >> descricao;
                cout << "Contraparte: "; cin >> contraparte;
                cout << "\n";

                cout << "Categorias disponíveis:\n";
                for (int i = 0; i < (int)categorias.size(); i++) {
                    cout << i + 1 << " - " << categorias[i].getNome() << "\n";
                }
                cout << "Categoria: "; cin >> categoriaId;

                if (categoriaId < 1 || categoriaId > (int)categorias.size()) {
                    cout << "Categoria inválida!\n";
                    break;
                }

                conta->adicionarMovimentacao(Movimentacao(
                    id,
                    valor,
                    data,
                    tipoMovimentacao,
                    descricao,
                    contraparte,
                    categorias[categoriaId - 1]
                ));
                cout << "Movimentação adicionada!\n";
                break;
            }
            case 2:
                conta->listarMovimentacoes();
                break;
            case 3: {
                int id;
                cout << "ID da movimentação a remover: "; cin >> id;
                conta->removerMovimentacao(id);
                break;
            }
            case 4:
                break;
            default:
                cout << "Opção inválida.\n";
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
        cout << "6   - Voltar\n";
        cout << "Opção: ";
        cin >> opcao;
        cout << "\n";

        switch (opcao) {
            case 1: {
                int id;
                string instituicao, numeroConta, chavePix, tipoConta;
                double saldo;
                cout << "ID: "; cin >> id;
                cout << "Instituição: "; cin >> instituicao;
                cout << "Número da Conta: "; cin >> numeroConta;
                cout << "Chave Pix: "; cin >> chavePix;
                cout << "Saldo inicial: "; cin >> saldo;
                cout << "Tipo da Conta: "; cin >> tipoConta;
                cout << "\n";
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

                cout << "Contas disponíveis:\n";
                p.listarContas();
                cout << "ID da conta: ";
                cin >> idConta;

                Conta* conta = p.encontrarContaPorId(idConta);
                if (conta == nullptr) {
                    cout << "Conta nao encontrada!\n";
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
                    cout << "Nenhuma categoria cadastrada!\n";
                    break;
                }
                cout << "Categorias disponíveis:\n";
                for (int i = 0; i < (int)categorias.size(); i++) {
                    cout << i + 1 << " - " << categorias[i].getNome() << "\n";
                }
                int idx;
                string tipo;
                cout << "Selecione a categoria: "; cin >> idx;
                cout << "Tipo (entrada/saída): "; cin >> tipo;
                if (idx >= 1 && idx <= (int)categorias.size()) {
                    p.exibirSaldoCategoria(categorias[idx - 1], tipo);
                } else {
                    cout << "Categoria inválida!\n";
                }
                break;
            }
            case 6:
                break;
            default:
                cout << "Opcao inválida.\n";
        }
    }
}

void menuPessoaFisica(PessoaFisica& pf, vector<Categoria>& categorias) {
    int opcao = 0;
    while (opcao != 1000) {
        cout << "\n--- " << pf.getNome() << " ---\n";
        cout << "1   - Exibir Dados\n";
        cout << "2   - Gerenciar Contas\n";
        cout << "3   - Adicionar Meta\n";
        cout << "4   - Listar Metas\n";
        cout << "5   - Remover Meta\n";
        cout << "6   - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;
        cout << "\n";

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
                cout << "Descrição: "; cin >> descricao;
                cout << "Orçamento: "; cin >> orcamento;
                cout << "Valor Atual: "; cin >> valorAtual;
                cout << "Prazo: "; cin >> prazo;
                cout << "\n";
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
            case 6:
                break;
            default:
                cout << "Opcao inválida.\n";
        }
    }
}

void menuPessoaJuridica(PessoaJuridica& pj, vector<Categoria>& categorias) {
    int opcao = 0;
    while (opcao != 6) {
        cout << "\n--- " << pj.getNome() << " ---\n";
        cout << "1   - Exibir Dados\n";
        cout << "2   - Gerenciar Contas\n";
        cout << "3   - Adicionar Meta\n";
        cout << "4   - Listar Metas\n";
        cout << "5   - Remover Meta\n";
        cout << "6   - Voltar\n";
        cout << "Opcao: ";
        cin >> opcao;
        cout << "\n";

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
                cout << "Descrição: "; cin >> descricao;
                cout << "Orçamento: "; cin >> orcamento;
                cout << "Valor Atual: "; cin >> valorAtual;
                cout << "Prazo: "; cin >> prazo;
                cout << "\n";
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
            case 6:
                break;
            default:
                cout << "Opção inválida.\n";
        }
    }
}

int main() {
    vector<PessoaFisica> pessoasFisicas;
    vector<PessoaJuridica> pessoasJuridicas;
    vector<Categoria> categorias;

    //categorias padrão
    categorias.push_back(Categoria(1, "Alimentação", true));
    categorias.push_back(Categoria(2, "Transporte", true));
    categorias.push_back(Categoria(3, "Moradia", true));
    categorias.push_back(Categoria(4, "Lazer", true));
    categorias.push_back(Categoria(5, "Saúde", true));

    int n = 0;
    while (n != 6) {
        cout << "\n-------------------------------\n";
        cout << "      Controle Financeiro\n";
        cout << "-------------------------------\n";
        cout << "1   - Criar Pessoa Física\n";
        cout << "2   - Criar Pessoa Jurídica\n";
        cout << "3   - Listar Pessoas\n";
        cout << "4   - Selecionar Pessoa\n";
        cout << "5   - Gerenciar Categorias\n";
        cout << "6   - Sair\n";
        cout << "Digite sua opção: ";
        cin >> n;
        cout << "\n";

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
                cout << "\n";
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
                cout << "\n";
                pessoasJuridicas.push_back(PessoaJuridica(id, nome, email, telefone, cnpj, razaoSocial));
                cout << "Pessoa " << pessoasJuridicas.back().getNome() << " criada!\n";
                break;
            }
            case 3: {
                cout << "\n--- Pessoas Físicas ---\n";
                for (auto& pf : pessoasFisicas) {
                    pf.exibirDados();
                    cout << "---\n";
                }
                cout << "\n--- Pessoas Jurídicas ---\n";
                for (auto& pj : pessoasJuridicas) {
                    pj.exibirDados();
                    cout << "---\n";
                }
                break;
            }
            case 4: {
                cout << "\n--- Pessoas Físicas ---\n";
                for (auto& pf : pessoasFisicas) {
                    cout << "ID: " << pf.getId() << " | Nome: " << pf.getNome() << "\n";
                }
                cout << "\n--- Pessoas Jurídicas ---\n";
                for (auto& pj : pessoasJuridicas) {
                    cout << "ID: " << pj.getId() << " | Nome: " << pj.getNome() << "\n";
                }

                int tipo, idPessoa;
                cout << "\n1 - Pessoa Física | 2 - Pessoa Jurídica\nTipo: "; cin >> tipo;
                cout << "ID da pessoa: "; cin >> idPessoa;

                if (tipo == 1) {
                    bool encontrou = false;
                    for (auto& pf : pessoasFisicas) {
                        if (pf.getId() == idPessoa) {
                            menuPessoaFisica(pf, categorias);
                            encontrou = true;
                            break;
                        }
                    }
                    if (!encontrou) cout << "Pessoa nao encontrada.\n";
                } else if (tipo == 2) {
                    bool encontrou = false;
                    for (auto& pj : pessoasJuridicas) {
                        if (pj.getId() == idPessoa) {
                            menuPessoaJuridica(pj, categorias);
                            encontrou = true;
                            break;
                        }
                    }
                    if (!encontrou) cout << "Pessoa não encontrada.\n";
                }
                break;
            }
            case 5: {
                int opcaoCat = 0;
                while (opcaoCat != 3) {
                    cout << "\n--- Categorias ---\n";
                    cout << "1   - Adicionar Categoria\n";
                    cout << "2   - Listar Categorias\n";
                    cout << "3   - Voltar\n";
                    cout << "Opção: "; cin >> opcaoCat;
                    cout << "\n";

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
                cout << "Opcao inválida.\n";
        }
    }

    return 0;
}