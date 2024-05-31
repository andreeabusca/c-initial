#include "Employee.h"
#include <iostream>
#include <algorithm>

Employee::Employee(const std::string &name)
    : name(name){}

void Employee::viewAppointments(std::vector<Appointment> appointments, const std::string& name) const {
    bool ok = false;
    for (std::vector<Appointment>::const_iterator it = appointments.begin(); it != appointments.end(); ++it) {
            if (it->getDentist_name() == name){
                it->display();
                ok = true;
            }
    }
    if (ok == false){
        std :: cout << "\tThere are no appointments." << std :: endl;
    }
}

void Employee::approveAppointment(std::vector<Appointment> &appointments,const std::string &appointmentTime, const std::string& name, const std::string &email) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime && it->getDentist_name() == name && it->getCustomerEmail() == email) {
            it->setStatus("Approved");
            return;
        }
    }
}

void Employee::rejectAppointment(std::vector<Appointment> &appointments,const std::string &appointmentTime, const std::string& name, const std::string &email) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime && it->getDentist_name() == name && it->getCustomerEmail() == email) {
            it->setStatus("Rejected");
            return;
        }
    }
}

const std::string& Employee::getName() const {
    return name;
}

