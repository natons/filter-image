#include "filtrodemedia.hpp"

list<Cor> FiltroDeMedia::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores = imagem->getCores();
	list<Cor>::iterator it = cores.begin();
	list<Cor>::iterator itAnterior;

	Cor anterior;
	int media;
	int cont = 0;
	for(Cor cor : imagem->getCores()){
		++cont;
		media += cor.getR();
		media += cor.getG();
		media += cor.getB();

		if(cont == 2){
			anterior = cor;
			itAnterior = it;
		}

		if(cont == 3){
			//anterior.setR((unsigned char)media/9);
			anterior.setG((unsigned char)media/9);
			//anterior.setB((unsigned char)media/9);
			cores.insert(itAnterior, anterior);
			cores.erase(++itAnterior);
			cont = 0;
			media = 0;
		}

		++it;
	}


	return cores;
}