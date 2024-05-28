#include <iostream>
#include "Customer.h"
#include "Employee.h"
#include "input_output.h"
#include <stdlib.h>
#include <string.h>
std::vector<Appointment> readAppointments = input_output::readAppointmentsFromCSV("appointments.csv");
void procedure_menu(){
    std::cout << "1.Dental Cleanings" << std::endl;
    std::cout << "2.Fillings" << std::endl;
    std::cout << "3.Extraction" << std::endl;
    std::cout << "4.Root Canal Treatment" << std::endl;
    std::cout << "5.Implant" << std::endl;
}
void menu_customer(Customer customer){
    std :: cout << "\t1.Make appointment" << std :: endl;
    std :: cout << "\t2.See your appointments" << std:: endl;
    std :: cout << "\t3.Exit" << std :: endl;

    std :: cout << "Choose action: ";
    int choice;
    std :: cin >> choice;
    if (choice == 1){
        procedure_menu();
        std::cout << "Enter procedure number: ";
        char procedure_number[2];
        std::cin >> procedure_number;
        std::cout << "Enter time of procedure (ex: 2024-06-01 11:00):";
        char procedure_time[60];
        std::cin >> procedure_time;
        Appointment app(procedure_number,procedure_time,customer.getEmail());
        customer.makeAppointment(app);
        readAppointments.push_back(app);
        std::cout << "New appointment registered" << std::endl;

        menu_customer(customer);

    }else if (choice == 2){
        customer.viewAppointments(readAppointments,customer.getEmail());
        std :: cout << "\tWhat do you want to do next?:" << std :: endl;
        std :: cout << "\t1.Change Appointment Time" << std:: endl;
        std :: cout << "\t2.Delete Appointment" << std :: endl;
        std :: cout << "\t3.None of the above" << std :: endl;
        int choice_2;
        std :: cout << "\t My choice: ";
        std :: cin >> choice_2;
        if (choice_2 == 1){
               std::cout << "Enter new procedure (if you don't want to change procedure, type the old one): ";
               char newprocedure[60];
               std::cin >> newprocedure;
               std::cout << "Enter old time: ";
                char oldprocedure_time[60];
               std::cin >> oldprocedure_time;
               std::cout << "Enter new time: ";
               char newprocedure_time[60];
               std::cin >> newprocedure_time;
               Appointment appc(newprocedure,newprocedure_time,customer.getEmail());
               customer.changeAppointment(oldprocedure_time,appc);
               std::cout << "Appointment change successfully! ";
               menu_customer(customer);


        }else if (choice_2 == 2){
            std::cout << "Enter the time of the appointment you want to delete: ";
            char olprocedure_time[60];
            std::cin >> olprocedure_time;
            customer.deleteAppointment(olprocedure_time);
            std::cout << "Appointment deleted successfully! ";
            menu_customer(customer);


        }else {
            menu_customer(customer);
        }

    }else {
        std :: cout << "\tExit complete!";
        system("CLS");
    }
};
void menu_employee();

int main()
{
    std :: cout << "\tWelcome to Dentist Management System!" << std:: endl;
    std :: cout << "\tChoose the method to connect [1 / 2]:" << std:: endl;
    std :: cout << "\t1.Customer" << std::endl;
    std :: cout << "\t2.Employee" << std:: endl;
    std :: cout << "\tMy choice: ";
    int choice;
    std :: cin >> choice;

    if (choice == 1){
            std::cout << "Enter surname and name (ex: Tom_Smith): ";
            char name[60];
            std::cin >> name;
            std::cout << std::endl;
            std:: cout << "Enter email: ";
            char email[60];
            std :: cin >> email;
            std::cout << std::endl;
            Customer customer(name,email);
            menu_customer(customer);


    }else if (choice == 2){
           std :: cout << "Enter password: ";
           char pass[12];
           std :: cin >> pass;
           std::cout << std::endl;
           if (strcmp(pass,"brightsmile") != 0){
            std:: cout << "Incorrect password! Only employees allowed!";
            system("CLS");
            main();

           }else {
               //menu_dentist();
               std::cout << "haha";
           }

    }else {
        std:: cout << "\tInvalid choice!" << std::endl;
        std:: cout << "\tDo you want to try again?[y/n]: ";
        char answer[1];
        std:: cin >> answer;
        if (strcmp(answer,"y")== 0){
            system("CLS");
            main();
        }else{
            std:: cout << "\tExit complete!";
            exit(1);

        }


    }






    // Employee approves an appointment
    //employee.approveAppointment("1");

    // Customer changes the appointment
    //Appointment app2("1", "2024-06-01 11:00", "john.doe@example.com");
    //customer.changeAppointment("1", app2);

    // Customer views their updated appointments
    //std::cout << "\nUpdated Customer's Appointments:\n";
    //customer.viewAppointments();

    // Employee views updated appointments
    //std::cout << "\nUpdated Employee's Appointments:\n";
    //employee.viewAppointments();

    // Write updated appointments to CSV
    input_output::writeAppointmentsToCSV("appointments.csv", readAppointments);

    return 0;
}
