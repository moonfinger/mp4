/*
 * bin.c
 *
 *  Created on: Feb 28, 2017
 *      Author: moonfinger
 */

#include "bin.h"
#include <arpa/inet.h>

#ifdef __cplusplus
extern "C" {
#endif


static void write(const void *src, size_t len, void *dst) {
	memcpy(dst, src, len);
}

int32_t bin_read_int8(const uint8_t *buf, int8_t *val) {
	write((void *)buf, 1, val);
	return 1;
}

int32_t bin_read_uint8(const uint8_t *buf, uint8_t *val) {
	write((void *)buf, 1, val);
	return 1;
}

int32_t bin_read_int16(const uint8_t *buf, int16_t *val) {
	int16_t val_ntohs;

	write((void *)buf, 2, (void *)&val_ntohs);
	*val = ntohs(val_ntohs);
	return 2;
}

int32_t bin_read_uint16(const uint8_t *buf, uint16_t *val) {
	uint16_t val_ntohs;

	write((void *)buf, 2, (void *)&val_ntohs);
	*val = ntohs(val_ntohs);
	return 2;
}

int32_t bin_read_int32(const uint8_t *buf, int32_t *val) {
	int32_t val_ntohl;

	write((void *)buf, 4, (void *)&val_ntohl);
	*val = ntohl(val_ntohl);
	return 4;
}

int32_t bin_read_uint32(const uint8_t *buf, uint32_t *val) {
	uint32_t val_ntohl;

	write((void *)buf, 4, (void *)&val_ntohl);
	*val = ntohl(val_ntohl);
	return 4;
}

int32_t bin_read_int64(const uint8_t *buf, int64_t *val) {
	uint64_t val_ntohl;

	write((void *)buf, 8, (void *)&val_ntohl);
	*val = ntohl(val_ntohl);

	return 8;
}

int32_t bin_read_uint64(const uint8_t *buf, uint64_t *val) {
	uint64_t val_ntohl;

	write((void *)buf, 8, (void *)&val_ntohl);
	*val = ntohl(val_ntohl);

	return 8;
}

int32_t bin_read_bytes(const uint8_t *buf, size_t len, uint8_t *val) {
	write((void *)buf, len, val);
	return len;
}

#ifdef __cplusplus
}
#endif
