# Neural Network-Inspired Pseudo-Random Number Generator (PRNG)

This repository contains a simple C implementation of a **Neural Network-inspired Pseudo-Random Number Generator (PRNG)**. The program uses an XORShift-based algorithm to generate random predictions for input strings like "cat" or "dog." The system updates a score based on correct predictions and keeps track of the highest score.

## Features
- **XORShift PRNG**: Utilizes an XORShift transformation to simulate randomness in predictions.
- **Simple Neural Network Output Simulation**: Generates binary output (0 or 1) based on the input ("cat" or "dog").
- **Score Tracking**: Maintains and updates current and high scores based on correct predictions.

## Code Overview
- **xorshift_transform**: This function applies the XORShift algorithm to a seed array.
- **neural_network_prng**: Simulates a neural network-like prediction based on the input string.
- **update_scores**: Updates the score and high score based on the PRNG’s predictions.
- **main**: The main function runs an infinite loop that randomly picks an input ("cat" or "dog") and checks the prediction.

## Prerequisites
- GCC (or any C compiler)
- Standard C libraries

## Compilation

To compile and execute the program, use the following command:

```bash
gcc -o neural_prng neural_prng.c 
./neural_prng
```
## How It Works

- The `xorshift_transform` function applies an XORShift transformation to update the internal state (`seed`) of the random number generator.
- The `neural_network_prng` function takes an input string (`"cat"` or `"dog"`) and generates a pseudo-random output based on the seed.
  - For `"cat"`, it expects a result of `0`.
  - For `"dog"`, it expects a result of `1`.
- The `update_scores` function checks if the prediction matches the expected output and adjusts the score and high score accordingly.
