#ifndef THEFINALSCORE_H
#define THEFINALSCORE_H

#include <QWidget>

namespace Ui {
class TheFinalScore;
}

class TheFinalScore : public QWidget
{
    Q_OBJECT

public:
    explicit TheFinalScore(QWidget *parent = nullptr);
    ~TheFinalScore();

private:
    Ui::TheFinalScore *ui;
};

#endif // THEFINALSCORE_H
