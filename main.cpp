/*  
    Authors:        Joseph Caldwell
                    Libra Bates
                    Aishat Oyedeji
    Date:           12/05/2022                   
    Instructor:     Curtis Chambers
    Description:    CSCE 2110: Project 2 - Agent Royale: Main
    
*/

#include <iostream>
#include "contest.h"

using namespace std;

int main() {

    srand(time(0));     //random num generator seed

    Contest contest;

    contest.IntializeGame();
    contest.RunSimulation(); 


    return 0;
}