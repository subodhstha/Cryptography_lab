//Write a program to implement the AES MixColumns operation for encryption. Apply the operation to a given state matrix and round key, and show the results.

#include <stdio.h>
#include <stdint.h>

// AES MixColumns operation
void mixColumns(uint8_t state[4][4]) {
    uint8_t tmp[4];
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < 4; i++) {
            tmp[i] = state[i][c];
        }

        state[0][c] = (uint8_t)(tmp[0] ^ tmp[1] ^ tmp[2] ^ tmp[3]);
        uint8_t t = tmp[0] ^ tmp[1];
        state[0][c] ^= 0x02 * tmp[0] ^ 0x03 * t;
        state[1][c] = (uint8_t)(t ^ tmp[2] ^ tmp[3]);
        t = tmp[1] ^ tmp[2];
        state[1][c] ^= 0x02 * tmp[1] ^ 0x03 * t;
        state[2][c] = (uint8_t)(t ^ tmp[0] ^ tmp[3]);
        t = tmp[2] ^ tmp[3];
        state[2][c] ^= 0x02 * tmp[2] ^ 0x03 * t;
        state[3][c] = (uint8_t)(t ^ tmp[1] ^ tmp[0]);
        t = tmp[3] ^ tmp[0];
        state[3][c] ^= 0x02 * tmp[3] ^ 0x03 * t;
    }
}

// Display the state matrix
void displayState(uint8_t state[4][4]) {
    printf("State Matrix:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%02X ", state[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example state matrix (4x4)
    uint8_t state[4][4] = {
        {0x32, 0x88, 0x31, 0xe0},
        {0x43, 0x5a, 0x31, 0x37},
        {0xf6, 0x30, 0x98, 0x07},
        {0xa8, 0x8d, 0xa2, 0x34}
    };

    // Example round key (4x4)
    uint8_t roundKey[4][4] = {
        {0x2b, 0x28, 0xab, 0x09},
        {0x7e, 0xae, 0xf7, 0xcf},
        {0x15, 0xd2, 0x15, 0x4f},
        {0x16, 0xa6, 0x88, 0x3c}
    };

    printf("Original State:\n");
    displayState(state);

    // Apply MixColumns operation
    mixColumns(state);
    printf("\nAfter MixColumns:\n");
    displayState(state);

    return 0;
}
