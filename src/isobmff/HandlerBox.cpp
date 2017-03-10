/*
 * HandlerBox.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#include "HandlerBox.h"
#include "../misc/bin.h"

HandlerBox::HandlerBox() {
	// TODO Auto-generated constructor stub
	m_pre_defined = 0;
	m_handler_type = 0;
//	m_reserved_0 = NULL;
//	m_name;
}

HandlerBox::~HandlerBox() {
	// TODO Auto-generated destructor stub
}

void HandlerBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);

	m_offset += bin_read_uint32(m_ptr + m_offset, &m_pre_defined);
	m_offset += bin_read_uint32(m_ptr + m_offset, &m_handler_type);

	for(uint32_t i = 0; i < (sizeof(m_reserved_0) / sizeof(int32_t)); i++) {
		m_offset += bin_read_uint32(m_ptr + m_offset, &m_reserved_0[i]);
	}

	char name_str[32];
	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(name_str), (uint8_t *)name_str);
	m_name = string(name_str);
}

uint32_t HandlerBox::GetPreDefined() {
	return m_pre_defined;
}

uint32_t HandlerBox::GetHandlerType() {
	return m_handler_type;
}

uint32_t* HandlerBox::GetReserved0() {
	return m_reserved_0;
}

string HandlerBox::GetName() {
	return m_name;
}
