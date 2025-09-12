#include "Estudante.h"

Estudante::Estudante(const std::string& nomeEstudante, int matriculaEstudante, double nota1Estudante, double nota2Estudante)
    : nome(nomeEstudante), matricula(matriculaEstudante), nota1(nota1Estudante), nota2(nota2Estudante), mediaFinal(0), resultadoFinal("") {}

std::string Estudante::obterNome() const {
    return nome;
}

int Estudante::obterMatricula() const {
    return matricula;
}

void Estudante::calcularResultados() {
    mediaFinal = (nota1 + nota2) / 2.0;
    resultadoFinal = avaliarStatus();
}

std::string Estudante::avaliarStatus() {
    if ((nota1 + nota2) / 2.0 >= 7.0) {
        return "Aprovado";
    }
    return "Reprovado";
}

std::string Estudante::obterDadosExtras() const {
    return "";
}

void Estudante::exibirDetalhes() const {
    std::cout << "\n";
    std::cout << "Nome.............. " << nome << std::endl;
    std::cout << "Matrícula......... " << matricula << std::endl;
    std::cout << "Nota 1............ " << nota1 << std::endl;
    std::cout << "Nota 2............ " << nota2 << std::endl;
    std::cout << "Média Final....... " << mediaFinal << std::endl;
    std::cout << "Situação Final.... " << resultadoFinal << std::endl;
    std::string curso = obterDadosExtras();
    if (!curso.empty()) {
        std::cout << "Curso ............ " << curso << std::endl;
    }
}