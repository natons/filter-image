#ifndef VALIDACAO_ARQUIVO_HPP
#define VALIDACAO_ARQUIVO_HPP

#include <iostream>
#include <fstream>

using namespace std;

class ValidacaoArquivo {

public:

		string validarArquivo(ifstream * arquivo,string nomeImagem);

		string validaEntradaNome(string nomeImagem);

		void validarNovoArquivo(ofstream * arquivo);

		void ignorarComentario(ifstream * arquivo);
		
		string existeArquivo(string nome);
};

#endif