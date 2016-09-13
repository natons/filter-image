#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "validacaoarquivo.hpp"

using namespace std;

void ValidacaoArquivo::validarArquivo(ifstream * arquivo){
	string nomeImagem;

	cout << "Entre com o nome da imagem (sem a extensao) ou  S para sair: ";
	cout << flush;  
	cin >> nomeImagem;

	if(nomeImagem[0] == 's' || nomeImagem[0] == 'S')
		exit(0);

	string diretorio = "doc/" + nomeImagem + ".ppm";
	arquivo->open(diretorio.c_str());

	while(arquivo->fail()){
		cout << "Erro na abertura do arquivo! Verifique o nome" << endl;
		cout << "Digite o nome novamente (sem a extensao) ou S para sair: ";
		cout << flush;  
		cin >> nomeImagem;
		if(nomeImagem[0] == 's' || nomeImagem[0] == 'S')
			exit(0);
		arquivo->open(nomeImagem.c_str());
	}

}

void ValidacaoArquivo::validarNovoArquivo(ofstream * arquivo){

	string nome;
	cout << "Digite o nome da nova imagem (sem a extensao): ";
	cout << flush;
	cin >> nome;

	string diretorio = "doc/" + nome + ".ppm";
	arquivo->open(diretorio.c_str());
	
	if(arquivo->fail()){
		cout << "Erro na abertura do arquivo!" << endl;
		exit(0);
	}
}

void ValidacaoArquivo::ignorarComentario(ifstream * arquivo){
	string linha;
	(*arquivo) >> linha;
	
	if(linha[0] != '#'){
		arquivo->seekg(-linha.size(),ios_base::cur);
		return;
	}

	while(linha[0] == '#'){
		
		getline(*arquivo,linha);

		(*arquivo) >> linha;
	}

	arquivo->seekg(-linha.size(),ios_base::cur);

}