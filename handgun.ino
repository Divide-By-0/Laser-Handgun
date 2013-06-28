int sensorReading;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(9, INPUT);
}

int ammo = 20;

void loop()
{
  sensorReading = digitalRead(9); 
  Serial.println(sensorReading); // using println prints out a new line onto the serial monitor aka console
  Serial.print("AMMO LEVEL IS CURRENTLY AT:  "); // using println prints out a new line onto the serial monitor aka console
  Serial.println(ammo); // using println prints out a new line onto the serial monitor aka console
  digitalWrite(13, HIGH);
  
  if (sensorReading == 1 && ammo > 0)
  {
    Serial.println("IMA FIRIN MY LAZER!");
    delay(200);
    --ammo;
  }
  else if (sensorReading == 0 && ammo < 20)
  {
    digitalWrite(13, LOW);
    Serial.println("Reloading...");
    delay(300);
    ++ammo;
  }
  else if (ammo == 0)
  {
    digitalWrite(13, LOW);
    Serial.println("OUT OF AMMO!");
    delay(60);
  }
  else
  {
    Serial.println("Ready to fire!");
    delay(50);
  }
  
}
