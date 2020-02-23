#include "CMS.h"

void Welcome_Screen(void)
{
	int user_input = 0;

	printf("\nWelcome To The Clinic Management System \n\n");
	printf("_______________________________________\n\n");
	printf("Please Select the desired mode: - \n\n");
	printf("1-Administrator Mode \n2-User Mode \n\n");

	fflush(stdin);
	scanf("%d", &user_input);

	if(user_input == ADMIN)
	{
		Current_Mode = ADMIN;
	}
	else if(user_input == USER)
	{
		Current_Mode = USER;
		printf("You are now logged in as a user");
	}
}

unsigned char Request_Password(void)
{
	int password_input = 0;

	printf("\nPlease enter the password \n");

	fflush(stdin);
	scanf("%d", &password_input);

	//Can be modified to be an array of digits
	if(password_input == 1234)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

void Verify_Admin_Login(void)
{
	if( SUCCESS == Request_Password() )
	{
		Admin_Logged_In();
	}
	else
	{	
		//MISRA-C Violation 
		for(int i=MAX_PWD_ATTEMPTS ; (i>0) && Current_Mode != ADMIN_LOGGED_IN ; i--)
		{
			printf("You have %d trials remaining, ", i);
			if( SUCCESS == Request_Password() )
			{
				Admin_Logged_In();
			}
		}
	}	
}

void Admin_Logged_In(void)
{
	Current_Mode = ADMIN_LOGGED_IN;
	printf("\n***You are now logged in as an administrator***\n\n");
}

void Admin_Options_Menu(void)
{
	printf("Select your option: -\n");
	printf("---------------------\n\n");
	printf("1- Add new patient record\n");
	printf("2- Edit patient record\n");
	printf("3- Reserve a slot with the doctor\n");
	printf("4- Cancel reservation\n\n");

	fflush(stdin);
	scanf("%d", &admin_cases);
}

unsigned char Add_New_Patient_Record(void)
{	
	int i = 0;

	fflush(stdin);
	printf("\nEnter Name: ");
	scanf("%s", &Patient_Database[patient_count].Name); /*[^\n]*/

	printf("Enter Age: ");
	fflush(stdin);
	scanf("%d", &Patient_Database[patient_count].Age);

	printf("Enter Gender: ");
	fflush(stdin);
	scanf("%s", &Patient_Database[patient_count].Gender);

	do
	{
		printf("Enter a unique ID: ");
		fflush(stdin);
		scanf("%d", &Patient_Database[patient_count].ID);
	
		//Checking that ID is unique...
		for(i = patient_count ; i >= 0 ; i--)
		{
			if(ID_Flag == FIRST_ID)
			{	
				ID_Flag = ID_IS_UNIQUE;
			}
			else if(Patient_Database[patient_count].ID == Patient_Database[i-1].ID)
			{
				ID_Flag = ID_IS_NOT_UNIQUE;
				printf("\n***ID already exists***\n");
				break;
			}
			else
			{
				ID_Flag = ID_IS_UNIQUE;
			}
		}
		
	}while(ID_Flag == ID_IS_NOT_UNIQUE);

	//Checking
	printf("\n***Successfully added new patient***\n");
	printf("Name: %s\n", Patient_Database[patient_count].Name);
	printf("Age: %d\n", Patient_Database[patient_count].Age);
	printf("Gender: %s\n", Patient_Database[patient_count].Gender);
	printf("ID: %d\n", Patient_Database[patient_count].ID);

	patient_count++;
	
	return SUCCESS;
}

unsigned char Edit_Patient_Record(int ID)
{
	printf("This feature has NOT been added yet...");

	return SUCCESS;
}

void Reserve_Slot_Menu(void)
{
	for(int i = 0 ; i < N_SLOTS ; i++)
	{	
		if(available_slots[i] == RESERVED)
			no_available_slots = TRUE;
		else
			no_available_slots = FALSE;
	}

	printf("\nChoose one of the available slots: -\n");
	printf("------------------------------------\n\n");
	if(no_available_slots == TRUE)
		printf("No slots are available with the doctor\n");
	
	if(available_slots[FIRST_SLOT-1] == NOT_RESERVED)
		printf("1- 02:00 PM to 02:30 PM\n");

	if(available_slots[SECOND_SLOT-1] == NOT_RESERVED)
		printf("2- 02:30 PM to 03:00 PM\n");

	if(available_slots[THIRD_SLOT-1] == NOT_RESERVED)
		printf("3- 03:00 PM to 03:30 PM\n");

	if(available_slots[FOURTH_SLOT-1] == NOT_RESERVED)
		printf("4- 04:00 PM to 04:30 PM\n");

	if(available_slots[FIFTH_SLOT-1] == NOT_RESERVED)
		printf("5- 04:30 PM to 05:00 PM\n\n");

	fflush(stdin);
	scanf("%d", &slot_cases);

	switch(slot_cases)
	{
		case FIRST_SLOT:
			printf("\nFirst Slot\n");
			Reserve_Slot(slot_cases);
			break;

		case SECOND_SLOT:
			printf("\nSecond Slot\n");
			Reserve_Slot(slot_cases);
			break;

		case THIRD_SLOT:
			printf("\nThird Slot\n");
			Reserve_Slot(slot_cases);
			break;

		case FOURTH_SLOT:
			printf("\nFourth Slot\n");
			Reserve_Slot(slot_cases);
			break;

		case FIFTH_SLOT:
			printf("\nFifth Slot\n");
			Reserve_Slot(slot_cases);
			break;
	}
}

unsigned char Reserve_Slot(unsigned char slot_number)
{
	unsigned char status;
	unsigned char rsv_id_input; //reservation ID user input

	do
	{
		printf("Please enter your ID for reservation: \n");
		fflush(stdin);
		scanf("%d", &rsv_id_input);

		//Checking that the entered ID exists
		for(int i = patient_count ; i >= 0 ; i--)
		{
			if(rsv_id_input == Patient_Database[patient_count].ID)
			{	
				printf("***ID accepted***");
				status = SUCCESS;
			}
			else
			{	
				printf("ID doesn't exist, ");
				status = FAILURE;	
			}
		}
	}while(status != SUCCESS);

	Patient_Database[patient_count].reserved_slot = slot_cases;
	available_slots[slot_cases-1] = RESERVED;

	return status;
}

unsigned char Cancel_Reservation(void)
{
	unsigned char status;
	unsigned char rsv_id_input;
	unsigned char slot;

	do
	{
		printf("Please enter your ID to cancel reservation: \n");
		fflush(stdin);
		scanf("%d", &rsv_id_input);
		
		for(int i = patient_count ; i >= 0 ; i--)
		{
			if(rsv_id_input == Patient_Database[patient_count].ID)
			{
				printf("\n***ID accepted***\n");
				slot = Patient_Database[patient_count].reserved_slot;
				Patient_Database[patient_count].reserved_slot = NOT_RESERVED;
				available_slots[slot-1] = NOT_RESERVED;

				status = SUCCESS;
			}
			else
			{	
				printf("\nID doesn't exist, ");
				status = FAILURE;	
			}	
		}
	}while(status != SUCCESS);

	return SUCCESS;
}

unsigned char View_Patient_Record(int ID)
{
	printf("This feature has NOT been added yet...");

	return SUCCESS;
}
