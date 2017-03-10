/*
 * bin.h
 *
 *  Created on: Feb 28, 2017
 *      Author: moonfinger
 */

#ifndef MISC_BIN_H_
#define MISC_BIN_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t bin_read_int8(const uint8_t *buf, int8_t *val);
int32_t bin_read_uint8(const uint8_t *buf, uint8_t *val);
int32_t bin_read_int16(const uint8_t *buf, int16_t *val);
int32_t bin_read_uint16(const uint8_t *buf, uint16_t *val);
int32_t bin_read_int32(const uint8_t *buf, int32_t *val);
int32_t bin_read_uint32(const uint8_t *buf, uint32_t *val);
int32_t bin_read_int64(const uint8_t *buf, int64_t *val);
int32_t bin_read_uint64(const uint8_t *buf, uint64_t *val);
int32_t bin_read_bytes(const uint8_t *buf, size_t len, uint8_t *val);

#ifdef __cplusplus
}
#endif

#endif /* MISC_BIN_H_ */
