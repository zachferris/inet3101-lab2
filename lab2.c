#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Holds part details
typedef struct {
    int partNumber;
    char partName[50];
    float partSize;
    char partSizeMetric[10];
    float partCost;
} Part;

// Global variables
char databaseName[50];  // Stores the database name
Part *records = NULL;  // Pointer to allocated memory
int recordCount = 0;  // Number of records in the database

// Function prototypes
void printAllRecords();
void addRecord();
void deleteRecord();
void printNumRecords();
void printDatabaseSize();
int printNumChanges(int print);
void displayMenu();

int main(int argc, char *argv[]) {
    // Check if database name is provided
    if (argc < 2) {
        printf("Error: Please provide a database name.\n");
        return 1;
    }

    // Store database name
    strcpy(databaseName, argv[1]);

    int choice;
    do {
        displayMenu();
        printf("Please enter your selection > ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printAllRecords(); break;
            case 2: addRecord(); break;
            case 3: deleteRecord(); break;
            case 4: printNumRecords(); break;
            case 5: printDatabaseSize(); break;
            case 6: printNumChanges(1); break;
            case 7: printf("Exiting program...\n"); break;
            default: printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 7);

    free(records); // free allocated memory before exiting
    return 0;
}


// Function to display menu
void displayMenu() {
    printf("\n=== %s Database Menu ===\n", databaseName);
    printf("1. Print all records\n");
    printf("2. Add a record\n");
    printf("3. Delete the last record\n");
    printf("4. Print number of records\n");
    printf("5. Print database size\n");
    printf("6. Print number of changes\n");
    printf("7. Exit\n");
}

// Function to print all records
void printAllRecords() {
    if (recordCount == 0) {
        printf("No records in the database.\n");
        return;
    }
    
    printf("Database Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("\tRecord %d:\n", i + 1);
        printf("\t\tPart Number: %d\n", records[i].partNumber);
        printf("\t\tPart Name: %s\n", records[i].partName);
        printf("\t\tPart Size: %.2f %s\n", records[i].partSize, records[i].partSizeMetric);
        printf("\t\tPart Cost: $%.2f\n", records[i].partCost);
    }
}

// Function to add a record
void addRecord() {
    // Allocate new memory for the record
    Part *newRecords = (Part *)malloc((recordCount + 1) * sizeof(Part));
    
    if (newRecords == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy old records to the new memory block
    for (int i = 0; i < recordCount; i++) {
        newRecords[i] = records[i];
    }

    // Free old memory
    free(records);
    records = newRecords;

    // Get new record data
    printf("Enter Part Number: ");
    scanf("%d", &records[recordCount].partNumber);

    printf("Enter Part Name: ");
    scanf("%49s", records[recordCount].partName);

    printf("Enter Part Size: ");
    scanf("%f", &records[recordCount].partSize);

    printf("Enter Part Size Metric: ");
    scanf("%9s", records[recordCount].partSizeMetric);

    printf("Enter Part Cost: ");
    scanf("%f", &records[recordCount].partCost);

    recordCount++;
    printf("Record added successfully.\n");
}


// Function to delete the last record
void deleteRecord() {
    if (recordCount == 0) {
        printf("No records to delete.\n");
        return;
    }

    recordCount--;  // Remove last record

    if (recordCount == 0) {
        free(records);
        records = NULL;
        printf("Last record deleted successfully.\n");
        return;
    }

    Part *newRecords = (Part *)malloc(recordCount * sizeof(Part));
    if (newRecords == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    memcpy(newRecords, records, recordCount * sizeof(Part));
    free(records);
    records = newRecords;

    printf("Last record deleted successfully.\n");

}

// Function to print number of records
void printNumRecords() {
    printf("Number of records: %d\n", recordCount);
}

// Function to print database size (in bytes)
void printDatabaseSize() {
    printf("Database size: %lu bytes\n", recordCount * sizeof(Part));
}

// Function to track number of changes
int printNumChanges(int print) {
    static int changeCount = 0;

    if (print) {
        printf("You have modified the database %d times.\n", changeCount);
    } else {
        changeCount++;
        printf("%d modifications so far.\n", changeCount);
    }
    return changeCount;
}
