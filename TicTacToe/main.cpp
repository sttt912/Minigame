#include <stdio.h>
#include <iostream>
using namespace std;

void board();
char pole[10]={'0','1','2','3','4','5','6','7','8','9'};

int main(){
    int x;
    int y;
    int stop=0;
    int player=1;
    
    while(stop!=1){
    printf("\e[1H\e[2J");
    board();
    
    if (player%2){
        cout<<"Ходить гравець 1"<<endl;
    }else{
        cout<<"Ходить гравець 2"<<endl;
    }
    cout<<"Куди поставити ваш знак:";
    cin>>x;
    if (x>9){ //перевірка на коректність уведенних данних
        cout<<"Ви увели некоректне значення клітинки:"<<endl;
        player--;
    }else{
        if(pole[x]=='X'){
            cout<<"Ви увели некоректне значення клітинки:"<<endl;
            player--;
        }else if(pole[x]=='O'){
            cout<<"Ви увели некоректне значення клітинки:"<<endl;
            player--;
        }else{
            pole[x]=(player%2)?'X':'O';
        }
    }
    
    
    player++; //додавання одного ходу
    
    if (pole[1] == pole[2] and pole[2] == pole[3]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[4] == pole[5] and pole[5] == pole[6]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[7] == pole[8] and pole[8] == pole[9]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[1] == pole[4] and pole[4] == pole[7]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[2] == pole[5] and pole[5] == pole[8]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[3] == pole[6] and pole[6] == pole[9]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[3] == pole[5] and pole[5] == pole[7]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (pole[1] == pole[5] and pole[5] == pole[9]){
        if (player%2){
            cout<<"Виграв гравець 1"<<endl;
        }else{
            cout<<"Виграв гравець 2"<<endl;
        }
    }else if (player>9){
        cout<<"Нічия"<<endl;
        break;
    }
    //Код який відповідає за закінчення гри
    cout<<"Ви хочете закінчити гру? 1 - так будь яке інше число ні";
    cin>>stop;
    
    }
    
    return 0;
}


void board(){
    cout << "Гравець 1 (X)  -  Гравець 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << pole[1] << "  |  " << pole[2] << "  |  " << pole[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << pole[4] << "  |  " << pole[5] << "  |  " << pole[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << pole[7] << "  |  " << pole[8] << "  |  " << pole[9] << endl;

    cout << "     |     |     " << endl << endl;
}

