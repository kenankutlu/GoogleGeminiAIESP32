# Google Gemini AI API Integration with ESP32

This code demonstrates how to use an ESP32 to send a query to Google Gemini AI's API via an HTTP POST request over Wi-Fi.

## Features

- Connects the ESP32 to a Wi-Fi network.
- Sends a request to the Google Gemini AI API to generate content.
- Prints the API response on the serial monitor.

---

## Requirements

### Hardware:
- ESP32 development board.

### Software:
- Arduino IDE installed with ESP32 board support.
- A valid API key for Google Gemini AI.

---

## Installation and Setup

### Step 1: Configure Wi-Fi Credentials
Replace the placeholders in the code with your Wi-Fi network credentials:
```cpp
const char* ssid = "***";      // Your Wi-Fi SSID
const char* password = "******"; // Your Wi-Fi password
```

### Step 2: Configure API Key and Endpoint
Replace the API key and endpoint URL in the code:
```cpp
String url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=***********************************************";
```

### Step 3: Upload the Code
1. Open the Arduino IDE.
2. Select your ESP32 board under **Tools > Board**.
3. Choose the correct port under **Tools > Port**.
4. Upload the code to your ESP32.

---

## Code Breakdown

### Wi-Fi Connection
The ESP32 connects to a Wi-Fi network:
```cpp
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.println("Connecting to WiFi...");
}
Serial.println("Connected to WiFi");
```
The program will not proceed until the device is successfully connected.

### HTTP Request
The function sends a POST request to the API endpoint:
- **Headers**: The `Content-Type` header specifies the data format as JSON.
- **Timeout**: A timeout of 10 seconds is set for the request.
- **Payload**: The JSON data includes the query to Google Gemini AI.

### Response Handling
The response is handled and printed:
```cpp
int httpResponseCode = http.POST(jsonPayload);
if (httpResponseCode > 0) {
  String response = http.getString();
  Serial.println("Response: " + response);
} else {
  Serial.println("Error in HTTP request: " + String(httpResponseCode));
}
```

---

## Expected Output

Once the code is uploaded and executed, the serial monitor will display:

```
Connecting to WiFi...
Connected to WiFi
Response Code: 200
Response: { "contents": [...response data...] }
```

In case of an error, the response code and error message will be printed.

---

## Notes and Considerations

1. **Security**:
   - Do not hardcode sensitive information like API keys in your code. Consider using a more secure method for storing keys.
2. **Error Handling**:
   - Ensure robust error handling for scenarios like connection issues or API errors.
3. **API Key Management**:
   - Keep your API key confidential and regenerate it if exposed.

---

## License
This project is free to use and modify. Ensure compliance with Google Gemini AI's terms of service.

---

### Check Out My YouTube Channel!  
For more tech-related content and projects, visit my YouTube channel:  
[Kenan Kutluyum](https://www.youtube.com/@KenanKutluyum)  

Don’t forget to subscribe and stay tuned for more updates! 🎥

