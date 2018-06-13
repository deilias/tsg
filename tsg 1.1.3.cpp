//
//
//               THE SURVIVAL GAME IN C++
//
//
/*=====================INFORMATION======================
A basic survival game made in C++ by Goat.

CODE INFORMATION:
Language: C++
Using: Basic console
Type: Single console application

GAME INFORMATION:
Type: Survival

======================================================*/
//
//
//
// DEVELOPER PLACE uwu
// -----------------------------------------------------------
// CURRENT GOAL:
//
// Make 'aCount' increase when gained a new achivement.
// Make save feature.
//
//
//
//
//
// -----------------------------------------------------------
//
// this game is play to use and can be modified as long
// you don't change the name "Goat" at any purpose, thanks!
//
// MADE WITH <3 AND EFFORT!
//
//
//

//The game starts here

// include library

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>
using namespace std; //i know, using "using namespace std;" is a bad practice, still trying to get over it lol

//variables

int health = 100;
int day;
char selectd;
int money = 100;
char selectdShop;
int gunPower = 5;
int potion = 3;
int bomb = 2;
int zombie;
char actOnActive;
int pDamage;
int zDamage;
int healthLose;
string dayCompletePhrase[5] = {"Congratulations!", "You win!", "Stage cleared!", "No more zombie!", "Finally it's over!"};
int dayCompletePhraseNumber;
bool debug = false;
string debugPasswordSecurityPrompt;
bool hasAchivement = false;
double zombieKilled;
int lostHP;

//achivement variables
int aCount; // show how much achivement do you have
            // this guy right there

        //achivement booleans
        bool aKilledOver100Zombie;
        bool aUpgradedGunToLevel00;
        bool aSurvivedFor20Days;
        bool aCheatActivated;
        bool a;


// functions

void showAchivement() {
    if(aCount>=1) {
      hasAchivement == true;

    };
    if(hasAchivement==false) {
        cout << endl;
        cout << "You currently do not have any achivement!" << endl;
        }
    else {
        cout << endl;
        cout << "Your achivements: \n";


        cout << "Your achivements: \n" << endl;
        if(aKilledOver100Zombie==true) {
            cout << "☆ Killed over 100 zombies \n";
        };

        if(aUpgradedGunToLevel00==true) {
            cout << "☆ Upgraded gun to level 100 \n";
        };

        if(aSurvivedFor20Days==true) {
            cout << "☆ Survived for 20 days \n";
        };

        if(aCheatActivated==true) {
            cout << "☆ CHEAT ACTIVATED! \n";
        };

        cout << "☆ You currently have " << aCount << " achivements. ☆ \n";
        };
    }

void showStatistic() {
    cout << "You have killed " << zombieKilled << " zombie(s)." << endl;
    cout << "You have totally lost " << lostHP << " HP." << endl;;
    cout << "You have survived for " << day << " day(s)." << endl;

    }

void gameReset() {
    cout << "Resetting game data...";
                money = 100;
                potion = 3;
                bomb = 2;
                day = 0;
                debug = false;
                hasAchivement = false;
    zombieKilled = 0;
    lostHP = 0;
    cout << " COMPLETE!";
    system("cls");
    }

void shop() {

    //this is shop
    cout << endl;
    if(debug==true) {
        cout << "You have: " << bomb << " bombs and " << potion << " healing potions left." << endl;
        cout << "Your gun power level is " << gunPower << endl;
        };
    cout << "Welcome to the shop! \nPlease choose what item you want to buy! \n";
    cout << "You have $" << money << endl;
    cout << "1: Upgrade Gun(50$ each upgrade) \n2: Healing potion($10) \n3: Bomb($20) \n> ";
    cin >> selectdShop;
    switch(selectdShop)
    {
        case '1':
        if(money>=50) {
        gunPower = gunPower + 2;
        money = money - 50;
        cout << "Gun upgraded!" << endl;
            }
        else {
        cout << "Not enough money!" << endl;
            };
        break;

        case '2':
        if(money>=10) {
        potion = potion + 1;
        money = money - 10;
        cout << "Purchase completed! You now have " << potion << " healing potion(s)!" << endl;
            }
        else {
        cout << "Not enough money!" << endl;
            };
        break;

        case '3':
        if(money>=20) {
        bomb = bomb + 1;
        money = money - 20;
        cout << "Purchase completed! You now have " << bomb << " bomb(s)!";
            }
        else {
        cout << "Not enough money!" << endl;
            };
        break;

        default:
        break;
        break;

    };
    }

void gameOnActive() {
    system("cls");
    zombie = rand() % 100 + 50;
    //game starts here
    cout << endl;

    while(health>=0 && zombie > 0) {

        cout << "There are " << zombie << " zombies trying to eat you! Choose what to do! \n";
        cout << "You have " << health << " HP left." << endl;
        cout << "1: Shoot those zombies! \n2: Use healing potion! (You currently have " << potion << " potion(s), heal 50 HP each use!) \n3: Use bomb on them! (You currently have " << bomb << " bomb(s)!) \n4: Wait for attacks... \n> ";
        cin >> actOnActive;
        cout << endl;
        switch(actOnActive)
        {
            case '1':
            zDamage = rand() % gunPower;
            zombie = zombie - zDamage;
            if(zDamage!=0) {
            cout << "G E T S H O T ! \nZombies turn!" << endl;
                if(zombie<-1) {zombie = 0;};
                }
            else {
            cout << "Oh no, missed! \nZombies turn!" << endl;
                };
            pDamage = rand() % 30;
            health = health - pDamage;
            cout << "You lose " << pDamage << " HP!" << endl;

            break;

            case '2':
            if(potion>0) {
            health = health + 50;
            potion = potion - 1;
            cout << "You healed 50 HP! \nZombies turn!" << endl;
                if(zombie<-1) {zombie = 0;};
                }
            else {
            cout << "There is no potion for you to use! \nZombies turn" << endl;
                };
            pDamage = rand() % zombie;
            health = health - pDamage;
            cout << "You lose " << pDamage << " HP!" << endl;
            break;

            case '3':
            if(bomb>0) {
            zDamage = rand() % 30 + 10;
            zombie = zombie - zDamage;
            if(zombie<-1) {zombie = 0;};
            bomb = bomb - 1;
            cout << "YES! KILLED SO MANY ZOMBIES! \nZombies turn!" << endl;
            }
            else {
            cout << "There is no bomb for you to use! \nZombies turn!" << endl;
                };
            pDamage = rand() % zombie;
            health = health - pDamage;
            cout << "You lose " << pDamage << " HP!" << endl;
            break;

            case '4':
            cout << "Zombies turn!" << endl;
            pDamage = rand() % zombie;
            health = health - pDamage;
            cout << "You lose " << pDamage << " HP!" << endl;
            break;
        };
        if(debug==true) {
            cout << "Zombie: " << zombie << endl;
            cout << "zDamage: " << zDamage << endl;
            cout << "pDamage: " << pDamage << endl;
            cin.get();
            cout << endl;
            };
            zombieKilled = zombieKilled + zDamage;
            lostHP = lostHP + pDamage;

    };
    if(zombie<=0) {
        dayCompletePhraseNumber = rand() % 4;
        cout << dayCompletePhrase[dayCompletePhraseNumber] << endl;
        day = day + 1;
        money = money + (rand() % 100 + 10);
    };
    system("cls");
} string debugPasswordSecurityActivityHolder = "debugGetListenerActivity";
void if3isSelected() {
    cout << "Thanks for playing!";
    //exit (code = 0)
    exit(0);
    }

void seeInventory() {
    //see the invertory
    cout << endl;
    cout << "Your inventory has: \n";
    cout << bomb << " bomb(s)." << endl;
    cout << potion << " healing potion(s);" << endl;
    cout << "Gun power level " << gunPower << endl;
    if(debug==true) {
    cout << "You have survived " << day << " day(s)." << endl;
    cout << "You have " << health << " HP left.";
        };
    cout << endl;

    }
void debugMode() {
    if(debug==false) {
        debug = true;
        cout << endl << "DEBUG/ADVANCED MODE IS ON." << endl;
        }
    else {
        debug = false;
        cout << endl << "DEBUG/ADVANCED MODE IS OFF." << endl;
        };

    }
void debugSecurity() {
    if(debug==false) {
        cout << endl << "DEBUG/ADVANCED MODE, NOT FOR INEXPERIENCE PLAYER" << endl;
        cout << "PLEASE TYPE IN THE ADMINSTRATOR PASSWORD TO ENABLE THIS FEATURE: ";
        cin >> debugPasswordSecurityPrompt;
            if(debugPasswordSecurityPrompt==debugPasswordSecurityActivityHolder) {
                    debugMode();
                }
            else {
                    cout << "WRONG PASSWORD!" << endl;
                };
            }
    else {
        debugMode();
        };
    }

void selector() {
            switch(selectd)
            {
                case '1':
                if(debug==true) {
            cout << endl << endl;
            cout << "-----------------DEBUG------------------- \n";
            };
                shop();
                cin.get();
                break;

                case '2':
                cout << "Game is starting! Get ready!";
                gameOnActive();
                cin.get();
                break;

                case '4':
                showAchivement();
                cin.get();
                break;

                case '6':
                if3isSelected();
                cin.get();
                break;

                case '3':
                seeInventory();
                cin.get();
                break;

                case '5':
                showStatistic();
                cin.get();
                break;

                case 'd':
                debugSecurity();
                cin.get();
                break;

                case 'p':
                if(debug==false) {
                cout << "Wrong input!" << endl;
                    }
                else {
                    money = 99999;
                potion = 99999;
                bomb = 99999;
                gunPower = 99999;
                cout << "Cheat Activated!" << endl;
                cin.get();
                    };
                break;

                case 'r':
                gameReset();
                break;

                default:
                cout << "Wrong input!" << endl;
                break;
            };
    }

    //main root
int main() {

    cout << "You will get 100$, 3 healing potions and 2 bombs as starter, good luck!" << endl;
    Sleep(2000);
    system("cls");

    while(health>=0) {
            srand(( unsigned )time( 0 ) * 100 );
        //achivement stuff
            if(zombieKilled>=100) {
              aKilledOver100Zombie = true;
            };

        //eof

        health = 100;
        if(debug==true) {
            cout << endl << endl;
            cout << "-----------------DEBUG------------------- \nType 'd' to exit debug mode \n";
            };
            cout << endl;
            cout << "Day " << day + 1 << endl;
            cout << "You have $" << money << endl;
            cout << "What to do?" << endl;
            cout << "Please type the desired number to act!" << endl;
            cout << "1: Go to shop \n2: Go to your base \n3: See inventory \n4: See Achivements \n5: See Statistics \n6: Quit";
            if(debug==true) {
                cout << "\nd: Exit debug mode \np: Cheat \nr: Reset data";
                };
            cout << endl << "> ";
            cin >> selectd;
            selector();
        };

        system("cls");
        cout << "You died!" << endl;

    if(debug==true) {
        cout << "SUMMARY: \nYou have: " << bomb << " bombs (3) and " << potion << " healing potions (2) left." << endl;
        cout << "Your gun power level is" << gunPower << endl;
        };
    if(day<=1) {
    cout << "You've survived for " << day << " day!" << endl;
    cout << "Thanks for playing!";
        }
    else {
        cout << "You've survived for " << day << " days!" << endl;
        cout << "Thanks for playing!";

    };
    getch();

}

//the game ends here
