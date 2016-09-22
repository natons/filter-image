#include "menuimagem.hpp"
#include "filtronegativo.hpp"
#include "filtropolarizado.hpp"
#include "filtropretobranco.hpp"
#include "filtrodemedia.hpp"

Filtro * MenuImagem::lerOpcaoFiltro(){
	int opcao;
	Filtro * filtro;
	cout << endl;
	cout << "----------------------------- ESCOLHA O FILTRO DESEJADO ----------------------------------" << endl;
	cout << endl;
	cout << "1 - Polarizado\t\t\t 2 - Negativo\t\t\t 3 - Preto e Branco" << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << "Digite a opção: ";
	cin >> opcao;

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
	}

	return filtro;
}