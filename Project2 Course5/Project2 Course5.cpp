// Project2 Course5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


enum enQLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOTybe { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

struct stQInfo {
    int NumTheQuestion;
    bool Result;
};
struct stGameInfo {
    int NumOfQuestion;
    enQLevel QuestionLevel;
    enOTybe OperationTybe;
    int NumOfRigthAnswer;
    int NumOfWrongAnswer;
    bool Result;
};




int AskTheUserForTheQuestion() {}

void ReadQuestionInfo (int RoundNum,stQInfo &Round) {}

void StartTheQuestion(int RoundNum, stQInfo Round) {

}

void  ResultOfTheQuestion(int RoundNum, stQInfo Round) {}

void ReadGameInfo (stGameInfo Game) {}

stGameInfo ResultOfTheGame(stGameInfo Game) {};

bool reStartTheGame() {}

void StartTheGame() {
    do {
        system("cls");
        system("color F0");
        stGameInfo GameInfo = {};
        int TotalQ = AskTheUserForTheQuestion();
        for (int QNum = 1; QNum <= TotalQ; QNum++) {
            stQInfo QInfo = {};

            ReadQuestionInfo(QNum, QInfo);
            StartTheQuestion(QNum, QInfo);
            ResultOfTheQuestion(QNum, QInfo);
        }

        ReadGameInfo(GameInfo);
        ResultOfTheGame(GameInfo);

    }while(reStartTheGame());
}


int main()
{
    


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
