
#include "loadwindows.h"
#include "ui_loadwindows.h"
#include "cartoon.h"


loadwindows::loadwindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loadwindows)
{
    ui->setupUi(this);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/title");
    QFont font;
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

    font.setFamily(fontFamilies.at(0));
    font.setBold(true);

    ui->title->setFont(font);
    ui->title->setStyleSheet("font-size: 35px;");

}

loadwindows::~loadwindows()
{
    delete ui;
}

void loadwindows::on_startButton_clicked()
{
    hide();
    cartoon *w = new cartoon;
    w->show();
}


void loadwindows::on_exitButton_clicked()
{
    QApplication::exit();
}

