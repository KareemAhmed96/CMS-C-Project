#include <stdio.h>

#define SUCCESS                     1
#define FAILURE                     0

#define TRUE                        1
#define FALSE                       0

#define NOT_DETERMINED              0
#define ADMIN                       1
#define	USER                        2
#define ADMIN_LOGGED_IN             3

#define MAX_PWD_ATTEMPTS            3

#define ADD_NEW_PATIENT_RECORD      1
#define EDIT_PATIENT_RECORD         2
#define RESERVE_SLOT                3
#define CANCEL_RESERVATION          4

#define ID_IS_NOT_UNIQUE            0
#define ID_IS_UNIQUE                1
#define FIRST_ID                    2

#define N_SLOTS                     5
#define FIRST_SLOT                  1
#define SECOND_SLOT                 2
#define THIRD_SLOT                  3
#define FOURTH_SLOT                 4
#define FIFTH_SLOT                  5

#define RESERVED                    1
#define NOT_RESERVED                0

unsigned char patient_count;
unsigned char Current_Mode;
unsigned char admin_cases;
unsigned char ID_Flag;
unsigned char available_slots[N_SLOTS];
unsigned char no_available_slots;
unsigned char slot_cases;

typedef struct {

    char Name[25];
    int Age;
    char Gender[25];
    long ID;
    unsigned char reserved_slot;

} Basic_Info_Type;

Basic_Info_Type Patient_Database[50];



/*********************FUNCTION PROTOTYPES*********************/
/* 
 * Function Name: Welcome_Screen
 * Welcome prompt and selection of
 * user mode or administrator mode
 */
void Welcome_Screen(void);


/* 
 * Function Name: Request_Password
 * Requests Password from the user
 * Returns Success or Failure if pwd is correct
 */
unsigned char Request_Password(void);


/* 
 * Function Name: Verify_Admin_Login
 * Checks with a maximum of 3 trials the Admin's password
 */
void Verify_Admin_Login(void);


/* 
 * Function Name: Admin_Logged_In
 * Sets the flag and prints to the user successful login
 */
void Admin_Logged_In(void);


/* 
 * Function Name: Admin_Options_Menu
 * Displays the admin options to the user
 * and prompts the user to input his selection
 */
void Admin_Options_Menu(void);


/* 
 * Function Name: Add_New_Patient_Record
 * Creates a new patient record
 * Appends it to the data-base (array of structures)
 * Returns Success or Failure 
 */
unsigned char Add_New_Patient_Record(void);


/* 
 * Function Name: Edit_Patient_Record
 * Edits a particular patient's Record
 * By entering the ID number
 * Returns Success or Failure if ID is found or not
 */
unsigned char Edit_Patient_Record(int ID);


/* 
 * Function Name: Reserve_Slot_Menu
 * Displays a dynamic list of reservation options
 * this list gets updated when a slot is reserved
 * which means that when a slot is reserved it will not
 * show again in the menu 
 */
void Reserve_Slot_Menu(void);


/* 
 * Function Name: Reserve_Slot
 * Reserves a slot with the doctor
 * By entering the ID number and slot number
 * Returns Success or Failure if ID is found or not
 * and if the slot number exists
 */
unsigned char Reserve_Slot(unsigned char slot_number);


/* 
 * Function Name: Cancel_Reservation
 * Cancels a slot with the doctor
 * By entering the ID number
 * Returns Success or Failure if ID is found or not
 */
unsigned char Cancel_Reservation(void);


/* 
 * Function Name: View_Patient_Record "user mode"
 * Shows basic information of the patient
 * By entering the ID number
 * Returns Success or Failure if ID is found or not
 */
unsigned char View_Patient_Record(int ID);


/* 
 * Function Name: View_Reservations_Today "user mode"
 * Prints all reservations of the day
 */
void View_Reservations_Today(void);
