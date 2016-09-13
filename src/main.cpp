#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "imagem.hpp"
#include "cor.hpp"
#include "filtro.hpp"
#include "filtronegativo.hpp"
#include <list>

using namespace std;

int main(){

	Imagem *imagem = new Imagem();

	imagem->lerImagem();

	imagem->imprimirDados();

	Filtro * filtro = new FiltroNegativo();
	
	imagem->setCores(filtro->aplicarFiltro(imagem));

	imagem->gravarImagem();
	
	return 0;
}