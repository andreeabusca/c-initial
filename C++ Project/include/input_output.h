#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H


#include <vector>
#include <string>
#include "Appointment.h"

class input_output {
public:
    static void writeAppointmentsToCSV(const std::string &filename, const std::vector<Appointment> &appointments);
    static std::vector<Appointment> readAppointmentsFromCSV(const std::string &filename);
};

#endif // CSVHANDLER_H
