/*
 * Box.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "Box.h"

#include "../misc/bin.h"

Box::Box() {
	m_ptr = NULL;
	m_offset = 0;
	m_size = 0;
	m_type = 0;
	m_parent = NULL;
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

void Box::ReadBoxHeader(uint8_t *buf, int32_t size) {
	m_ptr = buf;

	m_offset += bin_read_uint64(m_ptr + m_offset, &m_size);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_type);
}

uint64_t Box::GetSize() {
	return m_size;
}

uint32_t Box::GetType() {
	return m_type;
}
