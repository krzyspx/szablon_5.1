// digitalWrite(2, (millis() / 300) % 2);

//#define led_ziel   16      //dla BRAMA 5
//#define led_czerw   0    //dla BRAMA 5
#define led_czerw   5       //dla BRAMA 5.1
#define led_ziel    4       //dla BRAMA 5.1

#define sw   13
//#define sw   15 // nie działa bez dodatkowego opornika pullup 1k
#define led_wew   2


void ledsetup() {
  pinMode(led_czerw, OUTPUT); //LED na module
  digitalWrite(led_czerw, HIGH);

  pinMode(led_wew, OUTPUT); //LED na module
  digitalWrite(led_wew, LOW);

  pinMode(led_ziel, OUTPUT); //LED na module
  digitalWrite(led_ziel, HIGH);

  pinMode(sw, INPUT_PULLUP);
}


int flaga_led = 0;
void led_timer()
{
  flaga_led = !flaga_led;
  digitalWrite(led_czerw, flaga_led);
}


int  stanswOnOff = 1;
void swOnOff() {
  if (stanswOnOff != digitalRead(sw))  sendValue(pin1, String(digitalRead(sw))); // sw esp ----> app
  stanswOnOff = digitalRead(sw);
}
void sw_test() {
  swOnOff();
}
void connetion_test() {
  if (WiFi.status() != WL_CONNECTED)   digitalWrite(led_wew, LOW);  else digitalWrite(led_wew, HIGH); //wł LED gdy nie ma WiFi
}

int wsk_led = 0;
void led_app_timer()  // esp -----> app every 3000 ms
{
  wsk_led = !wsk_led;
  sendValue(pin0, String(wsk_led)); //esp ----> app
  connetion_test();
}
