
#include "opponent.h"

string Opponent::PlayRound() {      //UCB1 algorithm (logic is same for Goldfish Algorithm)

    unsigned int roundsPlayed = wins + ties + losses + 1;

    rockMean = rockMean + ((rockReward - rockMean) / rockPlays);
    paperMean = paperMean + ((paperReward - paperMean) / paperPlays);
    scissorMean = scissorMean + ((scissorReward - scissorMean) / scissorPlays);

    rockCon = rockMean + sqrt(2 *(log(roundsPlayed) / rockPlays));
    paperCon = paperMean + sqrt(2 *(log(roundsPlayed) / paperPlays));
    scissorsCon = scissorMean + sqrt(2 *(log(roundsPlayed) / scissorPlays));


    if(rockCon > paperCon && rockCon > scissorsCon) {
        return "R";
    }
    else if(paperCon > rockCon && paperCon > scissorsCon) {
        return "P";
    }
    else if(scissorsCon > rockCon && scissorsCon > paperCon) {
        return "S";
    }
    else {

        int number;

        number = rand() % 3;

        if(number == 0) {

            return "R";
        }
        if(number == 1) {

            return "P";
        }
        if(number == 2) {

            return "S";
        }
    }

    return ""; 
}

void Opponent::IncreaseLosses() {
    losses += 1;
}

void Opponent::IncreaseTies() {
    ties += 1;
}

void Opponent::IncreaseWins() {
    wins += 1;
}

void Opponent::IncreaseRockPlays() {
    rockPlays += 1;
}

void Opponent::IncreasePaperPlays() {
    paperPlays += 1;
}

void Opponent::IncreaseScissorPlays() {
    scissorPlays += 1;
}

int Opponent::GetWins() {
    return wins;
}

int Opponent::GetTies() {
    return ties;
}

int Opponent::GetLosses() {
    return losses;
}

void Opponent::SetRockReward(int val) {
    rockReward = val;
}

void Opponent::SetPaperReward(int val) {
    paperReward = val;
}

void Opponent::SetScissorReward(int val) {
    scissorReward = val;
}