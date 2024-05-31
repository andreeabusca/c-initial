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
void dentist_menu(){
    std::cout << "1.Cazacu_Drumitru" << std::endl;
    std::cout << "2.Bogdan_Octavian" << std::endl;
    std::cout << "3.Ardeleanu_Mircea" << std::endl;
    std::cout << "4.Girgiu_Victoria" << std::endl;
    std::cout << "5.Olteanu_Tania" << std::endl;
}
void menu_customer(Customer customer){
    std :: cout << "\t1.Make appointment" << std :: endl;
    std :: cout << "\t2.See your appointments" << std:: endl;
    std :: cout << "\t3.Exit" << std :: endl;

    std :: cout << "\tChoose action: ";
    int choice;
    std :: cin >> choice;
    if (choice == 1){
        procedure_menu();
        std::cout << "\tEnter procedure number: ";
        char procedure_number[2];
        std::cin >> procedure_number;
        std::cout << "\tEnter time of procedure (ex: 2024-06-01_11:00):";
        char procedure_time[60];
        std::cin >> procedure_time;
        dentist_menu();
        std::cout << "\tEnter dentist name: ";
        char dentist_name[60];
        std::cin >> dentist_name;

        Appointment app(procedure_number,procedure_time,customer.getEmail(),dentist_name);
        customer.makeAppointment(app);
        readAppointments.push_back(app);
        system("CLS");
        std::cout << "\tNew appointment registered" << std::endl;

        menu_customer(customer);

    }else if (choice == 2){
        customer.viewAppointments(readAppointments,customer.getEmail());
        std :: cout << "\tWhat do you want to do next?:" << std :: endl;
        std :: cout << "\t1.Change Appointment" << std:: endl;
        std :: cout << "\t2.Delete Appointment" << std :: endl;
        std :: cout << "\t3.None of the above" << std :: endl;
        int choice_2;
        std :: cout << "\t My choice: ";
        std :: cin >> choice_2;
        if (choice_2 == 1){
                procedure_menu();
               std::cout << "\tEnter new procedure (if you don't want to change procedure, type the old one): ";
               char newprocedure[2];
               std::cin >> newprocedure;
               std::cout << "\tEnter old time: ";
                char oldprocedure_time[60];
               std::cin >> oldprocedure_time;
               std::cout << "\tEnter new time (if you don't want to change time, type the old one): ";
               char newprocedure_time[60];
               std::cin >> newprocedure_time;
               dentist_menu();
               std::cout << "\tEnter new dentist name (if you don't want to change the dentist, type the old one): ";
               char dentist_name[60];
               std::cin >> dentist_name;
               Appointment appc(newprocedure,newprocedure_time,customer.getEmail(),dentist_name);
               customer.changeAppointment(readAppointments,oldprocedure_time,appc);
               system("CLS");
               std::cout << "\tAppointment change successfully! " << std::endl;
               menu_customer(customer);


        }else if (choice_2 == 2){
            std::cout << "\tEnter the time of the appointment you want to delete: ";
            char olprocedure_time[60];
            std::cin >> olprocedure_time;
            customer.deleteAppointment(readAppointments,olprocedure_time);
            system("CLS");
            std::cout << "\tAppointment deleted successfully! " << std::endl;
            menu_customer(customer);


        }else {
            menu_customer(customer);
        }

    }else {
        system("CLS");
        std :: cout << "\tExit complete!";

    }
};
void menu_dentist(Employee dentist){
    std :: cout << "\tWhat do you want to do next?" << std :: endl;
    std::cout << "\t1.View Appointments" << std :: endl;
    std::cout << "\t2.Accept Appointment" << std :: endl;
    std::cout << "\t3.Reject Appointment" << std :: endl;
    std::cout << "\t4.Exit" << std :: endl;
    std:: cout << "\tMy choice : ";
    int choice;
    std :: cin >> choice;
    if (choice == 1){
            dentist.viewAppointments(readAppointments,dentist.getName());
            menu_dentist(dentist);

    }else if (choice == 2){
        system("CLS");
        dentist.viewAppointments(readAppointments,dentist.getName());
        std :: cout << "\tEnter the time of the appointment you want to accept :";
        char time_acc[60];
        std :: cin >> time_acc;
        std :: cout << "\tEnter the email of the appointment you want to accept :";
        char email_acc[60];
        std :: cin >> email_acc;
        dentist.approveAppointment(readAppointments,time_acc,dentist.getName(),email_acc);
        system("CLS");
        std :: cout << "\tAppointment accepted successfully!" << std :: endl;
        menu_dentist(dentist);


    }else if(choice == 3){
        system("CLS");
        dentist.viewAppointments(readAppointments,dentist.getName());
        std :: cout << "\tEnter the time of the appointment you want to reject :";
        char time_acc[60];
        std :: cin >> time_acc;
        std :: cout << "\tEnter the email of the appointment you want to accept :";
        char email_acc[60];
        std :: cin >> email_acc;
        dentist.rejectAppointment(readAppointments,time_acc,dentist.getName(),email_acc);
        system("CLS");
        std :: cout << "\tAppointment rejected successfully!" << std :: endl;
        menu_dentist(dentist);

    }else{
        system("CLS");
        std :: cout << "\tExit complete!";

    }




}

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
            system("CLS");
            std:: cout << "Incorrect password! Only employees allowed!" << std :: endl;
            main();

           }else {
               std :: cout << "Enter your name (ex. Alina_Popescu) : ";
               char name_dentist[60];
               std :: cin >> name_dentist;
               Employee dentist(name_dentist);
               menu_dentist(dentist);
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

    input_output::writeAppointmentsToCSV("appointments.csv", readAppointments);

    return 0;
}
