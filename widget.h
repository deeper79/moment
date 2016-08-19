#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPalette>
#include <QFormLayout>
#include <QLabel>
#include <QList>
#include <QString>
#include <QRadioButton>
#include <QGroupBox>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);



    QList<QLineEdit *> plus;
    QList<QLineEdit *> minus;
    QList<QLabel *>    sum;
    QList<QLabel *>    diff;
    QList<QLabel *>    num;

    QLabel *zag1;
    QLabel *zag2;
    QLabel *zag3;
    QLabel *zag4;
    QLabel *title;
    QLabel *izm;

    QLabel *mean;
    QLabel *Max;

    QRadioButton  *kN;
    QRadioButton  *N;
    QRadioButton  *Kg;

    QRadioButton  *UM;
    QRadioButton  *KU;

     QGroupBox *boxRadio;
      QGroupBox *boxRadio1;
     float test;
     QString prev;

  //  QRadioButton  *kN_c;
  //  QRadioButton  *N_c;
  //  QRadioButton  *Kg_c;



signals:

public slots:
     void data_change();
     void chek_kN();
     void chek_N();
     void chek_kg();
};

#endif // WIDGET_H
