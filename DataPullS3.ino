#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "E85F Hyperoptic Fibre Broadband";  
const char* password = "Q9s2pkrVFDBn";          
const char* s3_url = "https://apidataforiotproject.s3.eu-west-2.amazonaws.com/optimal_bedtime_predictions.csv"; 

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // 
  }

  Serial.println("Connecting to WiFi...");

  int attempts = 0;
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {  
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to Wi-Fi.");
    return;  
  }


  WiFiClient client;
  if (client.connect("apidataforiotproject.s3.eu-west-2.amazonaws.com", 80)) {

    client.print(String("GET /optimal_bedtime_predictions.csv HTTP/1.1\r\n") +
                 "Host: apidataforiotproject.s3.eu-west-2.amazonaws.com\r\n" +
                 "Connection: close\r\n\r\n");


    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }


    while (client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);  
    }
  } else {
    Serial.println("Connection failed.");
  }
  client.stop();
}

void loop() {
}
