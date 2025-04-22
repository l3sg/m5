#include <iostream>
#include <string>
using namespace std;

// Employee class (base class)
class Employee {
protected:
    string name;
    string employeeNumber;
    string hireDate;

public:
    // Constructor with initializer list
    Employee(string n = "", string eNum = "", string hDate = "")
        : name(n), employeeNumber(eNum), hireDate(hDate) {
        // Precondition: Inputs are valid strings
        // Postcondition: Object initialized with provided values
    }

    // Accessors
    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    // Mutators
    void setName(string n) { name = n; }
    void setEmployeeNumber(string eNum) { employeeNumber = eNum; }
    void setHireDate(string hDate) { hireDate = hDate; }

    // Print function
    void printEmployee() const {
        // Postcondition: Prints all employee details
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Hire Date: " << hireDate << endl;
    }
};

// ProductionWorker class (inherits from Employee)
class ProductionWorker : public Employee {
private:
    int shift; // 1 for day, 2 for night
    double hourlyPayRate;

public:
    // Constructor with initializer list
    ProductionWorker(string n = "", string eNum = "", string hDate = "", 
                    int s = 1, double pay = 0.0)
        : Employee(n, eNum, hDate), shift(s), hourlyPayRate(pay) {
        // Precondition: shift is 1 or 2, pay >= 0
        // Postcondition: Object initialized with provided values
    }

    // Accessors
    int getShift() const { return shift; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    // Mutators
    void setShift(int s) { if (s == 1 || s == 2) shift = s; }
    void setHourlyPayRate(double pay) { if (pay >= 0) hourlyPayRate = pay; }

    // Print function
    void printProductionWorker() const {
        // Postcondition: Prints all production worker details
        printEmployee();
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
    }
};

// ShiftSupervisor class (inherits from Employee)
class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualBonus;

public:
    // Constructor with initializer list
    ShiftSupervisor(string n = "", string eNum = "", string hDate = "", 
                   double salary = 0.0, double bonus = 0.0)
        : Employee(n, eNum, hDate), annualSalary(salary), annualBonus(bonus) {
        // Precondition: salary, bonus >= 0
        // Postcondition: Object initialized with provided values
    }

    // Accessors
    double getAnnualSalary() const { return annualSalary; }
    double getAnnualBonus() const { return annualBonus; }

    // Mutators
    void setAnnualSalary(double salary) { if (salary >= 0) annualSalary = salary; }
    void setAnnualBonus(double bonus) { if (bonus >= 0) annualBonus = bonus; }

    // Print function
    void printShiftSupervisor() const {
        // Postcondition: Prints all shift supervisor details
        printEmployee();
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Annual Bonus: $" << annualBonus << endl;
    }
};

// TeamLeader class (inherits from ProductionWorker)
class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;

public:
    // Constructor with initializer list
    TeamLeader(string n = "", string eNum = "", string hDate = "", 
               int s = 1, double pay = 0.0, double mBonus = 0.0, 
               int reqHours = 0, int attHours = 0)
        : ProductionWorker(n, eNum, hDate, s, pay), 
          monthlyBonus(mBonus), requiredTrainingHours(reqHours), 
          attendedTrainingHours(attHours) {
        // Precondition: mBonus, reqHours, attHours >= 0
        // Postcondition: Object initialized with provided values
    }

    // Accessors
    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getAttendedTrainingHours() const { return attendedTrainingHours; }

    // Mutators
    void setMonthlyBonus(double bonus) { if (bonus >= 0) monthlyBonus = bonus; }
    void setRequiredTrainingHours(int hours) { if (hours >= 0) requiredTrainingHours = hours; }
    void setAttendedTrainingHours(int hours) { if (hours >= 0) attendedTrainingHours = hours; }

    // Print function
    void printTeamLeader() const {
        // Postcondition: Prints all team leader details
        printProductionWorker();
        cout << "Monthly Bonus: $" << monthlyBonus << endl;
        cout << "Required Training Hours: " << requiredTrainingHours << endl;
        cout << "Attended Training Hours: " << attendedTrainingHours << endl;
    }
};

// Main function to test the classes
int main() {
    // Test ProductionWorker objects
    ProductionWorker worker1("John Doe", "12345", "2023-01-15", 1, 15.50);
    ProductionWorker worker2("Jane Smith", "67890", "2022-06-20", 2, 18.75);

    cout << "Production Worker 1:\n";
    worker1.printProductionWorker();
    cout << "\nProduction Worker 2:\n";
    worker2.printProductionWorker();

    // Test ShiftSupervisor object
    ShiftSupervisor supervisor("Alice Johnson", "54321", "2021-03-10", 60000.0, 5000.0);
    cout << "\nShift Supervisor:\n";
    supervisor.printShiftSupervisor();

    // Test TeamLeader object
    TeamLeader leader("Bob Wilson", "98765", "2020-11-05", 1, 20.00, 1000.0, 40, 35);
    cout << "\nTeam Leader:\n";
    leader.printTeamLeader();

    return 0;
}