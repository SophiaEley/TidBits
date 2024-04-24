// InfoClip Starter Code
// Zane Cochran
// 13 APR 2024

// Setup
const char* ssid = "EZConnect";
const char* password = "HackBerryPlay";
String apiUrl = "https://cat-fact.herokuapp.com/facts/random"; // ***UPDATE THIS***

// Information
String catfact = "";
// String oldFact = "";

// State Machine
int mode = -1;
int lastMode = -1;

void setup() {
  Serial.begin(115200);
  delay(2000);

  wifiConnect();
  wifiRequest();
  initDisplay();
  initButtons();
}

void loop() {
  checkButtons();
  checkSleep();

  switch(mode){
    case -1: showIntro(); break;
    case 0: showSleep(); break;
    case 1: showNewFact(); break;
    case 2: showSecondCatPic(); break;
  }
}
