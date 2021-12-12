#include "playwindow.h"
#include "ui_playwindow.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <QDebug>
#include <QList>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QDialog>

// headers for regame
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playwindow.h"

using namespace std;
using std::stack;

std::vector<int> deckVector;
std::vector<int> userVector;
std::vector<int> computerVector;
stack<int> boardStack1;
stack<int> boardStack2;
stack<int> boardStack3;
stack<int> boardStack4;
stack<int> storeStack;

int player_current = 0;
int computer_current = 0;
int computer_total = 0;
int player_total =0 ;
int bulls = 0 ;
int penalty=0;

// variable that stores num of hand
int handCount = 0;

int Getbulls(int a)
{
    if (a % 5 == 0){
             bulls=2;
         } else if (a % 10 == 0) {
             bulls=3;
         } else if (a % 11 == 0) {
            if(a==55)
            {
               bulls=7;
                     }
            else
            {
             bulls=5;
            }

         } else {
             bulls=1;
         }
    return bulls;
}

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/table.png");
    this->statusBar()->setSizeGripEnabled(false);
    this->setFixedSize(800,500);

    ui-> card1Label_10 ->installEventFilter(this);
    ui-> card2Label_10 ->installEventFilter(this);
    ui-> card3Label_10 ->installEventFilter(this);
    ui-> card4Label_10 ->installEventFilter(this);
    ui-> card5Label_10 ->installEventFilter(this);
    ui-> card6Label_10 ->installEventFilter(this);
    ui-> card7Label_2 ->installEventFilter(this);
    ui-> card8Label_2 ->installEventFilter(this);
    ui-> card9Label_2 ->installEventFilter(this);
    ui-> card10Label_2 ->installEventFilter(this);

    ui-> cl_1_6 ->installEventFilter(this);
    ui-> cl_2_6 ->installEventFilter(this);
    ui-> cl_3_6 ->installEventFilter(this);
    ui-> cl_4_6 ->installEventFilter(this);

    loadList();
    at_start();

    ui->Directions->setVisible(true);
    ui->Directions2->setVisible(false);

    // labels for prompt popup
    ui-> promptLabel ->installEventFilter(this);
    ui-> RegameButton ->installEventFilter(this);
    ui->promptLabel->hide();
    // labels for end of game popup
    ui -> endGameWidget -> hide();
}


//computer_choice 에서 사용한 vector 삭제 해버리기
int computer_choice(){

    int choice_index=0; //computer의 choice(최종 return 값)

    //stack 사이즈가 저장된 vector 만들기 stacks_size
    vector<int> stacks_size;
    stacks_size.push_back(boardStack1.size());
    stacks_size.push_back(boardStack2.size());
    stacks_size.push_back(boardStack3.size());
    stacks_size.push_back(boardStack4.size());

    //각 열의 가장 마지막 카드들을 저장하기 last_cards
    vector<int> last_cards;
    last_cards.push_back(boardStack1.top()+1);
    last_cards.push_back(boardStack2.top()+1);
    last_cards.push_back(boardStack3.top()+1);
    last_cards.push_back(boardStack4.top()+1);

    //table 위의 각 열에 대한 정보 넣기(row_info, key: 몇 번 째 열인지, value: 열 사이즈)
    map <int, int> row_info;
    int i;
    for (i = 0; i < 4; i += 1)
    {
        row_info.insert(pair<int, int>(i, stacks_size[i]));
    }

    //열의 사이즈와 마지막 카드를 비교하면서 짧으면서도 크기가 작은 열 찾기
    int shortest_row = 0; //가장 짧은 열의 index
    int shortest_last = 200; //가장 짧은 열의 마지막 카드
    for (i = 0; i < 4; i += 1)
    {
        if(row_info[i] >= row_info[shortest_row])
        {
            if(shortest_last > last_cards[i])
            {
                shortest_last = last_cards[i];
                shortest_row = i;
            }
        }
    }

    //computer의 카드들을 card_map이라는 map에 저장하기
    map<int, int> card_map;
    for (i = 0; i < computerVector.size(); i += 1)
    {
        card_map.insert(pair<int, int>(i, computerVector[i]));
    }

    //컴퓨터가 들고 있는 카드 중에 해당 열에 들어갈 수 있는 가장 작은 카드 찾기
    int min_choice = 200;

    for (i = 0; i < card_map.size(); i++) {
        if (shortest_last < card_map[i])
        {
            if (card_map[i] < min_choice)
            {
                min_choice = card_map[i];
                choice_index = i;  //최종 return 값
            }

        }
    }

    return choice_index;
}

void card_remove(int index)
{
   computerVector.erase(computerVector.begin() + index);


}

// function that displays total pts
void displayPts() {
    // exit game if hand = 0
    if (handCount == 10){
        // afterwards exit game
        QApplication::quit();
        }
}

int com_choose_row()
{
    int min=0;
    int min_i=0;
    for(int i=0;i<4;i++)
        if(i==1)
        {
            for(int j=0;i<boardStack1.size();j++)
            {

                int temp=boardStack1.top();
                storeStack.push(temp);
                boardStack1.pop();
                penalty+=Getbulls(temp);


            }

            for(int i=0;i<storeStack.size();i++)
            {
                int temp=storeStack.top();
                boardStack1.push(temp);
                storeStack.pop();
            }
            min=penalty;
            min_i=1;
        }
        else if(i==2)
        {
            penalty=0;
            for(int j=0;i<boardStack2.size();j++)
            {

                int temp=boardStack2.top();
                storeStack.push(temp);
                boardStack2.pop();
                penalty+=Getbulls(temp);


            }

            for(int i=0;i<storeStack.size();i++)
            {
                int temp=storeStack.top();
                boardStack2.push(temp);
                storeStack.pop();
            }
            if (penalty<min)
            {
                min=penalty;
                min_i=2;
            }else{
                min=min;
                min_i=min_i;
            }
        }
        else if(i==3)
        {
            penalty=0;
            for(int j=0;i<boardStack3.size();j++)
            {

                int temp=boardStack3.top();
                storeStack.push(temp);
                boardStack3.pop();
                penalty+=Getbulls(temp);


            }

            for(int i=0;i<storeStack.size();i++)
            {
                int temp=storeStack.top();
                boardStack3.push(temp);
                storeStack.pop();
            }
            if (penalty<min)
            {
                min=penalty;
                min_i=3;
            }else{
                min=min;
                min_i=min_i;
            }
        }
        else
        {
            penalty=0;
            for(int j=0;i<boardStack4.size();j++)
            {

                int temp=boardStack4.top();
                storeStack.push(temp);
                boardStack4.pop();
                penalty+=Getbulls(temp);


            }

            for(int i=0;i<storeStack.size();i++)
            {
                int temp=storeStack.top();
                boardStack4.push(temp);
                storeStack.pop();
            }
            if (penalty<min)
            {
                min=penalty;
                min_i=4;
            }else{
                min=min;
                min_i=min_i;
            }
        }
    return min_i;

}
// declaring global variables

// load cards
void PlayWindow::loadList(){

    // Clear List
    cardHolder.clear();

    // Load in blue cards
    QPixmap card1(":/images/images/cards/b1.png");
    QPixmap card2(":/images/images/cards/b2.png");
    QPixmap card3(":/images/images/cards/b3.png");
    QPixmap card4(":/images/images/cards/b4.png");
    QPixmap card6(":/images/images/cards/b6.png");
    QPixmap card7(":/images/images/cards/b7.png");
    QPixmap card8(":/images/images/cards/b8.png");
    QPixmap card9(":/images/images/cards/b9.png");
    QPixmap card12(":/images/images/cards/b12.png");
    QPixmap card13(":/images/images/cards/b13.png");
    QPixmap card14(":/images/images/cards/b14.png");
    QPixmap card16(":/images/images/cards/b16.png");
    QPixmap card17(":/images/images/cards/b17.png");
    QPixmap card18(":/images/images/cards/b18.png");
    QPixmap card19(":/images/images/cards/b19.png");
    QPixmap card21(":/images/images/cards/b21.png");
    QPixmap card23(":/images/images/cards/b23.png");
    QPixmap card24(":/images/images/cards/b24.png");
    QPixmap card26(":/images/images/cards/b26.png");
    QPixmap card27(":/images/images/cards/b27.png");
    QPixmap card28(":/images/images/cards/b28.png");
    QPixmap card29(":/images/images/cards/b29.png");
    QPixmap card31(":/images/images/cards/b31.png");
    QPixmap card32(":/images/images/cards/b32.png");
    QPixmap card34(":/images/images/cards/b34.png");
    QPixmap card36(":/images/images/cards/b36.png");
    QPixmap card37(":/images/images/cards/b37.png");
    QPixmap card38(":/images/images/cards/b38.png");
    QPixmap card39(":/images/images/cards/b39.png");
    QPixmap card41(":/images/images/cards/b41.png");
    QPixmap card42(":/images/images/cards/b42.png");
    QPixmap card43(":/images/images/cards/b43.png");
    QPixmap card46(":/images/images/cards/b46.png");
    QPixmap card47(":/images/images/cards/b47.png");
    QPixmap card48(":/images/images/cards/b48.png");
    QPixmap card49(":/images/images/cards/b49.png");
    QPixmap card51(":/images/images/cards/b51.png");
    QPixmap card52(":/images/images/cards/b52.png");
    QPixmap card53(":/images/images/cards/b53.png");
    QPixmap card54(":/images/images/cards/b54.png");
    QPixmap card56(":/images/images/cards/b56.png");
    QPixmap card57(":/images/images/cards/b57.png");
    QPixmap card58(":/images/images/cards/b58.png");
    QPixmap card59(":/images/images/cards/b59.png");
    QPixmap card61(":/images/images/cards/b61.png");
    QPixmap card62(":/images/images/cards/b62.png");
    QPixmap card63(":/images/images/cards/b63.png");
    QPixmap card64(":/images/images/cards/b64.png");
    QPixmap card67(":/images/images/cards/b67.png");
    QPixmap card68(":/images/images/cards/b68.png");
    QPixmap card69(":/images/images/cards/b69.png");
    QPixmap card71(":/images/images/cards/b71.png");
    QPixmap card72(":/images/images/cards/b72.png");
    QPixmap card73(":/images/images/cards/b73.png");
    QPixmap card74(":/images/images/cards/b74.png");
    QPixmap card76(":/images/images/cards/b76.png");
    QPixmap card78(":/images/images/cards/b78.png");
    QPixmap card79(":/images/images/cards/b79.png");
    QPixmap card81(":/images/images/cards/b81.png");
    QPixmap card82(":/images/images/cards/b82.png");
    QPixmap card83(":/images/images/cards/b83.png");
    QPixmap card84(":/images/images/cards/b84.png");
    QPixmap card86(":/images/images/cards/b86.png");
    QPixmap card87(":/images/images/cards/b87.png");
    QPixmap card89(":/images/images/cards/b89.png");
    QPixmap card91(":/images/images/cards/b91.png");
    QPixmap card92(":/images/images/cards/b92.png");
    QPixmap card93(":/images/images/cards/b93.png");
    QPixmap card94(":/images/images/cards/b94.png");
    QPixmap card96(":/images/images/cards/b96.png");
    QPixmap card97(":/images/images/cards/b97.png");
    QPixmap card98(":/images/images/cards/b98.png");
    QPixmap card101(":/images/images/cards/b101.png");
    QPixmap card102(":/images/images/cards/b102.png");
    QPixmap card103(":/images/images/cards/b103.png");
    QPixmap card104(":/images/images/cards/b104.png");

    // Load in green cards
    QPixmap card5(":/images/images/cards/g5.png");
    QPixmap card15(":/images/images/cards/g15.png");
    QPixmap card25(":/images/images/cards/g25.png");
    QPixmap card35(":/images/images/cards/g35.png");
    QPixmap card45(":/images/images/cards/g45.png");
    QPixmap card65(":/images/images/cards/g65.png");
    QPixmap card75(":/images/images/cards/g75.png");
    QPixmap card85(":/images/images/cards/g85.png");
    QPixmap card95(":/images/images/cards/g95.png");

    // Load in yellow cards
    QPixmap card10(":/images/images/cards/y10.png");
    QPixmap card20(":/images/images/cards/y20.png");
    QPixmap card30(":/images/images/cards/y30.png");
    QPixmap card40(":/images/images/cards/y40.png");
    QPixmap card50(":/images/images/cards/y50.png");;
    QPixmap card60(":/images/images/cards/y60.png");
    QPixmap card70(":/images/images/cards/y70.png");
    QPixmap card80(":/images/images/cards/y80.png");
    QPixmap card90(":/images/images/cards/y90.png");
    QPixmap card100(":/images/images/cards/y100.png");

    // Load in pink cards
    QPixmap card11(":/images/images/cards/p11.png");
    QPixmap card22(":/images/images/cards/p22.png");
    QPixmap card33(":/images/images/cards/p33.png");
    QPixmap card44(":/images/images/cards/p44.png");
    QPixmap card66(":/images/images/cards/p66.png");
    QPixmap card77(":/images/images/cards/p77.png");
    QPixmap card88(":/images/images/cards/p88.png");
    QPixmap card99(":/images/images/cards/p99.png");

    // Load in the red card
    QPixmap card55(":/images/images/cards/r55.png");

    // add all cards to List
    cardHolder.append(card1);
    cardHolder.append(card2);
    cardHolder.append(card3);
    cardHolder.append(card4);
    cardHolder.append(card5);
    cardHolder.append(card6);
    cardHolder.append(card7);
    cardHolder.append(card8);
    cardHolder.append(card9);
    cardHolder.append(card10);
    cardHolder.append(card11);
    cardHolder.append(card12);
    cardHolder.append(card13);
    cardHolder.append(card14);
    cardHolder.append(card15);
    cardHolder.append(card16);
    cardHolder.append(card17);
    cardHolder.append(card18);
    cardHolder.append(card19);
    cardHolder.append(card20);
    cardHolder.append(card21);
    cardHolder.append(card22);
    cardHolder.append(card23);
    cardHolder.append(card24);
    cardHolder.append(card25);
    cardHolder.append(card26);
    cardHolder.append(card27);
    cardHolder.append(card28);
    cardHolder.append(card29);
    cardHolder.append(card30);
    cardHolder.append(card31);
    cardHolder.append(card32);
    cardHolder.append(card33);
    cardHolder.append(card34);
    cardHolder.append(card35);
    cardHolder.append(card36);
    cardHolder.append(card37);
    cardHolder.append(card38);
    cardHolder.append(card39);
    cardHolder.append(card40);
    cardHolder.append(card41);
    cardHolder.append(card42);
    cardHolder.append(card43);
    cardHolder.append(card44);
    cardHolder.append(card45);
    cardHolder.append(card46);
    cardHolder.append(card47);
    cardHolder.append(card48);
    cardHolder.append(card49);
    cardHolder.append(card50);
    cardHolder.append(card51);
    cardHolder.append(card52);
    cardHolder.append(card53);
    cardHolder.append(card54);
    cardHolder.append(card55);
    cardHolder.append(card56);
    cardHolder.append(card57);
    cardHolder.append(card58);
    cardHolder.append(card59);
    cardHolder.append(card60);
    cardHolder.append(card61);
    cardHolder.append(card62);
    cardHolder.append(card63);
    cardHolder.append(card64);
    cardHolder.append(card65);
    cardHolder.append(card66);
    cardHolder.append(card67);
    cardHolder.append(card68);
    cardHolder.append(card69);
    cardHolder.append(card70);
    cardHolder.append(card71);
    cardHolder.append(card72);
    cardHolder.append(card73);
    cardHolder.append(card74);
    cardHolder.append(card75);
    cardHolder.append(card76);
    cardHolder.append(card77);
    cardHolder.append(card78);
    cardHolder.append(card79);
    cardHolder.append(card80);
    cardHolder.append(card81);
    cardHolder.append(card82);
    cardHolder.append(card83);
    cardHolder.append(card84);
    cardHolder.append(card85);
    cardHolder.append(card86);
    cardHolder.append(card87);
    cardHolder.append(card88);
    cardHolder.append(card89);
    cardHolder.append(card90);
    cardHolder.append(card91);
    cardHolder.append(card92);
    cardHolder.append(card93);
    cardHolder.append(card94);
    cardHolder.append(card95);
    cardHolder.append(card96);
    cardHolder.append(card97);
    cardHolder.append(card98);
    cardHolder.append(card99);
    cardHolder.append(card100);
    cardHolder.append(card101);
    cardHolder.append(card102);
    cardHolder.append(card103);
    cardHolder.append(card104);
}


PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::at_start() {
    for (unsigned int i = 0; i < 103 ; ++i)
       deckVector.push_back(i+1);
    std::random_shuffle(deckVector.begin() , deckVector.end());

   ui->card1Label_10->setPixmap(cardHolder.at(deckVector[0]-1));
   userVector.push_back(deckVector[0]);
   ui->card2Label_10->setPixmap(cardHolder.at(deckVector[1]-1));
   userVector.push_back(deckVector[1]);
   ui->card3Label_10->setPixmap(cardHolder.at(deckVector[2]-1));
   userVector.push_back(deckVector[2]);
   ui->card4Label_10->setPixmap(cardHolder.at(deckVector[3]-1));
   userVector.push_back(deckVector[3]);
   ui->card5Label_10->setPixmap(cardHolder.at(deckVector[4]-1));
   userVector.push_back(deckVector[4]);
   ui->card6Label_10->setPixmap(cardHolder.at(deckVector[5]-1));
   userVector.push_back(deckVector[5]);
   ui->card7Label_2->setPixmap(cardHolder.at(deckVector[6]-1));
   userVector.push_back(deckVector[6]);
   ui->card8Label_2->setPixmap(cardHolder.at(deckVector[7]-1));
   userVector.push_back(deckVector[7]);
   ui->card9Label_2->setPixmap(cardHolder.at(deckVector[8]-1));
   userVector.push_back(deckVector[8]);
   ui->card10Label_2->setPixmap(cardHolder.at(deckVector[9]-1));
   userVector.push_back(deckVector[9]);

   // computer's deck
   computerVector.push_back(deckVector[10]);
   computerVector.push_back(deckVector[11]);
   computerVector.push_back(deckVector[12]);
   computerVector.push_back(deckVector[13]);
   computerVector.push_back(deckVector[14]);
   computerVector.push_back(deckVector[15]);
   computerVector.push_back(deckVector[16]);
   computerVector.push_back(deckVector[17]);
   computerVector.push_back(deckVector[18]);
   computerVector.push_back(deckVector[19]);
   // make computer's hand not show on board

   // store 4 cards on board in each board vector
   ui->cl_1_1->setPixmap(cardHolder.at(deckVector[20]-1));
   boardStack1.push(deckVector[20]);
   ui->cl_2_1->setPixmap(cardHolder.at(deckVector[21]-1));
   boardStack2.push(deckVector[21]);
   ui->cl_3_1->setPixmap(cardHolder.at(deckVector[22]-1));
   boardStack3.push(deckVector[22]);
   ui->cl_4_1->setPixmap(cardHolder.at(deckVector[23]-1));
   boardStack4.push(deckVector[23]);


}

int compare_two_Card_player()
{
    int dif=104;
    int difi=0;
        if (boardStack1.top() >player_current)
        {
            dif = 104;
            difi = 0;
        }
        else
        {
            dif =  player_current - boardStack1.top();
            difi = 1;
        }

        if (boardStack2.top() >player_current)
        {
            dif = dif;
            difi = difi;
        }
        else
        {
            if(player_current-boardStack2.top() < dif)
            {
                dif= player_current - boardStack2.top();
                difi = 2;
            }
            else
            {
                dif = dif;
                difi = difi;
            }
        }

        if (boardStack3.top() >player_current)
        {           dif = dif;
                    difi = difi;
        }
        else
        { // boardStack3.top < computer_current
            if(player_current- boardStack3.top() <dif)
            {
                dif= player_current - boardStack3.top() ;
                difi = 3;
            }
            else
            {
                dif = dif;
                difi = difi;
            }
        }

        if (boardStack4.top() >player_current)
        {
            dif = dif;
            difi = difi;
        }
        else
        {
            if(player_current -boardStack4.top() < dif)
            {
                dif= player_current- boardStack4.top();
                difi = 4;
            }
            else
            {
                dif = dif;
                difi = difi;
            }
        }
        return difi;
}
int compare_two_Card_computer()
{
    int c_dif=104;
    int c_difi=0;
        if (boardStack1.top() >computer_current)
        {
            c_dif = 104;
            c_difi = 0;
        }
        else
        {
            c_dif =  computer_current - boardStack1.top() ;
            c_difi = 1;
        }
        if (boardStack2.top() >computer_current)
        {
            c_dif = c_dif;
            c_difi = c_difi;
        }
        else
        {
            if(computer_current-boardStack2.top() < c_dif)
            {
                c_dif=computer_current- boardStack2.top();
                c_difi = 2;
            }
            else
            {
                c_dif = c_dif;
                c_difi = c_difi;
            }
        }
        if (boardStack3.top() >computer_current)
        {
            c_dif = c_dif;
            c_difi = c_difi;
        }
        else
        { // boardStack3.top < computer_current
            if(computer_current- boardStack3.top() <c_dif)
            {
                c_dif=computer_current- boardStack3.top() ;
                c_difi = 3;
            }
            else
            {
                c_dif = c_dif;
                c_difi = c_difi;
            }
        }
        if (boardStack4.top() >computer_current)
        {
            c_dif = c_dif;
            c_difi = c_difi;
        }
        else
        {
        if(computer_current -boardStack4.top() <c_dif)
            {
                c_dif=computer_current- boardStack4.top();
                c_difi = 4;
            }
            else
            {
                c_dif = c_dif;
                c_difi = c_difi;
            }
        }
        return c_difi;
}
bool PlayWindow::eventFilter(QObject *watched, QEvent *event)
{

    if(watched == ui-> card1Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card1Label_10;
        int a = userVector[0];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);
        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }

    }
    if(watched == ui-> card2Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card2Label_10;
        int a = userVector[1];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->tableLabel_2->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card3Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card3Label_10;
        int a = userVector[2];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);
        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card4Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card4Label_10;
        int a = userVector[3];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_6->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card5Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card5Label_10;
        int a = userVector[4];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card6Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card6Label_10;
        int a = userVector[5];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_7->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);


        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card7Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card7Label_2;
        int a = userVector[6];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_4->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card8Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card8Label_2;
        int a = userVector[7];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card9Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card9Label_2;
        int a = userVector[8];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card3Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);

        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }
    if(watched == ui-> card10Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card10Label_2;
        int a = userVector[9];
        int c ;
        c = computer_choice();
        computer_current = computerVector[c];
        //ui->card4Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a));
        player_current = a;
        computerTurn();
        card_remove(c);


        // increment hand
        handCount ++;
        cout << handCount << endl;
        // display total pts
        if (handCount == 10) {
            ui -> playerBullsLabel_3 -> setText(
              tr("Your Bulls: %1").arg(player_total));
            ui -> comBullsLabel_3 -> setText(
              tr("Computer's Bulls: %1").arg(computer_total));
            // declares winnner
            if (player_total < computer_total) {
                ui->decWinnerLabel_3->setText("You are the winner!");
            } else {
                ui->decWinnerLabel_3->setText("The Computer is the winner!");
            }
            // show end of game buttons
            ui -> endGameWidget -> show();
        }
    }

    int c_difi = 0;
    int c_dif = 104;
    if(watched == ui-> cl_1_6 && event->type() == QMouseEvent::MouseButtonPress)
    {
        ui->Directions->setVisible(true);
        ui->Directions2->setVisible(false);
        ui->cl_1_6->setText("");
        ui->cl_2_6->setText("");
        ui->cl_3_6->setText("");
        ui->cl_4_6->setText("");
        if(boardStack1.size()==1)
        {
            ui->cl_1_1->clear();
        }
        else if(boardStack1.size()==2)
        {
            ui->cl_1_1->clear();
            ui->cl_1_2->clear();
        }
        else if(boardStack1.size()==3)
        {
            ui->cl_1_1->clear();
            ui->cl_1_2->clear();
            ui->cl_1_3->clear();
        }
        else if(boardStack1.size()==4)
        {
            ui->cl_1_1->clear();
            ui->cl_1_2->clear();
            ui->cl_1_3->clear();
            ui->cl_1_4->clear();
        }
        else if(boardStack1.size()==5)
        {
            ui->cl_1_1->clear();
            ui->cl_1_2->clear();
            ui->cl_1_3->clear();
            ui->cl_1_4->clear();
            ui->cl_1_5->clear();
        }
        while(false == boardStack1.empty())
        {
            int temp=boardStack1.top();
            player_total+=Getbulls(temp);
            boardStack1.pop();
        }
        ui->cl_1_1->setPixmap(cardHolder.at(player_current-1));
        boardStack1.push(player_current);
        ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
        if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
        {
            int rand_com;
            rand_com=com_choose_row();
            if (rand_com==1)
            {
                if (boardStack1.size()==1)
                {
                    ui->cl_1_1->clear();
                }
                else if(boardStack1.size()==2)
                {
                    ui->cl_1_2->clear();
                    ui->cl_1_2->clear();
                }
                else if(boardStack1.size()==3)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                }
                else if(boardStack1.size()==4)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                }
                else
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                    ui->cl_1_5->clear();
                }
                ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack1.empty())
                {
                    int temp=boardStack1.top();
                    computer_total+=Getbulls(temp);
                    boardStack1.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack1.push(computer_current);
            }
            else if(rand_com==2)
            {
                if (boardStack2.size()==1)
                {
                    ui->cl_2_1->clear();
                }
                else if(boardStack2.size()==2)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                }
                else if(boardStack2.size()==3)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                }
                else if(boardStack2.size()==4)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                }
                else
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                    ui->cl_2_5->clear();
                }
                ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack2.empty())
                {
                    int temp=boardStack2.top();
                    computer_total+=Getbulls(temp);
                    boardStack2.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack2.push(computer_current);
            }
            else if(rand_com==3)
            {
                if (boardStack3.size()==1)
                {
                    ui->cl_3_1->clear();
                }
                else if(boardStack3.size()==2)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                }
                else if(boardStack3.size()==3)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                }
                else if(boardStack3.size()==4)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                }
                else
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                    ui->cl_3_5->clear();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                while(false == boardStack3.empty())
                {
                    int temp=boardStack3.top();
                    computer_total+=Getbulls(temp);
                    boardStack3.pop();
                }

                ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                boardStack3.push(computer_current);
            }
            else
            {
                if (boardStack4.size()==1)
                {
                    ui->cl_4_1->clear();
                }
                else if(boardStack4.size()==2)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                }
                else if(boardStack4.size()==3)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                }
                else if(boardStack4.size()==4)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                }
                else
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                    ui->cl_4_5->clear();
                }
                ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack4.empty())
                {
                    int temp=boardStack4.top();
                    computer_total+=Getbulls(temp);
                    boardStack4.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack4.push(computer_current);
            }
        }
        else
        {
            c_difi=compare_two_Card_player();

            if(c_difi==1)
            {
                if (boardStack1.size() == 1){
                    ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 2){
                    ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 3)
                {
                    ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 4)
                {
                    ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_1_1 ->clear();
                    ui->cl_1_2 -> clear();
                    ui->cl_1_3 ->clear();
                    ui->cl_1_4 -> clear();
                    ui->cl_1_5->clear();
                    while(false == boardStack1.empty())
                         {
                             int temp=boardStack1.top();
                             player_total+=Getbulls(temp);
                             boardStack1.pop();
                         }
                    ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack1.push(computer_current);
            }
            else if(c_difi==2)
            {
                if (boardStack2.size() == 1)
                {
                    ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 2)
                {
                    ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 3)
                {
                    ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 4)
                {
                    ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_2_1 ->clear();
                    ui->cl_2_2 -> clear();
                    ui->cl_2_3 ->clear();
                    ui->cl_2_4 -> clear();
                    ui->cl_2_5->clear();
                    while(false == boardStack2.empty())
                    {
                        int temp=boardStack2.top();
                        player_total+=Getbulls(temp);
                        boardStack2.pop();
                    }
                    ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack2.push(computer_current);
        }
            else if(c_difi==3)
            {
                if (boardStack3.size() == 1)
                {
                    ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 2)
                {
                    ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 3)
                {
                    ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 4)
                {
                    ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_3_1 ->clear();
                    ui->cl_3_2 -> clear();
                    ui->cl_3_3 ->clear();
                    ui->cl_3_4 -> clear();
                    ui->cl_3_5->clear();
                    while(false == boardStack3.empty())
                    {
                        int temp=boardStack3.top();
                        player_total+=Getbulls(temp);
                        boardStack3.pop();
                    }
                    ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack3.push(computer_current);
            }
            else if(c_difi ==4)
            {
                if (boardStack4.size() == 1)
                {
                    ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 2)
                {
                    ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 3)
                {
                    ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 4)
                {
                    ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_4_1 ->clear();
                    ui->cl_4_2 -> clear();
                    ui->cl_4_3 ->clear();
                    ui->cl_4_4 -> clear();
                    ui->cl_4_5->clear();
                    while(false == boardStack4.empty())
                    {
                        int temp=boardStack4.top();
                        player_total+=Getbulls(temp);
                        boardStack4.pop();
                    }
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                    ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                }
                boardStack4.push(computer_current);
            }
        }

        }

    if(watched == ui-> cl_2_6 && event->type() == QMouseEvent::MouseButtonPress)
    {
        ui->Directions->setVisible(true);
        ui->Directions2->setVisible(false);
        ui->cl_1_6->setText("");
        ui->cl_2_6->setText("");
        ui->cl_3_6->setText("");
        ui->cl_4_6->setText("");
        if(boardStack2.size()==1)
        {
            ui->cl_2_1->clear();


        }
        else if(boardStack2.size()==2)
        {
            ui->cl_2_1->clear();
            ui->cl_2_2->clear();


        }
        else if(boardStack2.size()==3)
        {
            ui->cl_2_1->clear();
            ui->cl_2_2->clear();
            ui->cl_2_3->clear();



        }
        else if(boardStack2.size()==4)
        {
            ui->cl_2_1->clear();
            ui->cl_2_2->clear();
            ui->cl_2_3->clear();
            ui->cl_2_4->clear();
        }
        else if(boardStack2.size()==5)
        {
            ui->cl_2_1->clear();
            ui->cl_2_2->clear();
            ui->cl_2_3->clear();
            ui->cl_2_4->clear();
            ui->cl_2_5->clear();
        }
        while(false == boardStack2.empty())
        {
            int temp=boardStack2.top();
            player_total+=Getbulls(temp);
            boardStack2.pop();
        }
        ui->cl_2_1->setPixmap(cardHolder.at(player_current-1));
        boardStack2.push(player_current);
        ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
        if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
        {
            int rand_com;
            rand_com=com_choose_row();
            if (rand_com==1)
            {
                if (boardStack1.size()==1)
                {
                    ui->cl_1_1->clear();
                }
                else if(boardStack1.size()==2)
                {
                    ui->cl_1_2->clear();
                    ui->cl_1_2->clear();
                }
                else if(boardStack1.size()==3)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                }
                else if(boardStack1.size()==4)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                }
                else
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                    ui->cl_1_5->clear();
                }
                ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack1.empty())
                {
                    int temp=boardStack1.top();
                    computer_total+=Getbulls(temp);
                    boardStack1.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack1.push(computer_current);
            }
            else if(rand_com==2)
            {
                if (boardStack2.size()==1)
                {
                    ui->cl_2_1->clear();
                }
                else if(boardStack2.size()==2)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                }
                else if(boardStack2.size()==3)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                }
                else if(boardStack2.size()==4)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                }
                else
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                    ui->cl_2_5->clear();
                }
                ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack2.empty())
                {
                    int temp=boardStack2.top();
                    computer_total+=Getbulls(temp);
                    boardStack2.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack2.push(computer_current);
            }
            else if(rand_com==3)
            {
                if (boardStack3.size()==1)
                {
                    ui->cl_3_1->clear();
                }
                else if(boardStack3.size()==2)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                }
                else if(boardStack3.size()==3)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                }
                else if(boardStack3.size()==4)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                }
                else
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                    ui->cl_3_5->clear();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                while(false == boardStack3.empty())
                {
                    int temp=boardStack3.top();
                    computer_total+=Getbulls(temp);
                    boardStack3.pop();
                }

                ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                boardStack3.push(computer_current);
            }
            else
            {
                if (boardStack4.size()==1)
                {
                    ui->cl_4_1->clear();
                }
                else if(boardStack4.size()==2)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                }
                else if(boardStack4.size()==3)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                }
                else if(boardStack4.size()==4)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                }
                else
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                    ui->cl_4_5->clear();
                }
                ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack4.empty())
                {
                    int temp=boardStack4.top();
                    computer_total+=Getbulls(temp);
                    boardStack4.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack4.push(computer_current);
            }
        }
        else
        {
            c_difi=compare_two_Card_player();

            if(c_difi==1)
            {
                if (boardStack1.size() == 1){
                    ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 2){
                    ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 3)
                {
                    ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 4)
                {
                    ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_1_1 ->clear();
                    ui->cl_1_2 -> clear();
                    ui->cl_1_3 ->clear();
                    ui->cl_1_4 -> clear();
                    ui->cl_1_5->clear();
                    while(false == boardStack1.empty())
                         {
                             int temp=boardStack1.top();
                             player_total+=Getbulls(temp);
                             boardStack1.pop();
                         }
                    ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack1.push(computer_current);
            }
            else if(c_difi==2)
            {
                if (boardStack2.size() == 1)
                {
                    ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 2)
                {
                    ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 3)
                {
                    ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 4)
                {
                    ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_2_1 ->clear();
                    ui->cl_2_2 -> clear();
                    ui->cl_2_3 ->clear();
                    ui->cl_2_4 -> clear();
                    ui->cl_2_5->clear();
                    while(false == boardStack2.empty())
                    {
                        int temp=boardStack2.top();
                        player_total+=Getbulls(temp);
                        boardStack2.pop();
                    }
                    ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack2.push(computer_current);
        }
            else if(c_difi==3)
            {
                if (boardStack3.size() == 1)
                {
                    ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 2)
                {
                    ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 3)
                {
                    ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 4)
                {
                    ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_3_1 ->clear();
                    ui->cl_3_2 -> clear();
                    ui->cl_3_3 ->clear();
                    ui->cl_3_4 -> clear();
                    ui->cl_3_5->clear();
                    while(false == boardStack3.empty())
                    {
                        int temp=boardStack3.top();
                        player_total+=Getbulls(temp);
                        boardStack3.pop();
                    }
                    ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack3.push(computer_current);
            }
            else if(c_difi ==4)
            {
                if (boardStack4.size() == 1)
                {
                    ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 2)
                {
                    ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 3)
                {
                    ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 4)
                {
                    ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_4_1 ->clear();
                    ui->cl_4_2 -> clear();
                    ui->cl_4_3 ->clear();
                    ui->cl_4_4 -> clear();
                    ui->cl_4_5->clear();
                    while(false == boardStack4.empty())
                    {
                        int temp=boardStack4.top();
                        player_total+=Getbulls(temp);
                        boardStack4.pop();
                    }
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                    ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                }
                boardStack4.push(computer_current);
            }
        }

       }

    if(watched == ui-> cl_3_6 && event->type() == QMouseEvent::MouseButtonPress)
    {
        ui->Directions->setVisible(true);
        ui->Directions2->setVisible(false);
        ui->cl_1_6->setText("");
        ui->cl_2_6->setText("");
        ui->cl_3_6->setText("");
        ui->cl_4_6->setText("");
        if(boardStack3.size()==1)
        {
            ui->cl_3_1->clear();

        }
        else if(boardStack3.size()==2)
        {
            ui->cl_3_1->clear();
            ui->cl_3_2->clear();

        }
        else if(boardStack3.size()==3)
        {
            ui->cl_3_1->clear();
            ui->cl_3_2->clear();
            ui->cl_3_3->clear();

        }
        else if(boardStack3.size()==4)
        {
            ui->cl_3_1->clear();
            ui->cl_3_2->clear();
            ui->cl_3_3->clear();
            ui->cl_3_4->clear();

        }
        else if(boardStack3.size()==5)
        {
            ui->cl_3_1->clear();
            ui->cl_3_2->clear();
            ui->cl_3_3->clear();
            ui->cl_3_4->clear();
            ui->cl_3_5->clear();

        }
        while(false == boardStack3.empty())
        {
            int temp=boardStack3.top();
            player_total+=Getbulls(temp);
            boardStack3.pop();

        }
        ui->cl_3_1->setPixmap(cardHolder.at(player_current-1));
        boardStack3.push(player_current);
        ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
        if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
        {
            int rand_com;
            rand_com=com_choose_row();
            if (rand_com==1)
            {
                if (boardStack1.size()==1)
                {
                    ui->cl_1_1->clear();
                }
                else if(boardStack1.size()==2)
                {
                    ui->cl_1_2->clear();
                    ui->cl_1_2->clear();
                }
                else if(boardStack1.size()==3)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                }
                else if(boardStack1.size()==4)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                }
                else
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                    ui->cl_1_5->clear();
                }
                ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack1.empty())
                {
                    int temp=boardStack1.top();
                    computer_total+=Getbulls(temp);
                    boardStack1.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack1.push(computer_current);
            }
            else if(rand_com==2)
            {
                if (boardStack2.size()==1)
                {
                    ui->cl_2_1->clear();
                }
                else if(boardStack2.size()==2)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                }
                else if(boardStack2.size()==3)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                }
                else if(boardStack2.size()==4)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                }
                else
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                    ui->cl_2_5->clear();
                }
                ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack2.empty())
                {
                    int temp=boardStack2.top();
                    computer_total+=Getbulls(temp);
                    boardStack2.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack2.push(computer_current);
            }
            else if(rand_com==3)
            {
                if (boardStack3.size()==1)
                {
                    ui->cl_3_1->clear();
                }
                else if(boardStack3.size()==2)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                }
                else if(boardStack3.size()==3)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                }
                else if(boardStack3.size()==4)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                }
                else
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                    ui->cl_3_5->clear();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                while(false == boardStack3.empty())
                {
                    int temp=boardStack3.top();
                    computer_total+=Getbulls(temp);
                    boardStack3.pop();
                }

                ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                boardStack3.push(computer_current);
            }
            else
            {
                if (boardStack4.size()==1)
                {
                    ui->cl_4_1->clear();
                }
                else if(boardStack4.size()==2)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                }
                else if(boardStack4.size()==3)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                }
                else if(boardStack4.size()==4)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                }
                else
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                    ui->cl_4_5->clear();
                }
                ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack4.empty())
                {
                    int temp=boardStack4.top();
                    computer_total+=Getbulls(temp);
                    boardStack4.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack4.push(computer_current);
            }
        }
        else
        {
            c_difi=compare_two_Card_player();

            if(c_difi==1)
            {
                if (boardStack1.size() == 1){
                    ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 2){
                    ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 3)
                {
                    ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 4)
                {
                    ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_1_1 ->clear();
                    ui->cl_1_2 -> clear();
                    ui->cl_1_3 ->clear();
                    ui->cl_1_4 -> clear();
                    ui->cl_1_5->clear();
                    while(false == boardStack1.empty())
                         {
                             int temp=boardStack1.top();
                             player_total+=Getbulls(temp);
                             boardStack1.pop();
                         }
                    ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack1.push(computer_current);
            }
            else if(c_difi==2)
            {
                if (boardStack2.size() == 1)
                {
                    ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 2)
                {
                    ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 3)
                {
                    ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 4)
                {
                    ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_2_1 ->clear();
                    ui->cl_2_2 -> clear();
                    ui->cl_2_3 ->clear();
                    ui->cl_2_4 -> clear();
                    ui->cl_2_5->clear();
                    while(false == boardStack2.empty())
                    {
                        int temp=boardStack2.top();
                        player_total+=Getbulls(temp);
                        boardStack2.pop();
                    }
                    ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack2.push(computer_current);
        }
            else if(c_difi==3)
            {
                if (boardStack3.size() == 1)
                {
                    ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 2)
                {
                    ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 3)
                {
                    ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 4)
                {
                    ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_3_1 ->clear();
                    ui->cl_3_2 -> clear();
                    ui->cl_3_3 ->clear();
                    ui->cl_3_4 -> clear();
                    ui->cl_3_5->clear();
                    while(false == boardStack3.empty())
                    {
                        int temp=boardStack3.top();
                        player_total+=Getbulls(temp);
                        boardStack3.pop();
                    }
                    ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack3.push(computer_current);
            }
            else if(c_difi ==4)
            {
                if (boardStack4.size() == 1)
                {
                    ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 2)
                {
                    ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 3)
                {
                    ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 4)
                {
                    ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_4_1 ->clear();
                    ui->cl_4_2 -> clear();
                    ui->cl_4_3 ->clear();
                    ui->cl_4_4 -> clear();
                    ui->cl_4_5->clear();
                    while(false == boardStack4.empty())
                    {
                        int temp=boardStack4.top();
                        player_total+=Getbulls(temp);
                        boardStack4.pop();
                    }
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                    ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                }
                boardStack4.push(computer_current);
            }
        }


      //어차피 사용자가 덱 10개중에 택하면 또 computerturn으로 돌아감

    }
    if(watched == ui-> cl_4_6 && event->type() == QMouseEvent::MouseButtonPress)
    {
        ui->Directions->setVisible(true);
        ui->Directions2->setVisible(false);
        ui->cl_1_6->setText("");
        ui->cl_2_6->setText("");
        ui->cl_3_6->setText("");
        ui->cl_4_6->setText("");
        if(boardStack4.size()==1)
        {
            ui->cl_4_1->clear();

        }
        else if(boardStack4.size()==2)
        {
            ui->cl_4_1->clear();
            ui->cl_4_2->clear();

        }
        else if(boardStack4.size()==3)
        {
            ui->cl_4_1->clear();
            ui->cl_4_2->clear();
            ui->cl_4_3->clear();
        }

        else if(boardStack4.size()==4)
        {
            ui->cl_4_1->clear();
            ui->cl_4_2->clear();
            ui->cl_4_3->clear();
            ui->cl_4_4->clear();
        }

        else if(boardStack4.size()==5)
        {
            ui->cl_4_1->clear();
            ui->cl_4_2->clear();
            ui->cl_4_3->clear();
            ui->cl_4_4->clear();
            ui->cl_4_5->clear();

        }
        while(false == boardStack4.empty())
        {
            int temp=boardStack4.top();
            player_total+=Getbulls(temp);
            boardStack4.pop();

        }
        ui->cl_4_1->setPixmap(cardHolder.at(player_current-1));
        boardStack4.push(player_current);
        ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));

        if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
        {
            int rand_com;
            rand_com=com_choose_row();
            if (rand_com==1)
            {
                if (boardStack1.size()==1)
                {
                    ui->cl_1_1->clear();
                }
                else if(boardStack1.size()==2)
                {
                    ui->cl_1_2->clear();
                    ui->cl_1_2->clear();
                }
                else if(boardStack1.size()==3)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                }
                else if(boardStack1.size()==4)
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                }
                else
                {
                    ui->cl_1_1->clear();
                    ui->cl_1_2->clear();
                    ui->cl_1_3->clear();
                    ui->cl_1_4->clear();
                    ui->cl_1_5->clear();
                }
                ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack1.empty())
                {
                    int temp=boardStack1.top();
                    computer_total+=Getbulls(temp);
                    boardStack1.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack1.push(computer_current);
            }
            else if(rand_com==2)
            {
                if (boardStack2.size()==1)
                {
                    ui->cl_2_1->clear();
                }
                else if(boardStack2.size()==2)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                }
                else if(boardStack2.size()==3)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                }
                else if(boardStack2.size()==4)
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                }
                else
                {
                    ui->cl_2_1->clear();
                    ui->cl_2_2->clear();
                    ui->cl_2_3->clear();
                    ui->cl_2_4->clear();
                    ui->cl_2_5->clear();
                }
                ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack2.empty())
                {
                    int temp=boardStack2.top();
                    computer_total+=Getbulls(temp);
                    boardStack2.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack2.push(computer_current);
            }
            else if(rand_com==3)
            {
                if (boardStack3.size()==1)
                {
                    ui->cl_3_1->clear();
                }
                else if(boardStack3.size()==2)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                }
                else if(boardStack3.size()==3)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                }
                else if(boardStack3.size()==4)
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                }
                else
                {
                    ui->cl_3_1->clear();
                    ui->cl_3_2->clear();
                    ui->cl_3_3->clear();
                    ui->cl_3_4->clear();
                    ui->cl_3_5->clear();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                while(false == boardStack3.empty())
                {
                    int temp=boardStack3.top();
                    computer_total+=Getbulls(temp);
                    boardStack3.pop();
                }

                ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                boardStack3.push(computer_current);
            }
            else
            {
                if (boardStack4.size()==1)
                {
                    ui->cl_4_1->clear();
                }
                else if(boardStack4.size()==2)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                }
                else if(boardStack4.size()==3)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                }
                else if(boardStack4.size()==4)
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                }
                else
                {
                    ui->cl_4_1->clear();
                    ui->cl_4_2->clear();
                    ui->cl_4_3->clear();
                    ui->cl_4_4->clear();
                    ui->cl_4_5->clear();
                }
                ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                while(false == boardStack4.empty())
                {
                    int temp=boardStack4.top();
                    computer_total+=Getbulls(temp);
                    boardStack4.pop();
                }
                ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                boardStack4.push(computer_current);
            }
        }
        else
        {
            c_difi=compare_two_Card_player();

            if(c_difi==1)
            {
                if (boardStack1.size() == 1){
                    ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 2){
                    ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 3)
                {
                    ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack1.size() == 4)
                {
                    ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_1_1 ->clear();
                    ui->cl_1_2 -> clear();
                    ui->cl_1_3 ->clear();
                    ui->cl_1_4 -> clear();
                    ui->cl_1_5->clear();
                    while(false == boardStack1.empty())
                         {
                             int temp=boardStack1.top();
                             player_total+=Getbulls(temp);
                             boardStack1.pop();
                         }
                    ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack1.push(computer_current);
            }
            else if(c_difi==2)
            {
                if (boardStack2.size() == 1)
                {
                    ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 2)
                {
                    ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 3)
                {
                    ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack2.size() == 4)
                {
                    ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_2_1 ->clear();
                    ui->cl_2_2 -> clear();
                    ui->cl_2_3 ->clear();
                    ui->cl_2_4 -> clear();
                    ui->cl_2_5->clear();
                    while(false == boardStack2.empty())
                    {
                        int temp=boardStack2.top();
                        player_total+=Getbulls(temp);
                        boardStack2.pop();
                    }
                    ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack2.push(computer_current);
        }
            else if(c_difi==3)
            {
                if (boardStack3.size() == 1)
                {
                    ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 2)
                {
                    ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 3)
                {
                    ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack3.size() == 4)
                {
                    ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_3_1 ->clear();
                    ui->cl_3_2 -> clear();
                    ui->cl_3_3 ->clear();
                    ui->cl_3_4 -> clear();
                    ui->cl_3_5->clear();
                    while(false == boardStack3.empty())
                    {
                        int temp=boardStack3.top();
                        player_total+=Getbulls(temp);
                        boardStack3.pop();
                    }
                    ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                }
                boardStack3.push(computer_current);
            }
            else if(c_difi ==4)
            {
                if (boardStack4.size() == 1)
                {
                    ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 2)
                {
                    ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 3)
                {
                    ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                }
                else if (boardStack4.size() == 4)
                {
                    ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                }
                else
                {
                    ui->cl_4_1 ->clear();
                    ui->cl_4_2 -> clear();
                    ui->cl_4_3 ->clear();
                    ui->cl_4_4 -> clear();
                    ui->cl_4_5->clear();
                    while(false == boardStack4.empty())
                    {
                        int temp=boardStack4.top();
                        player_total+=Getbulls(temp);
                        boardStack4.pop();
                    }
                    ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                    ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                }
                boardStack4.push(computer_current);
            }
        }

    }

    return QWidget::eventFilter(watched, event);
}



void PlayWindow::computerTurn(){
            bool clicklabel(QObject *watched, QEvent *event);
            int dif=104;
            int difi=0;
            int c_dif = 104; // 작은 수를 위한 배치 방법 고안
            int c_difi = 0;

            ui->computercurrentLabel->setText("Computer Card: " + QString::number(computer_current));

            // Player_current < Computer_current
            if (player_current < computer_current)
            {
                if(player_current<boardStack1.top()
                        && player_current<boardStack2.top()
                        && player_current<boardStack3.top()
                        && player_current<boardStack4.top())
                {
                    QTimer::singleShot(1000, this, [this] () { ui -> promptLabel -> show(); });
                    ui->promptLabel->setText("Your card has nowhere to go! Choose a ROW!");
                    QTimer::singleShot(3000, this, [this] () { ui -> promptLabel -> hide(); });
                    ui->cl_1_6->setText("     Click \n to select \n this Row!");
                    ui->cl_2_6->setText("     Click \n to select \n this Row!");
                    ui->cl_3_6->setText("     Click \n to select \n this Row!");
                    ui->cl_4_6->setText("     Click \n to select \n this Row!");
                    ui->Directions->setVisible(false);
                    ui->Directions2->setVisible(true);
                    ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));


                 }
                else
                {
                   difi=compare_two_Card_player();

                   if(difi==1)
                   {
                       if (boardStack1.size() == 1){
                           ui->cl_1_2->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack1.size() == 2){
                           ui->cl_1_3->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack1.size() == 3){
                           ui->cl_1_4->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack1.size() == 4){
                           ui->cl_1_5->setPixmap(cardHolder.at(player_current-1));
                       }
                       else {
                           ui->cl_1_1 ->clear();
                           ui->cl_1_2 -> clear();
                           ui->cl_1_3 ->clear();
                           ui->cl_1_4 -> clear();
                           ui->cl_1_5->clear();
                           ui->cl_1_1->setPixmap(cardHolder.at(player_current-1));
                           while(false == boardStack1.empty())
                           {
                               int temp=boardStack1.top();
                               player_total+=Getbulls(temp);
                               boardStack1.pop();
                           }
                           ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                       }
                       boardStack1.push(player_current);
                    }
                   else if(difi==2)
                   {
                       if (boardStack2.size() == 1){
                           ui->cl_2_2->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack2.size() == 2){
                           ui->cl_2_3->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack2.size() == 3){
                           ui->cl_2_4->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack2.size() == 4){
                           ui->cl_2_5->setPixmap(cardHolder.at(player_current-1));
                       }
                       else {
                           ui->cl_2_1 ->clear();
                           ui->cl_2_2 -> clear();
                           ui->cl_2_3 ->clear();
                           ui->cl_2_4 -> clear();
                           ui->cl_2_5->clear();
                           ui->cl_2_1->setPixmap(cardHolder.at(player_current-1));
                           while(false == boardStack2.empty())
                           {
                               int temp=boardStack2.top();
                               player_total+=Getbulls(temp);
                               boardStack2.pop();
                           }
                           ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                       }
                       boardStack2.push(player_current);
                   }

                   else if(difi==3)
                   {
                       if (boardStack3.size() == 1){
                           ui->cl_3_2->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack3.size() == 2){
                           ui->cl_3_3->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack3.size() == 3){
                           ui->cl_3_4->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack3.size() == 4){
                           ui->cl_3_5->setPixmap(cardHolder.at(player_current-1));
                       }
                       else {
                           ui->cl_3_1 ->clear();
                           ui->cl_3_2 -> clear();
                           ui->cl_3_3 ->clear();
                           ui->cl_3_4 -> clear();
                           ui->cl_3_5->clear();
                           ui->cl_3_1->setPixmap(cardHolder.at(player_current-1));

                           while(false == boardStack3.empty())
                           {
                               int temp=boardStack3.top();
                               player_total+=Getbulls(temp);
                               boardStack3.pop();
                           }
                           ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                       }
                     boardStack3.push(player_current);
                   }

                   else if(difi ==4)
                   {
                       if (boardStack4.size() == 1){
                           ui->cl_4_2->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack4.size() == 2){
                           ui->cl_4_3->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack4.size() == 3){
                           ui->cl_4_4->setPixmap(cardHolder.at(player_current-1));
                       }
                       else if (boardStack4.size() == 4){
                           ui->cl_4_5->setPixmap(cardHolder.at(player_current-1));
                       }
                       else {
                           ui->cl_4_1 ->clear();
                           ui->cl_4_2 -> clear();
                           ui->cl_4_3 ->clear();
                           ui->cl_4_4 -> clear();
                           ui->cl_4_5->clear();
                           ui->cl_4_1->setPixmap(cardHolder.at(player_current-1));
                           while(false == boardStack4.empty())
                           {
                               int temp=boardStack4.top();
                               player_total+=Getbulls(temp);
                               boardStack4.pop();
                           }
                           ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                       }
                       boardStack4.push(player_current);
                   }

                   // 컴퓨터꺼 계산
                   if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                           &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
                   {
                       int rand_com;
                       rand_com=com_choose_row();
                       if (rand_com==1)
                       {
                           if (boardStack1.size()==1)
                           {
                               ui->cl_1_1->clear();
                           }
                           else if(boardStack1.size()==2)
                           {
                               ui->cl_1_2->clear();
                               ui->cl_1_2->clear();
                           }
                           else if(boardStack1.size()==3)
                           {
                               ui->cl_1_1->clear();
                               ui->cl_1_2->clear();
                               ui->cl_1_3->clear();
                           }
                           else if(boardStack1.size()==4)
                           {
                               ui->cl_1_1->clear();
                               ui->cl_1_2->clear();
                               ui->cl_1_3->clear();
                               ui->cl_1_4->clear();
                           }
                           else
                           {
                               ui->cl_1_1->clear();
                               ui->cl_1_2->clear();
                               ui->cl_1_3->clear();
                               ui->cl_1_4->clear();
                               ui->cl_1_5->clear();
                           }
                           ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                           while(false == boardStack1.empty())
                           {
                               int temp=boardStack1.top();
                               computer_total+=Getbulls(temp);
                               boardStack1.pop();
                           }
                           ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           boardStack1.push(computer_current);
                       }
                       else if(rand_com==2)
                       {
                           if (boardStack2.size()==1)
                           {
                               ui->cl_2_1->clear();
                           }
                           else if(boardStack2.size()==2)
                           {
                               ui->cl_2_1->clear();
                               ui->cl_2_2->clear();
                           }
                           else if(boardStack2.size()==3)
                           {
                               ui->cl_2_1->clear();
                               ui->cl_2_2->clear();
                               ui->cl_2_3->clear();
                           }
                           else if(boardStack2.size()==4)
                           {
                               ui->cl_2_1->clear();
                               ui->cl_2_2->clear();
                               ui->cl_2_3->clear();
                               ui->cl_2_4->clear();
                           }
                           else
                           {
                               ui->cl_2_1->clear();
                               ui->cl_2_2->clear();
                               ui->cl_2_3->clear();
                               ui->cl_2_4->clear();
                               ui->cl_2_5->clear();
                           }
                           ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                           while(false == boardStack2.empty())
                           {
                               int temp=boardStack2.top();
                               computer_total+=Getbulls(temp);
                               boardStack2.pop();
                           }
                           ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           boardStack2.push(computer_current);
                       }
                       else if(rand_com==3)
                       {
                           if (boardStack3.size()==1)
                           {
                               ui->cl_3_1->clear();
                           }
                           else if(boardStack3.size()==2)
                           {
                               ui->cl_3_1->clear();
                               ui->cl_3_2->clear();
                           }
                           else if(boardStack3.size()==3)
                           {
                               ui->cl_3_1->clear();
                               ui->cl_3_2->clear();
                               ui->cl_3_3->clear();
                           }
                           else if(boardStack3.size()==4)
                           {
                               ui->cl_3_1->clear();
                               ui->cl_3_2->clear();
                               ui->cl_3_3->clear();
                               ui->cl_3_4->clear();
                           }
                           else
                           {
                               ui->cl_3_1->clear();
                               ui->cl_3_2->clear();
                               ui->cl_3_3->clear();
                               ui->cl_3_4->clear();
                               ui->cl_3_5->clear();
                           }
                           ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           while(false == boardStack3.empty())
                           {
                               int temp=boardStack3.top();
                               computer_total+=Getbulls(temp);
                               boardStack3.pop();
                           }

                           ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                           boardStack3.push(computer_current);
                       }
                       else
                       {
                           if (boardStack4.size()==1)
                           {
                               ui->cl_4_1->clear();
                           }
                           else if(boardStack4.size()==2)
                           {
                               ui->cl_4_1->clear();
                               ui->cl_4_2->clear();
                           }
                           else if(boardStack4.size()==3)
                           {
                               ui->cl_4_1->clear();
                               ui->cl_4_2->clear();
                               ui->cl_4_3->clear();
                           }
                           else if(boardStack4.size()==4)
                           {
                               ui->cl_4_1->clear();
                               ui->cl_4_2->clear();
                               ui->cl_4_3->clear();
                               ui->cl_4_4->clear();
                           }
                           else
                           {
                               ui->cl_4_1->clear();
                               ui->cl_4_2->clear();
                               ui->cl_4_3->clear();
                               ui->cl_4_4->clear();
                               ui->cl_4_5->clear();
                           }
                           ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                           while(false == boardStack4.empty())
                           {
                               int temp=boardStack4.top();
                               computer_total+=Getbulls(temp);
                               boardStack4.pop();
                           }
                           ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           boardStack4.push(computer_current);
                       }
                   }
                   else
                   {
                       c_difi=compare_two_Card_player();

                       if(c_difi==1)
                       {
                           if (boardStack1.size() == 1){
                               ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack1.size() == 2){
                               ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack1.size() == 3)
                           {
                               ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack1.size() == 4)
                           {
                               ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else
                           {
                               ui->cl_1_1 ->clear();
                               ui->cl_1_2 -> clear();
                               ui->cl_1_3 ->clear();
                               ui->cl_1_4 -> clear();
                               ui->cl_1_5->clear();
                               while(false == boardStack1.empty())
                                    {
                                        int temp=boardStack1.top();
                                        player_total+=Getbulls(temp);
                                        boardStack1.pop();
                                    }
                               ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                               ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           }
                           boardStack1.push(computer_current);
                       }
                       else if(c_difi==2)
                       {
                           if (boardStack2.size() == 1)
                           {
                               ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack2.size() == 2)
                           {
                               ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack2.size() == 3)
                           {
                               ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack2.size() == 4)
                           {
                               ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else
                           {
                               ui->cl_2_1 ->clear();
                               ui->cl_2_2 -> clear();
                               ui->cl_2_3 ->clear();
                               ui->cl_2_4 -> clear();
                               ui->cl_2_5->clear();
                               while(false == boardStack2.empty())
                               {
                                   int temp=boardStack2.top();
                                   player_total+=Getbulls(temp);
                                   boardStack2.pop();
                               }
                               ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                               ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           }
                           boardStack2.push(computer_current);
                   }
                       else if(c_difi==3)
                       {
                           if (boardStack3.size() == 1)
                           {
                               ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack3.size() == 2)
                           {
                               ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack3.size() == 3)
                           {
                               ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack3.size() == 4)
                           {
                               ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else
                           {
                               ui->cl_3_1 ->clear();
                               ui->cl_3_2 -> clear();
                               ui->cl_3_3 ->clear();
                               ui->cl_3_4 -> clear();
                               ui->cl_3_5->clear();
                               while(false == boardStack3.empty())
                               {
                                   int temp=boardStack3.top();
                                   player_total+=Getbulls(temp);
                                   boardStack3.pop();
                               }
                               ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                               ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                           }
                           boardStack3.push(computer_current);
                       }
                       else if(c_difi ==4)
                       {
                           if (boardStack4.size() == 1)
                           {
                               ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack4.size() == 2)
                           {
                               ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack4.size() == 3)
                           {
                               ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else if (boardStack4.size() == 4)
                           {
                               ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                           }
                           else
                           {
                               ui->cl_4_1 ->clear();
                               ui->cl_4_2 -> clear();
                               ui->cl_4_3 ->clear();
                               ui->cl_4_4 -> clear();
                               ui->cl_4_5->clear();
                               while(false == boardStack4.empty())
                               {
                                   int temp=boardStack4.top();
                                   player_total+=Getbulls(temp);
                                   boardStack4.pop();
                               }
                               ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                               ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                           }
                           boardStack4.push(computer_current);
                       }
                   }
                }
            }



////////////////////Computer < Player///////////////

            else{
                if(computer_current<boardStack1.top() &&computer_current<boardStack2.top()
                        &&computer_current<boardStack3.top() &&computer_current<boardStack4.top())
                {
                    int rand_com;
                    rand_com=com_choose_row();
                    if (rand_com==1)
                    {
                        if (boardStack1.size()==1)
                        {
                            ui->cl_1_1->clear();
                        }
                        else if(boardStack1.size()==2)
                        {
                            ui->cl_1_2->clear();
                            ui->cl_1_2->clear();
                        }
                        else if(boardStack1.size()==3)
                        {
                            ui->cl_1_1->clear();
                            ui->cl_1_2->clear();
                            ui->cl_1_3->clear();
                        }
                        else if(boardStack1.size()==4)
                        {
                            ui->cl_1_1->clear();
                            ui->cl_1_2->clear();
                            ui->cl_1_3->clear();
                            ui->cl_1_4->clear();
                        }
                        else
                        {
                            ui->cl_1_1->clear();
                            ui->cl_1_2->clear();
                            ui->cl_1_3->clear();
                            ui->cl_1_4->clear();
                            ui->cl_1_5->clear();
                        }
                        ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                        while(false == boardStack1.empty())
                        {
                            int temp=boardStack1.top();
                            computer_total+=Getbulls(temp);
                            boardStack1.pop();
                        }
                        ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        boardStack1.push(computer_current);
                    }
                    else if(rand_com==2)
                    {
                        if (boardStack2.size()==1)
                        {
                            ui->cl_2_1->clear();
                        }
                        else if(boardStack2.size()==2)
                        {
                            ui->cl_2_1->clear();
                            ui->cl_2_2->clear();
                        }
                        else if(boardStack2.size()==3)
                        {
                            ui->cl_2_1->clear();
                            ui->cl_2_2->clear();
                            ui->cl_2_3->clear();
                        }
                        else if(boardStack2.size()==4)
                        {
                            ui->cl_2_1->clear();
                            ui->cl_2_2->clear();
                            ui->cl_2_3->clear();
                            ui->cl_2_4->clear();
                        }
                        else
                        {
                            ui->cl_2_1->clear();
                            ui->cl_2_2->clear();
                            ui->cl_2_3->clear();
                            ui->cl_2_4->clear();
                            ui->cl_2_5->clear();
                        }
                        ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                        while(false == boardStack2.empty())
                        {
                            int temp=boardStack2.top();
                            computer_total+=Getbulls(temp);
                            boardStack2.pop();
                        }
                        ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        boardStack2.push(computer_current);
                    }
                    else if(rand_com==3)
                    {
                        if (boardStack3.size()==1)
                        {
                            ui->cl_3_1->clear();
                        }
                        else if(boardStack3.size()==2)
                        {
                            ui->cl_3_1->clear();
                            ui->cl_3_2->clear();
                        }
                        else if(boardStack3.size()==3)
                        {
                            ui->cl_3_1->clear();
                            ui->cl_3_2->clear();
                            ui->cl_3_3->clear();
                        }
                        else if(boardStack3.size()==4)
                        {
                            ui->cl_3_1->clear();
                            ui->cl_3_2->clear();
                            ui->cl_3_3->clear();
                            ui->cl_3_4->clear();
                        }
                        else
                        {
                            ui->cl_3_1->clear();
                            ui->cl_3_2->clear();
                            ui->cl_3_3->clear();
                            ui->cl_3_4->clear();
                            ui->cl_3_5->clear();
                        }
                        ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        while(false == boardStack3.empty())
                        {
                            int temp=boardStack3.top();
                            computer_total+=Getbulls(temp);
                            boardStack3.pop();
                        }

                        ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                        boardStack3.push(computer_current);
                    }
                    else
                    {
                        if (boardStack4.size()==1)
                        {
                            ui->cl_4_1->clear();
                        }
                        else if(boardStack4.size()==2)
                        {
                            ui->cl_4_1->clear();
                            ui->cl_4_2->clear();
                        }
                        else if(boardStack4.size()==3)
                        {
                            ui->cl_4_1->clear();
                            ui->cl_4_2->clear();
                            ui->cl_4_3->clear();
                        }
                        else if(boardStack4.size()==4)
                        {
                            ui->cl_4_1->clear();
                            ui->cl_4_2->clear();
                            ui->cl_4_3->clear();
                            ui->cl_4_4->clear();
                        }
                        else
                        {
                            ui->cl_4_1->clear();
                            ui->cl_4_2->clear();
                            ui->cl_4_3->clear();
                            ui->cl_4_4->clear();
                            ui->cl_4_5->clear();
                        }
                        ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                        while(false == boardStack4.empty())
                        {
                            int temp=boardStack4.top();
                            computer_total+=Getbulls(temp);
                            boardStack4.pop();
                        }
                        ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        boardStack4.push(computer_current);
                    }
                }
                else
                {

                    c_difi=compare_two_Card_computer();

                    if(c_difi == 1)
                    {
                        if (boardStack1.size() == 1)
                        {
                            ui->cl_1_2->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack1.size() == 2)
                        {
                            ui->cl_1_3->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack1.size() == 3)
                        {
                            ui->cl_1_4->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack1.size() == 4)
                        {
                            ui->cl_1_5->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else
                        {
                            ui->cl_1_1->clear();
                            ui->cl_1_2->clear();
                            ui->cl_1_3->clear();
                            ui->cl_1_4->clear();
                            ui->cl_1_5->clear();
                            while(false == boardStack1.empty())
                            {
                                int temp=boardStack1.top();
                                computer_total+=Getbulls(temp);
                                boardStack1.pop();
                            }
                            ui->cl_1_1->setPixmap(cardHolder.at(computer_current-1));
                            ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        }
                      boardStack1.push(computer_current);
                    }

                    else if(c_difi==2)
                    {
                        if (boardStack2.size() == 1){
                            ui->cl_2_2->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack2.size() == 2){
                            ui->cl_2_3->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack2.size() == 3){
                            ui->cl_2_4->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack2.size() == 4){
                            ui->cl_2_5->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else {
                            ui->cl_2_1->clear();
                            ui->cl_2_2->clear();
                            ui->cl_2_3->clear();
                            ui->cl_2_4->clear();
                            ui->cl_2_5->clear();
                            while(false == boardStack2.empty())
                            {
                                int temp=boardStack2.top();
                                computer_total+=Getbulls(temp);
                                boardStack2.pop();
                            }
                            ui->cl_2_1->setPixmap(cardHolder.at(computer_current-1));
                            ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        }
                      boardStack2.push(computer_current);
                    }
                    else if(c_difi==3)
                    {
                        if (boardStack3.size() == 1){
                            ui->cl_3_2->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack3.size() == 2){
                            ui->cl_3_3->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack3.size() == 3){
                            ui->cl_3_4->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else if (boardStack3.size() == 4){
                            ui->cl_3_5->setPixmap(cardHolder.at(computer_current-1));
                        }
                        else {
                            ui->cl_3_1->clear();
                            ui->cl_3_2->clear();
                            ui->cl_3_3->clear();
                            ui->cl_3_4->clear();
                            ui->cl_3_5->clear();
                            while(false == boardStack3.empty())
                            {
                                int temp=boardStack3.top();
                                computer_total+=Getbulls(temp);
                                boardStack3.pop();
                            }
                            ui->cl_3_1->setPixmap(cardHolder.at(computer_current-1));
                            ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                        }
                      boardStack3.push(computer_current);
                    }
                    else if(c_difi ==4)
                    {
                          if (boardStack4.size() == 1){
                              ui->cl_4_2->setPixmap(cardHolder.at(computer_current-1));
                          }
                          else if (boardStack4.size() == 2){
                              ui->cl_4_3->setPixmap(cardHolder.at(computer_current-1));
                          }
                          else if (boardStack4.size() == 3){
                              ui->cl_4_4->setPixmap(cardHolder.at(computer_current-1));
                          }
                          else if (boardStack4.size() == 4){
                              ui->cl_4_5->setPixmap(cardHolder.at(computer_current-1));
                          }
                          else {
                              ui->cl_4_1->clear();
                              ui->cl_4_2->clear();
                              ui->cl_4_3->clear();
                              ui->cl_4_4->clear();
                              ui->cl_4_5->clear();
                              while(false == boardStack4.empty())
                              {
                                  int temp=boardStack4.top();
                                  computer_total+=Getbulls(temp);
                                  boardStack4.pop();
                              }
                              ui->cl_4_1->setPixmap(cardHolder.at(computer_current-1));
                              ui->computertotalLabel_2->setText("com score: " + QString::number(computer_total));
                          }
                        boardStack4.push(computer_current);
                    }
                }


                    //player
                    if(player_current<boardStack1.top()
                            && player_current<boardStack2.top()
                            && player_current<boardStack3.top()
                            && player_current<boardStack4.top())
                    {
                        QTimer::singleShot(1000, this, [this] () { ui -> promptLabel -> show(); });
                        ui->promptLabel->setText("Your card has nowhere to go! Choose a ROW!");
                        QTimer::singleShot(3000, this, [this] () { ui -> promptLabel -> hide(); });
                        ui->cl_1_6->setText("     Click \n to select \n this Row!");
                        ui->cl_2_6->setText("     Click \n to select \n this Row!");
                        ui->cl_3_6->setText("     Click \n to select \n this Row!");
                        ui->cl_4_6->setText("     Click \n to select \n this Row!");
                        ui->Directions->setVisible(false);
                        ui->Directions2->setVisible(true);
                        ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));

                    }
                    else
                    {
                        difi=compare_two_Card_player();
                        if(difi==1)
                        {
                            if (boardStack1.size() == 1)
                            {
                                ui->cl_1_2->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack1.size() == 2)
                            {
                                ui->cl_1_3->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack1.size() == 3)
                            {
                                ui->cl_1_4->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack1.size() == 4)
                            {
                                ui->cl_1_5->setPixmap(cardHolder.at(player_current-1));
                            }
                            else
                            {
                                ui->cl_1_1 ->clear();
                                ui->cl_1_2 -> clear();
                                ui->cl_1_3 ->clear();
                                ui->cl_1_4 -> clear();
                                ui->cl_1_5->clear();

                                while(false == boardStack1.empty())
                                {
                                    int temp=boardStack1.top();
                                    player_total+=Getbulls(temp);
                                    boardStack1.pop();
                                }
                                ui->cl_1_1->setPixmap(cardHolder.at(player_current-1));
                                ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                            }
                            boardStack1.push(player_current);
                        }
                        else if(difi==2)
                        {
                            if (boardStack2.size() == 1){
                                ui->cl_2_2->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack2.size() == 2){
                                ui->cl_2_3->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack2.size() == 3){
                                ui->cl_2_4->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack2.size() == 4){
                                ui->cl_2_5->setPixmap(cardHolder.at(player_current-1));
                            }
                            else
                            {
                                ui->cl_2_1 ->clear();
                                ui->cl_2_2 -> clear();
                                ui->cl_2_3 ->clear();
                                ui->cl_2_4 -> clear();
                                ui->cl_2_5->clear();

                                while(false == boardStack2.empty())
                                {
                                    int temp=boardStack2.top();
                                    player_total+=Getbulls(temp);
                                    boardStack2.pop();
                                }
                                ui->cl_2_1->setPixmap(cardHolder.at(player_current-1));
                                ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                            }
                            boardStack2.push(player_current);
                        }
                        else if(difi==3)
                        {
                            if (boardStack3.size() == 1)
                            {
                                ui->cl_3_2->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack3.size() == 2)
                            {
                                ui->cl_3_3->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack3.size() == 3)
                            {
                                ui->cl_3_4->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack3.size() == 4)
                            {
                                ui->cl_3_5->setPixmap(cardHolder.at(player_current-1));
                            }
                            else
                            {
                                ui->cl_3_1 ->clear();
                                ui->cl_3_2 -> clear();
                                ui->cl_3_3 ->clear();
                                ui->cl_3_4 -> clear();
                                ui->cl_3_5->clear();

                                while(false == boardStack3.empty())
                                {
                                    int temp=boardStack3.top();
                                    player_total+=Getbulls(temp);
                                    boardStack3.pop();
                                }
                                ui->cl_3_1->setPixmap(cardHolder.at(player_current-1));
                                ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                            }
                            boardStack3.push(player_current);
                        }
                        else if(difi ==4)
                        {
                            if (boardStack4.size() == 1){
                                ui->cl_4_2->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack4.size() == 2)
                            {
                                ui->cl_4_3->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack4.size() == 3)
                            {
                                ui->cl_4_4->setPixmap(cardHolder.at(player_current-1));
                            }
                            else if (boardStack4.size() == 4)
                            {
                                ui->cl_4_5->setPixmap(cardHolder.at(player_current-1));
                            }
                            else
                            {
                                ui->cl_4_1 ->clear();
                                ui->cl_4_2 -> clear();
                                ui->cl_4_3 ->clear();
                                ui->cl_4_4 -> clear();
                                ui->cl_4_5->clear();

                                while(false == boardStack4.empty())
                                {
                                    int temp=boardStack4.top();
                                    player_total+=Getbulls(temp);
                                    boardStack4.pop();
                                }
                                ui->cl_4_1->setPixmap(cardHolder.at(player_current-1));
                                ui->playertotalLabel_3->setText("my score: " + QString::number(player_total));
                            }
                            boardStack4.push(player_current);
                        }
                    }
                }
            }

void PlayWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void PlayWindow::on_FINISH_clicked()
{
    QApplication::quit();
}

void PlayWindow::on_RegameButton_clicked()
{
    MainWindow *toMain = new MainWindow();
    this->close();
    toMain->show();

    // clear variable values
    handCount = 0;
    player_current = 0;
    computer_current = 0;
    computer_total = 0;
    player_total =0 ;
    bulls = 0 ;
    penalty=0;

    // clear
    deckVector.clear();
    userVector.clear();
    computerVector.clear();
    while(false == boardStack1.empty())
            {
                boardStack1.pop();
            }
    while(false == boardStack2.empty())
            {
                boardStack2.pop();
            }
    while(false == boardStack3.empty())
            {
                boardStack3.pop();
            }
    while(false == boardStack4.empty())
            {
                boardStack4.pop();
            }
    while(false == storeStack.empty())
            {
                storeStack.pop();
            }


}

void PlayWindow::on_quitButton_3_clicked()
{
    QApplication::quit();
}
