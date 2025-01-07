#include <iostream>
#include <ctime>
#include <limits>

using namespace std;

void drawBoard(char *pSpace, bool emptyBoard);
void playerMove(char *pSpace, char player);
void computerMove(char *pSpace, char computer);

char checkWinner(char *pSpace, char player, char computer){
    char win = ' ';
    if(pSpace[0] != ' ' && pSpace[0] == pSpace[1] && pSpace[0] == pSpace[2]){
        win = pSpace[0];
    } else if(pSpace[3] != ' ' && pSpace[3] == pSpace[4] && pSpace[3] == pSpace[5]){
        win = pSpace[3];
    } else if(pSpace[6] != ' ' && pSpace[6] == pSpace[7] && pSpace[6] == pSpace[8]){
        win = pSpace[6];
    } else if(pSpace[0] != ' ' && pSpace[0] == pSpace[3] && pSpace[0] == pSpace[6]){
        win = pSpace[0];
    } else if(pSpace[1] != ' ' && pSpace[1] == pSpace[4] && pSpace[1] == pSpace[7]){
        win = pSpace[1];
    } else if(pSpace[2] != ' ' && pSpace[2] == pSpace[5] && pSpace[2] == pSpace[8]){
        win = pSpace[2];
    } else if(pSpace[2] != ' ' && pSpace[2] == pSpace[5] && pSpace[2] == pSpace[8]){
        win = pSpace[2];
    } else if(pSpace[0] != ' ' && pSpace[0] == pSpace[4] && pSpace[0] == pSpace[8]){
        win = pSpace[0];
    } else if(pSpace[2] != ' ' && pSpace[2] == pSpace[4] && pSpace[2] == pSpace[6]){
        win = pSpace[2];
    }
    return win;
}

bool checkTie(char *pSpace){
    for(int i = 0; i < 9; i++){
        if(pSpace[i] == ' '){
           return false;
        }
    }
    return true;
}

bool moving(int turn, char *pSpace, char player, char computer){
    bool running = true;
    char win = ' ';
    bool tie = false;

    if(turn == 0){
        playerMove(pSpace, player);
        win = checkWinner(pSpace, player, computer);
        tie = checkTie(pSpace);
    } else {
        computerMove(pSpace, computer);
        drawBoard(pSpace, false);
        win = checkWinner(pSpace, player, computer);
        tie = checkTie(pSpace);

    }
    if(win == player){
        running = false;
        cout << "You won!!!";
    } else if(win == computer){
        running = false;
        cout << "Computer won!!!";
    } else if(tie){
        running = false;
        cout << "There was a tie!!!";
    }
    return running;
}

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;
    drawBoard(spaces, true);
    while(running){
        running = moving(0, spaces, player, computer);
        running = moving(1, spaces, player, computer);
    }
    cout << "Hope you liked the game.";
    return 0;
}

void drawBoard(char *pSpace, bool emptyBoard){
    cout << endl;
    if(emptyBoard){
        cout << "     |     |     " <<  endl;
        cout << "  1  |  2  |  3  " <<  endl;
        cout << "_____|_____|_____" <<  endl;
        cout << "     |     |     " <<  endl;
        cout << "  4  |  5  |  6  " <<  endl;
        cout << "_____|_____|_____" <<  endl;
        cout << "     |     |     " <<  endl;
        cout << "  7  |  8  |  9  " <<  endl;
        cout << "     |     |     " <<  endl;
    } else {
        cout << "     |     |     " <<  endl;
        cout << "  " << pSpace[0] << "  |  " << pSpace[1] << "  |  " << pSpace[2] << "  " <<  endl;
        cout << "_____|_____|_____" <<  endl;
        cout << "     |     |     " <<  endl;
        cout << "  " << pSpace[3] << "  |  " << pSpace[4] << "  |  " << pSpace[5] << "  " <<  endl;
        cout << "_____|_____|_____" <<  endl;
        cout << "     |     |     " <<  endl;
        cout << "  " << pSpace[6] << "  |  " << pSpace[7] << "  |  " << pSpace[8] << "  " <<  endl;
        cout << "     |     |     " <<  endl;
    }
    cout << endl;
}
void playerMove(char *pSpace, char player){
    int number;
    bool finished = false;

    cout << "Type a number between 1-9, where you want to place your X ";
    cin >> number;

    while (!finished){
        if(!cin.good()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "You didn't choose a number. Choose again: ";
            cin >> number;

        } else {
            if(number > 10 || number < 0){
                cout << "You didn't choose between 1-9. Choose again: ";
                cin >> number;

            } else {
                number--;
                if(pSpace[number] == ' '){
                    finished = true;
                    pSpace[number] = player;
                } else {
                    cout << "This spot is occupied. Choose again: ";
                    cin >> number;
                }
            }
        }
    }
}
void computerMove(char *pSpace, char computer){
    int number;
    srand(time(0));
    while(true){
        number = rand() % 9;
        if(pSpace[number] == ' '){
            pSpace[number] = computer;
            break;
        }
    }
}
