#include <stdio.h> 
#include <stdlib.h>
#include "user.h"
#include "admin.h"
int main() 
{
	Patient user[1000];
	u32 type_of_user,password_for_admin;
	u32 attempts = 0;
	while(1)
	{
		printf("if you are admin enter(0)\nif you are user enter(1)\n");
	    scanf("%d",&type_of_user);
	    switch(type_of_user)
	    {
		    case 0:
		    {
                printf("please enter password:\n");
			    while (attempts < 3)
                {        
	               if (scanf("%d", &password_for_admin) != 1)
	                {
		                printf("error the system will be closed\n");
		                exit(1);
         	        }
	                else if (password_for_admin == 1234)
			        {
                        printf("done\n");
		                u16 choice_admin;
			            while(1)
			            {
		                    printf("admin menu:\n");
                            printf("1 add new patient record\n");
                            printf("2 edit patient record\n");
                            printf("3 reserve a slot with the doctor\n");
						    printf("4 cancel reservation\n");
						    printf("5 exit\n");
						    printf("enter choice:\n");
						    scanf("%d", &choice_admin);
						    switch(choice_admin)
						    {
							    case 1:
							    {
								    add_new_patient_record(user);
								    break;
							    }
							    case 2:
							    {
								    printf("you must enter ID to be able to edit your information:\n");
								    u32 id_to_edit;
								    scanf("%d",&id_to_edit);
								    edit_patient_record(user,id_to_edit);
								    break;
							    }
							    case 3:
							    {
								    reserve_slot_with_doctor(user);
								    break;
							    }
							    case 4:
							    {
								    cancel_reservation(user);
								    break;
							    }
							    case 5:
							    {
								    printf("exit:\n");
									attempts=0;
							  	    break;
							    }
							   default:
							    {
								    printf("try again the choice is invalid");
								    break;
							    }
						    }
							if(choice_admin==5)
							{
								break;
							}
					    }
						break;
				    }
				   else 
				    {
					    attempts++;
					    printf("incorrect password attempts left: %d\n", 3 - attempts);
					    if (attempts == 3)
					    {
						    printf("maximum password attempts reached exiting admin\n");
						    exit(1);
					    }
					    printf("enter the admin password again: ");
				    }
			    }
				break;
		    }
	       case 1:
		    {
			    u16 choice_user;
			    while(1)
			    {
			        printf("user menu:\n");
                    printf("1 view patient record\n");
                    printf("2 view today's reservations\n");
                    printf("3 exit\n");
                    printf("enter choice:\n ");
                    scanf("%d", &choice_user);
			        switch(choice_user)
			        {
				        case 1:
				        {
						    view_patient_record(user) ;
					        break;
				        }
				       case 2:
				        {
					        view_today_reservations(user);
					        break;
				        }
				       case 3:
				        {
					       printf("exit\n");
						   break;
				        }
				       default:
				        {
					       printf("try again the choice is invalid");
					       break;
				        }	    
			        }
					if (choice_user==3)
					{
						break;
					}
			    }
				break;
		    }
	       default:
		    {
			   printf("invalid type of user \n");
			   exit(0);
		    }
	    }
		system("cls");
	}
	return 0;
}
