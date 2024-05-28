#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Appointment.h"

class Employee {
public:
    Employee(const std::string &name, const std::string &position);

    void viewAppointments() const;
    void addAppointment(const Appointment &appointment);
    void approveAppointment(const std::string &appointmentId);
    void rejectAppointment(const std::string &appointmentId);

private:
    std::string name;
    std::string position;
    std::vector<Appointment> appointments;
};

#endif // EMPLOYEE_H
