# 2110AgentRoyale

Description:
This collection of files includes all necessary files to compile our program, AgentRoyale. The program is a framework that will simulate a series of games of rock, paper, scissors, between two algorithms. Initially, the program will ask the user how many rounds they would like to simulate, as well as the step size. AgentRoyale will track the wins, ties, and losses between the algorithms and determine which algorithm wins the majority of the time. During the simulation, the current results will periodically be printed in accordance with the step size, and the final results will be printed at the end of the simulation. All this is implemented with three separate classes called: Self, Opponent, and Contest.

The Self and Opponent classes are essentially the copies of the same class, wherein most of the data members and functions are the same. They will each hold integer data members that track wins, losses, and ties. The main difference between these two classes is in the algorithms they contain. All the logic required of these opposing algorithms will be placed within a function called PlayRound() within their respective class. This function will output a string of either “R” | “P” | “S” that is representative of the algorithms choice of play in the given round. Should an algorithm require any additional data structures to function, these data members will be added accordingly with appropriate setter and getter functions.

The Contest class holds integer values for the total amount of rounds that the algorithms will compete, the refresh rate (both user defined variables upon program start), the current round of the contest, as well as an object of the Self class and an object of the Opponent class. The Contest class will call a function called RunSimulation() that will use a loop to continually call the PlayRound() function for both the Self and Opponent classes for the user designated number of games to be played. After each call of PlayRound(), appropriate functions will be called to adjust the values of wins, losses, and ties for both the Self and Opponent class, as well as any additional functions required to augment any necessary data structures for that particular algorithm.

After the simulation of all games is completed, the Contest class will call a function PrintResults() that will show all pertinent info from the simulation to the user. All three classes are separated into their own h and cpp files. In terms of major data structures for the project, these classes by default do not contain any. This could possibly be adjusted depending on how our members implement their desired algorithms. Should a team member’s algorithm require it, the potential data structures implemented could span from anything from graphs to vectors to store past round data to adjust what move said algorithm will play. Our modular class implementation allows for a very flexible way to implement and rapidly test various algorithms and their required data structures.

CONTRIBUTERS:
Libra Bates
Joseph Caldwell
Aishat Oyedeji

ROLES:
Joseph Caldwell assembled the framework and main.ccp file in order for all other team members to input their respective algorithms.
Libra Bates put together the Makefile
Each member is responsible for their own algorithm implementations. 

INSTRUCTIONS:
1.) Run the Makefile using the command 'make Royale'.
2.) Use the Royale excecutable to run the program (i.e. ./Royale).
3.) Provide the number of rounds to simulate
4.) Program provide the step size. This will dictate how many times the current results will be printed during the simulation
5.) Final output is provided
