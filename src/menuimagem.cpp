#include "menuimagem.hpp"
#include "filtronegativo.hpp"
#include "filtropolarizado.hpp"
#include "filtropretobranco.hpp"
#include "filtrodemedia.hpp"
#include "validacaomenu.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

Filtro * MenuImagem::lerOpcaoFiltro(){
	
	cout << endl;
	cout << "----------------------------- ESCOLHA O FILTRO DESEJADO ----------------------------------" << endl;
	cout << endl;
	cout << "1 - Polarizado\t\t 2 - Negativo\t\t 3 - Preto e Branco\t\t 4 - Média " << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Digite a opção: ";

	ValidacaoMenu validacao;
	int opcao = validacao.validarOpcao(validacao.validarInteiro(),1,4);


	Filtro * filtro = new Filtro();

	switch(opcao){
		case 1 : 
			filtro = new FiltroPolarizado();
			return filtro;
		case 2 :
			filtro = new FiltroNegativo();
			return filtro;
		case 3 :
			filtro = new FiltroPretoBranco();
			return filtro;
		case 4:
			FiltroDeMedia * media = new FiltroDeMedia();
			media->setMascara(lerOpcaoMascara());
			filtro = media;
			return filtro;
	}

	return filtro;
}

int MenuImagem::lerOpcaoMascara(){
	cout << "----------------------------- ESCOLHA A MÁSCARA DESEJADA ---------------------------------" << endl;
	cout << endl;
	cout << "1 - 3 x 3\t\t\t\t 2 - 5 x 5\t\t\t\t 3 - 7 x 7 " << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Digite a opção: ";

	ValidacaoMenu validacao;
	int opcao = validacao.validarOpcao(validacao.validarInteiro(),1,3);

	switch(opcao){
		case 1 : 
			return 3;
		case 2 :
			return 5;
		case 3 :
			return 7;
	}

	return opcao;
}

string MenuImagem::lerNomeImagem(){


	#ifdef WIN32
		system ("cls");
	#endif

	#ifndef WIN32
		system("clear"); 
	#endif

	string nomeImagem;
	cout << "Digite o nome da imagem ou Sair para sair do programa: ";
	getline(cin,nomeImagem);

	return nomeImagem;
}

void MenuImagem::mensagem(string mensagem){
	cout << endl;
	cout << "\t\t\t\t" << mensagem << endl << endl;
	cout << "\t\t\t\tPressione ENTER para continuar" << endl;
	getchar();
}