#include "filtrodemedia.hpp"

list<Cor> FiltroDeMedia::aplicarFiltro(Imagem  * imagem){

	list<Cor> cores = imagem->getCores();
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
	}



	/*
	Cor rgb[imagem->getAltura()][imagem->getLargura()];
	int i=0,j=-1;
	for(Cor cor : imagem->getCores()){

		if(j < imagem->getLargura()){
			j++;
		} else {
			i++;
			j = -1;
		}
		
		rgb[i][j] = cor;
	}

	cout << imagem->getCores().size() << endl;

	int limit = 1;
	int r,g,b;
	for(int i = limit; i < imagem->getAltura() - limit; ++i){
	    for(int j = limit; j < imagem->getLargura() - limit; ++j) {
	    	r = 0;
	    	g = 0;
	    	b = 0;

	    	for (int k = -1; k <= 1; ++k){
	    		for (int n = -1; n <= 1; ++n){
	    			r += rgb[i+k][j+n].getR();
	    			g += rgb[i+k][j+n].getG();
	    			b += rgb[i+k][j+n].getB();
	    		}
	    	}

	        r /= 9;

	        g /= 9;

	        b /= 9;

	        rgb[i][j].setR((unsigned char)r);
	        rgb[i][j].setG((unsigned char)g);
	        rgb[i][j].setB((unsigned char)b);
	        
	    }
	}

	for(int i = 0; i < imagem->getAltura(); ++i)
	    for(int j = 0; j < imagem->getLargura(); ++j) 
	    	cores.push_back(rgb[i][j]);*/

	return cores;
}