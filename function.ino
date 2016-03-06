void gear_func(int servo, int dvig) //dvig = 1 - вперед; dvig = 0 - нейтраль; dvig = 2 - назад; servo - отклонение руля
{
  //управление сервой
  int servo_current = 0;
  // Serial.write(servo);
  // Serial.println(servo);
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
    // Serial.println(servo_current);
    myservo.write(servo_current);
    servo_last_state = servo_current;
  }

  //управление мотором

  motor(dvig);

  fan_time = millis();
}
