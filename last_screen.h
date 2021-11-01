#ifndef LAST_SCREEN_H
#define LAST_SCREEN_H

#include <QWidget>

namespace Ui {
class Last_Screen;
}

class Last_Screen : public QWidget
{
    Q_OBJECT

public:
    explicit Last_Screen(QWidget *parent = nullptr);
    ~Last_Screen();

private:
    Ui::Last_Screen *ui;
};

#endif // LAST_SCREEN_H
