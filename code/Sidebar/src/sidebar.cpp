#include "../include/sidebar.h"
sideBar::sideBar(QWidget *parent) : QWidget(parent)
{
     ugv = new toggleButton();
     uav = new toggleButton();
     waypoint = new toggleButton();
     satellite = new toggleButton();
     opspace = new toggleButton();
     target = new toggleButton();
     uav -> setIcon(QIcon(":/icons/icon/UAVon.png"));
     uav -> setIconSize(QSize(65,65));
     ugv -> setIcon(QIcon(":/icons/icon/ugvOn.png"));
     ugv -> setIconSize(QSize(65,65));
     waypoint -> setIcon(QIcon(":/icons/icon/waypointOn.png"));
     waypoint -> setIconSize(QSize(65,65));
     satellite -> setIcon(QIcon(":/icons/icon/satelliteOn.png"));
     satellite -> setIconSize(QSize(65,65));
     target -> setIcon(QIcon(":/icons/icon/targetOn.png"));
     target -> setIconSize(QSize(65,65));
     opspace -> setIcon(QIcon(":/icons/icon/opspaceOn.png"));
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
     connect(target, SIGNAL(toggled()), this, SLOT(targetToggle()));
     connect(opspace, SIGNAL(toggled()), this, SLOT(opspaceToggle()));
}

void sideBar::uavToggle()
{
    if(uav -> checkVisibility())
    {
        uav -> setIcon(QIcon(":/icons/icon/UAVon.png"));
        uav -> setIconSize(QSize(65,65));
        emit uavOn();
    }
    else
    {
        uav -> setIcon(QIcon(":/icons/icon/UAVoff.png"));
        uav -> setIconSize(QSize(65,65));
        emit uavOff();
    }
}

void sideBar::ugvToggle()
{
    if(ugv -> checkVisibility())
    {
        ugv -> setIcon(QIcon(":/icons/icon/ugvOn.png"));
        emit ugvOn();
    }
    else
    {
        ugv -> setIcon(QIcon(":/icons/icon/ugvOff.png"));
        emit ugvOff();
    }
}

void sideBar::satelliteToggle()
{
    if(satellite -> checkVisibility())
    {
        satellite -> setIcon(QIcon(":/icons/icon/satelliteOn.png"));
        emit satelliteOn();
    }
    else
    {
        satellite -> setIcon(QIcon(":/icons/icon/satelliteOff.png"));
        emit satelliteOff();
    }
}

void sideBar::targetToggle()
{
    if(target -> checkVisibility())
    {
        target -> setIcon(QIcon(":/icons/icon/targetOn.png"));
        emit targetOn();
    }
    else
    {
        target -> setIcon(QIcon(":/icons/icon/targetOff.png"));
        emit targetOff();
    }
}

void sideBar::waypointToggle()
{
    if(waypoint -> checkVisibility())
    {
        waypoint -> setIcon(QIcon(":/icons/icon/waypointOn.png"));
        emit waypointOn();
    }
    else
    {
        waypoint -> setIcon(QIcon(":/icons/icon/waypointOff.png"));
        emit waypointOff();
    }
}

void sideBar::opspaceToggle()
{
    if(opspace -> checkVisibility())
    {
        opspace -> setIcon(QIcon(":/icons/icon/opspaceOn.png"));
        emit opspaceOn();
    }
    else
    {
        opspace -> setIcon(QIcon(":/icons/icon/opspaceOff.png"));
        emit opspaceOff();
    }
}
  sideBar::~sideBar()
{
}
