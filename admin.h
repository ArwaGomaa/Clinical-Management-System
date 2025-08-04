#ifndef ADMIN_H
#define ADMIN_H
#include <stdio.h>
#include "datatype.h"
void check_id(Patient *user,u32 id) ;
void add_new_patient_record(Patient*user);
void edit_patient_record(Patient*user,u32 ID);
void reserve_slot_with_doctor(Patient *user);
void cancel_reservation(Patient*user);
#endif
