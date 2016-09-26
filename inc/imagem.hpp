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
		int tamanhoCabecalho;
		list<Cor> cores;

public:
		Imagem();

		Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, string urlEndereco, int tamanhoCabecalho, list<Cor> cores);

		Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, int tamanhoCabecalho);
		
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

		int getTamanhoCabecalho();

		void setTamanhoCabecalho(int tamanhoCabecalho);

		list<Cor> getCores();
		
		void setCores(list<Cor> cores);




		int lerCabecalho();

		list<Cor> lerCores();

		void lerImagem(string nomeImagem);

		void gravarImagem();

		void imprimirDados();

		string getDado(ifstream * arquivo);
};

#endif