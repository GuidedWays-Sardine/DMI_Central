#ifndef ET
#define ET

#include "TrainRelatedInputs.hpp"
#include "TrackRelatedInputs.hpp"
#include "../Train_dynamique.hpp"
#include "../Train_statique.hpp"
#include "SpeedAndDistanceMonitoring.hpp"
#include "../Reseau.hpp"
#include "BasicEVCSecurity.hpp"

class SpeedAndDistanceMonitoring;


class ETCS_Bord : public Son, public Train_statique
{
	protected :
		std::string generalMode = "SB";// FS,SR,SB
		std::string version = "3.6.0";
		std::string connection = "Down"; //Down de base, Up avec connexion pupitre
		Train_dynamique *T_D;
		Software *soft;
		Reseau *Res;
		
		// variables TVM


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
		bool fu;


		// clock affichage cli
		Time periodeClignotement = seconds(0.65f);
		float floatdeux = 2;

		Clock clockTVM;

	public :
		TrackRelatedInputs TrackRI;
		TrainRelatedInputs TrainRI;
		SpeedAndDistanceMonitoring SDM;
		BasicEVCSecurity BasicEVCcommands;
		ETCS_Bord(Train_dynamique &T_D, Software &soft, Reseau &Res);
		void bord_update();
		void transition_generalMode();
		void connection_update();
		std::string getGeneralMode();
		void setGeneralMode(std::string M);
		std::string getVersion();
		void setVersion(std::string V);
		bool getDriverID();
		bool getTrainData();
		bool getETATLevelETCS();
		bool getTrainNumber();
		std::string getConnection();
		void setConnection(bool C);
		bool getPending_Emergency_Stop();
		bool getModif_DriverID_NTC();
		bool getNon_Leading();
		bool getPassive_Shunting();
		int getVrelease();
		bool getEOA();
		void setEOA(bool EOA);
		bool getmodif_Adhesion();
		void tvmBord();

		string getIndication();
		bool getSect();
		bool getBp();
		bool getCovit();
		int getSideBord();
		bool getFU();

};

#endif