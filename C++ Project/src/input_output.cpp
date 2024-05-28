#include "input_output.h"
#include <fstream>
#include <sstream>

void input_output::writeAppointmentsToCSV(const std::string &filename, const std::vector<Appointment> &appointments) {
    std::ofstream file(filename.c_str());
    if (file.is_open()) {
        file << "Procedure,Time,CustomerEmail,Status\n";
        for (std::vector<Appointment>::const_iterator it = appointments.begin(); it != appointments.end(); ++it) {
            file << it->getProcedure() << "," << it->getTime() << ","
                 << it->getCustomerEmail() << "," << it->getStatus() << "\n";
        }
        file.close();
    }
}

std::vector<Appointment> input_output::readAppointmentsFromCSV(const std::string &filename) {
    std::vector<Appointment> appointments;
    std::ifstream file(filename.c_str());
    if (file.is_open()) {
        std::string line;
        getline(file, line); // Skip the header line
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string procedure, time, customerEmail, status;
            getline(ss, procedure, ',');
            getline(ss, time, ',');
            getline(ss, customerEmail, ',');
            getline(ss, status, ',');
            Appointment appointment(procedure, time, customerEmail);
            appointment.setStatus(status);
            appointments.push_back(appointment);
        }
        file.close();
    }
    return appointments;
}
