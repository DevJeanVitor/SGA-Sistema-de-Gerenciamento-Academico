#pragma once

#include "StatusAprovacao.h"
#include <string>
#include <iostream>

class Estudante : public StatusAprovacao {
private:
    std::string nome;
    int matricula;
    double nota1, nota2;
    float mediaFinal;
    std::string resultadoFinal;

public:
    Estudante(const std::string& nomeEstudante, int matriculaEstudante, double nota1Estudante, double nota2Estudante);

    std::string obterNome() const;
    int obterMatricula() const;

    void calcularResultados();
    std::string avaliarStatus() override;

    virtual std::string obterDadosExtras() const;

    void exibirDetalhes() const;
};