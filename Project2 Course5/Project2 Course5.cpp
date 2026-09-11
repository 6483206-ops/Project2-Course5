// Project2 Course5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Algorithm>

using namespace std;


enum enQLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOTybe { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };

struct stQInfo {
    int NumTheQuestion;
    float RigthAnswer;
    bool Result;
    enOTybe OT;
    enQLevel QL;
};
struct stGameInfo {
    int NumOfQuestion;
    enQLevel QuestionLevel;
    enOTybe OperationTybe;
    int NumOfRigthAnswer = 0;
    int NumOfWrongAnswer = 0;
    bool Result;
};

void Tap(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void Swap(float& num1, float& num2) {
    int t = num1;
    num1 = num2;
    num2 = t;
}

string TransToQL(int num) {
    string arr[5] = { "Easy","Med","Hard","Mix" };
    return arr[num-1];
}

string TransToOT(int num) {
    string arr[6] = { "+", "-", "*", "/", "Mix" };
    return arr[num-1];
}

int RandomNumper(int From, int To) {
    int num;
    num = rand() % (To - From + 1) + From;
    return num;
}

int AskTheUserForTheQuestion() {
    cout << "How many Question do you want to answer ? ";
    int n; cin >> n;
    return n;
}

enQLevel AskTheUserForQLevel() {
    int n;
    do {
        cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
        cin >> n;
    } while (n != 1 && n != 2 && n != 3 && n != 4);
    return (enQLevel)n;

}

enOTybe AskTheUserForOT() {
    int n;
    do {
        cout << "Enter Operation Tybe [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
        cin >> n;
        cout << "\n\n";
    } while (n != 1 && n != 2 && n != 3 && n != 4 && n != 5);
    return (enOTybe)n;
}

void ReadGameInfo(stGameInfo& Game) {
    Game.NumOfQuestion = AskTheUserForTheQuestion();
    Game.QuestionLevel = AskTheUserForQLevel();
    Game.OperationTybe = AskTheUserForOT();
}

void GenerateRandomNumpers(float& num1, float& num2, enQLevel QL) {

    switch (QL) {
    case enQLevel::Easy:
        num1 = RandomNumper(1, 20);
        num2 = RandomNumper(1, 20);
        break;
    case enQLevel::Med:
        num1 = RandomNumper(20, 60);
        num2 = RandomNumper(20, 60);
        break;
    case enQLevel::Hard:
        num1 = RandomNumper(60, 150);
        num2 = RandomNumper(60, 150);
        break;
    }
}


void PrintQuestion(int num1, int num2, enOTybe OT) {
    cout << num1 << endl;
    cout << num2 << " " << TransToOT(OT);
    cout << "\n";
    cout << "_______________" << endl;
}

void SelectTheProcesAndPrint(float num1, float num2, enOTybe OT) {

    switch (OT) {
    case enOTybe::Add:
        PrintQuestion(num1, num2, OT);
        break;
    case enOTybe::Mul:
        PrintQuestion(num1, num2, OT);
        break;
    case enOTybe::Sub:
        if (num2 > num1)
            Swap(num1, num2);
        PrintQuestion(num1, num2, OT);
        break;
    case enOTybe::Div:
        if (num2 > num1)
            Swap(num1, num2);
        PrintQuestion(num1, num2, OT);
        break;
    }
}

float AnswerOfQ(float num1, float num2, enOTybe OT) {

    switch (OT) {
    case enOTybe::Add:
        return num1 + num2;
    case enOTybe::Mul:
        return num1 * num2;
    case enOTybe::Sub:
        return (float) max(num1, num2) - min(num1, num2);
    case enOTybe::Div:
        return (float) max(num1, num2) / min(num1, num2);
    }
}
bool ResultOfQuestion(float answer,float RigthAnswer) {
    if (answer == RigthAnswer)
        return true;
    else
        return false;
}

void ProcesMixOptions(stQInfo &QI, stGameInfo &GI) {
   
    if (GI.QuestionLevel == enQLevel::Mix) {
        QI.QL = enQLevel(RandomNumper(1, 3));
    }
    if (GI.OperationTybe == enOTybe::mix) {
        QI.OT = enOTybe(RandomNumper(1, 4));
    }
}

void StartTheQuestion (stGameInfo &Game, stQInfo &QI) {
    cout << "Question " << "[" << QI.NumTheQuestion << "/" << Game.NumOfQuestion << "]" << endl;
    cout << "\n\n";
   //fill the Info about the Question From the Info about the Game "Like Operation Tybe and Question Level" 
    QI.OT = Game.OperationTybe;
    QI.QL = Game.QuestionLevel;

    float num1, num2;
    ProcesMixOptions(QI,Game);
    GenerateRandomNumpers(num1,num2,QI.QL);
    SelectTheProcesAndPrint(num1, num2, QI.OT);

    float answer;
    cin >> answer;
    QI.RigthAnswer = AnswerOfQ(num1,num2,QI.OT);

    QI.Result = ResultOfQuestion(answer, QI.RigthAnswer);
    if (QI.Result)
        Game.NumOfRigthAnswer++;
    else
        Game.NumOfWrongAnswer++;
}

void  PrintResultOfTheQuestion(stQInfo QI) {

    if (!QI.Result) {
        system("color 4F");
        cout << "Wrong Answer :-( " << endl;
        cout << "The rigth answer is : " << QI.RigthAnswer << endl;
    }
    else {
        system("color 2F");
        cout << "Rigth Answer :-)" << endl;
    }

    cout << "\n\n";

}

void FailOrBassInGame(stGameInfo &GI) {

    int SuccesLimit = GI.NumOfQuestion / 2;

    if (GI.NumOfRigthAnswer >= SuccesLimit) {
        GI.Result = true;
    }
    else
        GI.Result = false;
}

void ResultOfTheGame(stGameInfo &Game) {

    FailOrBassInGame(Game);

    cout << endl;
    cout << "________________________________________\n\n";
    if (Game.Result) {
        Tap(8);
        Tap(8);
        cout << "Final Result Is Bass\n" << endl;
        system("color 2F");
    }
    else {
        Tap(8);
        cout << "Final Result Is Fail" << endl;
        system("color 4F");
    }
    cout << "________________________________________\n\n";
    cout << "Numper Of Question : " << Game.NumOfQuestion << endl;
    cout << "Question Level     : " << TransToQL(Game.QuestionLevel) << endl;
    cout << "OPTybe             : " << TransToOT(Game.OperationTybe) << endl;
    cout << "Numper Of Rigth Answer : " << Game.NumOfRigthAnswer << endl;
    cout << "Numper Of Wrong Answer : " << Game.NumOfWrongAnswer << endl;
    cout << "________________________________________\n\n";

};

bool reStartTheGame() {
    char Answer;
    do {
        cout << "Do you want to play again Y/N ? ";
        cin >> Answer;
    } while (Answer != 'Y' && Answer != 'N' && Answer != 'y' && Answer != 'n');
    if (Answer == 'Y' || Answer == 'y')
        return true;
    else
        return false;

}

void StartTheGame() {
    do {
        system("cls");
        system("color 07");
        stGameInfo GameInfo = {};
        ReadGameInfo(GameInfo);
        for (int QNum = 1; QNum <= GameInfo.NumOfQuestion; QNum++) {
            stQInfo QI = {};
            QI.NumTheQuestion = QNum;
            StartTheQuestion(GameInfo, QI);
            PrintResultOfTheQuestion(QI);
        }

        ResultOfTheGame(GameInfo);

    }while(reStartTheGame());
}





int main()
{
    srand((unsigned)time(NULL));
    StartTheGame();

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
