





#ifndef CAR_CONTROL_SYS_H_
#define CAR_CONTROL_SYS_H_


extern u8 test;



 extern volatile u8 temp_flag;
 extern volatile u8 dist_flag;
  extern volatile u8 press_flag;

void Car_Control_init();
void Car_Control_Runnable(void);
void pressure_wheel_test(void);
void temp_test(void);
void Accedent_test (void);
void Get_distance(void);

#endif /* CAR_CONTROL_SYS_H_ */