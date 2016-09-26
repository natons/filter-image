#include "validacaomenu.hpp"
#include <sstream>
#include <string>

using namespace std;

//método passado em sala de aula. Para verificação do valor inteiro.
int ValidacaoMenu::validarInteiro() {       
	string input = "";    
	int valor;    
	while (true) {
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, input);       
		stringstream myStream(input);       
		if (myStream >> valor)         
			break;       
		cout << "Inteiro inválido! Digite novamente: ";     
	}     
	return valor;
}

int ValidacaoMenu::validarOpcao(int opcao, int valorMenor, int valorMaior){
	while(opcao < valorMenor || opcao > valorMaior){
		cout << "Opção Inválida. Digite novamente: ";
		opcao = validarInteiro();
	}

	return opcao;
}