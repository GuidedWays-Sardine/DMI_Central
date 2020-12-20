#ifndef LS
#define LS

#include "Cadran.hpp"
#include "Symbol.hpp"

class LeftSide : public virtual Tools
{
	private :
		Cadran cadran;
		std::vector <Symbol> *symbol;
		ETCS_Bord *bord;
		
		//TVM

		string indication = "";
		bool sect = 0;
		bool bp = 0;
		bool covit = 0;
		int sideBord = 0;

		Time periodeClignotement = seconds(0.65f);
		float floatdeux = 2;

		Clock clockTVM;
	public :
		LeftSide(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D);
		void update();
		void targetDistance(int distance);
		
};

#endif