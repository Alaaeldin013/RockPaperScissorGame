
#include <iostream>
using namespace std;

int ReadRounds()
{
    int Rounds;

    cout << "How many rounds do you want to play: ";
    cin >> Rounds;

    return Rounds;
}

int ReadChoices()
{
    int Choice;

    cout << "\nEnter your choice -> [1]Rock | [2]Paper | [3]Scissor : ";
    cin >> Choice;

    return Choice;
}

int ComputerRandomChoice(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;

    return Random;
}

string ChiocesFromNumToStr(int Choice)
{
    switch (Choice)
    {
    case 1:
    {
        return "Rock";
        break;
    }
    case 2:
    {
        return "Paper";
        break;
    }
    case 3:
    {
        return "Scissor";
        break;
    }

    }
}

string TheWinner(int PlayerChoice, int ComputerChoice)
{
    if (ComputerChoice == 1 && PlayerChoice == 3)
    {
        return "Computer";
    }
    else if (ComputerChoice == 3 && PlayerChoice == 2)
    {
        return "Computer";
    }
    else if (ComputerChoice == 2 && PlayerChoice == 1)
    {
        return "Computer";
    }
    else if (ComputerChoice == PlayerChoice)
    {
        return "Draw";
    }
    else
    {
        return "Player";
    }
}

void WinningCounter(string TheWinner, int& PlayerScore, int& ComputerScore, int& Draws)
{
    if (TheWinner == "Player")
    {
        PlayerScore++;
        system("color 27");
    }
    else if (TheWinner == "Computer")
    {
        ComputerScore++;
        cout << "\a";
        system("color 47");  
    }
    else
    {
        Draws++;
        system("color 07");
    }
}

void RoundResult(string TheWinner, int NumberOfRounds, int PlayerChoice, int ComputerChoice)
{
    string PlayerC = ChiocesFromNumToStr(PlayerChoice);
    string ComputerC = ChiocesFromNumToStr(ComputerChoice);
    cout << "\n____________________ Round(" << NumberOfRounds << ") ____________________" << endl;
    cout << "Player    Choice: " << PlayerC << endl;
    cout << "Computer  Choice: " << ComputerC << endl;
    cout << "The Round Winner: " << TheWinner << endl;
    cout << "___________________________________________________" << endl;
}

void GameResult(int NumberOFRounds, int PlayerScore, int ComputerScore, int Draws)
{
    string FinalWinner;

    if (PlayerScore > ComputerScore)
    {
        FinalWinner = "Player";
        system("color 27");
    }
    else if (PlayerScore < ComputerScore)
    {
        FinalWinner = "Computer";
        system("color 47");
    }
    else
    {
        FinalWinner = "Draw";
        system("color 07");
    }

    cout << "\n\n\t\t\t__________________________________________________________" << endl;
    cout << "\n\t\t\t\t\t+++ G a m e  O v e r +++" << endl;
    cout << "\t\t\t__________________________________________________________" << endl;
    cout << "\t\t\t____________________ {Game Result} _______________________" << endl;
    cout << "\t\t\tGame Rounds       : " << NumberOFRounds << endl;
    cout << "\t\t\tPlayer   won times: " << PlayerScore <<  endl;
    cout << "\t\t\tComputer won times: " << ComputerScore << endl;
    cout << "\t\t\tDraw times        : " << Draws << endl;
    cout << "\t\t\tFinal Winner      : " << FinalWinner <<endl;
    cout << "\t\t\t__________________________________________________________\n\n\n" << endl;

}

void TheGame()
{
   
    bool Again = false;
    char YesOrNo;
    do {
        system("cls");
        system("color 07");
        int PlayerScore = 0, ComputerScore = 0, Draws = 0;
        int NumberOfRounds = ReadRounds();

        for (int i = 1; i <= NumberOfRounds; i++)
        {
            cout << "\nRound [" << i << "] :";
            int PlayerChoice = ReadChoices();
            int ComputerChoice = ComputerRandomChoice(1, 3);
            string Winner = TheWinner(PlayerChoice, ComputerChoice);

            WinningCounter(Winner, PlayerScore, ComputerScore, Draws);
            RoundResult(Winner, i, PlayerChoice, ComputerChoice);
        }
       
        GameResult(NumberOfRounds, PlayerScore, ComputerScore, Draws);

        {
            cout << "Do You Want to play Again -> Yes[Y] | No[N] : ";
            cin >> YesOrNo;

            if (YesOrNo == 'Y' || YesOrNo == 'y')
            {
                Again = true;
            }
            else
            {
                Again = false;
            }
        }

    } while (Again);


}


int main()
{
    srand((unsigned)time(NULL));

   
   
    TheGame();
   

}

