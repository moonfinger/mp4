/*
 * DataReferenceBox.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#include "DataReferenceBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

DataReferenceBox::DataReferenceBox() {
	// TODO Auto-generated constructor stub
	m_entry_count = 0;
//	m_parent = NULL;
}

DataReferenceBox::~DataReferenceBox() {
	// TODO Auto-generated destructor stub
}

void DataReferenceBox::Read(uint8_t* buf, int32_t len) {
	ReadFullBoxHeader(buf, len);
//	m_parent = static_cast<DataInformationBox *>(GetParent());

	m_offset += bin_read_uint32(m_ptr + m_offset, &m_entry_count);

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;
	int32_t size = (len - m_offset);
	uint32_t box_size, box_type;

	while(offset < size) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_urn: {
			DataEntryBox *entry = new DataEntryUrnBox();
			entry->Read(ptr + (offset - 8), box_size);

			AddDataEntry(entry);
			break;
		}
		case box_url: {
			DataEntryBox *entry = new DataEntryUrlBox();
			entry->Read(ptr + (offset - 8), box_size);

			AddDataEntry(entry);
			break;
		}
		default:
			break;
		}

		offset += box_size;
	}
}

uint32_t DataReferenceBox::GetEntryCount() {
	return m_entry_count;
}

vector<DataEntryBox*>& DataReferenceBox::GetDataEntryList() {
	return m_entry_list;
}

void DataReferenceBox::AddDataEntry(DataEntryBox* entry) {
	m_entry_list.push_back(entry);
}
