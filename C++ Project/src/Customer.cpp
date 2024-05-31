#include "Customer.h"
#include <iostream>
#include <algorithm>
#include <string.h>
Customer::Customer(const std::string &name, const std::string &email)
    : name(name), email(email) {}

void Customer::viewAppointments(std::vector<Appointment> appointments, const std::string& email) const {
    bool ok = false;
    for (std::vector<Appointment>::const_iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if(it->getCustomerEmail() == email){
             it->display();
             ok = true;
        }
    }
    if (ok == false){
        std:: cout << "There are no appointments." << std :: endl;
    }
}

void Customer::makeAppointment(const Appointment &appointment) {
    appointments.push_back(appointment);
}

void Customer::changeAppointment(std::vector<Appointment> &appointments, const std::string &appointmentTime, const Appointment &newAppointment) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime) {
            *it = newAppointment;
            return;
        }
    }
}

void Customer::deleteAppointment(std::vector<Appointment> &appointments,const std::string &appointmentTime) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime) {
            appointments.erase(it);
            return;
        }
    }
}

const std::string& Customer::getName() const {
    return name;
}

const std::string& Customer::getEmail() const {
    return email;
}
