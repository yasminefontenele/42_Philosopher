# Philosophers 🍝

![Philosophers](https://img.shields.io/badge/Philosophers-Threads%20%26%20Mutexes-4EAA25?logo=c&logoColor=white)  

Welcome to **Philosophers**, a project inspired by the classic **Dining Philosophers Problem**. This project challenges you to simulate the behavior of philosophers sitting around a table, alternating between eating, thinking, and sleeping, while avoiding starvation and deadlocks. Implemented in **C**, this project uses **threads** and **mutexes** to manage concurrency and synchronization.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Overview](#overview)
3. [Global Rules](#global-rules)
4. [Installation](#installation)
5. [Usage](#usage)

---

## Introduction

Philosophy (from Greek, *philosophia*, literally "love of wisdom") is the study of general and fundamental questions about existence, knowledge, values, reason, mind, and language. Historically, philosophy encompassed a wide range of disciplines, from astronomy to physics. In this project, you'll explore a practical and intriguing problem in computer science inspired by philosophy: the **Dining Philosophers Problem**.

---

## Overview

The **Dining Philosophers Problem** is a classic synchronization problem that illustrates challenges in concurrent programming. Here's the setup:

- One or more philosophers sit at a round table.
- There is a large bowl of spaghetti in the middle of the table.
- Each philosopher alternates between **eating**, **thinking**, and **sleeping**.
- To eat, a philosopher must pick up **two forks** (one on their left and one on their right).
- The simulation stops when a philosopher dies of starvation.

Your task is to implement this simulation while ensuring that no philosopher starves and that the program runs efficiently using threads and mutexes.

---

## Global Rules

Your program must comply with the following rules:

- **Global variables are forbidden**.
- The program must take the following arguments:
  - `number_of_philosophers`: The number of philosophers and forks.
  - `time_to_die` (in milliseconds): If a philosopher doesn't eat within this time, they die.
  - `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat.
  - `time_to_sleep` (in milliseconds): The time a philosopher spends sleeping.
  - `[number_of_times_each_philosopher_must_eat]` (optional): If specified, the simulation stops when all philosophers have eaten this many times.

### Logs
- State changes must be logged in the following format:
  - `timestamp_in_ms X has taken a fork`
  - `timestamp_in_ms X is eating`
  - `timestamp_in_ms X is sleeping`
  - `timestamp_in_ms X is thinking`
  - `timestamp_in_ms X died`
- Messages must not overlap, and death messages must be displayed within **10 ms** of the actual death.

---

### Description
- Each philosopher is represented by a **thread**.
- Each fork is protected by a **mutex** to prevent race conditions.
- The program must handle edge cases, such as a single philosopher or a large number of philosophers.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yasminefontenele/42_Philosopher.git
   cd philosophers
2. Compile the project using the provided Makefile
   ```bash
   make
3. Run the program:
   ```bash
   ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

## Usage

### Example

To simulate 5 philosophers with the following parameters:

- `time_to_die`: 800 ms
- `time_to_eat`: 200 ms
- `time_to_sleep`: 200 ms

Run:

```bash
./philo 5 800 200 200
