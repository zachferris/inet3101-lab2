# INET3101 C Programming Lab 2

## READ ME

**Author:** Zach Ferris
**Program Name:** Simple In-Memory Database (Lab 2)
**Description:**
The program is a simple menu-driven interface to interact with an in-memory database.
It allows users to add, delete, and display records, while also providing database statistics.

## Menu Options
1. Print all records
2. Add a record
3. Delete the last record
4. Print number of records
5. Print database size
6. Print number of changes
7. Exit

The program will repeatedly display this menu until the user selects the Exit option which is number 7.

## Functions and Their Behavior

### void printAllRecords()
- **Input:** None
- **Output:** Prints all records stored in the database.
- **Description:** Displays each record, including part number, name, size, metric, and cost. If there are no records, it prints an appropriate message.

### void addRecord()
- **Input:** User inputs values for:
    - Part number (integer)
    - Part name (string)
    - Part size (float)
    - Part size metric (string)
    - Part cost (float)
- **Output:** Prints confirmation of the added record.
- **Description:** Dynamically allocates memory for a new record, copies old records, and prompts user for input. The new record is stored, and memory is adjusted accordingly.

### void deleteRecord()
- **Input:** None
- **Output:** Prints a confirmation message for deletion.
- **Description:** Removes the last record from memory, reallocates the memory block accordingly, and prevents memory leaks by freeing unused space.

### void printNumRecords()
- **Input:** None
- **Output:** Displays the current number of records.
- **Description:** Keeps track of and displays the number of stored records.

### void printDatabaseSize()
- **Input:** None
- **Output:** Displays the total database size in bytes.
- **Description:** Uses sizeof() to calculate and display the memory footprint of the stored records.

### int printNumChanges(int print)
- **Input:** Integer (1 for print, 0 for increment).
- **Output:** If print is 1, it prints the total number of changes made to the database. If 0, it increments the count of changes.
- **Description:** Uses a static variable to track the number of modifications (adds or deletes) in the database.

## Files in the Project
- Lab2.c → The main source file containing the program logic.
- README.txt → This design document.
- labtest (compiled file) → Compiled version of the program.

## Command Line Arguments
- The program requires a database name as a command-line argument.
- Compile: gcc lab2.c -o databaseProgram
- Example usage: ./databaseProgram MyDatabase
