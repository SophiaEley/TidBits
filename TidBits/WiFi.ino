#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Connect to WiFi
void wifiConnect(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {delay(1000); Serial.println("Connecting...");}
  Serial.println("Connected to the WiFi network");
}

void wifiRequest(){
  HTTPClient http;
  http.begin(apiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println("API Response:");
    Serial.println(payload);
    wifiExtract(payload);
  } 
  else {
    Serial.print("Error in HTTP request: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void wifiExtract(String payload){
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {Serial.print("deserializeJson() failed: "); Serial.println(error.c_str()); return;}

    // Extract specific data
     catfact = (const char*) doc["text"];
    //sunset = (const char*)doc["results"]["sunset"];
    
    Serial.print("CatFact: "); Serial.println(catfact);
    //Serial.print("Sunset: "); Serial.println(sunset);
}
