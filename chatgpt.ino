const int trig_pin = 9; // 초음파센서 trigger 핀
const int echo_pin = 10; // 초음파센서 echo 핀
const int led_pin = 6; // LED 핀

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  long duration = pulseIn(echo_pin, HIGH); // 거리 측정
  int distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance >= 9) {
    digitalWrite(led_pin, HIGH); // LED 켜기
  } else {
    digitalWrite(led_pin, LOW); // LED 끄기
  }
  delay(1000); // 1초 대기
}
