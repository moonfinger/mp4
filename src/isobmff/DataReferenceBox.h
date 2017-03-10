/*
 * DataReferenceBox.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_DATAREFERENCEBOX_H_
#define ISOBMFF_DATAREFERENCEBOX_H_

#include <iostream>
#include <stdint.h>
#include <vector>

#include "FullBox.h"
#include "DataEntryBox.h"

using namespace std;

class DataReferenceBox : public FullBox {
public:
	DataReferenceBox();
	virtual ~DataReferenceBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	uint32_t GetEntryCount();
	vector<DataEntryBox *>& GetDataEntryList();
	void AddDataEntry(DataEntryBox* entry);

private:
	uint32_t m_entry_count;
	vector<DataEntryBox *> m_entry_list;
};

#endif /* ISOBMFF_DATAREFERENCEBOX_H_ */
