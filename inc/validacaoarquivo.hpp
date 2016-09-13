#ifndef VALIDACAO_ARQUIVO_HPP
#define VALIDACAO_ARQUIVO_HPP

#include <iostream>
#include <fstream>

using namespace std;

class ValidacaoArquivo {

public:

		void validarArquivo(ifstream * arquivo);

		void validarNovoArquivo(ofstream * arquivo);

		void ignorarComentario(ifstream * arquivo);

};

#endif