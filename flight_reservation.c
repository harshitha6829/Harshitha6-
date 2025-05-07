
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 5
#define NAME_LENGTH 50

// Structure for flight
typedef struct {
int flightNumber;
char origin[30];
char destination[30];
} Flight;

// Structure for passenger
typedef struct Passenger {
char name[NAME_LENGTH];
int flightNumber;
struct Passenger* next;
} Passenger;

Flight flights[MAX_FLIGHTS];              // Array of flights
Passenger* head = NULL;                   // Head of passenger linked list

void initializeFlights() {
flights[0] = (Flight){101, "New York", "Los Angeles"};
flights[1] = (Flight){102, "Chicago", "Miami"};
flights[2] = (Flight){103, "Dallas", "Seattle"};
flights[3] = (Flight){104, "Boston", "San Francisco"};
flights[4] = (Flight){105, "Houston", "Denver"};
}

void displayFlights() {
printf("\nAvailable Flights:\n");
for (int i = 0; i < MAX_FLIGHTS; i++) {
printf("%d: %s to %s\n", flights[i].flightNumber, flights[i].origin, flights[i].destination);
}
}

void bookPassenger() {
char name[NAME_LENGTH];
int flightNumber;

printf("\nEnter passenger name: ");  
scanf(" %[^
]", name);  

displayFlights();  
printf("Enter flight number to book: ");  
scanf("%d", &flightNumber);  

// Check if flight exists  
int found = 0;  
for (int i = 0; i < MAX_FLIGHTS; i++) {  
    if (flights[i].flightNumber == flightNumber) {  
        found = 1;  
        break;  
    }  
}  
if (!found) {  
    printf("Invalid flight number.\n");  
    return;  
}  

// Create new passenger node  
Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));  
strcpy(newPassenger->name, name);  
newPassenger->flightNumber = flightNumber;  
newPassenger->next = head;  
head = newPassenger;  

printf("Booking successful for %s on flight %d.\n", name, flightNumber);

}

void showBookings() {
Passenger* temp = head;
if (!temp) {
printf("\nNo bookings found.\n");
return;
}
printf("\nPassenger Bookings:\n");
while (temp != NULL) {
printf("Name: %s, Flight: %d\n", temp->name, temp->flightNumber);
temp = temp->next;
}
}

void freeMemory() {
Passenger* temp;
while (head != NULL) {
temp = head;
head = head->next;
free(temp);
}
}

int main() {
int choice;
initializeFlights();

do {  
    printf("\n--- Flight Reservation System ---\n");  
    printf("1. Show Flights\n");  
    printf("2. Book Passenger\n");  
    printf("3. Show Bookings\n");  
    printf("4. Exit\n");  
    printf("Enter your choice: ");  
    scanf("%d", &choice);  

    switch(choice) {  
        case 1: displayFlights(); break;  
        case 2: bookPassenger(); break;  
        case 3: showBookings(); break;  
        case 4: freeMemory(); printf("Exiting...\n"); break;  
        default: printf("Invalid choice.\n");  
    }  
} while (choice != 4);  

return 0;
}
