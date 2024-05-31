#include "Appointment.h"
#include <iostream>

Appointment::Appointment(const std::string &procedure, const std::string &time, const std::string &customerEmail,const std::string &dentist_name)
    : procedure(procedure), time(time), customerEmail(customerEmail), status("Pending"), dentist_name(dentist_name) {}

void Appointment::display() const {
    std::cout << "Appointment Procedure: " << procedure << ", Time: " << time << ", Customer Email: " << customerEmail
              << ", Status: " << status  << ",Dentist: " << dentist_name << std::endl;
}

const std::string& Appointment::getProcedure() const {
    return procedure;
}

const std::string& Appointment::getTime() const {
    return time;
}

const std::string& Appointment::getCustomerEmail() const {
    return customerEmail;
}

const std::string& Appointment::getStatus() const {
    return status;
}

void Appointment::setTime(const std::string &time) {
    this->time = time;
}

void Appointment::setStatus(const std::string &status) {
    this->status = status;
}
const std::string& Appointment::getDentist_name() const {
    return dentist_name;
}
