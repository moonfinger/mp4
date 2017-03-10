/*
 * DataInformationBox.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#include "DataInformationBox.h"
#include "FourCcDef.h"
#include "../misc/bin.h"

DataInformationBox::DataInformationBox() {
	// TODO Auto-generated constructor stub
	m_dref = NULL;
	m_parent = NULL;
}

DataInformationBox::~DataInformationBox() {
	// TODO Auto-generated destructor stub
	if(m_dref) delete m_dref;
}

void DataInformationBox::Read(uint8_t* buf, int32_t len) {
	ReadBoxHeader(buf, len);

	uint8_t *ptr = m_ptr;
	int32_t offset = 0;
	int32_t size = (len - m_offset);

	uint32_t box_size, box_type;

	while(offset < size) {
		offset += bin_read_uint32(ptr + offset, &box_size);
		offset += bin_read_uint32(ptr + offset, &box_type);

		switch(box_type) {
		case box_dref: {
			DataReferenceBox *dref = new DataReferenceBox();
			dref->Read(ptr + (offset - 8), box_size);

			SetDataReferenceBox(dref);
			break;
		}
		default:
			break;
		}

		offset += box_size;
	}
}

DataReferenceBox* DataInformationBox::GetDataReferenceBox() {
	return m_dref;
}

void DataInformationBox::SetDataReferenceBox(DataReferenceBox* dref) {
	m_dref = dref;
}

