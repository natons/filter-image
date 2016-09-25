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

int MenuImagem::isOpcao(int opcao){
	while(opcao < 1 || opcao > 4){
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
	
	opcao = isOpcao(le_teclado_int());

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
			filtro = new FiltroDeMedia();
			return filtro;
	}

	return filtro;
}