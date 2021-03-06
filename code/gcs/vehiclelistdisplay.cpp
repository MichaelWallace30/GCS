#include "vehiclelistdisplay.h"


VehicleListDisplay::VehicleListDisplay(QWidget *parent) :
    QWidget(parent),
    node(new comnet::Comms(1))
{
    node->InitConnection(UDP_LINK, "1337", "127.0.0.1");
    node->AddAddress(2, "127.0.0.1", 1338);
    node->Run();
}

//Sets the local vehicle pointer list
void VehicleListDisplay::setList(vehicle_list *list){
    vList = list;
    for(int i = 0; i < list->length(); i++){
        VehicleElementDisplay *element = new VehicleElementDisplay();
        element->setVehicle(vList->at(i));
        vehicleList->append(element);
    }
    return;
}

/**
 * @brief VehicleListDisplay::updateDisplay
 * Updates the display with the given id
 * @param id id of the vehicle to update
 */
void VehicleListDisplay::updateDisplay(int id){

}

