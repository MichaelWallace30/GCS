#ifndef TARGETINGGUI_H
#define TARGETINGGUI_H

//Qt includes
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>

class targetingGUI : public QWidget
{
    Q_OBJECT
public:
    explicit targetingGUI(QWidget *parent = 0);

signals:
    void target(float,float,float);

public slots:
    void targetsend();

private:
   void initGUIElements();
   void setGUIElementText();
   void addGUIElementToLayout();
   QGridLayout* mainLayout;
   QPushButton* targets;
   QLineEdit* latitude;
   QLineEdit* longitude;
   QLineEdit* altitude;
   QLabel* lat;
   QLabel* longi;
   QLabel* alt;

};

#endif // TARGETINGGUI_H
