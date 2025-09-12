#include "Validacao.h"
#include <iostream>
#include <limits>

void validarEntradaNome(std::string& nome, const std::regex& regexValidacaoTexto) {
    std::cout << "Nome: ";
    std::getline(std::cin >> std::ws, nome);
    while (nome.empty() || !std::regex_match(nome, regexValidacaoTexto)) {
        std::cout << "Nome inválido. Digite novamente: ";
        std::getline(std::cin, nome);
    }
}

void validarEntradaCurso(std::string& curso, const std::regex& regexValidacaoTexto) {
    std::cout << "Curso: ";
    std::getline(std::cin >> std::ws, curso);
    while (curso.empty() || !std::regex_match(curso, regexValidacaoTexto)) {
        std::cout << "Nome de curso inválido. Digite novamente: ";
        std::getline(std::cin, curso);
    }
}

void validarEntradaMatricula(int& matricula) {
    std::cout << "Matrícula: ";
    std::cin >> matricula;
    while (!std::cin || matricula <= 0) {
        std::cout << "Matrícula inválida. Deve ser um número positivo. Tente novamente: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> matricula;
    }
}

void validarEntradaNota(double& nota) {
    while (!std::cin || nota < 0.0 || nota > 10.0) {
        std::cout << "Nota inválida (0-10). Tente novamente: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> nota;
    }
}

void validarEntradaOpcao(int& opcao) {
    while (!std::cin) {
        std::cout << "Opção inválida. Deve ser um número. Tente novamente: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> opcao;
    }
}