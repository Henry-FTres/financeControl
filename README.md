
# financeControl

## 1. Visão geral do software

O **financeControl** é um sistema de controle financeiro desenvolvido em C++ para organizar pessoas, contas, movimentações, categorias e metas. O objetivo do trabalho é permitir o cadastro e o acompanhamento de informações financeiras de forma simples, usando conceitos de Programação Orientada a Objetos.

### Problema que o software resolve

Muitas pessoas e empresas precisam registrar entradas, saídas, contas, categorias e objetivos financeiros em um único lugar. Este projeto resolve esse problema ao centralizar esses dados e permitir consultas como:

- cadastro de pessoas físicas e jurídicas;
- criação e gerenciamento de contas;
- registro de movimentações financeiras;
- organização por categorias;
- acompanhamento de metas financeiras;
- consulta de saldo total e saldo por categoria.

![Modelo Lógico](modelo_logico.png)


## 2. Diagrama das classes

![Diagrama das classes](diagrama.png)

### Leitura do diagrama

- `Pessoa` é a classe base abstrata.
- `PessoaFisica` e `PessoaJuridica` herdam de `Pessoa`.
- `Pessoa` possui várias `Conta` e várias `Meta`.
- `Conta` possui várias `Movimentacao`.
- `Movimentacao` referencia uma `Categoria`.
- `Conta` e `Pessoa` usam `Categoria` para consultas de saldo e classificação.

## 3. Breve descricao sobre a linguagem escolhida

# O que é o C++?

- Eficiência e  Baixo e Alto Nível
- Desenvolvido por Bjarne Stroustrup em 1979
- C with Classes
- Renomeada para C++ em 1983

![Linha do tempo das versões da linguagem C++](languageversions.png)

# Principais aplicações:

- Engine de jogos;
- Sistemas operacionais;
- Sistemas embarcados;
- Navegadores da web;
- Aplicações da Blockchain;
- IoT;
- Entre outros;

# Principais características:

- Incremento;
- Alta performance;
- Gerenciamento de memória de baixo nível;

# Vantagens:

- Grande desempenho;
- Bastante utilizada no mercado;
- Suporta Orientação a Objetos;
- Grande diversidade de bibliotecas;
- Compatível com C;

# Desvantagens:

- Curva de aprendizado maior;
- Gerenciamento de memória em baixo nível;

## 4. Implementações realizadas na linguagem

### 4.1 Classe abstrata Pessoa

A classe `Pessoa` centraliza os dados comuns entre pessoas físicas e jurídicas, como nome, email, telefone, contas e metas. Ela também define o método abstrato `exibirDados()`, obrigando as classes filhas a implementarem sua própria exibição.

```cpp
virtual void exibirDados() const = 0;
```

Isso garante polimorfismo e separa o que é comum do que é específico de cada tipo de pessoa.

### 4.2 Herança em PessoaFisica e PessoaJuridica

As classes filhas reaproveitam a estrutura da classe base e adicionam seus campos específicos.

```cpp
class PessoaFisica : public Pessoa {
```

```cpp
class PessoaJuridica : public Pessoa {
```

Assim, o sistema evita repetição de código e torna a manutenção mais simples.

### 4.3 Controle de contas e movimentações

A classe `Conta` armazena informações bancárias e uma lista de movimentações. O sistema permite adicionar, listar e remover movimentações, além de realizar transferência entre contas.

```cpp
void adicionarMovimentacao(const Movimentacao& m);
void removerMovimentacao(int id);
void transferir(Conta& destino, double valor);
```

### 4.4 Classificação por categoria

Cada movimentação recebe uma `Categoria`, o que permite organizar entradas e saídas e calcular totais por categoria.

```cpp
double totalPorCategoria(const Categoria& categoria, const std::string& tipoMovimentacao) const;
```

### 4.5 Metas financeiras

A classe `Meta` representa um objetivo financeiro com orçamento, prazo, descrição e progresso. Ela permite acompanhar quanto já foi acumulado e quanto ainda falta.

```cpp
double calcularProgresso() const;
void exibirProgresso() const;
void exibirQuantoFalta() const;
```

## 5. Conceitos de Orientação a Objetos 

### 5.1 Classe Abstrata e Herança

A classe `Pessoa` é abstrata e define o contrato que `PessoaFisica` e `PessoaJuridica` devem seguir. Isso exemplifica **herança** e **polimorfismo**.

**Declaração da classe base (Pessoa.h):**
```cpp
class Pessoa {
protected:
    int id;
    string nome;
    string email;
    string telefone;
    vector<Conta> contas;
    vector<Meta> metas;
public:
    virtual void exibirDados() const = 0;  // Método abstrato
    void adicionarConta(const Conta& c);
    void adicionarMeta(const Meta& m);
};
```

**Herança em PessoaFisica:**
```cpp
class PessoaFisica : public Pessoa {
private:
    string cpf;
    string dataNascimento;
public:
    PessoaFisica(int id, string nome, string email, string telefone, 
                 string cpf, string dataNascimento);
    void exibirDados() const override;  // Implementação obrigatória
};
```

### 5.2 Instanciação de Objetos e Polimorfismo em Ação

**Criação de pessoa física (instância de classe filha):**
```cpp
vector<PessoaFisica> pessoasFisicas;
pessoasFisicas.push_back(
    PessoaFisica(1, "João Silva", "joao@email.com", "11999999999", 
                 "123.456.789-00", "15/05/1990")
);
```

**Chamada polimórfica (cada classe filha implementa seu próprio `exibirDados()`):**
```cpp
for (auto& pf : pessoasFisicas) {
    pf.exibirDados();  // Invoca PessoaFisica::exibirDados()
}
for (auto& pj : pessoasJuridicas) {
    pj.exibirDados();  // Invoca PessoaJuridica::exibirDados()
}
```

### 5.3 Composição e Encapsulamento

A classe `Pessoa` **contém** (`has-a`) várias `Conta` e `Meta`. Isso exemplifica **composição**.

**Declaração de membros compostos:**
```cpp
class Pessoa {
private:
    vector<Conta> contas;      // Composição: Pessoa contém Contas
    vector<Meta> metas;        // Composição: Pessoa contém Metas
public:
    void adicionarConta(const Conta& c) { contas.push_back(c); }
    Conta* encontrarContaPorId(int id);
};
```

**Uso de composição no programa principal:**
```cpp
Pessoa& p = pessoasFisicas[0];
p.adicionarConta(Conta(101, "Banco do Brasil", "12345-6", "chave@pix", 5000.0, "Corrente"));
p.listarContas();  // Exibe todas as contas dessa pessoa
```

### 5.4 Associação e Referências

Uma `Movimentacao` referencia uma `Categoria`, exemplificando **associação**.

**Declaração de associação:**
```cpp
class Movimentacao {
private:
    int id;
    double valor;
    string data;
    string tipoMovimentacao;
    string descricao;
    string contraparte;
    Categoria categoria;  // Associação: Movimentação tem uma Categoria
public:
    Movimentacao(int id, double valor, string data, string tipoMovimentacao,
                 string descricao, string contraparte, Categoria categoria);
    Categoria getCategoria() const { return categoria; }
};
```

**Instanciação com associação:**
```cpp
vector<Categoria> categorias;
categorias.push_back(Categoria(1, "Alimentação", true));
categorias.push_back(Categoria(2, "Transporte", true));

Conta* conta = p.encontrarContaPorId(101);
conta->adicionarMovimentacao(Movimentacao(
    1001,
    150.50,
    "11/06/2024",
    "saída",
    "Compras no supermercado",
    "Mercado XYZ",
    categorias[0]  // Associação: passa uma Categoria existente
));
```

### 5.5 Métodos de Consulta (Getters) e Encapsulamento

Os atributos são privados; o acesso ocorre através de métodos públicos, garantindo **encapsulamento**.

**Exemplo de getter em Conta:**
```cpp
class Conta {
private:
    int id;
    string numeroConta;
    double saldo;
    vector<Movimentacao> movimentacoes;
public:
    int getId() const { return id; }
    string getNumeroConta() const { return numeroConta; }
    double getSaldo() const { return saldo; }
    vector<Movimentacao> getMovimentacoes() const { return movimentacoes; }
};
```

**Uso seguro dos dados:**
```cpp
Conta* conta = p.encontrarContaPorId(101);
cout << "Saldo atual: " << conta->getSaldo() << endl;
cout << "Número: " << conta->getNumeroConta() << endl;
```

### 5.6 Coleções (Agregação) e Iteração

As classes utilizam `vector` (coleção) para armazenar múltiplas instâncias de outras classes.

**Declaração de coleções:**
```cpp
class Pessoa {
private:
    vector<Conta> contas;      // Coleção de Conta
    vector<Meta> metas;        // Coleção de Meta
};

class Conta {
private:
    vector<Movimentacao> movimentacoes;  // Coleção de Movimentacao
};
```

**Iteração polimórfica e acesso aos objetos:**
```cpp
vector<PessoaFisica> pessoasFisicas;
vector<PessoaJuridica> pessoasJuridicas;

// Iteração e exibição polimórfica
for (auto& pf : pessoasFisicas) {
    cout << "ID: " << pf.getId() << " | Nome: " << pf.getNome() << "\n";
    pf.listarContas();  // Método da classe Pessoa
}

for (auto& pj : pessoasJuridicas) {
    cout << "ID: " << pj.getId() << " | Nome: " << pj.getNome() << "\n";
    pj.listarContas();  // Mesmo método, comportamento específico
}
```

## 6. Como compilar

Os comandos abaixo já estão validados no projeto.

### Compilação

```bash
g++ Main.cpp Categoria\Categoria.cpp Conta\Conta.cpp Movimentacao\Movimentacao.cpp Meta\Meta.cpp Pessoa\Pessoa.cpp PessoaFisica\PessoaFisica.cpp PessoaJuridica\PessoaJuridica.cpp -o financeControl.exe
```

### Execução

```bash
.\financeControl.exe
```