#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int RollaDice(int a){// function that emitates a dice roll
    int dice1, dice2;
    srand(time(0));// to get totally random numbers
    dice1 = rand()% 6 + 1;//rolling dice 1
    dice2 = rand()% 6 + 1;//rolling dice 2
    cout << "dice1 = " << dice1 << "  dice2 = " << dice2 << endl;
    if ((dice1 + dice2 == 7) || (dice1 + dice2 == 11)){// probably you win in 8 cases of 36
            cout << "You won it!"<< endl;
            return 1;// means that you won
    }else if((dice1 + dice2 == 2) || (dice1 + dice2 == 3) || (dice1 + dice2 == 12)){//probably you lose in 4 cases of 36
            cout << "You lost it!" << endl;
            return -1;// means you lost
    }else{// probably draw in 24 cases of 36
        cout << "It is draw!" << endl;
        return 0;// means it is a draw
    }

}

double ChangeBet(int money){// this function allows you to change your bet
    cout << "Now input your new bet"<< endl;
    double newbet;// to have more various input

    while(1){// you will enter a correct bet!
        cin >> newbet;
        if((newbet - trunc(newbet) != 0) || (newbet < 1)){// bad number input error
            cout << "Bet can be only a positive integer number no less than 1" << endl;
            continue;
        }else if(newbet > money){// you can't bet more than you have
            cout << "Sorry, but you can't bet more than you have" << endl;
            continue;
        }else{// bet is correct
            break;
        }
    }
    return(newbet);
}
void Menu(int money, int bet, int type){// this function types menu in 2 variants
    cout << "Now you have " << money << "$ and your current bet is " << bet << "$" << endl;
    if(type == 1){// if you need whole menu
        cout << "You can:" << endl;
        cout << "Roll dices , press r or R" << endl;
        cout << "Change your bet , press b or B" << endl;
        cout << "Check menu, press m or M" << endl;
        cout << "Quit the casino, press q or Q" << endl;
    }
    cout << "Now choose your action" << endl;

}


int main()
{
    int bet, money;
    string command;
    money = 100;// actually you can change this parameter to have more money at start
    bet = money / 10;
    cout << "Welcome to Casino!" << endl;
    cout << "Here you can become incredibly rich! " << endl;
    Menu(money, bet, 1);// starting menu output
    while(money > 0){
        cin >> command;// what will you do now?
        if((command == "m") || (command == "M")){// just type menu
            Menu(money, bet, 1);// whole menu output
            continue;
        }else if((command == "b") || (command == "B")){// change a bet
            bet = ChangeBet(money);
            Menu(money, bet, 0);// only current menu output
            continue;
        }else if((command == "q") || (command == "Q")){// really want to take your money?
            break;
        }else if((command == "r") || (command == "R")){// the most interesting pat of the game!
            money += bet * RollaDice(1);// rolling returns a win/lose coficient
            if(money >= 10){// bet reset
                bet = 10;
            }else{
                bet = money;
            }
            Menu(money, bet, 0);
            continue;
        }else{// you will behave yourself good, won't you?
            cout << "Enter correct command please" << endl;
        }
    }
    if(money == 0){// sorry!
        cout << "You have no more money to continue playing!" << endl;
        cout << "Next time you will be more lucky!" << endl;
    }else{// at least you have something!
        cout << "You leave the casino with " << money << "$ in your wallet!" << endl;
    }
    cout << "Goodbye!" << endl;// Have a nice day!
    cout << "Return to us later!" << endl;// really, why don't you play it again?
    return 0;
}
