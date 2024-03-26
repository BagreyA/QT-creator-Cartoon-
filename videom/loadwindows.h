
#ifndef LOADWINDOWS_H
#define LOADWINDOWS_H

#include <QMainWindow>
#include <QLabel>
#include <QMovie>

#include <QFont>
#include <QFontDatabase>


QT_BEGIN_NAMESPACE
namespace Ui { class loadwindows; }
QT_END_NAMESPACE

class loadwindows : public QMainWindow

{
    Q_OBJECT

public:
    loadwindows(QWidget *parent = nullptr);
    ~loadwindows();

private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::loadwindows *ui;
};

#endif // LOADWINDOWS_H
