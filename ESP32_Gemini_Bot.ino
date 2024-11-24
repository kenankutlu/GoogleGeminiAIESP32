#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "***";
const char* password = "******";

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  HTTPClient http;
  
  String url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=***********************************************";
  String jsonPayload = "{\"contents\":[{\"parts\":[{\"text\":\"Explain how AI works\"}]}]}";

  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  http.setTimeout(10000);  // 10-second timeout
  
  int httpResponseCode = http.POST(jsonPayload);
  Serial.print("Response Code: ");
  Serial.println(httpResponseCode);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("Response: " + response);
  } else {
    Serial.println("Error in HTTP request: " + String(httpResponseCode));
  }

  http.end();
}

void loop() {
  // Empty loop
}
