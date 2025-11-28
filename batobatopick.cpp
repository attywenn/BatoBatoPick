#include <iostream>
#include <random>
#include <vector>
#include <limits>
using namespace std;

int main () {
    int min = 1, max = 3;
    vector<string> username;
    vector<string> password;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    int randomValue = distrib(gen);
    int choice;
    string un, pw;
    bool found_un=false, found_pw =false;
    int choiceBBP;
    int score = 0;
    int attempt = 10;
    int round = 1;
    
    do {    
        cout << "===>Bato-bato pick game<==="<< endl;
        cout<<">> MAIN MENU" <<endl
            <<"1. Start a game: "<<endl
            <<"2. Create profile"<<endl
            <<"3. Exit program"<<endl;
        cin>>choice;


        if (choice == 1) {
                cout<<"Who are you? "<<endl;
                do {
                    cout<<"Enter your username: "; cin>>un;
                    cout<<"Enter your password: "; cin>>pw;

                    for (string find_un : username) {
                        if (un == find_un) {
                            found_un = true;
                            break;
                        } 
                    } 
                    for (string find_pw : password) {
                        if (pw == find_pw) {
                            found_pw = true;
                            break;
                        }
                    }
                    if (found_un && found_pw) {
                        cout<<"You were successfully logged in!"<<endl; 
                        cout<<"Welcome, "<<un<<"!"<<endl;

                        // game starts
                        do {
                            cout<<"Round "<<round<<", fight!"<<endl;
                            int randomValue = distrib(gen);
                            cout<<"Enter your bet: "<<endl
                            <<"(1) para sa Bato"<<endl
                            <<"(2) para sa Papel"<<endl
                            <<"(3) para sa Gunting"<<endl
                            <<"(0) para umexit ka na g."<<endl;
                            cin>>choiceBBP;
                            cout<<endl;
                            
                            bool u_win = false;
                            bool bot_win = false;
                            bool kwits = false;
                            
                            if ((choiceBBP == 1 && randomValue == 3) || (choiceBBP == 2 && randomValue == 1) || (choiceBBP == 3 && randomValue == 2)) u_win = true;
                            if ((choiceBBP == 3 && randomValue == 1) || (choiceBBP == 1 && randomValue == 2) || (choiceBBP == 2 && randomValue == 3)) bot_win = true;
                            if ((choiceBBP == 1 && randomValue == 1) || (choiceBBP == 2 && randomValue == 2) || (choiceBBP == 3 && randomValue == 3)) kwits = true;
                            
                            string bet;
                            if (choiceBBP == 1) { bet = "Bato"; }
                            else if (choiceBBP == 2) { bet = "Papel"; }
                            else if (choiceBBP == 3) { bet = "Gunting"; }
                            
                            string bot_bet;
                            if (randomValue == 1) { bot_bet = "Bato"; }
                            else if (randomValue == 2) { bot_bet = "Papel"; }
                            else if (randomValue == 3) { bot_bet = "Gunting"; }
                            
                            if (u_win) {
                                cout<<"You win!"<<endl;
                                cout<<"You won with "<<bet<<" against "<<bot_bet<<endl;
                                score+=1;
                                cout<<"Score: "<<score<<endl;
                            } else if (bot_win) {
                                cout<<"You lose!"<<endl;
                                cout<<"Score: "<<score<<endl;
                                cout<<"You lose with "<<bet<<" against "<<bot_bet<<endl;
                            } else if (kwits) {
                                round-=1;
                                cout<<"Kwits kayo!" <<endl;
                                cout<<"Score: "<<score<<endl;
                                cout<<"You bet with "<<bet<<" against "<<bot_bet<<endl;
                            } else if (choiceBBP > 3) {
                                round-=1;
                                cout<<"Invalid."<<endl;
                            }
                            
                            round+=1;
                            if (round == 10) {
                                cout<<"===//GAME OVER//==="<<endl;
                                if (score>6) {
                                    cout<<">>>>>> [Wency's MESSAGE] Magaling ka, "<<un<<"! Tinalo mo si ADMIN WENXX!"<<endl;
                                } else {
                                    cout<<">>>>>> [Wency's MESSAGE] aahahahahahah talo"<<endl;
                                }
                                round=1;
                                cout<<endl;
                                break;
                            }

                            
                            
                        } while (choiceBBP!=0 || round != 10);
                    } else {
                        cout<<"No accounts were found."<<endl;
                    }
                    break;
                } while (1);


            } else if (choice == 2) {
                cout<<"Create profile"<<endl
                <<"Create username: "; cin>>un;
                username.push_back(un);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Create password: "; cin >> pw;
                password.push_back(pw);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout<<"You're all set!";
        }
        else if (choice == 3) {
                cout<<"Thank you! Come back again!"<<endl;
                return 0;
        }
    } while (1);
    return 0;
    
}