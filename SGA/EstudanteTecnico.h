#pragma once

#include "Estudante.h"

class EstudanteTecnico : public Estudante {
private:
    std::string curso;
public:
    EstudanteTecnico(const std::string& nome, int matricula, double nota1, double nota2, const std::string& cursoEstudante);
    std::string obterDadosExtras() const override;
};