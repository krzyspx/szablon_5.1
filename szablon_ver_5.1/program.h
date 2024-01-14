#define pirpompa 14013756

//#define pompaoff 4478228 //zmienic
//#define pompaon  4478225
#define pompaoff 17748 //zmienic
#define pompaon  17745

#define czasobiegu  24  // ilość sek włączenia pompy x 10
#define pompapilot 7730435 //

int obieg = -3;

void pin6_rec(String value) //LED in ESP
{
  int v = value.toInt();
  if (v == 1) digitalWrite(led_wew, HIGH); else digitalWrite(led_wew, LOW);
}
void pin7_rec(String value) //LED in ESP
{
  int v = value.toInt();
  if (v == 1) digitalWrite(led_czerw, HIGH); else digitalWrite(led_czerw, LOW);
}
void pin8_rec(String value) //LED in ESP
{
  int v = value.toInt();
  if (v == 1) digitalWrite(led_ziel, HIGH); else digitalWrite(led_ziel, LOW);
}

void programsetup() {
}
void programakcja() {

}

void pompazal() //wysyłanie kodu do załączenia pompy
{
  sendkodpilot(pompaon);
  Serial.println("kod on");
  akcja.updateInterval(2, 300);
  sendValue(pin11, String("kod on"));
}
void pompastop() //wysyłanie kodu do wyłączenia pompy
{
  sendkodpilot(pompaoff);
  Serial.println("kod off");
  akcja.updateInterval(2, 2000);
  sendValue(pin11, String("kod off"));
}

void pin15_rec(String value)
{
  int v = value.toInt();
  if (v)  pompazal(); else pompastop();
}
