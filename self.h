
/*
Main Algorithm submission:
Owner: Libra B.
Title of Algorithm: Libruh
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <random>
#include <time.h>
using namespace std;

class Self {

    public:
        string PlayRound();

        void IncreaseWins();
        void IncreaseTies();
        void IncreaseLosses();

        int GetWins();
        int GetTies();
        int GetLosses();
        
        void SoftMax(vector<double> &weights);
        void AdjustWeights(size_t position, double rate);
        Self();

    private:
        int wins = 0;
        int ties = 0;
        int losses = 0;

        vector<double> weights;
        vector<double> probability;
};
