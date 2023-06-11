#ifndef roomsCommands_h
#define roomsCommands_h

#include <iostream>
#include <string>
#include "PatientsCommands.h"

#define MAXROOMTYPES 14
#define MAXROOMSPERFLOOR 14
#define MAXFLOORS 4

std::string roomDescriptions[MAXROOMTYPES]{
	"The part of a hospital where people go when they are injured or suddenly become ill. The official name for this is Accident and Emergency. The American word is emergency room",
	"A room where a doctor examines a patient and discusses their medical problems with them",
	"A room in a hospital where patients can go during the day to watch television, read, or talk",
	"A room in a hospital where women give birth",
	"A place in a hospital where you can get medicines and drugs",
	"The department of a hospital for people who are very ill or badly injured, but need less care than people in intensive care",
	"The department of a hotel or hospital that is responsible for cleaning rooms",
	"The part of a hospital where pregnant women or women who have just given birth to babies are looked after",
	"An area in a hospital where new babies are looked after until they go home",
	"A room in a hospital where doctors perform medical operations",
	"A room in a hospital for mentally ill people, with soft material on the walls so that they cannot hurt themselves",
	"The part of a shop or hospital where medicines are prepared",
	"A room where someone who is ill rests or gets medical treatment",
	"A large room in a hospital with beds for people to stay in",
};

std::string roomNames[MAXROOMTYPES]{
	"Emergency room",
	"Consulting room",
	"Day room",
	"Delivery room",
	"Dispensary",
	"High dependency unit",
	"Housekeeping",
	"ICU",
	"Maternity ward",
	"Nursery",
	"Operating room",
	"Padded cell",
	"Pharmacy",
	"Sickroom",
};

struct  Rooms {
	//Room id made using floor number and room number
	std::string roomId;
	std::string roomName;
	std::string roomDescription;
	int nbOfPatientsInRoom = 0;
	Patient* patientsInRoom[4] ={ nullptr,nullptr,nullptr,nullptr }; // we can only fit 4 patients in a room


	Rooms* next;
	Rooms* prev;
};
struct LISTRooms {
	Rooms* head;
	Rooms* rear;
};
void InitializeListRooms(LISTRooms& LRooms) {
	LRooms.head = NULL;
	LRooms.rear = NULL;
}
bool IsEmptyRooms(LISTRooms& LRooms) {
	return (LRooms.head == NULL);
}

struct Floors {
	int floorNb = 0;
	//Each floor has double linked list of rooms
	LISTRooms listRooms;
	Floors* next;
	Floors* prev;
};

struct LISTFloors {
	Floors* head;
	Floors* rear;
};
bool IsEmptyFloors(LISTFloors& LFloors) {
	return (LFloors.head == NULL);
}

int GetNumberOfElementsFloors(LISTFloors& LFloors) {
	int nb = 0;
	Floors* cur;
	if (IsEmptyFloors(LFloors))
		return nb;
	cur = LFloors.head;
	while (cur != NULL) {
		nb++;
		cur = cur->next;
	}
	return nb;
}

int GetNumberOfElementsRooms(LISTRooms& LRooms) {
	return MAXROOMSPERFLOOR;
}

System::String^ InsertPatientToRoom(Rooms& room, Patient& patient) {
	System::String^ output = "";
	if (room.nbOfPatientsInRoom == 4) {
		//std::cout << "This room (ID: " << room.roomId << ") is full...";
		output+= "This room (ID: " + gcnew System::String(room.roomId.c_str()) + ") is full...\n";
		return output;
	}
	// make sure the patient isn't already in this room
	for (int i = 0; i < 4; i++) {
		if (room.patientsInRoom[i] != NULL) {
			if (room.patientsInRoom[i]->patientID == patient.patientID) {
				output += "Patient already in this room...\n";
				return output;
			}
		}
	}

	// if room doesnt have this patient and has space for more patients
	for (int i = 0; i < 4; i++) {
		if (room.patientsInRoom[i] == NULL) {
			room.patientsInRoom[i] = &patient;
			break;
		}
	}
		
		//std::cout << "Patient \"" << room.patientsInRoom[room.nbOfPatientsInRoom].firstName
		//	<< " " << room.patientsInRoom[room.nbOfPatientsInRoom].lastName
		//	<< " ID: " << room.patientsInRoom[room.nbOfPatientsInRoom].patientID
		//	<< "\", has been succesfully added...."
		//	<< std::endl;
		output += "Patient \"" + gcnew System::String(room.patientsInRoom[room.nbOfPatientsInRoom]->firstName.c_str())
			+ " " + gcnew System::String(room.patientsInRoom[room.nbOfPatientsInRoom]->lastName.c_str())
			+ " ID: " + room.patientsInRoom[room.nbOfPatientsInRoom]->patientID
			+ "\", has been succesfully added...\n";
		room.nbOfPatientsInRoom++;
		return output;
	}

System::String^ RemovePatientFromRoom(Rooms& room, int PatientID) { // index is the place of the patient in the room
	int found = 0;
	System::String^ output = "";
	if (room.nbOfPatientsInRoom == 0) {
		//std::cout << "This room has no patients" << std::endl;
		//return;
		output += "This room has no patients\n";
		return output;
	}
	for (int i = 0; i < room.nbOfPatientsInRoom; i++)
	{
		if (room.patientsInRoom[i] == NULL) continue;
		if (room.patientsInRoom[i]->patientID==PatientID)
		{
			room.patientsInRoom[i] = nullptr;
			found++;
			room.nbOfPatientsInRoom--;
		}
	}
	if (found == 0) {
		//std::cout << "Patient was not found...";
		output += "Patient was not found...\n";
		return output;
	}
	else {
		output += "Patient was remove from room with ID: " + gcnew System::String(room.roomId.c_str()) +"\n";
		return output;
	}
		//std::cout << "Patient was remove from room with ID: " << room.roomId << std::endl;
	//std::cout << std::endl;
}

System::String^ PrintPatientsInfoInRoom(Rooms* room) {
	System::String^ output;
	if (room->nbOfPatientsInRoom == 0){
		//std::cout << "This room has no patients" << std::endl;
		output += "This room has no patients\n";
		return  output;
	}
	else {
		//std::cout << "Patients inside this room:" << std::endl;
		output += "Patients inside this room:\n\n";
		for (int i = 0; i < 4; i++) {
			//std::cout << "Patient ID: " << std::to_string(room.patientsInRoom[i].patientID) << std::endl;
			//std::cout << "Patient first name: " << room.patientsInRoom[i].firstName << std::endl;
			//std::cout << "Patient last name: " << room.patientsInRoom[i].lastName << std::endl;
			//std::cout << "Patient's reason of stay: " << room.patientsInRoom[i].reasonOfStay << std::endl;
			//std::cout << "Patient guardian: " << room.patientsInRoom[i].guardian << std::endl;
			//std::cout << "Patient age: " << room.patientsInRoom[i].age << std::endl;
			//std::cout << "Patient address: " << room.patientsInRoom[i].address << std::endl;
			//std::cout << "==========" << std::endl;
			//std::cout << std::endl;
			if (room->patientsInRoom[i] != NULL) {
				output += "Patient ID: " + room->patientsInRoom[i]->patientID + "\n";
				output += "Patient first name: " + gcnew System::String(room->patientsInRoom[i]->firstName.c_str()) + "\n";
				output += "Patient last name: " + gcnew System::String(room->patientsInRoom[i]->lastName.c_str()) + "\n";
				output += "Patient's reason of stay: " + gcnew System::String(room->patientsInRoom[i]->reasonOfStay.c_str()) + "\n";
				output += "Patient guardian: " + gcnew System::String(room->patientsInRoom[i]->guardian.c_str()) + "\n";
				output += "Patient age : " + room->patientsInRoom[i]->age + "\n";
				output += "Patient address: " + gcnew System::String(room->patientsInRoom[i]->address.c_str()) + "\n";
				output += "==========\n\n";
			}
		}
		return output;
	}
}

void InsertElementFloors(LISTFloors& LFloors, int val) {
	Floors* tmp;
	tmp = new Floors;
	
	tmp->floorNb = val;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (IsEmptyFloors(LFloors)) {
		LFloors.head = tmp;
		LFloors.rear = tmp;
		return;
	}
	else {
		LFloors.rear->next = tmp;
		tmp->prev = LFloors.rear;
		LFloors.rear = tmp;
	}
}

//Create the room doubly linked list thing
void GenerateFloors(LISTFloors& listFloors) {
	for (int i = 1; i < 5; i++)
		InsertElementFloors(listFloors, i);
}

void InitializeListFloors(LISTFloors& LFloors) {
	LFloors.head = NULL;
	LFloors.rear = NULL;
	GenerateFloors(LFloors);
}

void InsertRoomsListToFloors(
	LISTFloors& LFloors,
	LISTRooms& LRooms1,
	LISTRooms& LRooms2,
	LISTRooms& LRooms3,
	LISTRooms& LRooms4
) {
	Floors* cur;
	cur = LFloors.head;
	cur->listRooms = LRooms1;
	cur = cur->next;
	cur->listRooms = LRooms2;
	cur = cur->next;
	cur->listRooms = LRooms3;
	cur = cur->next;
	cur->listRooms = LRooms4;
	cur = cur->next;
	delete cur;

}

void InsertInfoToRoomsList(LISTRooms& LRooms, int i, int floorNb) {
	Rooms* tmp;
	tmp = new Rooms;
	std::string id = std::to_string(floorNb)+"."+std::to_string(i);
	tmp->next = NULL;
	tmp->prev = NULL;
	if (IsEmptyRooms(LRooms)) {
		tmp->roomId = id;
		tmp->roomName = roomNames[i - 1];
		tmp->roomDescription = roomDescriptions[i - 1];
		LRooms.head = tmp;
		LRooms.rear = tmp;
	}
	else {
		tmp->roomId = id;
		tmp->roomName = roomNames[i - 1];
		tmp->roomDescription = roomDescriptions[i - 1];
		LRooms.rear->next = tmp;
		tmp->prev = LRooms.rear;
		LRooms.rear = tmp;
	}
}

//void PrintListH2RFloors(LISTFloors& LFloors) {
System::String^ PrintListH2RFloors(LISTFloors& LFloors) {
	Floors* cur = LFloors.head;
	System::String^ output = "";
	if (IsEmptyFloors(LFloors)) {
		//std::cout << "The floors list is empty" << std::endl;
		//return;
		output += "The floors list is empty\n\n";
		return output;
	}
	//std::cout << "The floors list is H2R:" << std::endl << std::endl;
	output += "The floors list is H2R:\n\n";
	while (cur != NULL) {
		//std::cout << cur->floorNb << " ";
		output += "Floor number: " + cur->floorNb + "\n";
		cur = cur->next;
	}
	//std::cout << std::endl;
	output += "=========\n";
	return output;
}
//void PrintListR2HFloors(LISTFloors& LFloors) {
System::String^ PrintListR2HFloors(LISTFloors& LFloors) {
	Floors* cur = LFloors.rear;
	System::String^ output = "";
	if (IsEmptyFloors(LFloors)) {
		//std::cout << "The floors list is empty" << std::endl;
		//return;
		output += "The floors list is empty\n\n";
		return output;
	}
	//std::cout << "The floors list is R2H:" << std::endl << std::endl;
	output += "The floors list is R2H:\n\n";
	while (cur != NULL) {
		//std::cout << cur->floorNb << " ";
		output += "Floor number: " + cur->floorNb + "\n";
		cur = cur->prev;
	}
	//std::cout << std::endl;
	output += "=========\n";
	return output;
}

//void PrintListH2RRooms(LISTRooms& LRooms) {
System::String^ PrintListH2RRooms(LISTRooms& LRooms) {
	Rooms* cur = LRooms.head;
	System::String^ output = "";
	if (IsEmptyRooms(LRooms)) {
		//std::cout << "The rooms list is empty" << std::endl << std::endl;
		//return;
		output += "The rooms list is empty\n\n";
		return output;
	}
	//std::cout << "The rooms list is H2R:" << std::endl << std::endl;
	output += "The rooms list is H2R:\n\n";
	while (cur != NULL) {
		//std::cout << cur->roomId << std::endl;
		//std::cout << cur->roomName << std::endl;
		//std::cout << cur->roomDescription << std::endl;

		output += "•Room ID: " + gcnew System::String(cur->roomId.c_str())  + "\n";
		output += "•Room Name: " + gcnew System::String(cur->roomName.c_str()) + "\n";
		output += "•Room Description: " + gcnew System::String(cur->roomDescription.c_str()) + "\n";
		output += "•Number of patients in this room: " + cur->nbOfPatientsInRoom + "\n\n";
		cur = cur->next;
	}
	//std::cout << std::endl;
	output += "=========\n";
	return output;
}

//void PrintListR2HRooms(LISTRooms& LRooms) {
System::String^ PrintListR2HRooms(LISTRooms& LRooms) {
	Rooms* cur = LRooms.rear;
	System::String^ output;
	if (IsEmptyRooms(LRooms)) {
		//std::cout << "The Rooms list is empty" << std::endl << std::endl;
		//return;
		output += "The Rooms list is empty\n\n";
		return output;
	}
	//std::cout << "The Rooms list is R2H:" << std::endl;
	output += "The rooms list is R2H:\n\n";
	while (cur != NULL) {
		//std::cout << cur->roomId << std::endl;
		//std::cout << cur->roomName << std::endl;
		//std::cout << cur->roomDescription << std::endl;

		output += "•Room ID: " + gcnew System::String(cur->roomId.c_str()) + "\n";
		output += "•Room Name: " + gcnew System::String(cur->roomName.c_str()) + "\n";
		output += "•Room Description: " + gcnew System::String(cur->roomDescription.c_str()) + "\n";
		output += "•Number of patients in this room: " + cur->nbOfPatientsInRoom + "\n\n";
		cur = cur->prev;
	}
	//std::cout << std::endl;
	output += "=========\n";
	return output;
}

Rooms* searchRoomsOnFloor(LISTRooms& LRooms, std::string ID) {
	Rooms* cur;
	cur = NULL;
	if (IsEmptyRooms(LRooms)) {
		//std::cout << "There no rooms on this floor..." << std::endl;
		return cur;
	}
	cur = LRooms.head;
	while (cur != NULL) {
		if (cur->roomId.compare(ID)==0) {
			return cur;
		}
		cur = cur->next;
	}
	cur = NULL;
	return cur;
}

//Rooms* GetRoom(LISTFloors& LFloors, std::string ID) {
Rooms* GetRoom(LISTFloors & LFloors, std::string ID) {
	Rooms* cur = NULL;
	Floors* curF;
	if (IsEmptyFloors(LFloors)) {
		//std::cout << "There are no floors meaning there's no rooms as well..." << std::endl; // will never be reached
		return cur;
	}
	LISTRooms crawler;
	curF = LFloors.head;
	while (curF != NULL) {
		crawler = curF->listRooms;
		cur = searchRoomsOnFloor(crawler, ID);
		if (cur != NULL) {
			break;
		}
		curF = curF->next;
	}
	return cur;
}

//Later use ( nvm, never used )

//void Initialize(ARRAY* structureObject);
//
//bool IsEmpty(ARRAY* structureObject);
//
//bool IsFull(ARRAY* structureObject);
//
//bool IsInArray(ARRAY* structureObject, int* val);
//
//int FindElement(ARRAY* structureObject, int* val);
//
//int GetElementNb(ARRAY* structureObject);
//
//void PrintArray(ARRAY* structureObject);
//
//bool InsertAtHead(ARRAY* structureObject, int* val);
//
//bool InsertAtQueue(ARRAY* structureObject, int* val);
//
//bool InsertAtPosition(ARRAY* structureObject, int* val, int pos);
//
//bool DeleteElement(ARRAY* structureObject, int val);
//
//bool DeleteAtPosition(ARRAY* structureObject, int pos);
//
//void DeleteAllElement(ARRAY* structureObject);
//
//bool ModifyElement(ARRAY* structureObject, int oldval, int newval);
//
//bool ModifyAtPosition(ARRAY* t, int newval, int pos);
//
//bool InsertElementSorted(ARRAY* structureObject, int* val);
//
//bool ModifyElementSorted(ARRAY* structureObject, int oldval, int newval);

#endif
