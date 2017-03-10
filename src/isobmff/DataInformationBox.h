/*
 * DataInformationBox.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_DATAINFORMATIONBOX_H_
#define ISOBMFF_DATAINFORMATIONBOX_H_

#include <iostream>
#include <stdint.h>
#include <vector>

#include "Box.h"
#include "DataReferenceBox.h"

using namespace std;

class DataInformationBox : public Box {
public:
	DataInformationBox();
	virtual ~DataInformationBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	DataReferenceBox* GetDataReferenceBox();
	void SetDataReferenceBox(DataReferenceBox* dref);

private:
	DataReferenceBox* m_dref;
};

#endif /* ISOBMFF_DATAINFORMATIONBOX_H_ */
