#ifndef beno
#define beno


#include "define.hpp"

struct Chrono

{

    sf::Clock chrono;

    sf::Time time;

    double time_second;
    short int etatChrono;

};

class Train_statique
{
    private :
        int etat_projecteurs = 0;
        int etat_disj = 0;
        bool etat_sablage = 0;
        struct Chrono chrono_sablage;
        bool etat_acquitt = 0;
        int etat_essui_glace = 0;
        bool etat_lave_glace = 0;
        int etat_light_cabine = 0;
        int etat_light_pupitre = 0;
        int etat_sifflet = 0;
        bool etat_LS_SF = 0;
        bool etat_BP_SF = 0;
        int signalisation = 0;
        double etat_VI = 0;
        int direction = 0;
        int etat_conduct_mod = 0;
        double etat_tract_frein = 0;
        int etat_porte = 0;
        bool etat_panto = 0;
        struct Chrono chrono_panto;
        bool etat_VA = 0;
        bool etat_cle_BL = 0;
        bool etat_ventilation = 0;
        int etat_GROG = 0;
        struct Chrono chrono_GROG;
        bool etat_TVM_V1 = 0;
        bool etat_TVM_V2 = 0;
        bool etat_alarme = 0;
        int sideSwitch = 1;

    public :
        Train_statique();
        void update();
        void set_projecteurs();
        void set_disj();
        void set_sablage();
        void set_acquitt();
        //void set_essui_glace();
        //void set_lave_glace();
        //void set_light_cabine();
        //void set_light_pupitre();
        void set_sifflet();
        //void set_LS_SF();
        //void set_BP_SF();
        void set_signalisation();
       //void set_VI();
        //void set_direction();
        //void set_conduct_mod();
        void set_tract_frein();
        //void setPorte();
        void set_panto();
        //void set_VA();
        //void set_cle_BL();
        //void set_ventilation();
        void set_GROG();
        //void set_TVM_V1();
        //void set_TVM_V2();
        //void set_alarme();
//      int getPanto();
//      bool getDisj();
//      int getSifflet();
//      void update();

        //get set armement parité TVM

        int getSideSwitch();
        void setSideSwitch(int SS);
};

#endif