#include "user.h"
void view_patient_record(Patient *user) 
{
    u16 found=0;
	u32 patient_id;
    printf("Enter patient ID:\n");
    scanf("%d", &patient_id);
    for (u32 i = 0; i < count; i++) 
	{
        if (user[i].ID== patient_id) 
		{
			printf("your id:%d\n",user[i].ID);
			printf("your name:%s\n",user[i].name);
            printf("your age: %d\n",user[i].age);
            printf("your gender: %c\n",user[i].gender);
			found=1;
		    break;
        }
    }
	 if (found!=1)
	{
		printf("patient id not found\n");
	}
}

void view_today_reservations(Patient *user)
{
	u16 found=0;
    printf("reservations:\n");
    for (u32 i = 0; i<count; i++)
	{
        if (user[i].reserved !=-1) 
		{
          printf("slot reserved by Patient ID: %d\n", user[i].ID);
		  found=1;
		}	
    } 
	if (found!=1)
	{
		printf("no reservations today:\n");
	}
}