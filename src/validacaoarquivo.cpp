#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include "validacaoarquivo.hpp"
#include <limits>

using namespace std;

string ValidacaoArquivo::validarArquivo(ifstream * arquivo, string nomeImagem){
	
	string diretorio;
	arquivo->exceptions( ifstream::failbit | ifstream::badbit );
	try {

		if(nomeImagem[0] == 's' || nomeImagem[0] == 'S')
			exit(0);

		nomeImagem = validaEntradaNome(nomeImagem);

		diretorio = "doc/" + nomeImagem + ".ppm";
	
		
		arquivo->open(diretorio.c_str(),ios_base::binary);

	} catch (ifstream::failure e) {

    	while(arquivo->fail()){
			cout << "Erro na abertura do arquivo! Verifique o nome" << endl;
			cout << "Digite o nome novamente ou S para sair: ";
			cout << flush;  
			getline(cin, nomeImagem);

			if(nomeImagem[0] == 's' || nomeImagem[0] == 'S')
				exit(0);

			nomeImagem = validaEntradaNome(nomeImagem);

			diretorio = "doc/" + nomeImagem + ".ppm";
			arquivo->open(diretorio.c_str());
		}
  	}

	return diretorio;
}

string ValidacaoArquivo::validaEntradaNome(string nomeImagem){

	string extensao;
	int size = nomeImagem.size() - 1;
	while(true){
		extensao += nomeImagem[size];
		if(nomeImagem[size] == '.' || size == 0)
			break;
		--size;
	}

	reverse(extensao.begin(),extensao.end());

	if(extensao == ".ppm" || extensao == ".PPM"){
		nomeImagem.erase(size, nomeImagem.size() - 1);
		return nomeImagem;
	}
	else if(extensao[0] == '.'){
		cout << endl;
		cout << "ERRO! Imagem com extensão inválida" << endl;
		cout << "Entre com o nome da imagem ou S para sair: ";
		cout << flush;
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nomeImagem);
		nomeImagem = validaEntradaNome(nomeImagem);
	}
	return nomeImagem;
}

void ValidacaoArquivo::validarNovoArquivo(ofstream * arquivo){

	string nome;
	arquivo->exceptions( ifstream::failbit | ifstream::badbit );
	try {
		cout << "Digite o nome da nova imagem: ";
		cout << flush;
		//cin.ignore(256, '\n');
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, nome);
		nome = validaEntradaNome(nome);
		nome = existeArquivo(nome);
		
		string diretorio = "doc/" + nome + ".ppm";
		arquivo->open(diretorio.c_str());


	} catch (ofstream::failure e){
			cout << "Erro na criação do arquivo!" << endl;
	}
}

void ValidacaoArquivo::ignorarComentario(ifstream * arquivo){

	char  * linha = new char[1];
	arquivo->read(linha,1);
	
	if(linha[0] != '#'){
		arquivo->seekg(-1,ios_base::cur);
		return;
	}

	while(linha[0] == '#'){
			
		char * caractere = new char[1];
		while(caractere[0] != '\n'){
			arquivo->read(caractere, 1);
		}
		arquivo->read(linha,1);

	}

	arquivo->seekg(-1,ios_base::cur);

}

string ValidacaoArquivo::existeArquivo(string nome){
	ifstream * is = new ifstream();
	is->exceptions( ifstream::failbit | ifstream::badbit );
	try {
		
		is->open("doc/"+nome+".ppm",ios_base::in | ios_base::binary);
		while(is->is_open()){
			is->close();
			cout << "Já existe um arquivo com este nome! Digite novamente: ";
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, nome);
			nome = validaEntradaNome(nome);
			is->open("doc/"+nome+".ppm",ios_base::in | ios_base::binary);
		}
	} catch(ifstream::failure e){
		return nome;
	}

	return nome;
}