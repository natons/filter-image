#include "imagem.hpp"
#include "cor.hpp"
#include <sstream>
#include "menuimagem.hpp"

using namespace std;

Imagem::Imagem(){

}

Imagem::Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, string urlEndereco, int tamanhoCabecalho, list<Cor> cores){
	this->formato = formato;
	this->altura = altura;
	this->largura = largura;
	this->escalaMaxima = escalaMaxima;
	this->urlEndereco = urlEndereco;
	this->tamanhoCabecalho = tamanhoCabecalho;
	this->cores = cores;
}

Imagem::Imagem(string formato, int altura, int largura, unsigned char escalaMaxima, int tamanhoCabecalho){
	this->formato = formato;
	this->altura = altura;
	this->largura = largura;
	this->escalaMaxima = escalaMaxima;
	this->tamanhoCabecalho = tamanhoCabecalho;
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

int Imagem::getTamanhoCabecalho(){
	return tamanhoCabecalho;
}

void Imagem::setTamanhoCabecalho(int tamanhoCabecalho){
	this->tamanhoCabecalho = tamanhoCabecalho;
}

list<Cor> Imagem::getCores(){
	return cores;
}

void Imagem::setCores(list<Cor> cores){
	this->cores = cores;
}

void Imagem::lerImagem(string nomeImagem){

	ifstream arquivo;

	ValidacaoArquivo va;

	setUrlEndereco(va.validarArquivo(&arquivo,nomeImagem));

	lerCabecalho();

	setCores(lerCores());

	arquivo.close();
}

int Imagem::lerCabecalho(){

	ifstream arquivo;
	arquivo.exceptions( ifstream::badbit );
	int posicao;
	try{
		arquivo.open(getUrlEndereco().c_str(), ios_base::binary);

		ValidacaoArquivo va;
		va.ignorarComentario(&arquivo);

		string formato = getDado(&arquivo);

		va.ignorarComentario(&arquivo);

		int altura, largura;
		istringstream * iss = new istringstream();
		iss->str(getDado(&arquivo));
		(*iss) >> largura >> altura;

		va.ignorarComentario(&arquivo);
		
		int escala;
		iss = new istringstream();
		iss->str(getDado(&arquivo));
		(*iss) >> escala;

		va.ignorarComentario(&arquivo);
		posicao = arquivo.tellg();

		arquivo.close();

		//setando atributos
		//Imagem(formato,altura,largura,(unsigned char)escala,posicao);
		setFormato(formato);setAltura(altura);setLargura(largura);setEscalaMaxima(escala);setTamanhoCabecalho(posicao);

	}catch(ifstream::failure e){
		cerr << "Erro na leitura do arquivo em lerCabecalho" << getUrlEndereco() << endl;
	}
	
	return posicao;
}

list<Cor> Imagem::lerCores(){

	ifstream arquivo;
	arquivo.exceptions( ifstream::badbit );
	list<Cor> cores;
	try {
		arquivo.open(getUrlEndereco().c_str(), ios_base::binary);
		arquivo.seekg(getTamanhoCabecalho()+1,arquivo.beg);

		Cor cor;
		while(!arquivo.eof()){
			unsigned char dado = arquivo.get();
			cor.setR(dado);
			dado = arquivo.get();
			cor.setG(dado);
			dado = arquivo.get();
			cor.setB(dado);

			cores.push_back(cor);
		}

		arquivo.close();


	} catch(ifstream::failure e){
		cerr << "Erro na leitura do arquivo em lerCores" << getUrlEndereco() << endl;
	}

	return cores;
}

void Imagem::gravarImagem(){

	ifstream arquivo;
	arquivo.exceptions( ifstream::badbit );

	ofstream arquivoImagem;
	ValidacaoArquivo va;
	va.validarNovoArquivo(&arquivoImagem);

	int tam = getTamanhoCabecalho();

	try{
		
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
		MenuImagem menu;
		string mensagem = "Nova imagem criada com sucesso!";
		menu.mensagem(mensagem);

	} catch(ifstream::failure e){
		cerr << "Erro na abertura/leitura do arquivo em gravarImagem" << getUrlEndereco() << endl;
	}
}

string Imagem::getDado(ifstream * arquivo){
	unsigned char byte;
	string dado;
	while((byte=arquivo->get()) != '\n'){
		dado += byte;
	}

	return dado;
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