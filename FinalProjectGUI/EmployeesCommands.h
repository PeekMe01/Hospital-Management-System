#ifndef EmployeesCommands_h
#define EmployeesCommands_h
#include <iostream>
#include <string>
#include <fstream>

struct Employee {
	int employeeID = 0; // did sorting
	std::string firstName; // did sorting
	std::string lastName; // did sorting
	std::string address; // did sorting
	int age; // did sorting
	std::string position; // there are 3 positions: doctor > nurse > intern // did sorting
	double salary; // did sorting

	Employee* next;
	Employee* prev;
};

struct LISTEmployee {
	Employee* head;
	Employee* rear;
};

bool writeEmployeeToFile(std::string file_name, Employee& employee) {
	std::ofstream file;
	file.open(file_name);
	file << employee.employeeID << "," << employee.firstName << "," << employee.lastName << "," << employee.address << "," << employee.age << "," << employee.position << "," << employee.position << std::endl;
	file.close();

	return true;

}

void InitializeListEmployee(LISTEmployee& LEmployee) {
	LEmployee.head = NULL;
	LEmployee.rear = NULL;
}

bool IsEmptyEmployee(LISTEmployee& LEmployee) {
	return (LEmployee.head == NULL);
}

void InsertElementEmployee(LISTEmployee& LEmployee, int id, std::string fname, std::string lname, std::string address, int age, std::string position, double salary) {
	Employee* cur, * tmp;
	tmp = new Employee;
	tmp->employeeID = id;
	tmp->firstName = fname;
	tmp->lastName = lname;
	tmp->address = address;
	tmp->age = age;
	tmp -> position = position; // did sorting
	tmp->salary = salary;

	tmp->next = NULL;
	tmp->prev = NULL;
	writeEmployeeToFile("employees.txt", *tmp);

	if (IsEmptyEmployee(LEmployee)) {
		LEmployee.head = tmp;
		LEmployee.rear = tmp;
		LEmployee.head->next = LEmployee.rear;
		LEmployee.head->prev = LEmployee.rear;
		LEmployee.rear->next = LEmployee.head;
		LEmployee.rear->prev = LEmployee.head;
		return;
	}
	// INSERTION AT HEAD
	if (tmp->employeeID <= LEmployee.head->employeeID) {
		LEmployee.rear->next = tmp;
		tmp->prev = LEmployee.rear;
		LEmployee.head->prev = tmp;
		tmp->next = LEmployee.head;
		LEmployee.head = tmp;
		return;
	}
	// INSERTION AT REAR
	if (tmp->employeeID >= LEmployee.rear->employeeID) {
		LEmployee.rear->next = tmp;
		tmp->prev = LEmployee.rear;
		LEmployee.head->prev = tmp;
		tmp->next = LEmployee.head;
		LEmployee.rear = tmp;
		return;
	}
	// ANYWHERE ELSE
	cur = LEmployee.head->next;
	while (cur != LEmployee.head && cur->employeeID < tmp->employeeID) {
		cur = cur->next;
	}
	tmp->prev = cur->prev;
	tmp->next = cur;
	cur->prev->next = tmp;
	cur->prev = tmp;
}

int GetNumberOfElementsEmployee(LISTEmployee& LEmployee) {
	int nb = 0;
	Employee* cur;
	if (IsEmptyEmployee(LEmployee)) {
		return nb;
	}
	cur = LEmployee.head;
	do {
		nb++;
		cur = cur->next;
	} while (cur != LEmployee.head);
	return nb;
}
//void PrintListH2REmployee(LISTEmployee& LEmployees) {
System::String^ PrintListH2REmployee(LISTEmployee& LEmployees) {
	Employee* cur;
	cur = LEmployees.head;
	System::String^ output = "";
	if (IsEmptyEmployee(LEmployees)) {
		//std::cout << "The employees list is empty" << std::endl;
		//return;
		output += "The employees list is empty\n\n";
		return output;
	}
	//std::cout << "The employees list is H2R:" << std::endl << std::endl;
	output += "The employees list is H2R:\n\n";
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		//std::cout << "Employee ID: " << std::to_string(cur->employeeID) << std::endl;
		//std::cout << "Employee first name: " << cur->firstName << std::endl;
		//std::cout << "Employee last name: " << cur->lastName << std::endl;
		//std::cout << "Employee address: " << cur->address << std::endl;
		//std::cout << "Employee age: " << cur->age << std::endl;
		//std::cout << "Employee position: " << cur->position << std::endl;
		//std::printf("Employee salary: $ %.02f\n", cur->salary);
		//std::cout << "==========" << std::endl;
		//std::cout << std::endl;
		output += "Employee ID: " + cur->employeeID + "\n";
		output += "Employee first name: " + gcnew System::String(cur->firstName.c_str()) + "\n";
		output += "Employee last name : " + gcnew System::String(cur->lastName.c_str()) + "\n";
		output += "Employee address: " + gcnew System::String(cur->address.c_str()) + "\n";
		output += "Employee age: " + cur->age + "\n";
		output += "Employee position: " + gcnew System::String(cur->position.c_str()) + "\n";
		output += ("Employee salary: $" + cur->salary) + ".00\n";
		output += "==========\n\n";
		cur = cur->next;
	}
	//std::cout << std::endl;
	return output;
}

//void PrintListR2HEmployee(LISTEmployee& LEmployees) {
System::String^ PrintListR2HEmployee(LISTEmployee& LEmployees) {
	Employee* cur;
	cur = LEmployees.rear;
	System::String^ output = "";
	if (IsEmptyEmployee(LEmployees)) {
		//std::cout << "The employees list is empty" << std::endl;
		//return;
		output += "The employees list is empty\n\n";
		return output;
	}
	//std::cout << "The employees list is R2H:" << std::endl << std::endl;
	output += "The employees list is R2H:\n\n";
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		output += "Employee ID: " + cur->employeeID + "\n";
		output += "Employee first name: " + gcnew System::String(cur->firstName.c_str()) + "\n";
		output += "Employee last name : " + gcnew System::String(cur->lastName.c_str()) + "\n";
		output += "Employee address: " + gcnew System::String(cur->address.c_str()) + "\n";
		output += "Employee age: " + cur->age + "\n";
		output += "Employee position: " + gcnew System::String(cur->position.c_str()) + "\n";
		output += ("Employee salary: $" + cur->salary) + ".00\n";
		output += "==========\n\n";
		std::cout << std::endl;
		cur = cur->prev;
	}
	//std::cout << std::endl;
	return output;
}

//void deleteElementEmployee(LISTEmployee& LEmployees, int EmployeeID) {
System::String^ deleteElementEmployee(LISTEmployee& LEmployees, int EmployeeID) {
	Employee* cur;
	System::String^ output = "";
	if (IsEmptyEmployee(LEmployees)) {
		//std::cout << "The employees list is empty" << std::endl;
		output += "The employees list is empty\n";
		return output;
	}

	if (GetNumberOfElementsEmployee(LEmployees) == 1) {
		cur = LEmployees.head;
		delete cur;
		InitializeListEmployee(LEmployees);
		return output += "You deleted the last employee, reinitializing Employee List...\n";
	}

	// IF WE NEED TO DELETE THE HEAD
	if (LEmployees.head->employeeID == EmployeeID) {
		cur = LEmployees.head->next;
		//std::cout << "Employee with ID \"" << cur->employeeID << "\" has been deleted..." << std::endl;
		output += "Employee with ID \"" + EmployeeID + "\" has been deleted...\n";
		delete LEmployees.head;
		LEmployees.head = cur;
		LEmployees.head->prev = LEmployees.rear;
		LEmployees.rear->next = LEmployees.head;
		return output;
	}

	// IF WE NEED TO DELETE THE REAR
	if (LEmployees.rear->employeeID == EmployeeID) {
		cur = LEmployees.rear->prev;
		//std::cout << "Employee with ID \"" << cur->employeeID << "\" has been deleted..." << std::endl;
		output += "Employee with ID \"" + EmployeeID + "\" has been deleted...\n";
		delete LEmployees.rear;
		LEmployees.rear = cur;
		LEmployees.head->prev = LEmployees.rear;
		LEmployees.rear->next = LEmployees.head;
		return output;
	}
	cur = LEmployees.head->next;
	while (cur != LEmployees.head && cur->employeeID != EmployeeID) {
		cur = cur->next;
	}
	if (cur == LEmployees.head) {
		//std::cout << "Patient not found..." << std::endl;
		output += "Employee not found...\n";
		return output;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	//std::cout << "Employee with ID \"" << cur->employeeID << "\" has been deleted..." << std::endl;
	output += "Employee with ID \"" + EmployeeID + "\" has been deleted...\n";
	delete cur;
	return output;
}

//void ReInitializeIDEmployees(LISTEmployee& LEmployees) {
System::String^ ReInitializeIDEmployees(LISTEmployee& LEmployees) {
	Employee* cur;
	System::String^ output = "";
	if (IsEmptyEmployee(LEmployees)) {
		//std::cout << "Employees list is empty..." << std::endl;
		//return;
		output += "Employees list is empty...\n";
		return output;
	}
	cur = LEmployees.head;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		cur->employeeID = i + 1;
		cur = cur->next;
	}
	output += "Patients list has be reinitialized...\n";
	return output;
}

Employee* getEmployee(LISTEmployee& LEmployees, int ID) {
	Employee* cur = NULL;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "Employees list is empty..." << std::endl;
		return cur;
	}
	cur = LEmployees.head;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		if (cur->employeeID == ID) {
			return cur;
		}
		cur = cur->next;
	}
	cur = NULL;
	return cur;
}

void SortByID_ASC(LISTEmployee& LEmployee) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployee)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by ID in ascending order..." << std::endl;
	cur = LEmployee.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		while (cmpWith != LEmployee.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->employeeID > cmpWith->employeeID && cur != LEmployee.head && cmpWith != LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->employeeID > cmpWith->employeeID && (cur == LEmployee.head && cmpWith == LEmployee.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->employeeID > cmpWith->employeeID && (cur == LEmployee.rear->prev && cmpWith == LEmployee.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->employeeID > cmpWith->employeeID && cur == LEmployee.head && cmpWith == LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;
				LEmployee.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployee.head;
		cmpWith = cur->next;
	}
}

void SortByID_DES(LISTEmployee& LEmployee) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployee)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employee by ID in descending order..." << std::endl;
	cur = LEmployee.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		while (cmpWith != LEmployee.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->employeeID < cmpWith->employeeID && cur != LEmployee.head && cmpWith != LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->employeeID < cmpWith->employeeID && (cur == LEmployee.head && cmpWith == LEmployee.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->employeeID < cmpWith->employeeID && (cur == LEmployee.rear->prev && cmpWith == LEmployee.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->employeeID < cmpWith->employeeID && cur == LEmployee.head && cmpWith == LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;
				LEmployee.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployee.head;
		cmpWith = cur->next;
	}
}

void SortByFirstNameA2Z(LISTEmployee& LEmployee) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployee)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by first name A2Z..." << std::endl;
	cur = LEmployee.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		while (cmpWith != LEmployee.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->firstName.compare(cmpWith->firstName) > 0 && cur != LEmployee.head && cmpWith != LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->firstName.compare(cmpWith->firstName) > 0 && (cur == LEmployee.head && cmpWith == LEmployee.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->firstName.compare(cmpWith->firstName) > 0 && (cur == LEmployee.rear->prev && cmpWith == LEmployee.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->firstName.compare(cmpWith->firstName) > 0 && cur == LEmployee.head && cmpWith == LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;
				LEmployee.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployee.head;
		cmpWith = cur->next;
	}
}

void SortByFirstNameZ2A(LISTEmployee& LEmployee) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployee)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by first name Z2A..." << std::endl;
	cur = LEmployee.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		while (cmpWith != LEmployee.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->firstName.compare(cmpWith->firstName) < 0 && cur != LEmployee.head && cmpWith != LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->firstName.compare(cmpWith->firstName) < 0 && (cur == LEmployee.head && cmpWith == LEmployee.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->firstName.compare(cmpWith->firstName) < 0 && (cur == LEmployee.rear->prev && cmpWith == LEmployee.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->firstName.compare(cmpWith->firstName) < 0 && cur == LEmployee.head && cmpWith == LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;
				LEmployee.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployee.head;
		cmpWith = cur->next;
	}
}

void SortByLastNameA2Z(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by last name A2Z..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->lastName.compare(cmpWith->lastName) > 0 && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->lastName.compare(cmpWith->lastName) > 0 && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->lastName.compare(cmpWith->lastName) > 0 && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->lastName.compare(cmpWith->lastName) > 0 && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortByLastNameZ2A(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by first name Z2A..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->lastName.compare(cmpWith->lastName) < 0 && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->lastName.compare(cmpWith->lastName) < 0 && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->lastName.compare(cmpWith->lastName) < 0 && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->lastName.compare(cmpWith->lastName) < 0 && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortByAddressLengthS2L(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by address length from shortest to longuest..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->address.length() > cmpWith->address.length() && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->address.length() > cmpWith->address.length() && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->address.length() > cmpWith->address.length() && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->address.length() > cmpWith->address.length() && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortByAddressLengthL2S(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees by address length from longuest to shortest..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->address.length() < cmpWith->address.length() && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->address.length() < cmpWith->address.length() && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->address.length() < cmpWith->address.length() && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->address.length() < cmpWith->address.length() && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortByAgeY2O(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees from youngest to oldest..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->age > cmpWith->age && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->age > cmpWith->age && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->age > cmpWith->age && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->age > cmpWith->age && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortByAgeO2Y(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees from oldest to youngest..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->age < cmpWith->age && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->age < cmpWith->age && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->age < cmpWith->age && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->age < cmpWith->age && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

//void SortByPosition_ASC(LISTEmployee& LEmployee) {
System::String^ SortByPosition_ASC(LISTEmployee& LEmployee) {
	Employee* cur, * cmpWith, * tmp;
	System::String^ output = "";
	int curImportance = 0, cmpWithImportance = 0;
	if (IsEmptyEmployee(LEmployee)) {
		//std::cout << "The employees list is empty" << std::endl;
		//return;
		output += "The employees list is empty\n";
		return output;
	}
	//std::cout << "Sorting employees by postion in ascending order..." << std::endl;
	output += "Sorting employees by postion in ascending order...\n";
	cur = LEmployee.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		while (cmpWith != LEmployee.head) {
			if (cur->position == "doctor") curImportance = 3;		// now we use these numbers assigned to be able to sort
			if (cur->position == "nurse") curImportance = 2;		// them depending on the Importance number
			if (cur->position == "intern") curImportance = 1;
			if (cmpWith->position == "doctor") cmpWithImportance = 3;
			if (cmpWith->position == "nurse") cmpWithImportance = 2;
			if (cmpWith->position == "intern") cmpWithImportance = 1;

			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE

			if (curImportance > cmpWithImportance && cur != LEmployee.head && cmpWith != LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (curImportance > cmpWithImportance && (cur == LEmployee.head && cmpWith == LEmployee.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (curImportance > cmpWithImportance && (cur == LEmployee.rear->prev && cmpWith == LEmployee.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;
				
				LEmployee.rear = cmpWith;
			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (curImportance > cmpWithImportance && cur == LEmployee.head && cmpWith == LEmployee.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployee.head = cur;
				LEmployee.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployee.head;
		cmpWith = cur->next;
	}
	output += "List has been sorted by Position ( ASC )...\n";
	return output;
}

//void SortByPosition_DEC(LISTEmployee& LEmployees) {
System::String^ SortByPosition_DEC(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	System::String^ output = "";
	int curImportance = 0, cmpWithImportance = 0;
	if (IsEmptyEmployee(LEmployees)) {
		//std::cout << "The employees list is empty" << std::endl;
		//return;
		output += "The employees list is empty\n";
		return output;
	}
	//std::cout << "Sorting employees by postion in descending order..." << std::endl;
	output += "Sorting employees by postion in descending order...\n";
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			if (cur->position == "doctor") curImportance = 3;		// now we use these numbers assigned to be able to sort
			if (cur->position == "nurse") curImportance = 2;		// them depending on the Importance number
			if (cur->position == "intern") curImportance = 1;
			if (cmpWith->position == "doctor") cmpWithImportance = 3;
			if (cmpWith->position == "nurse") cmpWithImportance = 2;
			if (cmpWith->position == "intern") cmpWithImportance = 1;

			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE

			if (curImportance < cmpWithImportance && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (curImportance < cmpWithImportance && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (curImportance < cmpWithImportance && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;
			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (curImportance < cmpWithImportance && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
	output += "List has been sorted by position ( DEC )...\n";
	return output;
}

void SortBySalaryL2H(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees from lowest salary to highest salary..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->salary > cmpWith->salary && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->salary > cmpWith->salary && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->salary > cmpWith->salary && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->salary > cmpWith->salary && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

void SortBySalaryH2L(LISTEmployee& LEmployees) {
	Employee* cur, * cmpWith, * tmp;
	if (IsEmptyEmployee(LEmployees)) {
		std::cout << "The employees list is empty" << std::endl;
		return;
	}
	std::cout << "Sorting employees from highest salary to lowest salary..." << std::endl;
	cur = LEmployees.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployees); i++) {
		while (cmpWith != LEmployees.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->salary < cmpWith->salary && cur != LEmployees.head && cmpWith != LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

			}

			// CUR IS HEAD AND CMPWITH IS NEXT TO IT
			if (cur->salary < cmpWith->salary && (cur == LEmployees.head && cmpWith == LEmployees.head->next)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->salary < cmpWith->salary && (cur == LEmployees.rear->prev && cmpWith == LEmployees.rear)) {

				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;
				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->salary < cmpWith->salary && cur == LEmployees.head && cmpWith == LEmployees.rear) {
				cur->next = cmpWith->next;
				cmpWith->next->prev = cur;

				cmpWith->prev = cur->prev;
				cur->prev->next = cmpWith;

				cmpWith->next = cur;
				cur->prev = cmpWith;

				//	NOW THAT CUR AND CMPWITH ARE FLIPPED WE FLIP THEM AGAIN
				tmp = cur;
				cur = cmpWith;
				cmpWith = tmp;

				LEmployees.head = cur;
				LEmployees.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LEmployees.head;
		cmpWith = cur->next;
	}
}

Employee* GetEmployee(LISTEmployee& LEmployee, int ID) {
	Employee* cur = NULL;
	if (IsEmptyEmployee(LEmployee)) {
		std::cout << "Employees list is empty..." << std::endl;
		return cur;
	}
	cur = LEmployee.head;
	for (int i = 0; i < GetNumberOfElementsEmployee(LEmployee); i++) {
		if (cur->employeeID == ID) {
			return cur;
		}
		cur = cur->next;
	}
	cur = NULL;
	return cur;
}

System::String^ printEmployee(Employee* employee) {
	System::String^ output = "";
	if (employee == NULL) {
		output += "This employee does not exist\n";
		return output;
	}
	else {
		output += "Employee ID: " + employee->employeeID + "\n";
		output += "Employee first name: " + gcnew System::String(employee->firstName.c_str()) + "\n";
		output += "Employee last name : " + gcnew System::String(employee->lastName.c_str()) + "\n";
		output += "Employee address: " + gcnew System::String(employee->address.c_str()) + "\n";
		output += "Employee age: " + employee->age + "\n";
		output += "Employee position: " + gcnew System::String(employee->position.c_str()) + "\n";
		output += ("Employee salary: $" + employee->salary) + ".00\n";
		output += "==========\n\n";
	}
	return output;
}
#endif // !EmployeesCommands_h

