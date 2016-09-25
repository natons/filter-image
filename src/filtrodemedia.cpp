#include "filtrodemedia.hpp"
#include "menuimagem.hpp"


FiltroDeMedia::FiltroDeMedia(){
	this->mascara = 3;
}

void FiltroDeMedia::setMascara(int mascara){
	this->mascara = mascara;
}

int FiltroDeMedia::getMascara(){
	return mascara;
}


list<Cor> FiltroDeMedia::aplicarFiltro(Imagem  * imagem){

	int altura = imagem->getAltura();
	int largura = imagem->getLargura();

	//transformando list em matriz
	Cor **rgb = getMatriz(altura,largura, imagem->getCores());

	int limit = getMascara()/2;
	int div = getMascara()*getMascara();
	int r,g,b;
	for(int i = limit; i < altura - limit; ++i){
	    for(int j = limit; j < largura - limit; ++j) {
	    	r = 0;
	    	g = 0;
	    	b = 0;
		    for (int k = -limit; k <= limit; ++k){
		    	for (int n = -limit; n <= limit; ++n){
		    		r += rgb[i+k][j+n].getR();
		    		g += rgb[i+k][j+n].getG();
		    		b += rgb[i+k][j+n].getB();
		    	}
		    }

		    r /= div;
	        g /= div;
	        b /= div;

	        rgb[i][j].setR((unsigned char)r);
	        rgb[i][j].setG((unsigned char)g);
	        rgb[i][j].setB((unsigned char)b);
	    }
	}

	list<Cor> cores = getList(rgb, largura, imagem->getCores());

	return cores;
}

Cor ** FiltroDeMedia::getMatriz(int altura, int largura, list<Cor> cores){

	Cor** rgb = new Cor*[altura];

	for(int i = 0; i < altura + 1; i++) {
        rgb[i] = new Cor[largura];
    }

	int linha=0,coluna=0,naocontar=0;
	//transformando list em matriz
	for(Cor cor : cores){

		rgb[linha][coluna] = cor;

		if(coluna == largura-1){
			naocontar = 1;
			linha++;
		}
		
		if(naocontar == 1){
			coluna = -1;
			naocontar = 0;
		}

		coluna++;	
	}

	return rgb;
}

list<Cor> FiltroDeMedia::getList(Cor** rgb, int largura, list<Cor> coresList){
	list<Cor> cores;
	int linha=0;
	int coluna=0;
	int naocontar=0;
	for(Cor cor : coresList){

		cor = rgb[linha][coluna];

		cores.push_back(cor);

		if(coluna == largura-1){
			naocontar = 1;
			linha++;
		}
		
		if(naocontar == 1){
			coluna = -1;
			naocontar = 0;
		}

		coluna++;
	}

	return cores;
}