
/*
Runner-up Algorithm submission:
Owner: Joseph C.
Title of Algorithm: Goldfish
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Opponent {

    public:
        string PlayRound();     //"BigBadEvilCode"

        void IncreaseWins();
        void IncreaseTies();
        void IncreaseLosses();
        void IncreaseRockPlays();
        void IncreasePaperPlays();
        void IncreaseScissorPlays();
        
        int GetWins();
        int GetTies();
        int GetLosses();

        void SetRockReward(int val);
        void SetPaperReward(int val);
        void SetScissorReward(int val);

    private:
        unsigned int wins = 0;
        unsigned int ties = 0;
        unsigned int losses = 0;

        double rockCon;             //confidence value
        double paperCon;            //confidence value
        double scissorsCon;         //confidence value
        double rockMean = 1;        //mean rock reward
        double paperMean = 1;       //mean paper reward
        double scissorMean = 1;     //mean scissor reward

        double rockReward = 0;
        double paperReward = 0;
        double scissorReward = 0;

        unsigned int rockPlays = 1;
        unsigned int paperPlays = 1;
        unsigned int scissorPlays = 1;
};