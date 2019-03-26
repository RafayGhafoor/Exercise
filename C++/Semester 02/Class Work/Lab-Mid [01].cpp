// ConsoleApplication1.cpp : Defines the entry point for the console
// application.
//

#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void RESIZE(char **&names, int *&marray) {
  int n_size = 0;
  for (; names[n_size]; n_size++) {
  }

  int *new_array = new int[n_size + 1];
  for (int i = 0; i < n_size; i++)
    new_array[i] = marray[i];

  delete[] marray;
  marray = new_array;
}

int getSize(char *names[]) {
  int n_size = 0;
  for (; names[n_size]; n_size++) {
  }
  return n_size;
}

int getCSize(char **&names) {
  int n_size = 0;
  for (; names[n_size]; n_size++) {
  }
  return n_size;
}

class UniversityCampus {
private:
  char *campusName;
  char **departments;
  int *noOfFacultyMembers;
  int *noOfStaffMembers;

public:
  UniversityCampus() {
    campusName = nullptr;
    departments = nullptr;
    noOfFacultyMembers = nullptr;
    noOfStaffMembers = nullptr;
  }

  UniversityCampus(UniversityCampus &obj) {
    // if (campusName)
    // {
    //     delete[] campusName;
    //     campusName = nullptr;
    // }

    // if (departments)
    // {
    //     for (int i = 0; departments[i]; i++)
    //         delete[] departments[i];
    //     delete[] departments;
    //     departments = nullptr;
    // }

    // if (noOfFacultyMembers)
    // {
    //     delete[] noOfFacultyMembers;
    //     noOfFacultyMembers = nullptr;
    // }
    // if (noOfStaffMembers)
    // {
    //     delete[] noOfStaffMembers;
    //     noOfStaffMembers = nullptr;
    // }

    campusName = new char[strlen(obj.campusName) + 1];
    strcpy(campusName, obj.campusName);

    int n_size = getCSize(obj.departments);

    // Allocation of departments
    departments = new char *[n_size + 2];

    // Iterate over departments
    for (int i = 0; i < n_size; i++) {
      // Allocate space for name of the department
      departments[i] = new char[strlen(obj.departments[i]) + 1];
      strcpy(departments[i], obj.departments[i]);
    }

    departments[n_size + 1] = nullptr;

    // Allocation of Faculty Members and Staff Members
    noOfFacultyMembers = new int[n_size + 1];
    noOfStaffMembers = new int[n_size + 1];

    // Copy the faculty and staff arrays
    for (int i = 0; i < n_size + 1; i++) {
      noOfFacultyMembers[i] = obj.noOfFacultyMembers[i];
      noOfStaffMembers[i] = obj.noOfStaffMembers[i];
    }
  }

  UniversityCampus(char dpt_name[], char *dpts[], int *faculty, int *staff) {
    campusName = new char[strlen(dpt_name) + 1];
    strcpy(campusName, dpt_name);

    int n_size = getCSize(dpts);

    // Allocation of departments
    departments = new char *[n_size + 1];

    // Iterate over departments
    for (int i = 0; i < n_size; i++) {
      // Allocate space for name of the department
      departments[i] = new char[strlen(dpts[i]) + 1];
      strcpy(departments[i], dpts[i]);
    }

    departments[n_size] = nullptr;

    // Allocation of Faculty Members and Staff Members
    noOfFacultyMembers = new int[n_size + 1];
    noOfStaffMembers = new int[n_size + 1];

    // Copy the faculty and staff arrays
    for (int i = 0; i < n_size; i++) {
      noOfFacultyMembers[i] = faculty[i];
      noOfStaffMembers[i] = staff[i];
    }
  }

  ~UniversityCampus() {
    if (campusName) {
      delete[] campusName;
      campusName = nullptr;
    }

    if (noOfFacultyMembers) {
      delete[] noOfFacultyMembers;
      noOfFacultyMembers = nullptr;
    }

    if (noOfStaffMembers) {
      delete[] noOfStaffMembers;
      noOfStaffMembers = nullptr;
    }

    if (noOfStaffMembers && departments) {
      for (int i = 0; departments[i]; i++) {
        delete[] departments[i];
      }
      delete[] departments;
      departments = nullptr;
    }
  }

  void addFaculty(char dept_name[], int num) {
    bool found = false;
    int found_index = 0;
    for (int i = 0; departments[i]; i++) {
      if (!strcmp(dept_name, departments[i])) {
        found = true;
        found_index = i;
        break;
      }
    }

    if (found) {
      RESIZE(departments, noOfFacultyMembers);
      noOfFacultyMembers[found_index] = num;
    }
  }

  void addStaff(char dept_name[], int num) {
    bool found = false;
    int found_index = 0;

    for (int i = 0; departments[i]; i++) {
      if (!strcmp(dept_name, departments[i])) {
        found = true;
        found_index = i;
        break;
      }
    }

    if (found) {
      RESIZE(departments, noOfStaffMembers);
      noOfStaffMembers[found_index] = num;
    }
  }

  void printCampusDetails() {
    int n_size = getCSize(departments);
    if (!campusName && !departments && !noOfFacultyMembers && !noOfStaffMembers)
      cout << "No information found for the Campus!\n";

    if (campusName)
      cout << "Campus Name: " << campusName;
    else
      cout << "No information found for campus" << endl;

    cout << "\nDepartments: ";

    if (!n_size)
      cout << "None\n";
    else if (departments) {
      for (int i = 0; i < n_size; i++)
        if (departments[i])
          cout << departments[i] << " ";
    }

    if (!noOfFacultyMembers)
      cout << "\nNo Faculty Members found\n";
    else
      cout << "\nNumber of Faculty Members: " << getCSize(departments);

    if (!noOfStaffMembers)
      cout << "\nNo Staff Members found\n";
    else
      cout << "\nNumber of Staff Members: " << getCSize(departments) << endl;
  }

  UniversityCampus &operator+(char str[]) {
    int size = 0;
    for (; departments[size]; size++)
      ;

    char **backup = new char *[size + 1];

    if (departments) {

      for (int i = 0; i < size; i++) {
        backup[i] = new char[strlen(departments[i]) + 1];
        strcpy(backup[i], departments[i]);
      }

      backup[size - 1] = new char[strlen(str) + 1];
      strcpy(backup[size - 1], str);
      backup[size] = nullptr;

      for (int i = 0; i < size; i++)
        delete[] departments[i];

      delete[] departments;
      departments = backup;
    }

    return *this;
  }

  UniversityCampus operator-(char str[]) {
    int size = 0;
    for (; departments[size]; size++)
      ;
    bool adder = false;
    char **backup = new char *[size - 1];

    for (int i = 0, x = 0; i < size; i++, x++) {
      if (strcmp(str, departments[i])) {
        backup[x] = new char[strlen(departments[i]) + 1];
        strcpy(backup[x], departments[i]);
      }

      else if (!adder) {
        i++;
        adder = 1;
      }
    }

    backup[size - 2] = nullptr;

    for (int i = 0; i < size; i++)
      delete[] departments[i];

    delete[] departments;

    departments = backup;

    return *this;
  }
};

int main() {
  char *dpts[20] = {"CS", "EE", "A&F", nullptr};
  int faculty[] = {46, 33, 23}, staff[] = {4, 3, 5};

  char campusName[] = "Lahore";
  UniversityCampus *lhr =
      new UniversityCampus(campusName, dpts, faculty, staff);
  lhr->printCampusDetails();
  char adder[] = "Mng";
  char adder1[] = "EE";
  *lhr = *lhr + adder;
  lhr->addFaculty(adder, 44);
  lhr->addStaff(adder, 4);
  lhr->printCampusDetails();
  *lhr = *lhr - adder1;
  lhr->printCampusDetails();
  delete lhr;
  lhr = nullptr;
  return 0;
}
