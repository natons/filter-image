#include "imagem.hpp"
#include "cor.hpp"

using namespace std;

Imagem::Imagem(){

}

Imagem::Imagem(string formato, int altura, int largura, int escalaMaxima, list<Cor> cores){
	this->formato = formato;
	this->altura = altura;
	this->largura = largura;
	this->escalaMaxima = escalaMaxima;
	this->cores = cores;
}

string Imagem::getFormato(){
	return formato;
}

void Imagem::setFormato(string formato){
	this->formato = formato;
}

int Imagem::getAltura(){
	return altura;
}

void Imagem::setAltura(int altura){
	this->altura = altura;
}
		
int Imagem::getLargura(){
	return largura;
}

void Imagem::setLargura(int largura){
	this->largura = largura;
}

int Imagem::getEscalaMaxima(){
	return escalaMaxima;
}

void Imagem::setEscalaMaxima(int escalaMaxima){
	this->escalaMaxima = escalaMaxima;
}

list<Cor> Imagem::getCores(){
	return cores;
}

void Imagem::setCores(list<Cor> cores){
	this->cores = cores;
}

void Imagem::lerImagem(){

	ifstream arquivo;

	ValidacaoArquivo va;

	va.validarArquivo(&arquivo);

	va.ignorarComentario(&arquivo);

	(arquivo) >> formato;

	va.ignorarComentario(&arquivo);

	(arquivo) >> altura >> largura;

	va.ignorarComentario(&arquivo);

	(arquivo) >> escalaMaxima;

	int R, G, B;
	Cor * cor;
	while(!arquivo.eof()){
		//va.ignorarComentario(&arquivo);
		arquivo >> R >> G >> B;
		cor = new Cor(R,G,B);
		cores.push_back(*cor);
	}	

	arquivo.close();
}

void Imagem::gravarImagem(){

	ofstream arquivoImagem;
	ValidacaoArquivo va;
	va.validarNovoArquivo(&arquivoImagem);

	arquivoImagem << getFormato() << endl;
	arquivoImagem << getAltura() << " " << getLargura() << endl;
	arquivoImagem << getEscalaMaxima() << endl;

	for(Cor cor : getCores()){
		arquivoImagem << cor.getR() << "\t" << cor.getG() << "\t" << cor.getB() << endl;
	}

	arquivoImagem.close();

	cout << "Nova imagem criada com sucesso! " << endl;
}

void Imagem::imprimirDados(){
	cout << "Formato: " << getFormato() << "\t" << "Dimensão: " << getAltura() << " X " << getLargura() << "\t" 
		<< "Escala Máxima: " << getEscalaMaxima() << endl;
}