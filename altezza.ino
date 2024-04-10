const int pinTrig = 6;
const int pinEcho = 10;
const int delay_ms = 10;
const float gravity = 9.81;

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
}

float getDistance() {
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  float duration = pulseIn(pinEcho, HIGH);
  float distance = duration * 0.017; // in centimetri
  return distance;
}

void loop() {
  int initial_distance = getDistance();
  delay(delay_ms);
  int final_distance = getDistance();

  float speed = abs(initial_distance - final_distance) / delay_ms; // in centimetri per millisecondo
  speed = speed * 10; // in metri al secondo

  // trova lo spazio percorso fino al punto di misurazione
  float space = -(speed * speed) / (2 * gravity);

  // aggiungi lo spazio tra il sensore e l'oggetto al momento della misurazione
  float space_total = space + final_distance;

  Serial.print("Oggetto rilasciato a ");
  Serial.print(space_total);
  Serial.println("m dal sensore");
}
