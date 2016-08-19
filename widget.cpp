#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent),prev("kN")

{
    QPalette pal;

    zag1 = new QLabel("Измерение +");
    zag2 = new QLabel("Измерение -");
    zag3 = new QLabel("Среднее");
    zag4 = new QLabel("Средняя разность");
    izm = new QLabel("Единицы измерения");
    title = new QLabel("Проверка момента трения и дисбаланса");
    QLabel *mean_text = new QLabel("Момент трения");
    QLabel *Max_text = new QLabel("Момент дисбаланса");
    QLabel *Os = new QLabel("Проверка оси:");
    mean = new QLabel("0.0");
    Max = new QLabel("0.0");



    kN = new QRadioButton("кН");
    N  = new QRadioButton("Н");
    Kg = new QRadioButton("кг");

    UM  = new QRadioButton("УМ");
    KU  = new QRadioButton("KУ");

    izm->setStyleSheet("color: white; font-size: 16px");

    QGridLayout *lay = new QGridLayout();
    boxRadio = new QGroupBox(this);

    QGridLayout *lay1 = new QGridLayout();
    boxRadio1 = new QGroupBox(this);

    kN->setStyleSheet("color: white; font-size: 16px");
    N->setStyleSheet("color: white; font-size: 16px");
    Kg->setStyleSheet("color: white; font-size: 16px");
    mean_text->setStyleSheet("color: white; font-size: 16px");
    mean->setStyleSheet("color: white; font-size: 16px");
    Max->setStyleSheet("color: white; font-size: 16px");
    Max_text->setStyleSheet("color: white; font-size: 16px");

    Os->setStyleSheet("color: white; font-size: 16px");
    KU->setStyleSheet("color: white; font-size: 16px");
    UM->setStyleSheet("color: white; font-size: 16px");
    Os->setAlignment(Qt::AlignCenter);

    Max_text->setAlignment(Qt::AlignCenter);
    Max->setAlignment(Qt::AlignCenter);

    mean_text->setAlignment(Qt::AlignCenter);
    mean->setAlignment(Qt::AlignCenter);

    izm->setAlignment(Qt::AlignCenter);

    lay->addWidget(izm,0,0,1,3);
    lay->addWidget(kN,1,0,1,1);
    lay->addWidget(N,1,1,1,1);
    lay->addWidget(Kg,1,2,1,1);
    kN->setChecked(true);
    boxRadio->setLayout(lay);

    lay1->addWidget(Os,0,0,1,3);
    lay1->addWidget(KU,1,1,1,1);
    lay1->addWidget(UM,1,2,1,1);
    KU->setChecked(true);
    boxRadio1->setLayout(lay1);

    zag1->setAlignment(Qt::AlignCenter);
    zag2->setAlignment(Qt::AlignCenter);
    zag3->setAlignment(Qt::AlignCenter);
    zag4->setAlignment(Qt::AlignCenter);
    title->setAlignment(Qt::AlignCenter);



    zag1->setStyleSheet("color: white; font-size: 16px");
    zag2->setStyleSheet("color: white; font-size: 16px");
    zag3->setStyleSheet("color: white; font-size: 16px");
    zag4->setStyleSheet("color: white; font-size: 16px");



    title->setStyleSheet("color: white; font-size: 20px");



    QGridLayout *layout = new QGridLayout();




    layout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    layout->setHorizontalSpacing(50);

    layout->addWidget(title ,0,0,1,5);


    layout->addWidget(boxRadio,2,1,1,1);
    layout->addWidget(boxRadio1,2,2,1,1);


    layout->addWidget(zag1 ,3,1,1,1);
    layout->addWidget(zag2 ,3,2,1,1);
    layout->addWidget(zag3 ,3,3,1,1);
    layout->addWidget(zag4 ,3,4,1,1);


    setLayout(layout);
    for(int i=0;i<12;i++){
        plus << new QLineEdit();
        minus<< new QLineEdit();
        sum  << new QLabel();
        diff << new QLabel();
        num  << new QLabel();
    }

    for(int i=0;i<12;i++){


        sum[i] ->setText("0.0");
        diff[i]->setText("0.0");
        num[i] ->setText(QString::number(i+1));

        plus[i] ->setStyleSheet(" font-size: 16px");
        minus[i]->setStyleSheet(" font-size: 16px");
        sum[i]  ->setStyleSheet("color: white; font-size: 16px");
        diff[i] ->setStyleSheet("color: white; font-size: 16px");
        num[i]  ->setStyleSheet("color: white; font-size: 16px");

        plus[i] ->setAlignment(Qt::AlignCenter);
        minus[i]->setAlignment(Qt::AlignCenter);
        sum[i]  ->setAlignment(Qt::AlignCenter);
        diff[i] ->setAlignment(Qt::AlignCenter);
        num[i]  ->setAlignment(Qt::AlignCenter);

        layout->addWidget(num[i] , i+4,0,1,1);
        layout->addWidget(plus[i] ,i+4,1,1,1);
        layout->addWidget(minus[i],i+4,2,1,1);
        layout->addWidget(sum[i],  i+4,3,1,1);
        layout->addWidget(diff[i], i+4,4,1,1);

        layout->addWidget(mean_text,16,3,1,1);
        layout->addWidget(Max_text ,16,4,1,1);
        layout->addWidget(mean     ,17,3,1,1);
        layout->addWidget(Max      ,17,4,1,1);


    }
    for(int i=0;i<12;i++){
        connect(plus[i],  SIGNAL(textEdited(const QString)), this, SLOT(data_change()));
        connect(minus[i], SIGNAL(textEdited(const QString)), this, SLOT(data_change()));

    }


    connect(kN, SIGNAL(toggled(bool)), this, SLOT(chek_kN()));
    connect(N,  SIGNAL(toggled(bool)), this, SLOT(chek_N()));
    connect(Kg, SIGNAL(toggled(bool)), this, SLOT(chek_kg()));
    connect(KU, SIGNAL(toggled(bool)), this, SLOT(data_change()));
    connect(UM, SIGNAL(toggled(bool)), this, SLOT(data_change()));

    pal.setColor(backgroundRole(),Qt::darkGreen);
    setAutoFillBackground(true);
    setGeometry(0,0,800,600);
    setPalette(pal);





}
void Widget::data_change(){
    float sum_m =0;
    double koef = 1.0;
    double max = 0;
    int iter = 0;

    if(KU->isChecked()) koef = 0.95;
    else                koef = 0.2;

    if(kN->isChecked()) koef *=1000;
    if(Kg->isChecked()) koef *=10;



    for(int i=0;i<12;i++){
        float a = plus[i] ->text().toFloat();
        float b = minus[i]->text().toFloat();
        if(a != 0 || b != 0){
            sum_m +=a;
            iter++;
        }
        sum[i]->setText(QString::number((a+b)/2));
        diff[i]->setText(QString::number((a-b)/2));

    }
    sum_m = sum_m/iter;

    max =  diff[0]->text().toFloat();

    double temp = max;

    for(int i=1;i<12;i++){
        temp = diff[i]->text().toFloat();
        if(temp<0) temp *=-1;

        if(max<temp) max = temp;

    }



    mean->setText(QString::number(sum_m*koef)+" Нм");
    Max ->setText(QString::number(max*koef)  +" Нм");
}


void Widget::chek_kN(){
    double koef = 0;

    if(kN->isChecked()){

        if(prev == "N")  koef = 0.001;
        if(prev == "Kg") koef = 0.01;


        for(int i=0;i<12;i++){
            plus[i] ->setText(QString::number(plus[i] ->text().toFloat()*koef));
            minus[i]->setText(QString::number(minus[i]->text().toFloat()*koef));
        }

       // prev = "kN";
       // data_change();

    }
}

void Widget::chek_N(){

    double koef = 0;

    if(N->isChecked()){

        if(prev == "kN")  koef = 1000.0;
        if(prev == "Kg")  koef = 10;

        for(int i=0;i<12;i++){
            plus[i] ->setText(QString::number(plus[i] ->text().toFloat()*koef));
            minus[i]->setText(QString::number(minus[i]->text().toFloat()*koef));
        }
        prev = "N";
        data_change();

    }

}

void Widget::chek_kg(){

    double koef = 0;

    if(Kg->isChecked()){

        if(prev == "kN") koef = 100.0;
        if(prev == "N")  koef = 0.1;

        for(int i=0;i<12;i++){

            plus[i] ->setText(QString::number(plus[i] ->text().toFloat()*koef));
            minus[i]->setText(QString::number(minus[i]->text().toFloat()*koef));
        }

        prev = "Kg";
        data_change();

    }

}

