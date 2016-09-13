#ifndef COR_HPP
#define COR_HPP

#include <iostream>

class Cor {

private:
	int R;
	int G;
	int B;

public:
	Cor();
	Cor(int R, int G, int B);

	int getR();
	int getG();
	int getB();

	void setR(int R);
	void setG(int G);
	void setB(int B);

};

#endif