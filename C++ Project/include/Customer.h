#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Appointment.h"

class Customer {
public:
    Customer(const std::string &name, const std::string &email);

    void viewAppointments(std::vector<Appointment> appointments,const std::string& email) const;
    void makeAppointment(const Appointment &appointment);
    void changeAppointment(std::vector<Appointment> &appointments, const std::string &appointmentId, const Appointment &newAppointment);
    void deleteAppointment(std::vector<Appointment> &appointments, const std::string &appointmentId);

    const std::string& getName() const;
    const std::string& getEmail() const;

private:
    std::string name;
    std::string email;
    std::vector<Appointment> appointments;
};

#endif // CUSTOMER_H
