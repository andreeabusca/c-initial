#include "Employee.h"
#include <iostream>
#include <algorithm>

Employee::Employee(const std::string &name, const std::string &position)
    : name(name), position(position) {}

void Employee::viewAppointments() const {
    for (std::vector<Appointment>::const_iterator it = appointments.begin(); it != appointments.end(); ++it) {
        it->display();
    }
}

void Employee::addAppointment(const Appointment &appointment) {
    appointments.push_back(appointment);
}

void Employee::approveAppointment(const std::string &appointmentTime) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime) {
            it->setStatus("Approved");
            return;
        }
    }
}

void Employee::rejectAppointment(const std::string &appointmentTime) {
    for (std::vector<Appointment>::iterator it = appointments.begin(); it != appointments.end(); ++it) {
        if (it->getTime() == appointmentTime) {
            it->setStatus("Rejected");
            return;
        }
    }
}

