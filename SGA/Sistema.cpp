#include "Sistema.h"
#include "Estudante.h"
#include "EstudanteTecnico.h"
#include "Validacao.h"
#include <iostream>
#include <vector>
#include <regex>
#include <locale.h>
#include <limits>
#include <windows.h> 

void cadastrarEstudanteEnsinoMedio(std::vector<Estudante>& estudantes, const std::regex& regex);
void cadastrarEstudanteTecnico(std::vector<EstudanteTecnico>& estudantes, const std::regex& regex);
void consultarPorMatricula(const std::vector<Estudante>& estudantesMedio, const std::vector<EstudanteTecnico>& estudantesTecnico);
void exibirTodosOsEstudantes(const std::vector<Estudante>& estudantesMedio, const std::vector<EstudanteTecnico>& estudantesTecnico);

int executarMenuUsuario() {
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    std::vector<Estudante> estudantesEnsinoMedio;
    std::vector<EstudanteTecnico> estudantesTecnicos;
    std::regex regexValidacaoTexto("^[A-Za-zÀ-ÖØ-öø-ÿ]+( [A-Za-zÀ-ÖØ-öø-ÿ]+)*$");

    int opcao;
    do {
        std::cout << "\n----- Sistema de Cadastro de Alunos -----" << std::endl;
        std::cout << "[1] Cadastrar aluno Ensino Médio" << std::endl;
        std::cout << "[2] Cadastrar aluno Ensino Técnico" << std::endl;
        std::cout << "[3] Buscar Aluno" << std::endl;
        std::cout << "[4] Listar estudantes cadastrados" << std::endl;
        std::cout << "[5] Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        
        validarEntradaOpcao(opcao);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcao) {
            case 1: cadastrarEstudanteEnsinoMedio(estudantesEnsinoMedio, regexValidacaoTexto); break;
            case 2: cadastrarEstudanteTecnico(estudantesTecnicos, regexValidacaoTexto); break;
            case 3: consultarPorMatricula(estudantesEnsinoMedio, estudantesTecnicos); break;
            case 4: exibirTodosOsEstudantes(estudantesEnsinoMedio, estudantesTecnicos); break;
            case 5: std::cout << "----- Sistema encerrado -----" << std::endl; break;
            default: std::cout << "Opção inválida, tente novamente." << std::endl;
        }
    } while (opcao != 5);
    return 0;
}

void cadastrarEstudanteEnsinoMedio(std::vector<Estudante>& estudantes, const std::regex& regex) {
    std::string nome;
    int matricula;
    double nota1, nota2;

    std::cout << "\n----- Cadastro de aluno Ensino Médio -----" << std::endl;
    validarEntradaNome(nome, regex);
    validarEntradaMatricula(matricula);
    
    std::cout << "Nota 1: "; std::cin >> nota1; validarEntradaNota(nota1);
    std::cout << "Nota 2: "; std::cin >> nota2; validarEntradaNota(nota2);

    Estudante& novo = estudantes.emplace_back(nome, matricula, nota1, nota2);
    novo.calcularResultados();
    std::cout << "Aluno cadastrado!" << std::endl;
}

void cadastrarEstudanteTecnico(std::vector<EstudanteTecnico>& estudantes, const std::regex& regex) {
    std::string nome, curso;
    int matricula;
    double nota1, nota2;

    std::cout << "\n----- Cadastro de aluno Técnico -----" << std::endl;
    validarEntradaNome(nome, regex);
    validarEntradaMatricula(matricula);
    
    std::cout << "Nota 1: "; std::cin >> nota1; validarEntradaNota(nota1);
    std::cout << "Nota 2: "; std::cin >> nota2; validarEntradaNota(nota2);

    validarEntradaCurso(curso, regex);

    EstudanteTecnico& novo = estudantes.emplace_back(nome, matricula, nota1, nota2, curso);
    novo.calcularResultados();
    std::cout << "Aluno cadastrado!" << std::endl;
}

void consultarPorMatricula(const std::vector<Estudante>& estudantesMedio, const std::vector<EstudanteTecnico>& estudantesTecnico) {
    int matricula;
    std::cout << "\n----- Pesquisa de alunos -----" << std::endl;
    validarEntradaMatricula(matricula);

    bool encontrado = false;
    for (const auto& estudante : estudantesMedio) {
        if (estudante.obterMatricula() == matricula) {
            std::cout << "\nAluno encontrado no Ensino Médio!" << std::endl;
            estudante.exibirDetalhes();
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        for (const auto& estudante : estudantesTecnico) {
            if (estudante.obterMatricula() == matricula) {
                std::cout << "\nAluno encontrado no Ensino Técnico!" << std::endl;
                estudante.exibirDetalhes();
                encontrado = true;
                break;
            }
        }
    }
    if (!encontrado) {
        std::cout << "Aluno com a matrícula " << matricula << " não encontrado!" << std::endl;
    }
}

void exibirTodosOsEstudantes(const std::vector<Estudante>& estudantesMedio, const std::vector<EstudanteTecnico>& estudantesTecnico) {
    std::cout << "\n----- Alunos do Ensino Médio -----" << std::endl;
    if (estudantesMedio.empty()) {
        std::cout << "Nenhum aluno cadastrado." << std::endl;
    } else {
        for (const auto& estudante : estudantesMedio) {
            estudante.exibirDetalhes();
        }
    }

    std::cout << "\n----- Alunos do Ensino Técnico -----" << std::endl;
    if (estudantesTecnico.empty()) {
        std::cout << "Nenhum aluno cadastrado." << std::endl;
    } else {
        for (const auto& estudante : estudantesTecnico) {
            estudante.exibirDetalhes();
        }
    }
}