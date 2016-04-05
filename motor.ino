//0 - стоп
//1 - вперед
//2 - назад

void motor(int type)
{
  // Serial.println(type);
  // Serial.println(last_motor_type);
  unsigned long currentMillis = millis();
  int power = 180;
  if (currentMillis > (last_motor_time + 100))
    power = 254;
  if (currentMillis > (last_motor_time + 500))
    power = 160;


  // Serial.println(power);

  if (type != last_motor_type)
  {
    last_motor_time = millis();

    if (type == 1)
    {
      if (sensor_center == 0 or sensor_left == 0 or sensor_right == 0)
        type = 0;
    }

    if (type == 0)
    {
      analogWrite(ENB, 0);
      analogWrite(ENBV, 0);
    }
    else if (type == 1)
    {
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      analogWrite (ENB, power);
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
      analogWrite (ENBV, power);
    }
    else if (type == 2)
    {
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      analogWrite (ENB, power);
      digitalWrite (IN1, HIGH);
      digitalWrite (IN2, LOW);
      analogWrite (ENBV, 0);
    }
    last_motor_type = type;
  }
  else if (type != 0)
  {
    analogWrite(ENB, power);
    analogWrite(ENBV, 0);
  }

  // else
  //   analogWrite(ENB, 0);

}
