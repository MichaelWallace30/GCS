#include "sidebar.h"
sideBar::sideBar(QWidget *parent) : QWidget(parent)
{
     ugv = new toggleButton();
     uav = new toggleButton();
     waypoint = new toggleButton();
     satellite = new toggleButton();
     opspace = new toggleButton();
     target = new toggleButton();
     uav -> setIcon(QIcon(":/icon/UAVon.png"));
     uav -> setIconSize(QSize(65,65));
     ugv -> setIcon(QIcon(":/icon/ugvOn.png"));
     ugv -> setIconSize(QSize(65,65));
     waypoint -> setIcon(QIcon(":/icon/waypointOn.png"));
     waypoint -> setIconSize(QSize(65,65));
     satellite -> setIcon(QIcon(":/icon/satelliteOn.png"));
     satellite -> setIconSize(QSize(65,65));
     target -> setIcon(QIcon(":/icon/targetOn.png"));
     target -> setIconSize(QSize(65,65));
     opspace -> setIcon(QIcon(":/icon/opspaceOn.png"));
     opspace -> setIconSize(QSize(65,65));
     QGridLayout *mainLayout = new QGridLayout;
     mainLayout ->setContentsMargins(0,0,0,0);
     mainLayout ->setVerticalSpacing(0);
     mainLayout->addWidget(ugv, 0, 0);
     mainLayout->addWidget(uav, 1, 0);
     mainLayout->addWidget(waypoint, 2, 0);
     mainLayout->addWidget(satellite, 3, 0);
     mainLayout->addWidget(target,4,0);
     mainLayout->addWidget(opspace,5,0);
     setLayout(mainLayout);
     connect(uav, SIGNAL(toggled()), this, SLOT(uavToggle()));
     connect(ugv, SIGNAL(toggled()), this, SLOT(ugvToggle()));
     connect(target, SIGNAL(toggled()), this, SLOT(targetToggle()));
     connect(waypoint, SIGNAL(toggled()), this, SLOT(waypointToggle()));
     connect(satellite, SIGNAL(toggled()), this, SLOT(satelliteToggle()));
     connect(opspace, SIGNAL(toggled()), this, SLOT(opspaceToggle()));
}

void sideBar::uavToggle()
{
    if(uav -> checkVisibility())
    {
        uav -> setIcon(QIcon(":/icon/UAVon.png"));
        uav -> setIconSize(QSize(65,65));
        emit uavOn(true);
    }
    else
    {
        uav -> setIcon(QIcon(":/icon/UAVoff.png"));
        uav -> setIconSize(QSize(65,65));
        emit uavOn(false);
    }
}

void sideBar::ugvToggle()
{
    if(ugv -> checkVisibility())
    {
        ugv -> setIcon(QIcon(":/icon/ugvOn.png"));
        emit ugvOn(true);
    }
    else
    {
        ugv -> setIcon(QIcon(":/icon/ugvOff.png"));
        emit ugvOn(false);
    }
}

void sideBar::satelliteToggle()
{
    if(satellite -> checkVisibility())
    {
        satellite -> setIcon(QIcon(":/icon/satelliteOn.png"));
        emit satelliteOn(true);
    }
    else
    {
        satellite -> setIcon(QIcon(":/icon/satelliteOff.png"));
        emit satelliteOn(false);
    }
}

void sideBar::targetToggle()
{
    if(target -> checkVisibility())
    {
        target -> setIcon(QIcon(":/icon/targetOn.png"));
        emit targetOn(true);
    }
    else
    {
        target -> setIcon(QIcon(":/icon/targetOff.png"));
        emit targetOn(false);
    }
}

void sideBar::waypointToggle()
{
    if(waypoint -> checkVisibility())
    {
        waypoint -> setIcon(QIcon(":/icon/waypointOn.png"));
        emit waypointOn(true);
    }
    else
    {
        waypoint -> setIcon(QIcon(":/icon/waypointOff.png"));
        emit waypointOn(false);
    }
}

void sideBar::opspaceToggle()
{
    if(opspace -> checkVisibility())
    {
        opspace -> setIcon(QIcon(":/icon/opspaceOn.png"));
        emit opspaceOn(true);
    }
    else
    {
        opspace -> setIcon(QIcon(":/icon/opspaceOff.png"));
        emit opspaceOn(false);
    }
}
  sideBar::~sideBar()
{
}
