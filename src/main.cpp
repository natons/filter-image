#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "imagem.hpp"
#include "cor.hpp"
#include "filtro.hpp"
#include "filtronegativo.hpp"
#include "filtropolarizado.hpp"
#include "filtropretobranco.hpp"
#include "filtrodemedia.hpp"
#include "menuimagem.hpp"
#include <list>

using namespace std;

int main(){

	MenuImagem menu;
	string nomeImagem;
	do{

		nomeImagem = menu.lerNomeImagem();

		Imagem *imagem = new Imagem();
	
		imagem->lerImagem(nomeImagem);
		
		imagem->imprimirDados();
	
		Filtro * filtro = menu.lerOpcaoFiltro();
		
		imagem->setCores(filtro->aplicarFiltro(imagem));
	
		imagem->gravarImagem();

	} while(nomeImagem != "Sair" && nomeImagem != "sair");
	
	return 0;
}