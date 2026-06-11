
# financeControl

## 1. Visao geral do software

O **financeControl** e um sistema de controle financeiro desenvolvido em C++ para organizar pessoas, contas, movimentacoes, categorias e metas. O objetivo do trabalho e permitir o cadastro e o acompanhamento de informacoes financeiras de forma simples, usando conceitos de Programacao Orientada a Objetos.

### Problema que o software resolve

Muitas pessoas e empresas precisam registrar entradas, saidas, contas, categorias e objetivos financeiros em um unico lugar. Este projeto resolve esse problema ao centralizar esses dados e permitir consultas como:

- cadastro de pessoas fisicas e juridicas;
- criacao e gerenciamento de contas;
- registro de movimentacoes financeiras;
- organizacao por categorias;
- acompanhamento de metas financeiras;
- consulta de saldo total e saldo por categoria.

### Principais funcionalidades

- criar, listar e selecionar pessoas;
- diferenciar pessoa fisica e pessoa juridica;
- adicionar e remover contas;
- adicionar, listar e remover movimentacoes;
- cadastrar categorias padrao e novas categorias;
- criar metas e acompanhar progresso;
- calcular saldo total e saldo por categoria;
- transferir valores entre contas.

## 2. Diagrama das classes

![Diagrama das classes](diagrama.png)

### Leitura do diagrama

- `Pessoa` e a classe base abstrata.
- `PessoaFisica` e `PessoaJuridica` herdam de `Pessoa`.
- `Pessoa` possui varias `Conta` e varias `Meta`.
- `Conta` possui varias `Movimentacao`.
- `Movimentacao` referencia uma `Categoria`.
- `Conta` e `Pessoa` usam `Categoria` para consultas de saldo e classificacao.

## 3. Breve descricao sobre a linguagem escolhida

O projeto foi desenvolvido em **C++**, uma linguagem compilada, rapida e bastante usada em sistemas que exigem controle direto sobre memoria e boa performance. No trabalho, C++ foi uma boa escolha porque permitiu aplicar conceitos importantes de Programacao Orientada a Objetos, como:

- classes e objetos;
- encapsulamento com atributos privados e metodos publicos;
- heranca entre `Pessoa`, `PessoaFisica` e `PessoaJuridica`;
- polimorfismo por meio de metodos virtuais;
- uso de `vector` para armazenar listas dinamicas de objetos.

## 4. Implementacoes realizadas na linguagem

### 4.1 Classe abstrata Pessoa

A classe `Pessoa` centraliza os dados comuns entre pessoas fisicas e juridicas, como nome, email, telefone, contas e metas. Ela tambem define o metodo abstrato `exibirDados()`, obrigando as classes filhas a implementarem sua propria exibicao.

```cpp
virtual void exibirDados() const = 0;
```

Isso garante polimorfismo e separa o que e comum do que e especifico de cada tipo de pessoa.

### 4.2 Heranca em PessoaFisica e PessoaJuridica

As classes filhas reaproveitam a estrutura da classe base e adicionam seus campos especificos.

```cpp
class PessoaFisica : public Pessoa {
```

```cpp
class PessoaJuridica : public Pessoa {
```

Assim, o sistema evita repeticao de codigo e torna a manutencao mais simples.

### 4.3 Controle de contas e movimentacoes

A classe `Conta` armazena informacoes bancarias e uma lista de movimentacoes. O sistema permite adicionar, listar e remover movimentacoes, alem de realizar transferencia entre contas.

```cpp
void adicionarMovimentacao(const Movimentacao& m);
void removerMovimentacao(int id);
void transferir(Conta& destino, double valor);
```

### 4.4 Classificacao por categoria

Cada movimentacao recebe uma `Categoria`, o que permite organizar entradas e saidas e calcular totais por categoria.

```cpp
double totalPorCategoria(const Categoria& categoria, const std::string& tipoMovimentacao) const;
```

### 4.5 Metas financeiras

A classe `Meta` representa um objetivo financeiro com orcamento, prazo, descricao e progresso. Ela permite acompanhar quanto ja foi acumulado e quanto ainda falta.

```cpp
double calcularProgresso() const;
void exibirProgresso() const;
void exibirQuantoFalta() const;
```

## 5. Exemplos de trechos relevantes do codigo

### Exemplo 1: criacao de uma pessoa fisica

```cpp
pessoasFisicas.push_back(PessoaFisica(id, nome, email, telefone, cpf, dataNascimento));
```

### Exemplo 2: criacao de uma conta

```cpp
p.adicionarConta(Conta(id, instituicao, numeroConta, chavePix, saldo, tipoConta));
```

### Exemplo 3: criacao de uma movimentacao com categoria

```cpp
conta->adicionarMovimentacao(Movimentacao(
	id,
	valor,
	data,
	tipoMovimentacao,
	descricao,
	contraparte,
	categorias[categoriaIdx - 1]
));
```

### Exemplo 4: criacao de uma meta

```cpp
pf.adicionarMeta(Meta(id, orcamento, prazo, descricao, valorAtual));
```

## 6. Demonstracao da execucao

O programa possui um menu em modo texto. A execucao comeca na classe principal do arquivo `Main2.cpp`, onde sao exibidas as opcoes para:

- criar pessoa fisica;
- criar pessoa juridica;
- listar pessoas;
- selecionar uma pessoa;
- gerenciar categorias;
- sair do sistema.

Ao selecionar uma pessoa, e possivel acessar novos menus para:

- exibir dados;
- gerenciar contas;
- adicionar e listar metas;
- remover metas;
- cadastrar e listar movimentacoes;
- consultar saldo total e saldo por categoria.

### Saida esperada na inicializacao

```text
Controle Financeiro
1 - Criar Pessoa Fisica
2 - Criar Pessoa Juridica
3 - Listar Pessoas
4 - Selecionar Pessoa
5 - Gerenciar Categorias
6 - Sair
```

### Observacao importante da execucao

No menu principal, a opcao de saida e `6`.

## 7. Como compilar

Os comandos abaixo ja estao validados no projeto.

### Compilacao

```bash
g++ Main2.cpp Categoria\Categoria.cpp Conta\Conta.cpp Movimentacao\Movimentacao.cpp Meta\Meta.cpp Pessoa\Pessoa.cpp PessoaFisica\PessoaFisica.cpp PessoaJuridica\PessoaJuridica.cpp -o financeControl.exe
```

### Execucao

```bash
.\financeControl.exe
```

## 8. Roteiro sugerido para apresentacao

1. Apresente o software e o problema que ele resolve.
2. Mostre o diagrama de classes e explique as relacoes entre elas.
3. Explique por que C++ foi escolhido.
4. Mostre os principais trechos de codigo e o papel de cada classe.
5. Execute o sistema ao vivo e navegue pelos menus principais.
6. Finalize mostrando uma pessoa, uma conta, uma movimentacao e uma meta cadastradas.

## 9. Estrutura do projeto

```text
financeControl/
├── Main.cpp
├── Main2.cpp
├── Categoria/
├── Conta/
├── Meta/
├── Movimentacao/
├── Pessoa/
├── PessoaFisica/
└── PessoaJuridica/
```

## 10. Conclusao

O projeto financeControl demonstra a aplicacao pratica de Programacao Orientada a Objetos em C++, com classes bem separadas, heranca, encapsulamento e organizacao de dados financeiros. O sistema atende ao objetivo de registrar e consultar informacoes de forma clara, servindo como base para futuras melhorias, como persistencia em arquivo e validacoes mais completas.