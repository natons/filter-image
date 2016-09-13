#include "cor.hpp"

Cor::Cor(){

}

Cor::Cor(int R, int G, int B){
	this->R = R;
	this->G = G;
	this->B = B;
}

int Cor::getR(){
	return R;
}
int Cor::getG(){
	return G;
}
int Cor::getB(){
	return B;
}


void Cor::setR(int R){
	this->R = R;
}
void Cor::setG(int G){
	this->G = G;
}
void Cor::setB(int B){
	this->B = B;
}
