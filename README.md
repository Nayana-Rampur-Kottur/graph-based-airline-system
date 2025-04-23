# ✈️ Indian Airways - Shortest Route Management System

**Data Structures: Graphs**  
**Presented By:**  
Nayana Rampur Kottur

---

## Table of Contents
- [Project Overview](#project-overview)
- [Objective](#objective)
- [Graph Concept](#graph-concept)
- [System Design](#system-design)
- [Structures and Data Representation](#structures-and-data-representation)
- [Operations and Logic](#operations-and-logic)
- [User Interaction Flow](#user-interaction-flow)
- [Running the Program](#running-the-program)
- [Sample Inputs and Outputs](#sample-inputs-and-outputs)
- [Conclusion](#conclusion)

---

## Project Overview

This project simulates the **airway management system** for "Indian Airways", focusing on finding the **shortest route** between two cities based on direct flights available.  
The system leverages **graphs** (using adjacency matrices) and **Dijkstra’s algorithm** for calculating shortest paths between airports.

---

## Objective

To build a system where:
- Each city is treated as a **node**.
- Each flight path is an **edge** with a weight (distance).
- Users can:
  - View available cities and flights.
  - Find the **shortest flight route** between two cities.

---

## Graph Concept

A **graph** is a collection of **vertices (cities)** and **edges (flight paths)** where each edge can have an associated weight (distance or cost).

**In this system:**
- Cities are nodes.
- Flight distances are weights.
- **Dijkstra’s algorithm** is used to compute the minimum distance between two nodes.

---

## System Design

- A **weighted directed graph** is represented using an **adjacency matrix**.
- Each element `matrix[i][j]` indicates the distance from city `i` to city `j`.

---

## Structures and Data Representation

| Structure | Description |
|:----------|:------------|
| `Graph` | Contains adjacency matrix and city names. |
| `Priority Queue` | (Internally used in Dijkstra) - for efficiently picking the next nearest city. |

---

## Operations and Logic

| Operation | Logic |
|:----------|:------|
| **Add City** | Adds a new city to the system. |
| **Add Flight Path** | Adds a direct flight between two cities with given distance. |
| **Display Available Cities** | Lists all cities added. |
| **Find Shortest Route** | Runs Dijkstra’s algorithm to find and print the shortest path and total distance between two selected cities. |

---

## User Interaction Flow

1. **View Available Cities**
   - Lists all the cities (nodes) currently in the system.

2. **Add Flight (Optional)**
   - Admins can add new direct flights between two cities by specifying distance.

3. **Find Shortest Route**
   - Enter source and destination cities.
   - System computes the shortest route using Dijkstra’s algorithm.

4. **Exit**
   - End the session.

---

## Running the Program 🚀

### 1. Compile
Use a C compiler to compile:
```bash
gcc indian_airways.c -o indian_airways.o
```

### 2. Execute
Use terminal to run:
```bash
./indian_airways.o
```