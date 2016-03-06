void bluetooth_mode_loop()
{
  if (Serial1.available()) {
      int inByte = Serial1.read();
      Serial.write(inByte);
      Serial.println();
      unsigned long currentMillis = millis();
      switch (inByte) {
        case 'F':   
          gear_func(0, 0);
          //go = "go run!";
        case 'L':
          gear_func(-25, 0);
          //go = "go left!";
        case 'R':
          gear_func(25, 0);
          //go = "go right!";
        case 'S':
          gear_func(0, 0);
          //go = "go run stop!";
        case 'G':
          gear_func(-25, 1);
          //go = "go run left!";
        case 'I':
          gear_func(25, 1);
          //go = "go run right!";
        case 'B':
          gear_func(0, -1);
          //go = "go run back!";
        case 'J':
          gear_func(25, -1);
          //go = "go run back right!";
        case 'H':
          gear_func(-25, -1);
          //go = "go run back left!";
        case 'X':
          work_type = 1;
        case 'x':
          work_type = 0;         
      }
    }
}

