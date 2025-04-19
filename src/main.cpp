// Queue Example
// #include <Arduino.h>

// QueueHandle_t myQueue;  // Queue handle

// void TaskBlink(void *pvParameters) {
//   pinMode(2, OUTPUT);  //LED (GPIO 2)
//   while (1) {
//     digitalWrite(2, HIGH);
//     vTaskDelay(500 / portTICK_PERIOD_MS);
//     digitalWrite(2, LOW);
//     vTaskDelay(500 / portTICK_PERIOD_MS);
    
//     bool ledStatus = digitalRead(2);
//     xQueueSend(myQueue, &ledStatus, 0);
//   }
// }

// void TaskSerial(void *pvParameters) {
//   bool ledStatus;
//   while (1) {
    
//     if (xQueueReceive(myQueue, &ledStatus, portMAX_DELAY) == pdTRUE) {
//       // LED state write serial monitor
//       Serial.print("LED Durumu: ");
//       Serial.println(ledStatus ? "ON" : "OFF");
//     }
//   }
// }

// void setup() {
//   Serial.begin(9600);
  
//   myQueue = xQueueCreate(10, sizeof(bool));
  
//   // FreeRTOS duty 
//   xTaskCreate(TaskBlink, "BlinkTask", 1000, NULL, 1, NULL);
//   xTaskCreate(TaskSerial, "SerialTask", 1000, NULL, 1, NULL);
// }

// void loop() {
//   // Main loop null, work in FreeRTOS function
// }

//Semaphore Example
#include <Arduino.h>

SemaphoreHandle_t mySemaphore;  // Semaphore tanımı

void TaskLED(void *pvParameters) {
  pinMode(2, OUTPUT);
  while (1) {
    if (xSemaphoreTake(mySemaphore, portMAX_DELAY) == pdTRUE) {
      digitalWrite(2, HIGH);
      Serial.println("LED ON");
      vTaskDelay(500 / portTICK_PERIOD_MS);

      digitalWrite(2, LOW);
      Serial.println("LED OFF");
      vTaskDelay(500 / portTICK_PERIOD_MS);

      xSemaphoreGive(mySemaphore);  // Semaforu geri bırak
    }
  }
}

void TaskSerial(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(mySemaphore, portMAX_DELAY) == pdTRUE) {
      Serial.println("Görev 2: Seri portu kullaniyor...");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      xSemaphoreGive(mySemaphore);  // Semaforu geri bırak
    }
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);  // Stabil başlatmak için kısa gecikme

  // Mutex şeklinde semaphore oluşturuluyor
  mySemaphore = xSemaphoreCreateMutex();

  // Görevler oluşturuluyor
  xTaskCreate(TaskLED, "LED Task", 1000, NULL, 1, NULL);
  xTaskCreate(TaskSerial, "Serial Task", 1000, NULL, 1, NULL);
}

void loop() {
  // FreeRTOS görevleri çalışıyor, loop boş
}



