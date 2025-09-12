#include "EstudanteTecnico.h"

EstudanteTecnico::EstudanteTecnico(const std::string& nome, int matricula, double nota1, double nota2, const std::string& cursoEstudante)
    : Estudante(nome, matricula, nota1, nota2), curso(cursoEstudante) {}

std::string EstudanteTecnico::obterDadosExtras() const {
    return curso;
}