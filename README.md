# FreeRTOS Examples on ESP32

This repository contains basic examples demonstrating core FreeRTOS concepts using an **ESP32 DevKit v1** board with the **Arduino** framework.

---

## 📚 Contents

1. [Task Priority & Preemption](#1-task-priority--preemption)
2. [Queue Example](#2-queue-example)
3. [Semaphore Example](#3-semaphore-example)

---

## 1. 🧩 Task Priority & Preemption

This example shows how task priorities and preemption work in FreeRTOS.

### 🔹 Description
- `TaskLow`: turns the LED **ON** every second. (priority 1)
- `TaskHigh`: turns the LED **OFF** every 3 seconds. (priority 2)
- `TaskHigh` preempts `TaskLow` due to higher priority.

### 🛠 Hardware
- ESP32 DevKit v1
- On-board LED (usually GPIO 2)

### 📄 Code Highlights
```cpp
xTaskCreate(TaskLow, "Low", 1000, NULL, 1, NULL);
xTaskCreate(TaskHigh, "High", 1000, NULL, 2, NULL);
