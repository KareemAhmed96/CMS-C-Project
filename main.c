#include "CMS.h"

int main(void)
{	
	ID_Flag = FIRST_ID; // First patient ID

	while(1)
	{
		Welcome_Screen();

		if(Current_Mode == ADMIN)
		{
			Verify_Admin_Login();
			// After verification is complete..
			// the flag "Current_Mode" = ADMIN_LOGGED_IN
		}
		else if(Current_Mode == USER)
		{
			// User code here
		}
		else
		{
			Current_Mode = NOT_DETERMINED;
		}
		

		if(Current_Mode == ADMIN_LOGGED_IN)
		{	
			Admin_Options_Menu();
			
			switch(admin_cases)
			{
				case ADD_NEW_PATIENT_RECORD:

					//printf("Add new patient record");
					Add_New_Patient_Record();

					printf("\nPatient count = %d\n\n", patient_count);

					break;
				
				case EDIT_PATIENT_RECORD:

					//printf("Edit patient record");
					printf("This feature has NOT been added yet...");

					break;
				
				case RESERVE_SLOT:
					printf("\nReserve a slot with the doctor,");
					Reserve_Slot_Menu();
					
					break;
				
				case CANCEL_RESERVATION:

					//printf("Cancel reservation");
					Cancel_Reservation();

					break;
			}
		}
	}
	return 0;
}
