#include "Virtual_train.hpp"

Virtual_train::Virtual_train(Software &soft) : reseau(train_dynamique), etcs(soft, train_dynamique, reseau), train_statique(), train_dynamique(reseau,train_statique)
{
    //cout<< "VT" <<endl;
    this->soft = &soft;
}

void Virtual_train::update()
{
	
    train_statique.update();
    train_dynamique.update();
    etcs.ETCS_uptade();
	
//	if (n == 0) {
		std::thread reseau_Update(&Reseau::Reseau_update, &reseau);
		reseau_Update.detach();
//	}
 //   n = 1;
}

//sans Arduino commenter L11 et L15