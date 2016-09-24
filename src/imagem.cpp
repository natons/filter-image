#include "imagem.hpp"
#include "cor.hpp"
#include <sstream>

using namespace std;

Imagem::Imagem(){

}

Imagem::Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, list<Cor> cores){
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

unsigned char Imagem::getEscalaMaxima(){
	return escalaMaxima;
}

void Imagem::setEscalaMaxima(unsigned char escalaMaxima){
	this->escalaMaxima = escalaMaxima;
}

void Imagem::setUrlEndereco(string urlEndereco){
	this->urlEndereco = urlEndereco;
}

string Imagem::getUrlEndereco(){
	return urlEndereco;
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

	setUrlEndereco(va.validarArquivo(&arquivo));

	arquivo.seekg(lerCabecalho(),ios_base::cur);

	setCores(lerCores(&arquivo));
	arquivo.close();
}

int Imagem::lerCabecalho(){

	ifstream arquivo;
	arquivo.open(getUrlEndereco().c_str());
	ValidacaoArquivo va;
	va.ignorarComentario(&arquivo);

	setFormato(getDado(&arquivo));

	va.ignorarComentario(&arquivo);

	int altura, largura;
	istringstream * iss = new istringstream();
	iss->str(getDado(&arquivo));
	(*iss) >> largura >> altura;
	setAltura(altura);
	setLargura(largura);

	va.ignorarComentario(&arquivo);
	
	int escala;
	iss = new istringstream();
	iss->str(getDado(&arquivo));
	(*iss) >> escala;
	setEscalaMaxima(escala);

	va.ignorarComentario(&arquivo);
	int posicao = arquivo.tellg();

	arquivo.close();
	return posicao;
}

int Imagem::getTamanhoCabecalho(){

	ifstream arquivo;
	arquivo.open(getUrlEndereco().c_str());
	ValidacaoArquivo va;
	va.ignorarComentario(&arquivo);

	getDado(&arquivo);

	va.ignorarComentario(&arquivo);
	
	getDado(&arquivo);

	va.ignorarComentario(&arquivo);
	
	getDado(&arquivo);

	va.ignorarComentario(&arquivo);
	
	int tam = arquivo.tellg();

	arquivo.close();

	return tam - 1;
}

list<Cor> Imagem::lerCores(ifstream * arquivo){
	Cor cor;
	list<Cor> cores;
	while(!arquivo->eof()){
		unsigned char dado = arquivo->get();
		cor.setR(dado);
		dado = arquivo->get();
		cor.setG(dado);
		dado = arquivo->get();
		cor.setB(dado);

		cores.push_back(cor);
	}

	return cores;
}

void Imagem::gravarImagem(){

	ofstream arquivoImagem;
	ValidacaoArquivo va;
	va.validarNovoArquivo(&arquivoImagem);

	int tam = getTamanhoCabecalho();
	ifstream arquivo;
	arquivo.open(getUrlEndereco().c_str());
	while(arquivo.tellg() <= tam)
		arquivoImagem.put((unsigned char) arquivo.get());
	arquivo.close();
	
	for(Cor cor : getCores()){
		
		arquivoImagem.put(cor.getR());
		
		arquivoImagem.put(cor.getG());
		
		arquivoImagem.put(cor.getB());
		
	}
	
	arquivoImagem.close();
	cout << endl;
	cout << "\t\t\tNova imagem criada com sucesso! " << endl;
	cout << endl;
}

void Imagem::imprimirDados(){
	cout << endl;
	cout << "-------------------------------------- CABEÇALHO -----------------------------------------" << endl;
	cout << endl;
	cout << "Formato: " << getFormato() << "\t\t\t" << "Dimensão: " << getLargura() << " X " << getAltura() << "\t\t\t" 
		<< "Escala Máxima: ";
		printf("%d", getEscalaMaxima());
	cout << endl;
	cout << endl;
	cout << "------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

string Imagem::getDado(ifstream * arquivo){
	unsigned char byte;
	string dado;
	while((byte=arquivo->get()) != '\n'){
		dado += byte;
	}

	return dado;
}