#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Appointment.h"

class Employee {
public:
    Employee(const std::string &name);

    void viewAppointments(std::vector<Appointment> appointments, const std::string& name) const;
    void approveAppointment(std::vector<Appointment> &appointments, const std::string &appointmentId, const std::string& name, const std::string &email);
    void rejectAppointment(std::vector<Appointment> &appointments, const std::string &appointmentId, const std::string& name, const std::string &email);
    const std::string& getName() const;

private:
    std::string name;
    std::vector<Appointment> appointments;
};

#endif // EMPLOYEE_H
