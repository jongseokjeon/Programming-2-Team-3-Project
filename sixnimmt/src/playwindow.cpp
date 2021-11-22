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
using namespace std;
using std::stack;

std::vector<int> userVector;
std::vector<int> computerVector;
stack<int> boardStack1;
stack<int> boardStack2;
stack<int> boardStack3;
stack<int> boardStack4;
std::vector<int> deckVector;

int player_current = 0;
int computer_current = 0;
int computer_wins = 0;
int player_wins = 0;
int holdingCardCount = 1;
int holdingCardCountComputer = 1;


PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/images/table.png");
    //ui->tableLabel->setPixmap(pix);
    //ui->tableLabel->lower();
    //ui->okaybutton->setEnabled(true); // the name must be changed to ok button
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

    loadList();
}

bool PlayWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui-> card1Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card1Label_10;
        int a = userVector[0];
        //ui->tableLabel_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card2Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card2Label_10;
        int a = userVector[1];
        //ui->tableLabel_2->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card3Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card3Label_10;
        int a = userVector[2];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card4Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card4Label_10;
        int a = userVector[3];
        //ui->card2Label_6->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card5Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card5Label_10;
        int a = userVector[4];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card6Label_10 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card6Label_10;
        int a = userVector[5];
        //ui->card2Label_7->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card7Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card7Label_2;
        int a = userVector[6];
        //ui->card2Label_4->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card8Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card8Label_2;
        int a = userVector[7];
        //ui->card2Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card9Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card9Label_2;
        int a = userVector[8];
        //ui->card3Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();
    }
    if(watched == ui-> card10Label_2 && event->type() == QMouseEvent::MouseButtonPress)
    {
        delete ui->card10Label_2;
        int a = userVector[9];
        //ui->card4Label_5->setPixmap(cardHolder.at(a));
        ui->playercurrentLabel_2->setText("Current Card: " + QString::number(a+1));
        player_current = a+1;
        computerTurn();

    }
    return QWidget::eventFilter(watched, event);
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


// global deck value variable 생성 , 사용할 random index 생성

// 클릭할 때 유저 카드10개, 컴터 10개, 보드 4개 생성
void PlayWindow::on_twistButton_2_clicked()
{
    int deckValues[104] = {1, 2, 3,   4,   5,   6,   7,   8,   9,   10,   11,   12,   13,   14,   15,   16,   17,
                           18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
                           34,   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
                           50,   51,   52,   53,   54,   55,   56,   57,   58,   59,   60,   61,   62,   63,   64,   65,
                           66,   67,   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
                           82,   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,   97,
                           98,   99,   100, 101, 102, 103, 104};

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> dis(0, 104);

        int number = dis(gen);
        // 여기에다가 경기 진행될 때 사용자의 점수 실시간으로 반영하는 기능으로 만들면 좋을듯
    //    ui->playercurrentLabel->setText("Current Card: " + QString::number(deckValues[number-1]));
    //    player_score += deckValues[number-1];
    //    ui->playertotalLabel->setText("Total: " + QString::number(player_score));


        // 카드 생성 버튼 (twist) 클릭했을 때

        // create vector that stores user's hand

        // create vector that stores computer's hand

        // create 4 vectors that stores the cards on the board - 나중에 백터 사용하려면 이렇게 따로 백터에 저장해야 될 듯


        // random index edit


           for(int i=0;i<104;i++)
           {
                       int a;
                       a = dis(gen);//값이 겹침
                       deckVector.push_back(a);
           }
       ui->card1Label_10->setPixmap(cardHolder.at(deckVector[0]));
       userVector.push_back(deckVector[0]);
       ui->card2Label_10->setPixmap(cardHolder.at(deckVector[1]));
       userVector.push_back(deckVector[1]);
       ui->card3Label_10->setPixmap(cardHolder.at(deckVector[2]));
       userVector.push_back(deckVector[2]);
       ui->card4Label_10->setPixmap(cardHolder.at(deckVector[3]));
       userVector.push_back(deckVector[3]);
       ui->card5Label_10->setPixmap(cardHolder.at(deckVector[4]));
       userVector.push_back(deckVector[4]);
       ui->card6Label_10->setPixmap(cardHolder.at(deckVector[5]));
       userVector.push_back(deckVector[5]);
       ui->card7Label_2->setPixmap(cardHolder.at(deckVector[6]));
       userVector.push_back(deckVector[6]);
       ui->card8Label_2->setPixmap(cardHolder.at(deckVector[7]));
       userVector.push_back(deckVector[7]);
       ui->card9Label_2->setPixmap(cardHolder.at(deckVector[8]));
       userVector.push_back(deckVector[8]);
       ui->card10Label_2->setPixmap(cardHolder.at(deckVector[9]));
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
       ui->card1Label_12->setPixmap(cardHolder.at(deckVector[20]));
       boardStack1.push(deckVector[20]);
       ui->card1Label_14->setPixmap(cardHolder.at(deckVector[21]));
       boardStack2.push(deckVector[21]);
       ui->card1Label_13->setPixmap(cardHolder.at(deckVector[22]));
       boardStack3.push(deckVector[22]);
       ui->card1Label_11->setPixmap(cardHolder.at(deckVector[23]));
       boardStack4.push(deckVector[23]);

       int temp = deckVector[0];

}


//    QPixmap win(":/images/images/win.png");
//    QPixmap lose(":/images/images/lose.png");
//    QPixmap draw(":/images/images/draw.png");

    //return; //value10
//}





//void PlayWindow::on_card1Label_10_linkActivated(const QString &link,스택받아오기)//여기서 카드값 보여줌
//{
//    //스택중에 첫번째 스택에 담긴 값을 label에 띄움
//    ui->playercurrentLabel->setText("Current Card: " + QString::number(deckValues[number-1]));
//}


void PlayWindow::computerTurn(){
            int dif=0;
            int difi=0;
            int a;
            a = rand()%10;
            ui->computercurrentLabel->setText("Computer Card: " + QString::number(a+1));
            computer_current=a;
            if (computer_current<player_current)
            {

                   if (boardStack1.top() >computer_current)
                   {           dif = 0;
                               difi = 0;
                   }
                   else
                   {
                       dif = boardStack1.top()- computer_current;
                       difi = 1;
                   }
                   if (boardStack2.top() >computer_current)
                   {           dif = dif;
                               difi = difi;
                   }
                   else
                   {
                       if(boardStack2.top()- computer_current<dif)
                       {
                           dif=boardStack2.top()- computer_current;
                           difi = 2;
                       }
                       else
                       {
                           dif = dif;
                           difi = difi;
                       }
                   }
                   if (boardStack3.top() >computer_current)
                   {           dif = dif;
                               difi = difi;
                   }
                   else
                   {
                       if(boardStack3.top()- computer_current<dif)
                       {
                           dif=boardStack3.top()- computer_current;
                           difi = 3;
                       }
                       else
                       {
                           dif = dif;
                           difi = difi;
                       }
                   }
                   if (boardStack4.top() >computer_current)
                   {           dif = dif;
                               difi = difi;
                   }
                   else
                   {
                       if(boardStack4.top()- computer_current<dif)
                       {
                           dif=boardStack4.top()- computer_current;
                           difi = 4;
                       }
                       else
                       {
                           dif = dif;
                           difi = difi;
                       }
                   }

            if(difi==1)
            {
                       ui->tableLabel_5->setPixmap(cardHolder.at(computer_current));//player_current가 a+1한거니까
            }

            else if(difi==2)
            {
                       ui->tableLabel_2->setPixmap(cardHolder.at(computer_current));
            }
            else if(difi==3)
            {
                       ui->tableLabel_3->setPixmap(cardHolder.at(computer_current));
            }
            else
            {
                       ui->tableLabel_4->setPixmap(cardHolder.at(computer_current));
            }
            }else{

                if (boardStack1.top() >player_current)
                {           dif = 0;
                            difi = 0;
                }
                else
                {
                    dif = boardStack1.top()- player_current;
                    difi = 1;
                }
                if (boardStack2.top() >player_current)
                {           dif = dif;
                            difi = difi;
                }
                else
                {
                    if(boardStack2.top()- player_current<dif)
                    {
                        dif=boardStack2.top()- player_current;
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
                {
                    if(boardStack3.top()-player_current<dif)
                    {
                        dif=boardStack3.top()- player_current;
                        difi = 3;
                    }
                    else
                    {
                        dif = dif;
                        difi = difi;
                    }
                }
                if (boardStack4.top() >player_current)
                {           dif = dif;
                            difi = difi;
                }
                else
                {
                    if(boardStack4.top()- player_current<dif)
                    {
                        dif=boardStack4.top()- player_current;
                        difi = 4;
                    }
                    else
                    {
                        dif = dif;
                        difi = difi;
                    }
                }

         if(difi==1)
         {
                    ui->tableLabel_5->setPixmap(cardHolder.at(player_current));//player_current가 a+1한거니까
         }

         else if(difi==2)
         {
                    ui->tableLabel_2->setPixmap(cardHolder.at(player_current));
         }
         else if(difi==3)
         {
                    ui->tableLabel_3->setPixmap(cardHolder.at(player_current));
         }
         else
         {
                    ui->tableLabel_4->setPixmap(cardHolder.at(player_current));
         }
            }

}



//

//        QPixmap win(":/images/images/win.png");
//        QPixmap lose(":/images/images/lose.png");
//        QPixmap draw(":/images/images/draw.png");

//        int computer_score = 0;
//        while (computer_score < 16){
//            computer_score += rand() % 10 + 1;

//            ui->computercurrentLabel->setText("Computer: " + QString::number(computer_score));

//                switch(holdingCardCountComputer){
//                    case 1:
//                        ui->card10Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 2:
//                        ui->card9Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 3:
//                        ui->card8Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 4:
//                        ui->card7Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 5:
//                        ui->card6Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 6:
//                        ui->card5Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 7:
//                        ui->card4Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 8:
//                        ui->card3Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 9:
//                        ui->card2Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                    case 10:
//                        ui->card1Label_2->setPixmap(cardHolder.at(computer_score - 1));
//                        break;
//                }
//                ++holdingCardCountComputer;
//        }


//        //if computer is bust  //컴퓨터 turn에 카드 비교가 필요하네.
//        if (computer_score > player_score ){
//            computer_score를 젤 끝에 있는 카드들이랑 먼저 비교(처음이라면 처음4장 카드들과 비교하게 될것)
//            ui바꾸고.computer카드 놓는거
//            젤 끝에 있는 카드들이랑 player_score를 비교해서
//            ui바꾸고 player카드 놓는거
//        } else{
//            player_score를 맨 앞의 네장 카드들이랑 먼저비교
//            ui바꾸고.player카드 놓는거
//            젤 끝에 있는 카드들이랑 computer_score를 비교해서
//            ui바꾸고 computer카드 놓는거
//        }
//        // if same score or both bust
//        if ((computer_score == player_score) || ((computer_score > 21) && (player_score > 21))){
//            ui->outcomeLabel->setPixmap(draw);
//        }
//        // if both players are not bust AND computer is larger than player
//        else if (((computer_score < 22) && (player_score < 22) && (computer_score > player_score)) || ((player_score > 21) && computer_score < 22 )){
//            ui->outcomeLabel->setPixmap(lose);;
//            ++computer_wins;
//        }
//        // else, player wins
//        else{
//            ui->outcomeLabel->setPixmap(win);
//            ++player_wins;
//        }
//        ui->statusbar->showMessage("Player " + QString::number(player_wins) + " - Gamescore - " + "Computer " + QString::number(computer_wins));
//        this->setEnabled(true);
//    }





//void PlayWindow::on_playagainButton_clicked()
//{
//    //Clear Labels and Variables
//    player_score = 0;
//    computer_score = 0;
//    holdingCardCount = 1;
//    holdingCardCountComputer = 1;

//    ui->playercurrentLabel->setText("Card: " + QString::number(0));
//    ui->playertotalLabel->setText("Total: " + QString::number(0));

//    ui->twistButton->setEnabled(true);
//    ui->playagainButton->setEnabled(false);
//    ui->stickButton->setEnabled(false);
//    ui->outcomeLabel->clear();
//    ui->computerStatusLabel->setText("");
//    ui->statusLabel->setText("");
//    ui->computerScoreLabel->setText("Computer: " + QString::number(0));

//    // Clear Cards from player table
//    ui->card1Label->clear();
//    ui->card2Label->clear();
//    ui->card3Label->clear();
//    ui->card4Label->clear();
//    ui->card5Label->clear();
//    ui->card6Label->clear();
//    ui->card8Label->clear();
//    ui->card9Label->clear();
//    ui->card10Label->clear();

//    ui->card10Label_2->clear();
//    ui->card9Label_2->clear();
//    ui->card8Label_2->clear();
//    ui->card7Label_2->clear();
//    ui->card6Label_2->clear();
//    ui->card5Label_2->clear();
//    ui->card4Label_2->clear();
//    ui->card3Label_2->clear();
//    ui->card2Label_2->clear();
//    ui->card1Label_2->clear();

//}

//void PlayWindow::on_actionQuit_triggered()
//{
    //QApplication::quit();
//}




//void PlayWindow::on_okaybutton_clicked()
//{
//    ui->InstructionLabel->setText("Choose one card in your deck!");
//}

/*
void PlayWindow::on_OKAYButton_clicked()
{
    int dif=0;
    int difi=0;
    int a;
    a = rand()%10;
    ui->computercurrentLabel->setText("Current Card: " + QString::number(a+1));
    computer_current=a;
    if (computer_current<player_current)
    {

           if (boardStack1.top() >computer_current)
           {           dif = 0;
                       difi = 0;
           }
           else
           {
               dif = boardStack1.top()- computer_current;
               difi = 1;
           }
           if (boardStack2.top() >computer_current)
           {           dif = dif;
                       difi = difi;
           }
           else
           {
               if(boardStack2.top()- computer_current<dif)
               {
                   dif=boardStack2.top()- computer_current;
                   difi = 2;
               }
               else
               {
                   dif = dif;
                   difi = difi;
               }
           }
           if (boardStack3.top() >computer_current)
           {           dif = dif;
                       difi = difi;
           }
           else
           {
               if(boardStack3.top()- computer_current<dif)
               {
                   dif=boardStack3.top()- computer_current;
                   difi = 3;
               }
               else
               {
                   dif = dif;
                   difi = difi;
               }
           }
           if (boardStack4.top() >computer_current)
           {           dif = dif;
                       difi = difi;
           }
           else
           {
               if(boardStack4.top()- computer_current<dif)
               {
                   dif=boardStack4.top()- computer_current;
                   difi = 4;
               }
               else
               {
                   dif = dif;
                   difi = difi;
               }
           }
           if(difi==1)
           {
               ui->tableLabel_5->setPixmap(cardHolder.at(computer_current-1));//player_current가 a+1한거니까
           }

           }else if(difi==2)
           {
               ui->tableLabel_2->setPixmap(cardHolder.at(computer_current-1));
           }else if(difi==3)
           {
               ui->tableLabel_3->setPixmap(cardHolder.at(computer_current-1));
           }else
           {
               ui->tableLabel_4->setPixmap(cardHolder.at(computer_current-1));
           }
}
*/

