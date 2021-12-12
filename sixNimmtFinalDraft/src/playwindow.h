#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
#include <QDebug>
#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();
    QList<QPixmap> cardHolder;
    int deckValues[104];
    bool eventFilter(QObject *watched, QEvent *event);
    void at_start();


public slots:
    void loadList();
    void computerTurn();
private slots:
    void on_actionQuit_triggered();
    void on_FINISH_clicked();
    void on_RegameButton_clicked();

    void on_quitButton_3_clicked();

private:
    Ui::PlayWindow *ui;
    QTimer *m_Timer;

protected:
};


#endif // PLAYWINDOW_H
