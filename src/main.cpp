#include <Arduino.h>

QueueHandle_t myQueue;  // Kuyruk handle

void TaskBlink(void *pvParameters) {
  pinMode(2, OUTPUT);  // Dahili LED (GPIO 2)
  while (1) {
    digitalWrite(2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(2, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    
    // LED yanma durumunu kuyruğa gönder
    bool ledStatus = digitalRead(2);
    xQueueSend(myQueue, &ledStatus, 0);
  }
}

void TaskSerial(void *pvParameters) {
  bool ledStatus;
  while (1) {
    // Kuyruktan LED durumunu al
    if (xQueueReceive(myQueue, &ledStatus, portMAX_DELAY) == pdTRUE) {
      // LED durumunu seri port üzerinden yazdır
      Serial.print("LED Durumu: ");
      Serial.println(ledStatus ? "ON" : "OFF");
    }
  }
}

void setup() {
  Serial.begin(9600);
  // Kuyruğu oluştur
  myQueue = xQueueCreate(10, sizeof(bool));
  
  // FreeRTOS görevlerini oluştur
  xTaskCreate(TaskBlink, "BlinkTask", 1000, NULL, 1, NULL);
  xTaskCreate(TaskSerial, "SerialTask", 1000, NULL, 1, NULL);
}

void loop() {
  // Ana loop boş, çünkü işler FreeRTOS görevlerinde yapılacak
}


