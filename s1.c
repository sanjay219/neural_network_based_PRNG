#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Define the size of the input seed and the number of weights
#define SEED_SIZE 3
#define NUM_WEIGHTS 3

// Function to apply the fixed-weight neural network transformation
void transform_seed(uint64_t seed[SEED_SIZE], double weights[NUM_WEIGHTS]) {
    for (int i = 0; i < SEED_SIZE; i++) {
        seed[i] ^= (uint64_t)(seed[i] * weights[0]);
        seed[i] ^= (uint64_t)(seed[i] / weights[1]);
        seed[i] ^= (uint64_t)(seed[i] * weights[2]);
    }
}

// Neural network-based PRNG to generate random output
int neural_network_prng(char* input, uint64_t seed[SEED_SIZE], double weights[NUM_WEIGHTS]) {
    transform_seed(seed, weights);
    uint64_t result = seed[0] ^ seed[1] ^ seed[2];

    // Simulate neural network output
    if (strcmp(input, "cat") == 0) {
        return result % 2 == 0 ? 0 : 1; // 0 for "cat", incorrect results are 1
    } else if (strcmp(input, "dog") == 0) {
        return result % 2 == 1 ? 1 : 0; // 1 for "dog", incorrect results are 0
    }
    return -1; // Invalid input
}

// Function to update score and high score
void update_scores(int prediction, int expected, int* score, int* high_score) {
    if (prediction == expected) {
        (*score)++;
        if (*score > *high_score) {
            *high_score = *score;
        }
    } else {
        *score = 0;
    }
}

int main() {
    uint64_t seed[SEED_SIZE] = {123456789, 362436069, 521288629}; // Example seeds
    double weights[NUM_WEIGHTS] = {21.0, 35.0, 4.0}; // Fixed weights (f64)
    int score = 0;
    int high_score = 0;

    char* inputs[] = {"cat", "dog"};
    int expected_output[] = {0, 1};

    srand(time(NULL)); // Seed the random number generator

    // Infinite loop to continuously generate predictions
    while (1) {
        // Randomly select input
        char* input = inputs[rand() % 2];
        int expected = (strcmp(input, "cat") == 0) ? 0 : 1;

        // Get neural network output
        int prediction = neural_network_prng(input, seed, weights);

        // Update scores
        update_scores(prediction, expected, &score, &high_score);

        // Print results
        printf("Input: %s, Prediction: %d, Expected: %d, Score: %d, High Score: %d\n",
               input, prediction, expected, score, high_score);

        // Break condition (optional)
        if (prediction == -1) {
            break;
        }
    }

    return 0;
}