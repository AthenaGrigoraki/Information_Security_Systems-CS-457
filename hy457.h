#include <stdint.h>



uint8_t *get_key(int size);
int get_length(uint8_t *plaintext);
void word_decryption(uint8_t *key);
uint8_t *one_time_pad_encr(uint8_t *plaintext,uint8_t *key);
uint8_t *one_time_pad_dencr(uint8_t *cipertext,uint8_t *key,int size);

uint8_t *rail_fence_encr(uint8_t *plaintext,int rails);
uint8_t **rail_fence_decr(uint8_t *cipertext,int rails);

uint8_t *affine_encr(uint8_t *plaintext);
uint8_t *affine_decr(uint8_t *cipertext);

uint8_t *feistel_encr(uint8_t *plaintext, uint8_t *key, int size);
uint8_t *feistel_dencr(uint8_t *plaintext, uint8_t *key, int size);

uint8_t *beaufort_encr(uint8_t *plaintext, uint8_t *key);
uint8_t *beaufort_dencr(uint8_t *cipertext, uint8_t *key);
