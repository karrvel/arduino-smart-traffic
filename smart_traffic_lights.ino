const int GREEN1_PIN = 5;
const int YELLOW1_PIN = 6;
const int RED1_PIN = 7;

const int GREEN2_PIN = 11;
const int YELLOW2_PIN = 12;
const int RED2_PIN = 13;

unsigned long green1Duration = 2000;  // Traffic light 1 green duration in ms
unsigned long green2Duration = 2000;  // Traffic light 2 green duration in ms
const unsigned long yellowDuration = 1000; // Yellow light duration in ms

void setup() {
  Serial.begin(9600);
  setupPins();
  initializeTrafficLights();
}

void loop() {
  checkForInput();

  setTrafficLightState("Traffic Light 1: Green, Traffic Light 2: Red", HIGH, LOW, LOW, LOW, LOW, HIGH);
  delay(green1Duration);
  resetTrafficLights();

  setTrafficLightState("Traffic Light 1: Yellow, Traffic Light 2: Yellow", LOW, HIGH, LOW, LOW, HIGH, LOW);
  delay(yellowDuration);
  resetTrafficLights();

  setTrafficLightState("Traffic Light 1: Red, Traffic Light 2: Green", LOW, LOW, HIGH, HIGH, LOW, LOW);
  delay(green2Duration);
  resetTrafficLights();

  setTrafficLightState("Traffic Light 1: Yellow, Traffic Light 2: Yellow", LOW, HIGH, LOW, LOW, HIGH, LOW);
  delay(yellowDuration);
  resetTrafficLights();
}

void setupPins() {
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(YELLOW1_PIN, OUTPUT);
  pinMode(RED1_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(YELLOW2_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);
}

void initializeTrafficLights() {
  digitalWrite(GREEN1_PIN, HIGH);
  digitalWrite(RED2_PIN, HIGH);
}

void checkForInput() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    updateDuration(input, "green1:", green1Duration);
    updateDuration(input, "green2:", green2Duration);
  }
}

void updateDuration(const String &input, const String &label, unsigned long &duration) {
  if (input.startsWith(label)) {
    duration = input.substring(label.length()).toInt() * 1000;
    Serial.print(label);
    Serial.print(" time updated to: ");
    Serial.print(duration / 1000);
    Serial.println(" seconds");
  }
}

void setTrafficLightState(const char* message, int green1, int yellow1, int red1, int green2, int yellow2, int red2) {
  Serial.println(message);
  digitalWrite(GREEN1_PIN, green1);
  digitalWrite(YELLOW1_PIN, yellow1);
  digitalWrite(RED1_PIN, red1);
  digitalWrite(GREEN2_PIN, green2);
  digitalWrite(YELLOW2_PIN, yellow2);
  digitalWrite(RED2_PIN, red2);
}

void resetTrafficLights() {
  digitalWrite(GREEN1_PIN, LOW);
  digitalWrite(YELLOW1_PIN, LOW);
  digitalWrite(RED1_PIN, LOW);
  digitalWrite(GREEN2_PIN, LOW);
  digitalWrite(YELLOW2_PIN, LOW);
  digitalWrite(RED2_PIN, LOW);
}
