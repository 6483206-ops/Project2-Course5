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

int RandomNumper(int From, int To) {
    int num;
    num = rand() % (To - From + 1) + From;
    return num;
}

string TransToQL(int num) {
    string arr[5] = { "Easy","Med","Hard","Mix" };
    return arr[num];
}

string TransToOT(int num) {
    string arr[6] = { "Add", "Sub", "Mul", "Div", "Mix" };
    return arr[num];
}

int AskTheUserForTheQuestion() {
    cout << "How many Question do you want to answer ? ";
    int n; cin >> n;
    return n;
}

enQLevel AskTheUserForQLevel() {
    int n;
    cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
    cin >> n;
    return (enQLevel)n;

}

enOTybe AskTheUserForOT() {
    int n;
    cout << "Enter Operation Tybe [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
    cin >> n;
    return (enOTybe)n;
}



void StartTheQuestion(stGameInfo Game, int QNum) {
    cout << "Question " << "[" << QNum << "/" << Game.NumOfQuestion << "]" << endl;
    cout << "\n\n";


}

void  ResultOfTheQuestion(int RoundNum, stQInfo Round) {}

void ReadGameInfo (stGameInfo &Game) {
    Game.NumOfQuestion = AskTheUserForTheQuestion();
    Game.QuestionLevel = AskTheUserForQLevel();
    Game.OperationTybe = AskTheUserForOT();
}

stGameInfo ResultOfTheGame(stGameInfo Game) {};

bool reStartTheGame() {}

void StartTheGame() {
    do {
        system("cls");
        system("color F0");
        stGameInfo GameInfo = {};
        ReadGameInfo(GameInfo);
        for (int QNum = 1; QNum <= GameInfo.NumOfQuestion; QNum++) {
           
            StartTheQuestion(GameInfo, QNum);
            ResultOfTheQuestion(QNum, QInfo);
        }

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
