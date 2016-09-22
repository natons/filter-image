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
		unsigned char escalaMaxima;
		string urlEndereco;
		list<Cor> cores;

public:
		Imagem();

		Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, list<Cor> cores);
		
		string getFormato();

		void setFormato(string formato);

		int getAltura();

		void setAltura(int altura);

		int getLargura();

		void setLargura(int largura);

		unsigned char getEscalaMaxima();

		void setEscalaMaxima(unsigned char escalaMaxima);

		void setUrlEndereco(string urlEndereco);

		string getUrlEndereco();

		list<Cor> getCores();
		
		void setCores(list<Cor> cores);

		int lerCabecalho();

		int getTamanhoCabecalho();

		list<Cor> lerCores(ifstream * arquivo);

		void lerImagem();

		void gravarImagem();

		void imprimirDados();

		string getDado(ifstream * arquivo);
};

#endif