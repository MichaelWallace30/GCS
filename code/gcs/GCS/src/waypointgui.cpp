#include "waypointgui.h"
#include <QDebug>

WaypointGUI::WaypointGUI(QWidget *parent, Vehicle22* vech) :
    QWidget(parent)
{
    /* Type defn
        0 insert
        1 edit
        2 erase
    */
    //Initialize and set up buttons & mouse over
    mainLayout = new QGridLayout();
    mainLayout->setMargin( 0 );
    WaypointB = new QPushButton();
    WaypointB->setText("Send Waypoint");
    vehicle = new QLineEdit();
    vehicle->setToolTip("Vehicle");
    latitude = new QLineEdit();
    latitude->setToolTip("Latitude");
    longitude = new QLineEdit();
    longitude->setToolTip("Longitude");
    altitude = new QLineEdit();
    altitude->setToolTip("Altitude");
    heading = new QLineEdit();
    heading->setToolTip("Heading");
    id = new QLineEdit();
    id->setToolTip("ID");
    type = new QLineEdit();
    type->setToolTip("Type");

    //Create and set labels for user input
    vIDLabel = new QLabel("VehicleID");
    wIDLabel = new QLabel("WaypointID");
    typeLabel = new QLabel("Type");
    latLabel = new QLabel("Lat");
    lonLabel = new QLabel("Lon");
    altLabel = new QLabel("Alt");
    headingLabel = new QLabel("Heading");

    //Add widgets to layout
    mainLayout->addWidget(WaypointB,1,0);
    mainLayout->addWidget(vIDLabel, 1, 1);
    mainLayout->addWidget(vehicle,1,2);
    mainLayout->addWidget(wIDLabel,1,3);
    mainLayout->addWidget(id,1,4);
    mainLayout->addWidget(typeLabel,1,5);
    mainLayout->addWidget(type,1,6);
    mainLayout->addWidget(latLabel,1,7);
    mainLayout->addWidget(latitude,1,8);
    mainLayout->addWidget(lonLabel,1,9);
    mainLayout->addWidget(longitude,1,10);
    mainLayout->addWidget(altLabel,1,11);
    mainLayout->addWidget(altitude,1,12);
    mainLayout->addWidget(headingLabel,1,13);
    mainLayout->addWidget(heading,1,14);

    //Set Widget layout
    setLayout( mainLayout );
    connect(WaypointB,SIGNAL(clicked()),this,SLOT(send_waypoint()));
    v = vech;
}

void WaypointGUI::send_waypoint()
{
    Waypoint22* w = new Waypoint22(id->text().toInt(),
                         type->text().toInt(),
                         latitude->text().toDouble(),
                         longitude->text().toDouble(),
                         altitude->text().toInt(),
                         0);

    mutex.lock();
    v->appendWaypoint(w, Qt::green );
    mutex.unlock();
    emit waypoint(vehicle->text().toInt());
}

void WaypointGUI::coordDesignated(double lat, double lon){
    latitude->setText(QString("%1").arg(lat, 0, 'f'));
    longitude->setText(QString("%1").arg(lon, 0, 'f'));
}
