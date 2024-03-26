#include "cartoon.h"
#include "ui_cartoon.h"

#define dx 50
#define speedCar 20
#define stopedCar 20
#define pr 30

cartoon::cartoon(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cartoon)
{
    ui->setupUi(this);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/title");
    QFont font;
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

    font.setFamily(fontFamilies.at(0));
    font.setBold(true);

    ui->endText->setFont(font);

    ui->endText->setStyleSheet("font-size: 60px;");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(carStart()));
    timer->start(100);
}

cartoon::~cartoon()
{
    delete ui;
}


int statusLocation = 0;

int carTime = 0;
int endFly = 0;
int bgStatus = 0;
int itemSt = 0;
int dialog = 0;
void cartoon::carStart(){

    if(statusLocation == 0){
        if(ui->hellicopter->geometry().x() < 1250 && endFly == 0){
            ui->hellicopter->setPixmap(QPixmap(":/image/hellcopter"));
            ui->hellicopter_2->setPixmap(QPixmap(":/image/hellcopter"));
            ui->hellicopter->setGeometry(ui->hellicopter->geometry().x() + dx, ui->hellicopter->geometry().y(), ui->hellicopter->width(), ui->hellicopter->height());
            ui->hellicopter_2->setGeometry(ui->hellicopter_2->geometry().x() + dx, ui->hellicopter_2->geometry().y(), ui->hellicopter_2->width(), ui->hellicopter_2->height());
        }else{
            endFly = 1;
            ui->person->hide();
        }

        if(endFly == 1){
    //      первый переход
            if(ui->background->geometry().x() > -1200 && bgStatus == 0){
                if(ui->background->geometry().x() > -1000){
                    ui->friendly->setGeometry(ui->friendly->geometry().x() - pr, ui->friendly->geometry().y(), ui->friendly->width(), ui->friendly->height());
                    ui->defCar->setGeometry(ui->defCar->geometry().x() - pr, ui->defCar->geometry().y(), ui->defCar->width(), ui->defCar->height());
                }else{
                    ui->friendly->hide();
                    ui->defCar->hide();
                    ui->mainCar->raise();
                }
                if(ui->mainCar->geometry().x() < 300){
                    ui->mainCar->setGeometry(ui->mainCar->geometry().x() + speedCar, ui->mainCar->geometry().y(), ui->mainCar->width(), ui->mainCar->height());
                }

                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 0){
                    bgStatus = 1;
                    ui->background->setPixmap(QPixmap(":/image/back3"));
                    ui->background->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      второй переход
            if(ui->background_2->geometry().x() > -1200 && bgStatus == 1){
                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 1){
                    bgStatus = 2;
                    ui->background_2->setPixmap(QPixmap(":/image/back4"));
                    ui->background_2->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      третий переход
            if(ui->background->geometry().x() > -1200 && bgStatus == 2){
                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 2){
                    bgStatus = 3;
                    ui->background->setPixmap(QPixmap(":/image/back5"));
                    ui->background->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      четвертый переход
            if(ui->background_2->geometry().x() > -1200 && bgStatus == 3){

                if(ui->trashCar_1->geometry().x() > - 300){
                    ui->trashCar_1->setPixmap(QPixmap(":/image/car2"));
                    ui->trashCar_1->setGeometry(ui->trashCar_1->geometry().x() - 100, ui->trashCar_1->geometry().y(), ui->trashCar_1->width(), ui->trashCar_1->height());
                }else{
                    ui->trashCar_1->hide();
                }

                if(ui->mainCar->geometry().x() > 100){
                    ui->mainCar->setGeometry(ui->mainCar->geometry().x() - speedCar, ui->mainCar->geometry().y() + 5, ui->mainCar->width(), ui->mainCar->height());
                }

                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 3){
                    bgStatus = 4;
                    ui->background_2->setPixmap(QPixmap(":/image/back6"));
                    ui->background_2->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      пятый переход
            if(ui->background->geometry().x() > -1200 && bgStatus == 4){

                if(ui->trashCar_2->geometry().x() > -300){
                    ui->trashCar_2->setPixmap(QPixmap(":/image/car5"));
                    ui->trashCar_2->raise();
                    ui->trashCar_2->setGeometry(ui->trashCar_2->geometry().x() - 100, ui->trashCar_2->geometry().y(), ui->trashCar_2->width(), ui->trashCar_2->height());
                }else{
                    ui->trashCar_2->hide();
                }

                if(ui->mainCar->geometry().x() < 200){
                    ui->mainCar->setGeometry(ui->mainCar->geometry().x() + speedCar, ui->mainCar->geometry().y() - 10, ui->mainCar->width(), ui->mainCar->height());
                }

                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 4){
                    bgStatus = 5;
                    ui->background->setPixmap(QPixmap(":/image/back7"));
                    ui->background->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      шестой переход
            if(ui->background_2->geometry().x() > -1200 && bgStatus == 5){

                if(ui->mainCar->geometry().x() < 300){
                    ui->mainCar->setGeometry(ui->mainCar->geometry().x() + speedCar, ui->mainCar->geometry().y(), ui->mainCar->width(), ui->mainCar->height());
                }

                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 5){
                    bgStatus = 6;
                    ui->background_2->setPixmap(QPixmap(":/image/back8"));
                    ui->hellDown->setPixmap(QPixmap(":/image/hellcopter"));
                    ui->background_2->setGeometry(1200, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                    ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
                }
            }

    //      заключительный переход
            if(ui->background->geometry().x() > -1200 && bgStatus == 6){

                if(ui->hellDown->geometry().y() < 700){
                    if(ui->hellDown->geometry().x() < 500){
                        ui->hellDown->setGeometry(ui->hellDown->geometry().x() + 30, ui->hellDown->geometry().y() + 30, ui->hellDown->width(), ui->hellDown->height());
                    }else{
                        ui->hellDown->setGeometry(ui->hellDown->geometry().x() + 30, ui->hellDown->geometry().y() - 50, ui->hellDown->width(), ui->hellDown->height());
                        ui->brick->setPixmap(QPixmap(":/image/brickMeme"));
                        ui->brick->raise();
                        ui->brick->setGeometry(ui->brick->geometry().x() - 14, ui->brick->geometry().y() + 30, ui->brick->width(), ui->brick->height());
                    }
                }


                if(ui->mainCar->geometry().x() > 100){
                    ui->mainCar->setGeometry(ui->mainCar->geometry().x() - speedCar, ui->mainCar->geometry().y(), ui->mainCar->width(), ui->mainCar->height());
                }

                ui->background->setGeometry(ui->background->geometry().x() - dx, ui->background->y(), ui->background->width(), ui->background->height());
                ui->background_2->setGeometry(ui->background_2->geometry().x() - dx, ui->background_2->y(), ui->background_2->width(), ui->background_2->height());
            }else{
                if(bgStatus == 6){
                    statusLocation = 1;
                    bgStatus = 7;
                }
            }

        }
    }

    if(statusLocation == 1){

        if(ui->wp_1->geometry().x() > 800 && itemSt == 0){
            ui->wp_1->setPixmap(QPixmap(":/image/warrier"));
            ui->wp_1->setGeometry(ui->wp_1->geometry().x() - 20, ui->wp_1->geometry().y(), ui->wp_1->width(), ui->wp_1->height());
            ui->wp_2->setPixmap(QPixmap(":/image/warrier"));
            ui->wp_2->setGeometry(ui->wp_2->geometry().x() - 30, ui->wp_2->geometry().y(), ui->wp_2->width(), ui->wp_2->height());
            ui->wp_3->setPixmap(QPixmap(":/image/warrier"));
            ui->wp_3->setGeometry(ui->wp_3->geometry().x() - 10, ui->wp_3->geometry().y(), ui->wp_3->width(), ui->wp_3->height());
        }else{
            if(itemSt == 0){
                itemSt = 1;
                ui->person->show();
            }
        }

        if(ui->flyCar->geometry().x() > 600 && itemSt == 1){
            ui->flyCar->setPixmap(QPixmap(":/image/jump"));
            if(ui->flyCar->geometry().x() > 700 && ui->flyCar->geometry().x() < 780){
                ui->wp_1->hide();
                ui->wp_2->hide();
                ui->wp_3->hide();
            }
            ui->flyCar->setGeometry(ui->flyCar->geometry().x() - 50, ui->flyCar->geometry().y() + 30, ui->flyCar->width(), ui->flyCar->height());
        }else{
            if(itemSt == 1){
                itemSt = 2;
            }
        }

        if(itemSt == 2){
            ui->friendly->setGeometry(ui->flyCar->geometry().x(), ui->flyCar->geometry().y(), ui->flyCar->width(), ui->flyCar->height());
            ui->friendly->raise();
            ui->friendly->show();
            ui->person->setPixmap(QPixmap(":/image/person1"));
            ui->brick->hide();

            ui->textd_1->setStyleSheet("font-size: 20px; font-weight: bold;");
            ui->textd_2->setStyleSheet("font-size: 20px; font-weight: bold;");

            if(dialog < 12){
                ui->textd_1->setText("Спасибо, брат! Выручил =)");
                dialog++;
            }else{
                if(dialog < 24){
                    ui->textd_1->setText("");
                    ui->textd_2->setText("Всегда рад помочь, брат))");
                    dialog++;
                }else{
                    ui->textd_2->setText("");
                    if(dialog < 47){
                        if(dialog == 28){
                            ui->endText->setText("К|");
                        }
                        if(dialog == 31){
                            ui->endText->setText("Ко|");
                        }
                        if(dialog == 34){
                            ui->endText->setText("Кон|");
                        }
                        if(dialog == 37){
                            ui->endText->setText("Коне|");
                        }
                        if(dialog == 40){
                            ui->endText->setText("Конец|");
                        }
                        if(dialog == 43){
                            ui->endText->setText("Конец!|");
                        }
                        if(dialog == 46){
                            ui->endText->setText("Конец!");
                        }
                        dialog++;
                    }
                }
            }

        }

    }

}
