void auto_mode_loop()
{
  //Serial1.begin(9600);
  unsigned long currentMillis = millis(); //текущее время в мс
  String go;
  int dist_cm_center = 0;
  float dist_cm_left = 0;
  float dist_cm_right = 0;
  if (currentMillis - previousMillis > interval)
    {
      previousMillis = currentMillis; //сохраняем текущее время
      dist_cm_center = digitalRead(ir_PIN);
      dist_cm_left = ultrasonic_left.ping();
      dist_cm_left = dist_cm_left / US_ROUNDTRIP_CM;
      dist_cm_right = ultrasonic_right.ping();
      dist_cm_right = dist_cm_right / US_ROUNDTRIP_CM;

      String message = "";
      message = String(message + " " + int(dist_cm_left) + " " + int(dist_cm_center) + " " + int(dist_cm_right));
      // Serial.println(message);

      if (dist_cm_center == HIGH)
      {
        if (dist_cm_left < 10 && dist_cm_right < 10 && dist_cm_left != 0 && dist_cm_right != 0)
        {
          go = "go run back!";
          if (last_povorot == 0)
            myservo.write(servo_center - 25);
          else
            myservo.write(servo_center + 25);
          last_povorot = random(0, 1);
          // digitalWrite(D1, 1);
          // analogWrite(M1, 1);
        }
        else if (dist_cm_left < 10 && dist_cm_left != 0)
        {
          go = "go run right!";
          myservo.write(servo_center + 25);
          // digitalWrite(D1, 0);
          // analogWrite(M1, 255);
        }
        else if (dist_cm_right < 10 && dist_cm_right != 0)
        {
          go = "go run left!";
          myservo.write(servo_center - 25);
          // digitalWrite(D1, 0);
          // analogWrite(M1, 255);
        }
        else
        {
          go = "go run!";
          myservo.write(servo_center);
          // digitalWrite(D1, 0);
          // analogWrite(M1, 255);
        }
      }
      else
      {
        go = "go run back!";
        if (last_povorot == 0)
          myservo.write(servo_center - 25);
        else
          myservo.write(servo_center + 25);
        last_povorot = random(0, 1);
        // digitalWrite(D1, 1);
        // analogWrite(M1, 1);
      }
    }
}

void sensor_loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval)
  {
    previousMillis = currentMillis; //сохраняем текущее время
    int dist_cm_center = digitalRead(ir_PIN);
    sensor_center = dist_cm_center;

    int dist_cm_left = ultrasonic_left.ping();
    dist_cm_left = dist_cm_left / US_ROUNDTRIP_CM;
    if (dist_cm_left < 10 && dist_cm_left != 0)
    {
      sensor_left = 0;
      digitalWrite(ledPin_left, HIGH);      
    }
    else
    {
       sensor_left = 1;
       digitalWrite(ledPin_left, LOW);
    }
      

    int dist_cm_right = ultrasonic_right.ping();
    dist_cm_right = dist_cm_right / US_ROUNDTRIP_CM;
    if (dist_cm_right < 10 && dist_cm_right != 0)
    {
      digitalWrite(ledPin_right, HIGH);
      sensor_right = 0;
    }
      
    else
    {
      digitalWrite(ledPin_right, LOW);
      sensor_right = 1;
    }
      
    
    String message = "";
    message = String(message + int(sensor_left) + "-" + int(sensor_center) + "-" + int(sensor_right) + " " + int(dist_cm_left) + " " + int(dist_cm_center) + " " + int(dist_cm_right));
    Serial.println(message);
  }
}
