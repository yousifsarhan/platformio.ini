#include <Arduino.h>

// ---- Optional: DHT22 ----
// If you want DHT support, install library in PlatformIO:
// PlatformIO > Libraries > search "DHT sensor library" (Adafruit)
// Then uncomment the lines below
// #include <DHT.h>
// #define DHTPIN 2
// #define DHTTYPE DHT22
// DHT dht(DHTPIN, DHTTYPE);

// ---- Analog sensor ----
const int ANALOG_PIN = A0;

// ---- Timing ----
const unsigned long READ_INTERVAL_MS = 50;   // raw read rate
const unsigned long STREAM_INTERVAL_MS = 200; // print rate

unsigned long lastRead = 0;
unsigned long lastStream = 0;

// ---- Moving average filter (for analog) ----
const int WINDOW = 10;
int samples[WINDOW];
int idx = 0;
long sum = 0;
bool filled = false;

int movingAverage(int newValue) {
  sum -= samples[idx];
  samples[idx] = newValue;
  sum += samples[idx];

  idx = (idx + 1) % WINDOW;
  if (idx == 0) filled = true;

  int count = filled ? WINDOW : idx;
  return (int)(sum / max(1, count));
}

void setup() {
  Serial.begin(115200);
  delay(200);

  // init sample buffer
  for (int i = 0; i < WINDOW; i++) samples[i] = 0;

  // dht.begin();

  Serial.println("SensorHub:START");
  // Print header so it’s easy to parse in Excel / Python / Node
  Serial.println("ms,analog_raw,analog_filt,tempC,humidity");
}

void loop() {
  unsigned long now = millis();

  // Read sensors on schedule (non-blocking)
  if (now - lastRead >= READ_INTERVAL_MS) {
    lastRead = now;

    int raw = analogRead(ANALOG_PIN);
    int filt = movingAverage(raw);

    // float temp = dht.readTemperature();
    // float hum  = dht.readHumidity();

    // If DHT not used, just set to -1
    float temp = -1;
    float hum = -1;

    // Stream on its own schedule
    if (now - lastStream >= STREAM_INTERVAL_MS) {
      lastStream = now;

      // CSV format: easy to log + plot
      Serial.print(now);
      Serial.print(",");
      Serial.print(raw);
      Serial.print(",");
      Serial.print(filt);
      Serial.print(",");
      Serial.print(temp);
      Serial.print(",");
      Serial.println(hum);
    }
  }
}
