#ifndef PatientsCommands_h
#define PatientsCommands_h
#include <iostream>
#include <string>
struct Patient {
	int patientID=0; // did sorting
	std::string firstName; // did sorting
	std::string lastName; // did sorting
	std::string reasonOfStay; // did sorting
	int age=0; // did sorting
	std::string guardian; // did sorting
	std::string address; // did sorting

	Patient* next;
	Patient* prev;
	};

struct LISTPatient {
	Patient* head;
	Patient* rear;
};

bool writePatientToFile(std::string file_name, Patient& patient) {
	std::ofstream file;
	file.open(file_name);
	file << patient.patientID << "," << patient.firstName << "," << patient.lastName << "," << patient.reasonOfStay << "," << patient.age << "," << patient.guardian << "," << patient.address << std::endl;
	file.close();

	return true;
 
}

void InitializeListPatient(LISTPatient& LPatient) {
	LPatient.head = NULL;
	LPatient.rear = NULL;
}

bool IsEmptyPatient(LISTPatient& LPatient) {
	return (LPatient.head == NULL);
}

void InsertElementPatient(LISTPatient& LPatient, int id,std::string fname, std::string lname, std::string ROS, int age, std::string guardian, std::string address) {
	Patient* cur, *tmp;
	tmp = new Patient;
	tmp->patientID = id;
	tmp->firstName = fname;
	tmp->lastName = lname;
	tmp->reasonOfStay = ROS;
	tmp->age = age;
	tmp->guardian = guardian;
	tmp->address = address;
	tmp->next = NULL;
	tmp->prev = NULL;
	writePatientToFile("patients.txt", *tmp);

	if (IsEmptyPatient(LPatient)) {
		LPatient.head = tmp;
		LPatient.rear = tmp;
		LPatient.head->next = LPatient.rear;
		LPatient.head->prev = LPatient.rear;
		LPatient.rear->next = LPatient.head;
		LPatient.rear->prev = LPatient.head;
		return;
	}
	// INSERTION AT HEAD
	if (tmp->patientID <= LPatient.head->patientID) {
		LPatient.rear->next = tmp;
		tmp->prev = LPatient.rear;
		LPatient.head->prev = tmp;
		tmp->next = LPatient.head;
		LPatient.head = tmp;
		return;
	}
	// INSERTION AT REAR
	if (tmp->patientID >= LPatient.rear->patientID) {
		LPatient.rear->next = tmp;
		tmp->prev = LPatient.rear;
		LPatient.head->prev = tmp;
		tmp->next = LPatient.head;
		LPatient.rear = tmp;
		return;
	}
	// ANYWHERE ELSE
	cur = LPatient.head->next;
	while (cur != LPatient.head && cur->patientID < tmp->patientID) {
		cur = cur->next;
	}
	tmp->prev = cur->prev;
	tmp->next = cur;
	cur->prev->next = tmp;
	cur->prev = tmp;
}

int GetNumberOfElementsPatient(LISTPatient& LPatient) {
	int nb = 0;
	Patient* cur;
	if (IsEmptyPatient(LPatient)) {
		return nb;
	}	
	cur = LPatient.head;
	do {
		nb++;
		cur = cur->next;
	} while (cur != LPatient.head);
	return nb;
}

//void PrintListH2RPatient(LISTPatient& LPatients) {
System::String^ PrintListH2RPatient(LISTPatient& LPatients) {
	Patient* cur;
	cur = LPatients.head;
	System::String^ output = "";
	if (IsEmptyPatient(LPatients)) {
		//std::cout << "The Patients list is empty" << std::endl;
		//return;
		output += "The Patients list is empty\n\n";
		return output;
	}
	//std::cout << "The Patients list is H2R:" << std::endl << std::endl;
	output += "The Patients list is H2R:\n\n";
	for (int i = 0; i < GetNumberOfElementsPatient(LPatients); i++) {
		//std::cout << "Patient ID: " << std::to_string(cur->patientID) << std::endl;
		//std::cout << "Patient first name: " << cur->firstName << std::endl;
		//std::cout << "Patient last name: " << cur->lastName << std::endl;
		//std::cout << "Patient's reason of stay: " << cur->reasonOfStay << std::endl;
		//std::cout << "Patient guardian: " << cur->guardian << std::endl;
		//std::cout << "Patient age: " << cur->age << std::endl;
		//std::cout << "Patient address: " << cur->address << std::endl;
		//std::cout << "==========" << std::endl;
		//std::cout << std::endl;
		output += "Patient ID: " + cur->patientID + "\n";
		output += "Patient first name: " + gcnew System::String(cur->firstName.c_str()) + "\n";
		output += "Patient last name: " + gcnew System::String(cur->lastName.c_str()) + "\n";
		output += "Patient's reason of stay: " + gcnew System::String(cur->reasonOfStay.c_str()) + "\n";
		output += "Patient guardian: " + gcnew System::String(cur->guardian.c_str()) + "\n";
		output += "Patient age : " + cur->age + "\n";
		output += "Patient address: " + gcnew System::String(cur->address.c_str()) + "\n";
		output += "==========\n\n";
		cur = cur->next;
	}
	//std::cout << std::endl;
	return output;
}

//void PrintListR2HPatient(LISTPatient& LPatients) {
System::String^ PrintListR2HPatient(LISTPatient& LPatients) {
	Patient* cur;
	cur = LPatients.rear;
	System::String^ output = "";
	if (IsEmptyPatient(LPatients)) {
		//std::cout << "The Patients list is empty" << std::endl;
		//return;
		output += "The Patients list is empty\n\n";
		return output;
	}
	//std::cout << "The Patients list is R2H:" << std::endl << std::endl;
	output += "The Patients list is R2H:\n\n";
	for (int i = 0; i < GetNumberOfElementsPatient(LPatients); i++) {
		//std::cout << "Patient ID: " << std::to_string(cur->patientID) << std::endl;
		//std::cout << "Patient first name: " << cur->firstName << std::endl;
		//std::cout << "Patient last name: " << cur->lastName << std::endl;
		//std::cout << "Patient's reason of stay: " << cur->reasonOfStay << std::endl;
		//std::cout << "Patient guardian: " << cur->guardian << std::endl;
		//std::cout << "Patient age: " << cur->age << std::endl;
		//std::cout << "Patient address: " << cur->address << std::endl;
		//std::cout << "==========" << std::endl;
		//std::cout << std::endl;
		output += "Patient ID: " + cur->patientID + "\n";
		output += "Patient first name: " + gcnew System::String(cur->firstName.c_str()) + "\n";
		output += "Patient last name: " + gcnew System::String(cur->lastName.c_str()) + "\n";
		output += "Patient's reason of stay: " + gcnew System::String(cur->reasonOfStay.c_str()) + "\n";
		output += "Patient guardian: " + gcnew System::String(cur->guardian.c_str()) + "\n";
		output += "Patient age : " + cur->age + "\n";
		output += "Patient address: " + gcnew System::String(cur->address.c_str()) + "\n";
		output += "==========\n\n";
		cur = cur->prev;
	}
	//std::cout << std::endl;
	return output;
}

System::String^ deleteElementPatient(LISTPatient& LPatient, int PatientID) {
	Patient* cur;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The patients list is empty" << std::endl;
		output += "The patients list is empty\n";
		return output;
	}
	if (GetNumberOfElementsPatient(LPatient) == 1 && LPatient.head->patientID == PatientID) {
		cur = LPatient.head;
		delete cur;
		InitializeListPatient(LPatient);
		return output += "You deleted the last patient, reinitializing Patient List...\n";
	}
	// IF WE NEED TO DELETE THE HEAD
	if (LPatient.head->patientID == PatientID) {
		cur = LPatient.head->next;
		//std::cout << "Patient with ID \"" << cur->patientID << "\" has been deleted..." << std::endl;
		output += "Patient with ID \"" + PatientID + "\" has been deleted...\n";
		delete LPatient.head;
		LPatient.head = cur;
		LPatient.head->prev = LPatient.rear;
		LPatient.rear->next = LPatient.head;
		return output;
	}

	// IF WE NEED TO DELETE THE REAR
	if (LPatient.rear->patientID == PatientID) {
		cur = LPatient.rear->prev;
		//std::cout << "Patient with ID \"" << cur->patientID << "\" has been deleted..." << std::endl;
		output += "Patient with ID \"" + PatientID + "\" has been deleted...\n";
		delete LPatient.rear;
		LPatient.rear = cur;
		LPatient.head->prev = LPatient.rear;
		LPatient.rear->next = LPatient.head;
		return output;
	}
	cur = LPatient.head->next;
	while (cur != LPatient.head && cur->patientID != PatientID) {
		cur = cur->next;
	}
	// here we went a full circle meaning we couldnt find him
	if (cur == LPatient.head) {
		//std::cout << "Patient not found..." << std::endl;
		output += "Patient not found...\n";
		return output;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	//std::cout << "Patient with ID \"" << cur->patientID << "\" has been deleted..." << std::endl;
	delete cur;
	output += "Patient with ID \"" + PatientID + "\" has been deleted...\n";
	return output;
}

//void SortByAgeY2O(LISTPatient& LPatient) {
System::String^ SortByAgeY2O(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients from youngest to oldest..." << std::endl;
	output += "Sorting patients from youngest to oldest...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->age > cmpWith->age && cur!=LPatient.head && cmpWith!=LPatient.rear) {
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
			if (cur->age > cmpWith->age &&(cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->age > cmpWith->age &&(cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->age > cmpWith->age && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "List has been sorted by Age ( ASC )...\n";
	return output;
}

//void SortByAgeO2Y(LISTPatient& LPatient) {
System::String^ SortByAgeO2Y(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients from oldest to youngest..." << std::endl;
	output += "Sorting patients from oldest to youngest...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->age < cmpWith->age && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->age < cmpWith->age && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->age < cmpWith->age && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->age < cmpWith->age && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "List has been sorted by Age ( DEC )...\n";
	return output;
}

//void SortByID_ASC(LISTPatient& LPatient) {
System::String^ SortByID_ASC(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by ID in ascending order..." << std::endl;
	output += "Sorting patients by ID in ascending order...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->patientID > cmpWith->patientID && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->patientID > cmpWith->patientID && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->patientID > cmpWith->patientID && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->patientID > cmpWith->patientID && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "List has been sorted by IDs ( ASC )...\n";
	return output;
}

//void SortByID_DES(LISTPatient& LPatient) {
System::String^ SortByID_DES(LISTPatient & LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by ID in descending order..." << std::endl;
	output += "Sorting patients by ID in descending order...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->patientID < cmpWith->patientID && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->patientID < cmpWith->patientID && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->patientID < cmpWith->patientID && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->patientID < cmpWith->patientID && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by IDs ( DEC )...\n";
	return output;
}

//void SortByFirstNameA2Z(LISTPatient& LPatient) {
System::String^ SortByFirstNameA2Z(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by first name A2Z..." << std::endl;
	output += "Sorting patients by first name A2Z...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->firstName.compare(cmpWith->firstName) > 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->firstName.compare(cmpWith->firstName) > 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->firstName.compare(cmpWith->firstName) > 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->firstName.compare(cmpWith->firstName) > 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by first name ( A2Z )...\n";
	return output;
}

//void SortByFirstNameZ2A(LISTPatient& LPatient) {
System::String^ SortByFirstNameZ2A(LISTPatient & LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by first name Z2A..." << std::endl;
	output += "Sorting patients by first name Z2A\n...";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->firstName.compare(cmpWith->firstName) < 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->firstName.compare(cmpWith->firstName) < 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->firstName.compare(cmpWith->firstName) < 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->firstName.compare(cmpWith->firstName) < 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by first name ( Z2A )...\n";
	return output;
}

//void SortByLastNameA2Z(LISTPatient& LPatient) {
System::String^ SortByLastNameA2Z(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by last name A2Z..." << std::endl;
	output += "Sorting patients by last name A2Z...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->lastName.compare(cmpWith->lastName) > 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->lastName.compare(cmpWith->lastName) > 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->lastName.compare(cmpWith->lastName) > 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->lastName.compare(cmpWith->lastName) > 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by last name ( A2Z )...\n";
	return output;
}

//void SortByLastNameZ2A(LISTPatient& LPatient) {
System::String^ SortByLastNameZ2A(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by first name Z2A..." << std::endl;
	output += "Sorting patients by first name Z2A...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->lastName.compare(cmpWith->lastName) < 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->lastName.compare(cmpWith->lastName) < 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->lastName.compare(cmpWith->lastName) < 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->lastName.compare(cmpWith->lastName) < 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by last name ( Z2A )...\n";
	return output;
}

//void SortByGuardianA2Z(LISTPatient& LPatient) {
System::String^ SortByGuardianA2Z(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by guardian A2Z..." << std::endl;
	output += "Sorting patients by guardian A2Z...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->guardian.compare(cmpWith->guardian) > 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->guardian.compare(cmpWith->guardian) > 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->guardian.compare(cmpWith->guardian) > 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->guardian.compare(cmpWith->guardian) > 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by guardian ( A2Z )...\n";
	return output;
}

//void SortByGuardianZ2A(LISTPatient& LPatient) {
System::String^ SortByGuardianZ2A(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by guardian Z2A..." << std::endl;
	output += "Sorting patients by guardian Z2A...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->guardian.compare(cmpWith->guardian) < 0 && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->guardian.compare(cmpWith->guardian) < 0 && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->guardian.compare(cmpWith->guardian) < 0 && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->guardian.compare(cmpWith->guardian) < 0 && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by guardian ( Z2A )...\n";
	return output;
}

//void SortByAddressLengthS2L(LISTPatient& LPatient) {
System::String^ SortByAddressLengthS2L(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by address length from shortest to longuest..." << std::endl;
	output += "Sorting patients by address length from shortest to longuest...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->address.length() > cmpWith->address.length() && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->address.length() > cmpWith->address.length() && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->address.length() > cmpWith->address.length() && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->address.length() > cmpWith->address.length() && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by address length ( ASC )...\n";
	return output;
}

//void SortByAddressLengthL2S(LISTPatient& LPatient) {
System::String^ SortByAddressLengthL2S(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty";
		return output;
	}
	//std::cout << "Sorting patients by address length from longuest to shortest..." << std::endl;
	output += "Sorting patients by address length from longuest to shortest...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->address.length() < cmpWith->address.length() && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->address.length() < cmpWith->address.length() && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->address.length() < cmpWith->address.length() && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->address.length() < cmpWith->address.length() && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by address length ( DEC )...\n";
	return output;
}

//void SortByReasonOfStayLengthS2L(LISTPatient& LPatient) {
System::String^ SortByReasonOfStayLengthS2L(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by reason of stay length from shortest to longuest..." << std::endl;
	output += "Sorting patients by reason of stay length from shortest to longuest...";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->reasonOfStay.length() > cmpWith->reasonOfStay.length() && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->reasonOfStay.length() > cmpWith->reasonOfStay.length() && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->reasonOfStay.length() > cmpWith->reasonOfStay.length() && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->reasonOfStay.length() > cmpWith->reasonOfStay.length() && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by reason of stay length ( ASC )...\n";
	return output;
}

//void SortByReasonOfStayLengthL2S(LISTPatient& LPatient) {
System::String^ SortByReasonOfStayLengthL2S(LISTPatient& LPatient) {
	Patient* cur, * cmpWith, * tmp;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "The list is empty" << std::endl;
		//return;
		output += "The list is empty\n";
		return output;
	}
	//std::cout << "Sorting patients by reason of stay length from longuest to shortest..." << std::endl;
	output += "Sorting patients by reason of stay length from longuest to shortest...\n";
	cur = LPatient.head;
	cmpWith = cur->next;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		while (cmpWith != LPatient.head) {
			// CUR IS ANYWHERE AND CMPWITH IS ANYWHERE
			if (cur->reasonOfStay.length() < cmpWith->reasonOfStay.length() && cur != LPatient.head && cmpWith != LPatient.rear) {
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
			if (cur->reasonOfStay.length() < cmpWith->reasonOfStay.length() && (cur == LPatient.head && cmpWith == LPatient.head->next)) {

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

				LPatient.head = cur;

			}

			// CUR IS RIGHT BEFORE REAR
			if (cur->reasonOfStay.length() < cmpWith->reasonOfStay.length() && (cur == LPatient.rear->prev && cmpWith == LPatient.rear)) {

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

				LPatient.rear = cmpWith;

			}

			// CUR IS HEAD AND CMPWITH IS REAR
			if (cur->reasonOfStay.length() < cmpWith->reasonOfStay.length() && cur == LPatient.head && cmpWith == LPatient.rear) {
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

				LPatient.head = cur;
				LPatient.rear = cmpWith;

			}
			// AND THEN WE ADVANCE
			cmpWith = cmpWith->next;
			cur = cur->next;
		}
		cur = LPatient.head;
		cmpWith = cur->next;
	}
	output += "Patient list has been sorted by reason of stay length ( DEC )...\n";
	return output;
}

//void ReInitializeIDPatients(LISTPatient& LPatient) {
System::String^ ReInitializeIDPatients(LISTPatient& LPatient) {
	Patient* cur;
	System::String^ output = "";
	if (IsEmptyPatient(LPatient)) {
		//std::cout << "Patients list is empty..." << std::endl;
		//return;
		output += "Patients list is empty...\n";
		return output;
	}
	cur = LPatient.head;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		cur->patientID = i + 1;
		cur = cur->next;
	}
	output += "Patients list has be reinitialized...\n";
	return output;
}

Patient* GetPatient(LISTPatient& LPatient, int ID) {
	Patient* cur=NULL;
	if (IsEmptyPatient(LPatient)) {
		std::cout << "Patients list is empty..." << std::endl;
		return cur;
	}
	cur = LPatient.head;
	for (int i = 0; i < GetNumberOfElementsPatient(LPatient); i++) {
		if (cur->patientID == ID) {
			return cur;
		}
		cur = cur->next;
	}
	cur = NULL;
	return cur;
}

System::String^ printPatient(Patient* patient) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "This patient does not exist\n";
		return output;
	}
	else {
		output += "Patient ID: " + patient->patientID + "\n";
		output += "Patient first name: " + gcnew System::String(patient->firstName.c_str()) + "\n";
		output += "Patient last name: " + gcnew System::String(patient->lastName.c_str()) + "\n";
		output += "Patient's reason of stay: " + gcnew System::String(patient->reasonOfStay.c_str()) + "\n";
		output += "Patient guardian: " + gcnew System::String(patient->guardian.c_str()) + "\n";
		output += "Patient age : " + patient->age + "\n";
		output += "Patient address: " + gcnew System::String(patient->address.c_str()) + "\n";
		output += "==========\n\n";
	}
	return output;
}

System::String^ changeFirstName(Patient* patient, std::string fName) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->firstName = fName;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his first name...\n";
	return output;
}

System::String^ changeLastName(Patient* patient, std::string lName) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->lastName = lName;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his last name...\n";
	return output;
}

System::String^ changeReasonOfStay(Patient* patient, std::string reasonOfStay) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->reasonOfStay = reasonOfStay;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his reason of stay...\n";
	return output;
}

System::String^ changeAge(Patient* patient, int age) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->age = age;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his age...\n";
	return output;
}

System::String^ changeGuardian(Patient* patient, std::string guardian) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->guardian = guardian;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his guardian...\n";
	return output;
}

System::String^ changeAddress(Patient* patient, std::string address) {
	System::String^ output = "";
	if (patient == NULL) {
		output += "Patient not found...\n";
		return output;
	}
	patient->address = address;
	output += "Patient with ID " + patient->patientID + " has succesfully updated his address...\n";
	return output;
}
#endif