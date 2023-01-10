
#include <iomanip>
#include <vector>
#include "self.h"
#include "opponent.h"

using namespace std;

class Contest {

    public:
        void IntializeGame();
        void PlayRound();
        void PrintRoundInfo();
        void RunSimulation();
        void PrintResults();

    private:
        unsigned int totalRounds;
        unsigned int refreshRate;
        unsigned int currentRound = 0;
        Self self;
        Opponent opponent;

};