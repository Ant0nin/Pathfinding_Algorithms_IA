#include "Noeud.h"


Noeud* popa;

Noeud::Noeud(int newX,int newY,Noeud* pere)
{

	x = newX;
	y = newY;
	popa = pere;
	heur = calcHeur();

}

Noeud Noeud::sucesseur(Operateur op)
{
	int newX = x;
	int newY = y;
	switch (op)
	{
	case HAUT:
		y--;
		break;
	case BAS:
		y++;
		break;
	case GAUCHE:
		x--;
		break;
	case DROITE:
		x++;
		break;
	}
	return Noeud(newX,newY,this);
}

bool Noeud::valid()
{
	bool ret = true;

	//Si le terrain [x][y] est un mur 1
	if (true) ret= false;
	return ret;
}

bool Noeud::isBut()
{
	bool ret = false;
	//Si le terrain [x][y] est la sortie -1
	if (true) ret = true;
	return ret;
}

Noeud* Noeud::getPopa()
{
	return popa;
}

int Noeud::calcHeur()
{
	float ret = sqrt(pow(x - 1,2) + pow(y - 1,2));
	return ret;
}
