void gear_func(int servo, int dvig) //dvig = 1 - вперед; dvig = 0 - нейтраль; dvig = -1 - назад; servo - отклонение руля
{
  //управление сервой
  int servo_current;
  if (servo > 0)
  {
    if ( (servo + servo_last_state) <= (servo_center + servo_max_state) )
      servo_current = servo + servo_last_state;
    else
      servo_current = servo_center + servo_max_state;
  }
  else if (servo < 0)
  {
    if ( (servo_last_state - servo) <= (servo_center - servo_max_state) )
      servo_current = servo_last_state - servo;
    else
      servo_current = servo_center - servo_max_state;
  }
  else
    servo_current = servo_center;

  if (servo_current != servo_last_state)
  {
    myservo.write(servo_current);
    servo_last_state = servo_current;
  }

  //управление мотором
  if (dvig_last_state != dvig)
  {
    int dw;
    int aw;
    
    if (dvig > 0)
    {
      dw = 0; aw = 255;
    }
    else if (dvig < 0)
    {
      dw = 1; aw = 1;
    }
    else
    {
      dw = 0; aw = 0;
    }

    digitalWrite(D1, dw);
    analogWrite(M1, aw);
    dvig_last_state = dvig;
  }
  
  fan_time = millis();
}

