#include "Train_statique.hpp"

Train_statique::Train_statique()
{
}

void Train_statique::update()
{
}


//
//// Les seters
//
//// Voir peut-être si coder CG CP
//// Voir les relations entre les différents états
//// Voir comment coder différemment un bouton et un interrupteur
//
//void Train_statique::set_projecteurs()
//{ etat_projecteurs = PE->getCmd_projecteurs();}
//
void Train_statique::set_disj()
{

 // Timer : maintien 2s pour l'armement uniquement
 // Voir Benoît pour savoir comment gérer le bouton armement et fermeture

/*	if(res->getPupitre_entrant().commande_disj_pin1 == 1)
	etat_disj = 1;
	if(res->getPupitre_entrant().commande_disj_pin1 == 0)
	etat_disj = 0;*/

}

void Train_statique::set_sablage()
{
 // Timer : maintien

chrono_sablage.time = chrono_sablage.chrono.getElapsedTime();
chrono_sablage.time_second = chrono_sablage.time.asSeconds();
/*if(res->getPupitre_entrant().commande_sablage!=(int)etat_sablage && chrono_sablage.etatChrono==0)
	{
	chrono_sablage.chrono.restart();
	chrono_sablage.etatChrono=1;
	}
if(chrono_sablage.time_second>1 && chrono_sablage.etatChrono==1)
	{
		etat_sablage = !etat_sablage;
		chrono_sablage.etatChrono=0;
	}*/
}

/*void Train_statique::set_acquitt()
{
 // Timer : à voir
}*/
//void TrainStatique::set_essui_glace()
//{etat_essui_glace = PE->getCmd_essui_glace();}
//
//void TrainStatique::set_lave_glace()
//{
//  // Timer : voir
//  etat_lave_glace = PE->getCmd_lave_glace();
//}
//
//void TrainStatique::set_light_cabine()
//{
//  // Timer : voir
//
//}
//
//void TrainStatique::set_light_pupitre()
//{
//  // Timer : voir
//
//}
//
/*void Train_statique::set_sifflet()
{
if (res->getPupitre_entrant().commande_sifflet_pin1 == 1 && res->getPupitre_entrant().commande_sifflet_pin2 == 0)
	etat_sifflet = 1;
	if (res->getPupitre_entrant().commande_sifflet_pin1 == 0 && res->getPupitre_entrant().commande_sifflet_pin2 == 0)
	etat_sifflet = 0;
	if (res->getPupitre_entrant().commande_sifflet_pin1 == 1 && res->getPupitre_entrant().commande_sifflet_pin2 == 1)
	etat_sifflet = -1;
}*/

//get set TVM à compléter avant avec l'algo des trois interrupteurs TVM
// 0 : pas de TVM
//1 : parité impaire
//2 : parité paire

int Train_statique::getSideSwitch() {
	return sideSwitch;
}
void Train_statique::setSideSwitch(int SS) 
{
	sideSwitch = SS;
}
//void TrainStatique::set_LS_SF()
//{
//  // C'est la lumière qui est modifiée par l'acquittement
//}
//
//void TrainStatique::set_BP_SF()
//{
//
//}
//
void Train_statique::set_signalisation()
{
 // C'est écrit dans le manuel de spec comment je dois le coder
}
//void TrainStatique::set_VI()
//{VI = PE->getCmd_VI();}
//
//void TrainStatique::set_direction()
//{direction = PE->getCmd_inverseur();}
//
//void TrainStatique::set_conduct_mod()
//{conduct_mod = PE->getCmd_conduct_mod();}
//
void Train_statique::set_tract_frein()
 {
// 	//tract_frein = PE->getCmd_tract_frein();
 }
//void TrainStatique::setPorte()
//{
//
//}
//
void Train_statique::set_panto()
{
	// Timer 2s pour lever/baisser panto
	chrono_panto.time = chrono_panto.chrono.getElapsedTime();
	chrono_panto.time_second = chrono_panto.time.asSeconds();
	/*if(res->getPupitre_entrant().commande_BP_panto_pin1==(int)etat_panto && etat_panto==0)
	{
	chrono_panto.chrono.restart();
	chrono_panto.etatChrono=1;
	}*/
	if(chrono_panto.time_second>2 && chrono_panto.etatChrono==1)
		{
			etat_sablage = !etat_sablage;
			chrono_sablage.etatChrono=0;
		}
	//if(res->getPupitre_entrant().commande_BP_panto_pin1==(int)etat_panto && etat_panto==1)
	//etat_panto = 0;
}
//void TrainStatique::set_VA()
//{
//
//}
//
//void TrainStatique::set_cle_BL()
//{
//
//}
//
//void TrainStatique::set_ventilation()
//{
//
//}
//
void Train_statique::set_GROG()
{
	/*chrono_GROG.time = chrono_sablage.chrono.getElapsedTime();
	chrono_GROG.time_second = chrono_sablage.time.asSeconds();
	// Timer 2s pour armement/désarmement
	// Timer 5s de maintien pour lancer l'allumage
	if(res->getPupitre_entrant().commande_allum_diesel_pin1 == 1 && res->getPupitre_entrant().commande_allum_diesel_pin2 == 1 && chrono_GROG.etatChrono==0)
	{
		chrono_GROG.etatChrono=1;
		chrono_GROG.chrono.restart();
	}
	if((res->getPupitre_entrant().commande_allum_diesel_pin1 != 1 || res->getPupitre_entrant().commande_allum_diesel_pin2 != 1) && chrono_GROG.etatChrono==1 && chrono_GROG.time_second<2)
	{
		chrono_GROG.etatChrono=0;
		chrono_GROG.chrono.restart();
	}
	if(chrono_GROG.etatChrono==1 && chrono_GROG.time_second>7)
	{
		chrono_GROG.etatChrono=0;
		chrono_GROG.chrono.restart();
		etat_GROG=1;
	}
	if(res->getPupitre_entrant().commande_allum_diesel_pin1 == 0 && res->getPupitre_entrant().commande_allum_diesel_pin2 == 0 && chrono_GROG.etatChrono != -1)
	{
		chrono_GROG.etatChrono=-1;
		chrono_GROG.chrono.restart();
	}
	if(chrono_GROG.etatChrono==-1 && chrono_GROG.time_second>3)
	{
		chrono_GROG.etatChrono=0;
		chrono_GROG.chrono.restart();
		etat_GROG=0;
	}*/
}
//void Train_statique::set_TVM_V1()
//
//void TrainStatique::set_TVM_V2()
//{
//
//}
//
//void TrainStatique::set_alarme()
//{
//
//}

//int TrainStatique::getPanto(){return panto;}
//int TrainStatique::getSifflet(){return sifflet;}
//bool TrainStatique::getDisj(){return disj;}

//void TrainStatique::update()
//{
//  set_disj();
//  set_panto();
//  set_sifflet();
//}