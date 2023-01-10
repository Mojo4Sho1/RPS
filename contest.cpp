
#include <iostream>
#include "contest.h"

using namespace std;

void Contest::IntializeGame() {

    cout << endl;
    cout << "Welcome to Agent Royale." << endl;

    cout << "Please input the number of rounds to simulate: ";
    cin >> totalRounds;

    cout << "Please input the step size: ";
    cin >> refreshRate;

}

void Contest::PlayRound() {

    string selfPlay = self.PlayRound();
    string opponentPlay = opponent.PlayRound();

    if(selfPlay == "R") {                   //case 1: 3 potential outcomes

        if(opponentPlay == "R") {           //case 1: outcome  1
            //opponent.IncreaseRockPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseTies();
            opponent.IncreaseTies();
            self.AdjustWeights(0, 1);
            currentRound += 1;
            opponent.SetRockReward(.75);
            return;
        }
        if(opponentPlay == "P") {           //case 1: outcome 2
            //opponent.IncreasePaperPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseLosses();
            opponent.IncreaseWins();
            self.AdjustWeights(0, -2);
            currentRound += 1;
            opponent.SetPaperReward(1);
            return;
        }
        if(opponentPlay == "S") {           //case 1: outcome 3
            //opponent.IncreaseScissorPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseWins();
            opponent.IncreaseLosses();
            self.AdjustWeights(0, 2);
            currentRound += 1;
            opponent.SetScissorReward(0);
            return;
        }
    }
    if(selfPlay == "P") {                   //case 2: 3 potential outcomes

        if(opponentPlay == "R") {           //case 2: outcome  1
            //opponent.IncreaseRockPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseWins();
            self.AdjustWeights(1, 2);
            opponent.IncreaseLosses();
            currentRound += 1;
            opponent.SetRockReward(0);
            return;
        }
        if(opponentPlay == "P") {           //case 2: outcome  2    
            //opponent.IncreasePaperPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)   

            self.IncreaseTies();
            self.AdjustWeights(1, 1);
            opponent.IncreaseTies();
            currentRound += 1;
            opponent.SetPaperReward(.75);
            return;
        }
        if(opponentPlay == "S") {           //case 2: outcome  3
            //opponent.IncreaseScissorPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseLosses();
            self.AdjustWeights(1, -2);
            opponent.IncreaseWins();
            currentRound += 1;
            opponent.SetScissorReward(1);
            return;
        }
    }
    if(selfPlay == "S") {                   //case 3: 3 potential outcomes

        if(opponentPlay == "R") {           //case 3: outcome  1
            //opponent.IncreaseRockPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)
            
            self.IncreaseLosses();
            self.AdjustWeights(2, -2);
            opponent.IncreaseWins();
            currentRound += 1;
            opponent.SetRockReward(1);
            return;
        }
        if(opponentPlay == "P") {           //case 3: outcome  2
            //opponent.IncreasePaperPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseWins();
            self.AdjustWeights(2, 2);
            opponent.IncreaseLosses();
            currentRound += 1;
            opponent.SetPaperReward(0);
            
        }
        if(opponentPlay == "S") {           //case 3: outcome  3
           // opponent.IncreaseScissorPlays() <- Goldfish doesnt update value (UCB1 does, this is the only difference)

            self.IncreaseTies();
            self.AdjustWeights(2, 1);
            opponent.IncreaseTies();
            currentRound += 1;
            opponent.SetScissorReward(.75);
            return;
        }
    }
}

void Contest::PrintRoundInfo() {

    int wins = self.GetWins();
    int ties = self.GetTies();
    int losses = self.GetLosses();

    float winPercent = static_cast<float>(wins) / currentRound * 100; 
    float tiePercent = static_cast<float>(ties) / currentRound * 100;
    float lossPercent = static_cast<float>(losses) / currentRound * 100;

    cout << endl << setprecision(3);
    cout << "\tRound #" << currentRound << endl << endl;
    cout << "Win:  " << wins << "\t\t" << winPercent << "%" << endl;
    cout << "Tied: " << ties << "\t\t" << tiePercent << "%" << endl;
    cout << "Loss: " << losses << "\t\t" << lossPercent << "%" << endl << endl;

}

void Contest::RunSimulation() {

    for (int i = 0; i < totalRounds; ++i) {

        PlayRound();
        
        if(currentRound % refreshRate == 0) {
            PrintRoundInfo();
        }
    }

    PrintResults();
}

void Contest::PrintResults() {

    int selfWins = self.GetWins();
    int selfTies = self.GetTies();
    float selfWinPer = static_cast<float>(selfWins) / currentRound * 100; 
    float selfTiePer = static_cast<float>(selfTies) / currentRound * 100;

    int oppWins = opponent.GetWins();
    int oppTies = opponent.GetTies();
    float oppWinPer = static_cast<float>(oppWins) / currentRound * 100;
    float oppTiePer = static_cast<float>(oppTies) / currentRound * 100;

    cout << "Winning Algorithm: ";

    if(self.GetWins() > opponent.GetWins()) {
        cout << "Libruh" << endl;
        cout << "Win Percentage: " << selfWinPer << "%" << endl;
        cout << "Tie Percentage: " << selfTiePer << "%" << endl << endl;

        cout << "Losing Algorithm: Goldfish" << endl;
        cout << "Win Percentage: " << oppWinPer << "%" << endl;
        cout << "Tie Percentage: " << oppTiePer << "%" << endl;
    }
    else{
        cout << "Goldfish" << endl;
        cout << "Win Percentage: " << oppWinPer << "%" << endl;
        cout << "Tie Percentage: " << oppTiePer << "%" << endl << endl;

        cout << "Losing Algorithm: Libruh" << endl;
        cout << "Win Percentage: " << selfWinPer << "%" << endl;
        cout << "Tie Percentage: " << selfTiePer << "%" << endl;
    }

}

