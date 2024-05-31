#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
public:
    Appointment(const std::string &procedure, const std::string &time, const std::string &customerEmail, const std::string &dentist_name);

    void display() const;

    const std::string& getProcedure() const;
    const std::string& getTime() const;
    const std::string& getCustomerEmail() const;
    const std::string& getDentist_name() const;
    const std::string& getStatus() const;

    void setTime(const std::string &time);
    void setStatus(const std::string &status);

private:
    std::string procedure;
    std::string time;
    std::string customerEmail;
    std::string dentist_name;
    std::string status;
};

#endif // APPOINTMENT_H
