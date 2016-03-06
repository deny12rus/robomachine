//0 - стоп
//1 - вперед
//2 - назад

void motor(int type)
{
  // Serial.println(type);
  // Serial.println(last_motor_type);
  unsigned long currentMillis = millis();
  int power = 100;
  if (currentMillis > (last_motor_time + 100))
    power = 250;
  // else
    // power = 250;
  Serial.println(power);

  if (type != last_motor_type)
  {
    last_motor_time = millis();
    if (type == 0)
    {
      analogWrite(ENB, 0);
    }
    else if (type == 1)
    {
      digitalWrite (IN4, HIGH);
      digitalWrite (IN3, LOW);
      analogWrite(ENB, power);
    }
    else if (type == 2)
    {
      digitalWrite (IN3, HIGH);
      digitalWrite (IN4, LOW);
      analogWrite(ENB, power);
    }
    last_motor_type = type;
  }
  else if (type != 0)
    analogWrite(ENB, power);
  // else
  //   analogWrite(ENB, 0);

}
