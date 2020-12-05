#ifndef TV
#define TV
#pragma once
#include "../Reseau.hpp"
#include "../define.hpp"
#include "../Train_dynamique.hpp"
#include "../Train_statique.hpp"
#include "../Sound.hpp"

class TVM_Bord : public Son
{
	protected:
		
		string indicationTemp = "";
		double mainFrequency;
		double secondaryFrequency;
		double punctualEmitterFrequency;
		string indication = "";
		int side;
		bool sect = 0;
		bool sortieTunnel = 0;
		bool commutation = 0;
		bool carre = 0;
		double lastSecondaryFrequency = 0;
		bool desv2 = 0;
		bool desv1 = 0;
		bool testAD = 0;
		bool armv2 = 0;
		bool armv1 = 0;
		bool kv65 = 0;
		bool bp = 0;
		bool entree = 0;
		bool covit = 0;
		int sideSwitch = 0;
		int sideBord = 0;
		double vitesse;
		Reseau* Res;
		Train_statique* train_statique;
		Train_dynamique* train_dynamique;
		bool fu;

	public:
		TVM_Bord(Reseau &Res, Train_dynamique &train_dynamique, Train_statique &train_statique);
		void update();
		string getIndication();
		bool getSect();
		bool getBp();
		bool getCovit();
		int getSideBord();
		bool getFU();
};

#endif