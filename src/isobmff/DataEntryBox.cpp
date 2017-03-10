/*
 * DataEntryBox.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#include "DataEntryBox.h"
#include "../misc/bin.h"

DataEntryBox::DataEntryBox() {
	// TODO Auto-generated constructor stub
//	m_parent = NULL;
}

DataEntryBox::~DataEntryBox() {
	// TODO Auto-generated destructor stub
}

DataEntryUrlBox::DataEntryUrlBox() {
}

DataEntryUrlBox::~DataEntryUrlBox() {
}

void DataEntryUrlBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
//	m_parent = static_cast<DataReferenceBox *>(GetParent());

	char location_str[128];

	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(location_str), (uint8_t *)location_str);

	m_location = string(location_str);
}

string DataEntryUrlBox::GetName() {
	return NULL;
}

string DataEntryUrlBox::GetLocation() {
	return m_location;
}

DataEntryUrnBox::DataEntryUrnBox() {
}

DataEntryUrnBox::~DataEntryUrnBox() {
}

void DataEntryUrnBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
//	m_parent = static_cast<DataReferenceBox *>(GetParent());

	char name_str[32];
	char location_str[128];

	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(name_str), (uint8_t *)name_str);
	m_offset += bin_read_bytes(m_ptr + m_offset, sizeof(location_str), (uint8_t *)location_str);

	m_name = string(name_str);
	m_location = string(location_str);
}

string DataEntryUrnBox::GetName() {
	return m_name;
}

string DataEntryUrnBox::GetLocation() {
	return m_location;
}
