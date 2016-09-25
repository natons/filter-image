#include "filtrodemedia.hpp"

list<Cor> FiltroDeMedia::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores;
	/*
	list<Cor>::iterator it = cores.begin(); 	
	list<Cor>::iterator itAnterior;
	Cor anterior;

	long int cont, r=0,g=0,b=0;
	for (Cor cor : imagem->getCores())
	{
		cont++;

		r += (long int)cor.getR();
		g += (long int)cor.getG();
		b += (long int)cor.getB();

		if(cont == 5){
			anterior = cor;
			itAnterior = it;
		}

		if(cont == 9){
			r /= 9;
			g /= 9;
			b /= 9;

			anterior.setR((unsigned char) r);
			anterior.setG((unsigned char) g);
			anterior.setB((unsigned char) b);

			cores.insert(itAnterior, anterior); 			
			cores.erase(++itAnterior);

			r = 0;
			g = 0;
			b = 0;
			cont = 0;
		}

		++it;
	}*/


	
	Cor rgb[imagem->getAltura()][imagem->getLargura()];

	int linha=0,coluna=-1;
	for(Cor cor : imagem->getCores()){

		if(coluna < imagem->getLargura()){
			coluna++;
		} else {
			linha++;
			coluna = -1;
		}
		
		rgb[linha][coluna] = cor;
	}

	int limit = 2;
	double div = 25.0;
	double r,g,b;
	for(int i = limit; i < imagem->getAltura() - limit; ++i){
	    for(int j = limit; j < imagem->getLargura() - limit; ++j) {
	    	r = 0;
	    	g = 0;
	    	b = 0;
		    	for (int k = -limit; k <= limit; ++k){
		    		for (int n = -limit; n <= limit; ++n){
		    			r += rgb[i+k][j+n].getR();
		    			g += rgb[i+k][j+n].getG();
		    			b += rgb[i+k][j+n].getB();
		    			//cout << (int)rgb[i+k][j+n].getR() << " " << (int)rgb[i+k][j+n].getG() << " " << (int)rgb[i+k][j+n].getB() << "\t";
		    		}
		    		//cout << endl;
		    	}

		        r /= div;

		        g /= div;

		        b /= div;

		        //cout << r << " " << g << " " << b << endl;

		        //cout << endl;

		        rgb[i][j].setR((unsigned char)r);
		        rgb[i][j].setG((unsigned char)g);
		        rgb[i][j].setB((unsigned char)b);

	    }
	}

	linha=0;
	coluna=-1;
	for(Cor cor : imagem->getCores()){

		if(coluna < imagem->getLargura()){
			coluna++;
		} else {
			linha++;
			coluna = -1;
		}

		cor = rgb[linha][coluna];

		cores.push_back(cor);
	}
	return cores;
}