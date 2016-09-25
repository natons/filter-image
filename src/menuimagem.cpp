#include "menuimagem.hpp"
#include "filtronegativo.hpp"
#include "filtropolarizado.hpp"
#include "filtropretobranco.hpp"
#include "filtrodemedia.hpp"
#include <sstream>

using namespace std;

//método passado em sala de aula. Para verificação do valor inteiro.
int MenuImagem::le_teclado_int() {       
	string input = "";    
	int valor;    
	while (true) {         
		//cin.ignore(256, '\n');
		getline(cin, input);       
		stringstream myStream(input);       
		if (myStream >> valor)         
			break;       
		cout << "Inteiro inválido! Digite novamente: ";     
	}     
	return valor;
}

int MenuImagem::isOpcao(int opcao, int menor, int maior){
	while(opcao < menor || opcao > maior){
		cout << "Opção Inválida. Digite novamente: ";
		opcao = le_teclado_int();
	}

	return opcao;
}

Filtro * MenuImagem::lerOpcaoFiltro(){
	int opcao;
	Filtro * filtro = new Filtro();
	cout << endl;
	cout << "----------------------------- ESCOLHA O FILTRO DESEJADO ----------------------------------" << endl;
	cout << endl;
	cout << "1 - Polarizado\t\t 2 - Negativo\t\t 3 - Preto e Branco\t\t 4 - Média " << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Digite a opção: ";
	
	opcao = isOpcao(le_teclado_int(),1,4);

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

	int opcao = isOpcao(le_teclado_int(),1,3);

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