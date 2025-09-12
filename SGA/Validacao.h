#pragma once

#include <string>
#include <regex>

void validarEntradaNome(std::string& nome, const std::regex& regexValidacaoTexto);
void validarEntradaMatricula(int& matricula);
void validarEntradaNota(double& nota);
void validarEntradaCurso(std::string& curso, const std::regex& regexValidacaoTexto);
void validarEntradaOpcao(int& opcao);