#include "LeftSide.hpp"

LeftSide::LeftSide(vector<Symbol> &symbol, Software &soft, ETCS_Bord &bord, Train_dynamique &T_D) : cadran(soft, T_D, bord), symbol(&symbol)
{
	//cout<< "LEFT" <<endl;
	this->soft = &soft;
	this->bord = &bord;
}

void LeftSide::targetDistance(int distance)
{
	if(distance >= 0 && bord->getGeneralMode() == "FS" && (bord->SDM.SL.getStatus() == "TSM" || bord->SDM.SL.getStatus() == "RSM"))
	{
		creation_texte(to_string((int)round((distance / 10.0)) * 10), GREY, 10, 0, V2f(54 / 2.0, 54 + 30 / 2.0), 1);
		rectangle(V2f(12, 54 + 30 - 1), V2f(13, 2), GREY);
		rectangle(V2f(16, 54 + 30 + 6), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 13), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 22), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 32), V2f(9, 1), GREY);
		rectangle(V2f(12, 54 + 30 + 45), V2f(13, 2), GREY);
		rectangle(V2f(16, 54 + 30 + 59), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 79), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 105), V2f(9, 1), GREY);
		rectangle(V2f(16, 54 + 30 + 152), V2f(9, 1), GREY);
		rectangle(V2f(12, 54 + 30 + 185), V2f(13, 2), GREY);
		if(distance <= 100)
		{
			rectangle(V2f(29 , static_cast<float>(85 + 185 * ( 1 - (1.722 * pow(10, - 3) * distance)))), V2f(10, static_cast<float>(185 * (1.722 * pow(10, - 3) * distance))), GREY);
		}
		else if(distance <= 1000)
		{
			rectangle(V2f(29, 186 + 54 + 30 - (185 - 152)), V2f(10, 185 - 152), GREY);
			rectangle(V2f(29, static_cast<float>(85 + 185 * ( 1 - (log(distance*(1/58.8236)) / log(17))))), V2f(10, static_cast<float>(185 * (log(distance * (1 / 58.8236)) / log(17)))), GREY);
		}
		else
		{
			rectangle(V2f(29, 186  + 54 + 30 -185), V2f(10, 185), GREY);
		}
	}
}

void LeftSide::update()
{
	creation_rectangle(V2f(0, 0), V2f(54, 54), 1);															//A1
	creation_rectangle(V2f(0, 54), V2f(54, (191 + 30)), 1);													//A2-3
	creation_rectangle(V2f(0, (54 +30 + 191)), V2f(54, 25), 1);												//A4
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25)), V2f(54, 25), 1);										//C8
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 2)), V2f(54, 25), 1);									//C9
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 3)), V2f(54, 25), 1);									//E1
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 4)), V2f(54, 25), 1);									//E2
	creation_rectangle(V2f(0, (54 + 30 + 191 + 25 * 5)), V2f(54, 25), 1);									//E3
	creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 1);							//C1
	creation_rectangle(V2f(54, 0), V2f(280, 300), 1);														//B
	creation_rectangle(V2f(54, (54 + 30 + 191 + 25 + 50)), V2f(234, 4 * 20), 1);							//E5-6-7-8
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50)), V2f(46, 40), 2);							//E10
	creation_rectangle(V2f((54 + 234), (54 + 30 + 191 + 25 + 50 + 40)), V2f(46, 40), 2);					//E11
	creation_rectangle(V2f((54 + 26 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B6
	creation_rectangle(V2f((54 + 140 + 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B5
	creation_rectangle(V2f((54 + 140 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);						//B4
	creation_rectangle(V2f((54 + 140 - 36 * 3 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);					//B3
	creation_rectangle(V2f((54 + 254 - 36 / 2.0), (274 - 36 / 2.0)), V2f(36, 36), 1);		      			//B7

	if(bord->getConnection() == "Up" && bord->getGeneralMode()=="FS") //Connection Up
	{
		ST_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0));	//E1
	}
	else if(bord->getConnection() == "Down" && bord->getGeneralMode() == "SR") //Connection Lost/Set-Up failed
		ST_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 * 3 + 25 / 2.0));	//E1

	/*if(version == "3.6.0")
	{
		data->setTTI((data->getDEOA() - (3 / 5.0)*data->getD_but())/(bord->TrainRI.T_data.getVtrain()/3.6)); // TEMPORAIRE POUR LA DEMO
		//Rappel TTIdisp est à 14 s selon la subset026
		if((data->getGeneralMode() == "FS" || ((data->getGeneralMode() == "OS" || data->getGeneralMode() == "SR") && TTI == "On")) && (data->getMode() == "CSM" || data->getMode() == "PIM") && data->getTTI() < 14)  //A1 : TTI
		{
			if(temp_TTI == 0)
			{
				son.jouer_alarmes(2, 1);
				temp_TTI = 1;
			}
			rectangle(V2f(2,2), V2f(50, 50), DARK_GREY);
			for(int n = 0; n <= 10; n++)
			{
				if(14*(10 - n)/10 <= data->getTTI() && data->getTTI() < 14*(10 - (n - 1))/10)
					rectangle(V2f(54/2 - 2.5*n, 54/2 - 2.5*n), V2f(n*5,n*5), WHITE);
			}
		}
		else
			temp_TTI = 0;

		SSI.setPosition(V2f(local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).x - 6 * RE, local2globalCoordonates(centreIV, 90 + 144, V2f(111 * RE, graduations[20].teta() - abs(graduations[0].teta() - graduations[1].teta()) / 2.0)).y - 6 * RE));
		fenetre.draw(SSI);
	}
	if(version == "3.4.0")		//Voir avec benoit
	{
		LS_01.afficher(V2f(54 / 2.0, 54 / 2.0));	//A1
		creation_texte(to_string(LSSMA), GREY, 16, 0, V2f(54 / 2.0, 54 / 2.0), 1); //400km/h
	}*/
	//pictrogrammes
	if(bord->TrainRI.T_data.getLevel() == "Level 0")
        LE_01.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(bord->TrainRI.T_data.getLevel()  == "Level 1")
        LE_03.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(bord->TrainRI.T_data.getLevel()  == "Level 2")
        LE_04.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
    else if(bord->TrainRI.T_data.getLevel()  == "Level 3")
        LE_05.afficher(V2f(54 / 2.0, 54 + 30 + 191 + 25 + 25 / 2.0));
	if(bord->SDM.SADMC.getCommand_triggered() ==  "EB")
	{
		ST_01.afficher(V2f(54/2, 54+30+191+25+25+12.5)); // Emergency Brake
	}
	if(bord->getGeneralMode() == "FS")
		MO_11.afficher(V2f((54 + 254 - 36 / 2.0 + 17), (274 - 36 / 2.0 + 17)));
	if(bord->getGeneralMode() == "SR")
		MO_09.afficher(V2f((54 + 254 - 36 / 2.0 + 17), (274 - 36 / 2.0 + 17)));
	if(bord->getGeneralMode() == "SB")
		MO_13.afficher(V2f((54 + 254 - 36 / 2.0 + 17), (274 - 36 / 2.0 + 17)));
	//
	//TexteMessages();//special class texte



	if (bord->getGeneralMode() == "TVM") {
		sideBord = bord->getSideBord();

		indication = bord->getIndication();
		if (sideBord != 3) {
			if (indication.at(3) == 'R' || sideBord == 0) {
				creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
				creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
				creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 5);
			}

			else if (indication.at(3) == 'V') {
				creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
				creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
				creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
			}

			else if (indication.at(3) == 'C' && clockTVM.getElapsedTime() > periodeClignotement / floatdeux) {
				creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
				creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
				creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 6);
			}

			else if (indication.at(3) == 'E') {
				creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
				creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
				creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 7);
			}
			else if (indication.at(3) == 'A') {
				creation_rectangle(V2f((54 + 3 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
				creation_rectangle(V2f((54 + 1 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
				creation_rectangle(V2f((54 + 5 * 37), (54 + 30 + 191 + 25)), V2f(58, 50), 8);
			}
		}

		if (sideBord != 0 && sideBord != 3) {
			if (indication.at(0) == '3' && indication.at(1) == '0' && indication.at(2) == '0' && indication.at(3) == 'V') {
				creation_texte("3", WHITE, 48, soft->getRE()*1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '3' && indication.at(1) == '0' && indication.at(2) == '0' && indication.at(3) == 'C' && clockTVM.getElapsedTime() > periodeClignotement / floatdeux) {
				creation_texte("3", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'V') {
				creation_texte("2", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("7", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'C' && clockTVM.getElapsedTime() > periodeClignotement / floatdeux) {
				creation_texte("2", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("7", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '2' && indication.at(1) == '7' && indication.at(2) == '0' && indication.at(3) == 'A') {
				creation_texte("2", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("7", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '2' && indication.at(1) == '2' && indication.at(2) == '0' && indication.at(3) == 'E') {
				creation_texte("2", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("2", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '2' && indication.at(1) == '2' && indication.at(2) == '0' && indication.at(3) == 'A') {
				creation_texte("2", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("2", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '1' && indication.at(1) == '6' && indication.at(2) == '0' && indication.at(3) == 'E') {
				creation_texte("1", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("6", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '1' && indication.at(1) == '6' && indication.at(2) == '0' && indication.at(3) == 'A') {
				creation_texte("1", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("6", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '0' && indication.at(1) == '8' && indication.at(2) == '0' && indication.at(3) == 'E') {
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("8", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '0' && indication.at(1) == '8' && indication.at(2) == '0' && indication.at(3) == 'A') {
				creation_texte("0", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("8", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", BLACK, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
			else if (indication.at(0) == '0' && indication.at(1) == '0' && indication.at(2) == '0') {
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 1 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 3 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
				creation_texte("0", WHITE, 48, soft->getRE() * 1.33f, V2f(54 + 5 * 37 + 29, 54 + 30 + 191 + 25 + 25), 1);
			}
		}

		if (clockTVM.getElapsedTime() > periodeClignotement)
			clockTVM.restart();

		sect = bord->getSect();
		if (sect == 1)
			Sect.afficher(V2f(54 + 140 + 36, 274));			//F5
		bp = bord->getBp();
		if (bp == 1)
			BP.afficher(V2f(54 + 140 - 36, 274));
	}



	targetDistance(static_cast<int>(bord->TrackRI.SADL.getTargetDistance()));
	cadran.update();

	// affichage BS
	
	LS_A_UL.afficher(V2f(640 + (640* soft->getBlackRatio()-640)/2 - 22, 43));
	LS_DF_F.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 86));
	LS_I.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 129));
	SOS_PSH.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 172));
	SOS_RS.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 215));
	SOS_DAAT.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 258));
	SOS_VA.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 302));
	MAIS_MERDE.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 345));
	SOS_PZB.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 388));
	SOS_ZUB.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 - 22, 431));

	LS_QT_DJ.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 43));
	LS_AUTOR_DJ.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 86));
	LS_DF_TRA.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 129));
	LS_SI_AL.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 172));
	LS_PCO.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 215));
	LS_DF_F_FP.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 258));
	SOS_TRI.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 302));
	EMPTY.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 345));
	EMPTY.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 388));
	SOS_INTG.afficher(V2f(640 + (640 * soft->getBlackRatio() - 640) / 2 + 22, 431));
}
