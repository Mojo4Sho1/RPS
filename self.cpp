
#include "self.h"

string Self::PlayRound() {
   srand(time(0));

   do{
   SoftMax(weights);

   double x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
   if(x <= probability[0])
   {
    return "R";
   }
   else if(x > probability[0] && x <= (probability[0] + probability[1]))
   {
    return "P";
   }
   else if(x > (probability[0] + probability[1]) && x <= (probability[0] + probability[1] + probability[2]))
   {
    return "S";
   }
   else{
       weights.at(1) = 0;
       weights.at(0) = 0;
       weights.at(2) = 0;
       continue;
   }
   }while(1);
}

void Self::IncreaseLosses() {
    losses += 1;
}

void Self::IncreaseTies() {
    ties += 1;
}

void Self::IncreaseWins() {
    wins += 1;
}

int Self::GetWins() {
    return wins;
}

int Self::GetTies() {
    return ties;
}

int Self::GetLosses() {
    return losses;
}

void Self::SoftMax(vector<double> &weights)
{
    double probVal;
    double sum = 0;
    for(size_t i = 0; i < weights.size() -1; i++)
    {
        probVal = exp(weights.at(i));
        sum += probVal;
        probability.at(i) = probVal;
    }
    for(size_t i = 0; i < weights.size() - 1; i++)
    {
        probability.at(i) = probability.at(i)/sum;
    }
}

void Self::AdjustWeights(size_t position, double rate)
{
    weights[position] += rate;
    return;
}

Self::Self()
{
    for(int i = 0; i < 3; i++)
    {
    weights.push_back(0.0);
    probability.push_back(0.0);
    }
}
