#include "cor.hpp"

Cor::Cor(){

}

Cor::Cor(unsigned char R, unsigned char G, unsigned char B){
	this->R = R;
	this->G = G;
	this->B = B;
}

unsigned char Cor::getR(){
	return R;
}
unsigned char Cor::getG(){
	return G;
}
unsigned char Cor::getB(){
	return B;
}


void Cor::setR(unsigned char R){
	this->R = R;
}
void Cor::setG(unsigned char G){
	this->G = G;
}
void Cor::setB(unsigned char B){
	this->B = B;
}
