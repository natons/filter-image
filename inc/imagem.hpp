#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <iostream>
#include <string>
#include <list>
#include "validacaoarquivo.hpp"
#include "cor.hpp"
#include <fstream>

using namespace std;

class Imagem {

private:
		string formato;
		int altura;
		int largura;
		int escalaMaxima;
		list<Cor> cores;

public:
		Imagem();

		Imagem(string formato, int altura, int largura, int escalaMaxima, list<Cor> cores);
		
		string getFormato();

		void setFormato(string formato);

		int getAltura();

		void setAltura(int altura);

		int getLargura();

		void setLargura(int largura);

		int getEscalaMaxima();

		void setEscalaMaxima(int escalaMaxima);

		list<Cor> getCores();
		
		void setCores(list<Cor> cores);

		void lerImagem();

		void gravarImagem();

		void imprimirDados();
};

#endif