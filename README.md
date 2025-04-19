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

A **low-priority task** turns the LED ON every second. A **high-priority task** turns the LED OFF every 3 seconds. The high-priority task interrupts the low-priority one, demonstrating FreeRTOS’s **preemptive scheduling** behavior.

---

## 2. 📦 Queue Example

This example shows how to use a **queue** to safely pass data between tasks in FreeRTOS.

A **Sender Task** generates an increasing number periodically and places it in a queue. A **Receiver Task** waits for data from the queue and prints it to the serial monitor. This demonstrates safe and efficient **inter-task communication**, allowing tasks to exchange data asynchronously without conflicts.

---

## 3. 🔐 Semaphore Example

This example demonstrates how to use a **binary semaphore** to synchronize two tasks.

A **Producer Task** signals (gives) the semaphore at regular intervals. A **Consumer Task** waits (takes) the semaphore, and when it receives the signal, it performs an action such as turning on an LED. This is a classic synchronization mechanism to coordinate actions between tasks in real-time systems.

---

## 🚀 Getting Started

1. Clone this repository.
2. Open the project in [PlatformIO](https://platformio.org/) or Arduino IDE.
3. Upload to your ESP32 DevKit v1 board.
4. Use **Serial Monitor (115200 baud)** to view task messages.

---

## 🧠 Concepts Covered

- Task creation and prioritization
- Preemptive multitasking
- Inter-task communication with Queues
- Task synchronization using Semaphores

---

## 📌 License

This project is open-source and intended for educational purposes.
