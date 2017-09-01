#include <ESP8266WiFi.h>
 
const char* ssid = "Awang";//type your ssid
const char* password = "1234567890";//type your password
 
int ledPin = 2; // GPIO2 of ESP8266
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
   
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
    
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
   
  // Match the request
 /*
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 */
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("Led pin is now: ");
  client.flush();
  /* 
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  */
  int val=random(25,35);
  client.println(val);
  client.println("<br><br>");
  //client.println("<script>function doClose(time){jump.innerText=time;  if(time!=0){window.setTimeout(\"doClose(\"+(time-1)+\")\", 1000);}else{window.location.href=\"https://www.baidu.com\";}}</script>");
  //client.println("<script>alert('I am using JS now!');</script>");
  //client.println("<BODY onload=\"doClose(15)\"><div><span><h4><span id=\"jump\">15 seconds</span><br></br></h4></span></div></div></BODY>");
  //client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  //client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
