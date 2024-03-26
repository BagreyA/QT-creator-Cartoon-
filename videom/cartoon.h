#ifndef CARTOON_H
#define CARTOON_H

#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

#include <QFont>
#include <QFontDatabase>

namespace Ui {
class cartoon;
}

class cartoon : public QMainWindow
{
    Q_OBJECT

public:
    explicit cartoon(QWidget *parent = nullptr);
    ~cartoon();
    QTimer *timer;

public slots:
    void carStart();

private:
    Ui::cartoon *ui;
};

#endif // CARTOON_H
