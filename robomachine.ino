#include <NewPing.h>

//#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>


#define D1 22 // Направление вращение двигателя 1
#define M1 23 // ШИМ вывод для управления двигателем 1
#define D2 27 // направление вращение вентилятора
#define M2 26 //шим вывод для упр двигателем
#define servo_pin  25 //пин сервы руля
#define ledPin_left 40
#define ledPin_right 41
#define ledPin_center 42
#define ledPin_stop 43
#define ir_PIN 47
#define min_dist 15
#define ultrasonic_pg 5
#define MAX_DISTANCE 2000


NewPing ultrasonic_left(50, 51, MAX_DISTANCE);
NewPing ultrasonic_right(48, 49, MAX_DISTANCE);

Servo myservo;
int servo_center = 45; //центр рулевой тяги
int servo_last_state = 45; //последнее положение руля
int servo_max_state = 25; //максимальное отклонение реля от центра

int dvig_last_state = 0;

int last_povorot = 0;
int work_type = 0; //режим работы, 0 - блютус, 1 - самостоятельное движение


long interval = 250; //интервал опроса датчиков
long previousMillis = 0; //предыдущее время опроса
long fan_time = 0; //время включения вентилятора


void fan_loop()
{
  digitalWrite(D2, 0);
  unsigned long currentMillis = millis();
  if ((currentMillis - fan_time) > 5000)
    analogWrite(M2, 0);
  else
    analogWrite(M2, 130);
}



void setup() {
  // put your setup code here, to run once:
  //lcd.init();
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(ledPin_left, OUTPUT);
  pinMode(ledPin_right, OUTPUT);
  pinMode(ledPin_center, OUTPUT);
  pinMode(ledPin_stop, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(ir_PIN, INPUT);
  myservo.attach(servo_pin);
  myservo.write(servo_center);
}

void loop() {
  // put your main code here, to run repeatedly:
  fan_loop();
  
  if (work_type == 0)
  {
    bluetooth_mode_loop();
  }
  else
  {
    auto_mode_loop();    
  }
}


