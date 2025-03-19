#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>

char ssid[] = "VM14FR3";
char pass[] = "kqvqmTg15fLk4LybjR9f5ACnk";

int status = WL_IDLE_STATUS;

WiFiServer server(80);
WiFiClient client;

// put function declarations here:
void connectToNetwork();
void webServer();
void jsonReturn();

void setup()
{
  Serial.begin(9600);

  connectToNetwork();
  webServer();
}

void loop()
{
  // Check if a client is available (trying to connect)
  client = server.available();

  if (client)
  {
    Serial.println("New client connected!");

    // Wait until the client sends some data
    while (client.connected())
    {
      Serial.println("Client Connected!");

      if (client.available())
      {
        Serial.println("Client available!");

        jsonReturn();
        // After sending the response, break out of the loop (client will be closed)
        break;
      }
    }

    // Close the client connection after the response
    client.stop();
    Serial.println("Client disconnected.");
    delay(1000);
  }
}

// put function definitions here:
void connectToNetwork()
{
  while (status != WL_CONNECTED)
  {
    Serial.print("Trying to connecto to: ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);

    if (status == WL_CONNECTED)
    {
      Serial.print("Connected to: ");
      Serial.println(ssid);
      Serial.print("IP: ");
      Serial.println(WiFi.localIP());

      break;
    }

    delay(10000);
  }
}

void webServer()
{
  Serial.println("Starting Web Server...");
  server.begin();
  Serial.print("Address: http://");
  Serial.println(WiFi.localIP());
}

void jsonReturn()
{
  String request = client.readStringUntil('\r');
  Serial.print("Request: ");
  Serial.println(request);

  if (request.indexOf("GET") != -1)
  {
    String response = "{\"name\": \"Crysthoffer Ratier\"}";

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(response.length()); // Set the content length
    client.println("Connection: close");
    client.println(); // Blank line to indicate end of headers

    client.print(response);
    client.print("");

    Serial.println("Response sent!");
  }
}