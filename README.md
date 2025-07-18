# Treasure Quest: The Straw Hat Crew

## Overview

**Treasure Quest: The Straw Hat Crew** is an innovative project inspired by the popular One Piece web series. In this simulation, a crew of pirates (the Straw Hat Crew) is tasked with collecting treasures scattered across various locations. Each treasure has a specific arrival time and size, and it is distributed to the crew members based on their current load. The goal is to ensure that the treasure goes to the crewmate with the least total load, optimizing the crew's efficiency.

## Features

- **Dynamic Treasure Assignment**: Treasures are assigned to crewmates based on their current load, ensuring optimal distribution.
- **Heap Data Structure**: A custom heap implementation is used to efficiently manage and retrieve the crewmate with the least load.
- **Single Processing**: Each crewmate can process one treasure at a time, simulating realistic treasure collection dynamics.
- **Arrival Times and Sizes**: Treasures are characterized by their arrival times and sizes, adding complexity to the assignment process.
- **Interactive Simulation**: The program simulates the process of treasure arrival and assignment in real-time.

## Custom Heap Implementation

### What is a Heap?

A heap is a specialized tree-based data structure that satisfies the heap property:
- In a **min-heap**, for any given node, the value of the node is less than or equal to the values of its children. This allows efficient retrieval of the smallest element.
- A heap is commonly used for priority queues, where the highest priority element is served first.

### Key Components of the Custom Heap

1. **Node Structure**: Each node in the heap represents a crewmate and contains:
   - `crewmate_id`: Unique identifier for the crewmate.
   - `total_load`: The total size of treasures assigned to the crewmate.
  
2. **Insertion**: The insert operation maintains the heap property by placing the new node in the correct position.

3. **Deletion**: The delete operation retrieves and removes the crewmate with the least load, ensuring the heap remains balanced.

4. **Heapify Operations**: The custom heap includes methods for heapifying up and down to maintain the heap structure after insertions and deletions.

## Getting Started

### Prerequisites

- Python 3.x
- Basic knowledge of command-line operations
- Any code editor (e.g., VSCode, PyCharm)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/sitendernarwal/treasure-quest-straw-hat-crew.git
