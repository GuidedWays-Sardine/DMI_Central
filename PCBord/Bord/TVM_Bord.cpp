#include "TVM_Bord.hpp"

TVM_Bord::TVM_Bord(Reseau &Res, Train_dynamique &train_dynamique, Train_statique &train_statique)
{
	this->Res = &Res;
	this->train_dynamique = &train_dynamique;
	this->train_statique = &train_statique;
}

void TVM_Bord::update() {
	mainFrequency = Res->getMainFrequency();
	secondaryFrequency = Res->getSecondFrequency();
	side = Res->getSideFrequency();

	// sol : doit faire le retardateur avec un simili cdv pour simuler le retardateur

	mainFrequency = 10.3;

	if (mainFrequency == 11.4)
		indication = "300V";
	else if (mainFrequency == 13.6)
		indication = "300C";
	else if (mainFrequency == 10.3)
		indication = "270V";
	else if (mainFrequency == 12.5)
		indication = "270C";
	else if (mainFrequency == 16.9)
		indication = "270A";
	else if (mainFrequency == 14.7)
		indication = "220A";
	else if (mainFrequency == 15.8)
		indication = "220E";
	else if (mainFrequency == 18)
		indication = "160A";
	else if (mainFrequency == 19.1)
		indication = "160E";
	else if (mainFrequency == 20.2)
		indication = "080A";
	else if (mainFrequency == 22.4)
		indication = "080E";
	else if (mainFrequency == 24.6)
		indication = "000R";
	else if (mainFrequency == 29)
		indication = "RRRR";

	if (indicationTemp != indication && indication != "" && indicationTemp != "")
		playfunction(5);

	vitesse = train_dynamique->getV_train();

	if (mainFrequency == 11.4 && vitesse > 315)
		covit = 1;
	else if (mainFrequency == 13.6 && vitesse > 315)
		covit = 1;
	else if (mainFrequency == 10.3 && vitesse > 285)
		covit = 1;
	else if (mainFrequency == 12.5 && vitesse > 285)
		covit = 1;
	else if (mainFrequency == 16.9 && vitesse > 315)
		covit = 1;
	else if (mainFrequency == 14.7 && vitesse > 285)
		covit = 1;
	else if (mainFrequency == 15.8 && vitesse > 235)
		covit = 1;
	else if (mainFrequency == 18 && vitesse > 235)
		covit = 1;
	else if (mainFrequency == 19.1 && vitesse > 170)
		covit = 1;
	else if (mainFrequency == 20.2 && vitesse > 170)
		covit = 1;
	else if (mainFrequency == 22.4 && vitesse > 90)
		covit = 1;
	else if (mainFrequency == 24.6 && vitesse > 90)
		covit = 1;
	else if (mainFrequency == 29 && vitesse > 35)
		covit = 1;
	else
		covit = 0;
	side = 2000;

	//cout << indication << endl;
	if (side == 1700 || side == 2300)
		side = 1;
	else if (side == 2000 || side == 2600)
		side = 2;
	else
		side = 0;

	if (secondaryFrequency == 1318)
		sect = 1;
	else if (secondaryFrequency == 1319)
		sect = 0;

	if (lastSecondaryFrequency != 1600 && secondaryFrequency == 1600)
		commutation = 1;

	if (lastSecondaryFrequency != 1882 && secondaryFrequency == 1882)
		carre = 1;

	if (lastSecondaryFrequency != 2867 && secondaryFrequency == 2867)
		armv2 = 0;

	if (lastSecondaryFrequency != 3008 && secondaryFrequency == 3008)
		armv2 = 0;

	if ((lastSecondaryFrequency != 3290 && secondaryFrequency == 3290) || (lastSecondaryFrequency != 2163 && secondaryFrequency == 2163)) {
		armv2 = 1;
		armv1 = 0;
	}
    else if ((lastSecondaryFrequency != 3430 && secondaryFrequency == 3430) || (lastSecondaryFrequency != 2726 && secondaryFrequency == 2726)) {
		armv1 = 1;
		armv2 = 0;
	}
	

    if (lastSecondaryFrequency != 3571 && secondaryFrequency == 3571)  
		kv65 = 1;

	if (secondaryFrequency == 3725)
		bp = 1;
	else if (secondaryFrequency == 3726)
		bp = 0;

	armv2 = 1;
	sideSwitch = train_statique->getSideSwitch();
	if (armv1==1) {
		sideBord = 1;
		train_statique->setSideSwitch(sideBord);
	}
	else if (armv2 == 1) {
		sideBord = 2;
		train_statique->setSideSwitch(sideBord);
	}
	else if (armv1 == 0 && armv2==0 && sideSwitch == 1 && side == 1) {
		sideBord = 1;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 1 && side == 2) {
		sideBord = 0;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 2 && side == 1) {
		sideBord = 0;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 2 && side == 2) {
		sideBord = 2;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 0 && side == 1) {
		sideBord = 3;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 0 && side == 2) {
		sideBord = 3;
	}
	else if (armv1 == 0 && armv2 == 0 && sideSwitch == 0 && side == 0) {
		sideBord = 3;
	}

	// if (commutation ==1 && rpi->getCanal()==1)
	//     rpi->setCanal(2);
	// if (commutation ==1 && rpi->getCanal()==2)
	//     rpi->setCanal(1);

	if ((covit == 1) || (kv65 == 1 && mainFrequency == 24.6) || (carre == 1 && mainFrequency == 29))
		fu = 1;
	else if ((covit == 0) && ((kv65 == 0) || (kv65 == 1 && mainFrequency != 24.6)) && ((carre == 0) || (carre == 1 && mainFrequency != 29)))
		fu = 0;

	indicationTemp = indication;
	lastSecondaryFrequency = secondaryFrequency;
	commutation = 0;
	carre = 0;
	kv65 = 0;

}



//get indication pour ecran

string TVM_Bord::getIndication() { 
	return indication;  
}
bool TVM_Bord::getSect() {
	return sect;
}
bool TVM_Bord::getBp() {
	return bp;
}
bool TVM_Bord::getCovit() {
	return covit;
}
int TVM_Bord::getSideBord() {
	return sideBord;
}
bool TVM_Bord::getFU() {
	return fu;
}