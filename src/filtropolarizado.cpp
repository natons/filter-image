#include "filtropolarizado.hpp"

list<Cor> FiltroPolarizado::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores;
	
	Cor c;
	for(Cor cor : imagem->getCores()){
		if(cor.getR() < imagem->getEscalaMaxima()/2){
	           	c.setR(0);
	    }else{
	      		c.setR(imagem->getEscalaMaxima());
	    }

	    if(cor.getG() < imagem->getEscalaMaxima()/2){
	            c.setG(0);
	    }else{
	            c.setG(imagem->getEscalaMaxima());
	    }

	    if(cor.getB() < imagem->getEscalaMaxima()/2){
	            c.setB(0);
	    }else{
	           	c.setB(imagem->getEscalaMaxima());
	    }
	    cores.push_back(c);
	}


	return cores;
}