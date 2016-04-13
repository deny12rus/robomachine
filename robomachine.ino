#include <NewPing.h>
#include <Wire.h>
#include <Servo.h>

//мотор
int IN3 = 4;
int IN4 = 5;
int ENB = 3; //шим
int last_motor_type = 0;
long last_motor_time = 0;

//сервопривод
#define servo_pin 2 //пин сервы руля
Servo myservo;
int servo_center = 105; //центр рулевой тяги
int servo_last_state = servo_center; //последнее положение руля
int servo_max_state = 20; //максимальное отклонение руля от центра
int last_povorot = 0;

//вентилятор
int IN1 = 6;
int IN2 = 7;
int ENBV = 9;

// #define D1 22 // Направление вращение двигателя 1
// #define M1 23 // ШИМ вывод для управления двигателем 1
// #define D2 27 // направление вращение вентилятора
// #define M2 26 //шим вывод для упр двигателем
#define ledPin_left 40
#define ledPin_right 41
#define ledPin_center 42
#define ledPin_stop 43
#define ir_PIN 13
#define min_dist 15
#define ultrasonic_pg 5
#define MAX_DISTANCE 2000

//ультра звыуковые сенсоры
NewPing ultrasonic_left(12, 11, MAX_DISTANCE);
NewPing ultrasonic_right(8, 10, MAX_DISTANCE);

//
int sensor_center = 1;
int sensor_right = 1;
int sensor_left = 1;
//
int dvig_last_state = 0;

//режим работы, 0 - блютус, 1 - самостоятельное движение
int work_type = 0;


long interval = 250; //интервал опроса датчиков
long previousMillis = 0; //предыдущее время опроса
long fan_time = 0; //время включения вентилятора


void fan_loop()
{
  // unsigned long currentMillis = millis();
  // if ((currentMillis - fan_time) > 5000)
  //   analogWrite(ENBV, 0);
  // else
  //   analogWrite(ENBV, 230);
  // if (last_motor_type != 0)
  //   analogWrite(ENBV, 230);
  // else
  //   analogWrite(ENBV, 0);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Serial1.begin(9600);
  pinMode(ledPin_left, OUTPUT);
  pinMode(ledPin_right, OUTPUT);
  pinMode(ledPin_center, OUTPUT);
  pinMode(ledPin_stop, OUTPUT);
  pinMode(ir_PIN, INPUT);
  //мотор
  pinMode (ENB, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  //серва
  myservo.attach(servo_pin);
  myservo.write(servo_center);
  //вентилятор
  pinMode (ENBV, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  // digitalWrite (IN1, HIGH);
  // digitalWrite (IN2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // fan_loop();
  sensor_loop();

  if (work_type == 0)
    bluetooth_mode_loop();
  else
    auto_mode_loop();
}
