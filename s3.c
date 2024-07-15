#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

// Define the size of the input seed
#define SEED_SIZE 3

// Function to apply the xorshift PRNG transformation
void xorshift_transform(uint64_t seed[SEED_SIZE]) {
    uint64_t t = seed[0] ^ (seed[0] << 11);
    seed[0] = seed[1];
    seed[1] = seed[2];
    seed[2] = (seed[2] ^ (seed[2] >> 19)) ^ (t ^ (t >> 8));
}

// Neural network-inspired PRNG to generate random output
int neural_network_prng(char* input, uint64_t seed[SEED_SIZE]) {
    xorshift_transform(seed);
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
    int score = 0;
    int high_score = 0;

    char* inputs[] = {"cat", "dog"};
    int expected_output[] = {0, 1};

    srand(time(NULL)); // Seed the random number generator

    while (1) {
        // Randomly select input
        char* input = inputs[rand() % 2];
        int expected = (strcmp(input, "cat") == 0) ? 0 : 1;

        // Get neural network output
        int prediction = neural_network_prng(input, seed);

        // Update scores
        update_scores(prediction, expected, &score, &high_score);

        // Print results
        printf("Input: %s, Prediction: %d, Expected: %d, Score: %d, High Score: %d\n",
               input, prediction, expected, score, high_score);

        // Add a short delay to make the updates visible
        struct timespec ts = {0, 100000000L}; // 100 milliseconds
        nanosleep(&ts, NULL);
    }

    return 0;
}
