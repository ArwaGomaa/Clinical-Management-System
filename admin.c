#include <stdio.h>
#include "admin.h"
u32 reservations[5]={0};
u32 count=0;
void check_id(Patient *user,u32 id) 
{
    for (u32 i = 0;i < count;i++) 
	{
        if (user[i].ID == id)
	    {
            printf("incorrect ID \n");
        }
    }
	printf("ID unique\n");
}
void add_new_patient_record(Patient*user)
{
	if (count>=1000)
	{
		printf("you cannot add more storage is full\n");
	}
	printf("please enter required information :\n");
	printf("enter your name :\n");
	scanf(" %[^\n]s",user[count].name);
	fflush(stdin);
	printf("enter your age :\n");
	scanf("%d",&user[count].age);
	fflush(stdin);
	printf("enter your gender(f/m) :\n");
	scanf("%c",&user[count].gender);
	fflush(stdin);
	printf("enter your ID :\n");
	scanf("%d",&user[count].ID);
	fflush(stdin);
	check_id(user,user[count].ID);
	user[count].reserved=-1;
	count++;
}
void edit_patient_record(Patient*user,u32 ID)
{
	u16 found=0;
	for (u32 i=0;i<count;i++)
	{
		 if (user[i].ID == ID)
	    {
			printf("edit your inforamtion:\n");
			printf("enter your name :\n");
	        scanf(" %[^\n]s",user[count].name);
			fflush(stdin);
	        printf("enter your age :\n");
	        scanf("%d",&user[i].age);
	        fflush(stdin);
	        printf("enter your gender(f/m) :\n");
	        scanf("%c",&user[i].gender);
			fflush(stdin);
			printf("the information has been updated successfully\n");
			found=1;
		    break;
		}
	}
	if (found!=1)
	{
		printf("patirnt id not found\n");
	}
}
void reserve_slot_with_doctor(Patient *user)
{
	u8 *Slot[]={
		"2pm to 2:30pm",
        "2:30pm to 3pm",
        "3pm to 3:30pm",
        "4pm to 4:30pm",
        "4:30pm to 5pm"
	};
	u16 found=0;
	u32 ID;
	u32 slot;
	printf("enter patient ID:\n");
    scanf("%d", &ID);
	 for (u32 i = 0; i < count; i++) 
	 {
        if (user[i].ID == ID) 
		{
			printf("available Slot:\n");
			for(u32 j=0;j<5;j++)
			{
				if(reservations[j]==0)
				{
					printf("%d,%s\n",j+1,Slot[j]);
				}
			}
            printf("enter slot number (1-5):\n");
            scanf("%d", &slot);
            if (slot < 1 || slot > 5)
			{
                printf("invalid slot number enter a number between (1-5):\n");
            }
            if (reservations[slot - 1] == 0) 
			{
                reservations[slot - 1]= 1;
				user[i].reserved=slot-1;
                printf("slot reserved successfully:\n");
            }
			else
			{
                printf("slot is already reserved:\n");
            }
			found=1;
		    break;
        }
    }
   if (found!=1)
	{
		printf("patirnt id not found\n");
	}
}
void cancel_reservation(Patient*user) 
{
	u32 ID;
	u16 found=0;
	printf("enter patient ID:\n");
    scanf("%d", &ID);
    for (u32 i = 0; i <count; i++) 
	{ if (user[i].ID == ID)
		{
			 if (reservations[i] == 1) 
			{
                reservations[i]= 0;
                printf("slot cancel successfully:\n");
            }
			else
			{
				printf("no reservation for this ID:\n");			
			}
			found=1;
		    break;
        }
    }
	if (found!=1)
	{
		printf("patirnt id not found\n");
	}
}