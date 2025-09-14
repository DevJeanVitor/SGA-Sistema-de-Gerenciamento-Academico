**`v1.0.0`**

# SGA (Sistema de Gerenciamento Acadêmico)

O SGA é um sistema de console desenvolvido em C++ para o gerenciamento de registros de estudantes. O projeto permite cadastrar, consultar e listar alunos do Ensino Médio e Técnico, aplicando conceitos  de Programação Orientada a Objetos (POO) para garantir um código modular, reutilizável e de fácil manutenção.

## Demonstração do Sistema

O vídeo abaixo apresenta uma demonstração completa das funcionalidades do sistema, desde o cadastro de diferentes tipos de alunos até a consulta e listagem dos registros.

<div align="center">
  <video src="https://github.com/user-attachments/assets/008d27ff-ea29-4833-8d40-243892e24813" controls="controls" style="max-width: 800px;"></video>
</div>

## Sobre o Projeto

Este sistema foi criado para a gestão de dados acadêmicos em um ambiente de console. Abordando tanto a organização estrutural, separação de responsabilidades em diferentes módulos integrado ao tratamento de entradas de dados, garantindo uma experiência de usuário mais segura e intuitiva.

A aplicação utiliza os paradigmas da Programação Orientada a Objetos (POO) para modelar as entidades do sistema, como `Estudante` e `EstudanteTecnico`, promovendo um código mais limpo e escalável.

## Funcionalidades Principais

O sistema oferece as seguintes operações:

1.  **Cadastro de Aluno do Ensino Médio:** Coleta nome, matrícula e duas notas.

<p align="center">
  <img src="https://github.com/user-attachments/assets/992d32da-777d-4323-b716-b50b125f94ea" alt="Cadastro de Aluno do Ensino Médio: Coleta nome, matrícula e duas notas" width="500">
</p>

2.  **Cadastro de Aluno do Ensino Técnico:** Coleta os mesmos dados do aluno de Ensino Médio, mais o nome do curso técnico.

<p align="center">
  <img src="https://github.com/user-attachments/assets/0cb9f77e-9cea-452f-bb34-5b4f6a8434c4" alt="Cadastro de Aluno do Ensino Técnico: Coleta os mesmos dados do aluno de Ensino Médio, mais o nome do curso técnico.s" width="500">
</p>

3.  **Busca por Matrícula:** Permite localizar um aluno específico em qualquer uma das listas (Médio ou Técnico) a partir de sua matrícula.

<p align="center">
  <img src="https://github.com/user-attachments/assets/764d54a2-7d4f-4085-8343-bb8162339f34" alt="Busca por Matrícula: Permite localizar um aluno específico em qualquer uma das listas (Médio ou Técnico) a partir de sua matrícula" width="500">
</p>

4.  **Listagem de Alunos Cadastrados:** Exibe todos os alunos cadastrados, separados por categoria, com seus respectivos detalhes, média final e status de aprovação.

<p align="center">
  <img src= "https://github.com/user-attachments/assets/1a95c732-829b-491f-a68b-dc282ccce51a" alt="Listagem de Alunos Cadastrados: Exibe todos os alunos cadastrados, separados por categoria, com seus respectivos detalhes, média final e status de aprovação." width="500">
</p>
## Validação de Dados

Um dos pilares do sistema é a garantia da integridade dos dados inseridos pelo usuário. Foram implementadas validações rigorosas para os seguintes campos:

-   **Nome e Curso:** Utiliza Expressões Regulares (Regex) para garantir que apenas textos válidos (letras e espaços) sejam aceitos, rejeitando números ou caracteres especiais.
-   **Matrícula:** A entrada deve ser um número inteiro e positivo. O sistema impede o cadastro de matrículas negativas ou inválidas.
-   **Notas (1 e 2):** As notas devem ser valores numéricos dentro do intervalo de 0.0 a 10.0. Qualquer valor fora desse intervalo é rejeitado.
-   **Opção do Menu:** A escolha no menu principal deve ser um valor numérico. Entradas de texto são tratadas para evitar que o programa encerre inesperadamente.

O vídeo a seguir demonstra como o sistema reage a entradas inválidas, solicitando a correção ao usuário.

<div align="center">
  <video src="https://github.com/user-attachments/assets/0faf7e36-b08e-45e8-9f52-726a1e41de22" controls="controls" style="max-width: 800px;"></video>
</div>

## Paradigma de Orientação a Objetos em C++

O projeto foi estruturado seguindo os princípios da POO:

-   **Encapsulamento:** Os atributos das classes, como `nome`, `matricula` e `notas` na classe `Estudante`, são declarados como `private`. O acesso e a manipulação desses dados são controlados através de métodos públicos (`public`), como `obterNome()`, `calcularResultados()` e `exibirDetalhes()`. Isso protege a integridade dos dados e oculta a complexidade interna dos objetos.

-   **Abstração:** A classe `StatusAprovacao` atua como uma interface (classe abstrata pura), definindo um "contrato" que obriga as classes filhas a implementar um método `avaliarStatus()`.

-   **Herança:** A classe `Estudante` herda de `StatusAprovacao`, e a classe `EstudanteTecnico` herda de `Estudante`, reutilizando atributos e métodos e especializando o comportamento quando necessário.

-   **Polimorfismo:** O método `obterDadosExtras()` é declarado como `virtual` na classe `Estudante` e sobrescrito (`override`) na classe `EstudanteTecnico`. Isso permite que o mesmo método se comporte de maneiras diferentes dependendo do objeto, exibindo o curso apenas para alunos técnicos.

## Estrutura do Projeto

O código-fonte foi modularizado para separar as responsabilidades e facilitar a manutenção, seguindo a estrutura hierárquica abaixo:

```
/SGA
|-- StatusAprovacao.h
|-- Estudante.h
|-- Estudante.cpp
|-- EstudanteTecnico.h
|-- EstudanteTecnico.cpp
|-- Validacao.h
|-- Validacao.cpp
|-- Sistema.h
|-- Sistema.cpp
|-- main.cpp
|-- .vscode/
|   |-- tasks.json
```

## Compilação e Execução

1 - Clonar o Repositório

```bash
git clone (https://github.com/DevJeanVitor/SGA-Sistema-de-Gerenciamento-Academico.git)
 ```

2 - Existem duas formas de compilar o projeto:

#### Opção A: Via Linha de Comando (g++)

Navegue até à pasta raiz do projeto (`SGA`) pelo terminal e execute o comando abaixo:

```bash
g++ main.cpp Estudante.cpp EstudanteTecnico.cpp Validacao.cpp Sistema.cpp -o sga_programa
````

Após a compilação, um executável chamado sga_programa.exe (no Windows) ou sga_programa (no Linux/macOS) será criado. Para executar, utilize:

```bash
./sga_programa
````

### Opção B: Via VS Code (Tarefa Automatizada)
O projeto já inclui um ficheiro de configuração tasks.json para facilitar a compilação dentro do Visual Studio Code.

1 - Abra a pasta do projeto no VS Code.

2 - Verifique o caminho do compilador: Abra o ficheiro **.vscode/tasks.json**. Localize a linha "command" e substitua o caminho de exemplo pelo caminho real do seu compilador g++.exe.

3 - Com qualquer ficheiro .cpp aberto, pressione o atalho **Ctrl+Shift+B**.

4 - A tarefa de compilação será executada, gerando o ficheiro **sga_programa.exe**.

5 - Abra o terminal integrado do VS Code **(Ctrl+ ` )** e execute o programa com o comando **./sga_programa**.

**Aviso sobre o Tempo de Compilação**

Este projeto utiliza a biblioteca `<regex>` do C++ para garantir uma validação robusta de nomes e cursos. A depender das especificações técnicas do seu computador, o processo de **compilação** (ao executar o comando `g++` ou a tarefa no VS Code) pode demorar um pouco mais do que o esperado. Este é um comportamento normal e não afeta a performance do programa após executado.

## Autor

Este projeto foi desenvolvido por: **Jean Vítor**.

- [LinkedIn](https://www.linkedin.com/in/devjeanvitor)
- [GitHub](https://github.com/DevJeanVitor)
