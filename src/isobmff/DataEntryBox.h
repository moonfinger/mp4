/*
 * DataEntryBox.h
 *
 *  Created on: Mar 10, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_DATAENTRYBOX_H_
#define ISOBMFF_DATAENTRYBOX_H_

#include <iostream>
#include <stdint.h>

#include "FullBox.h"

using namespace std;

class DataEntryBox : public FullBox {
public:
	DataEntryBox();
	virtual ~DataEntryBox();

public:
	virtual void Read(uint8_t *buf, int32_t len) = 0;
	virtual string GetName() = 0;
	virtual string GetLocation() = 0;
};

class DataEntryUrlBox : public DataEntryBox {
public:
	DataEntryUrlBox();
	virtual ~DataEntryUrlBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	string GetName();	// always return NULL
	string GetLocation();

private:
	string m_location;
};

class DataEntryUrnBox : public DataEntryBox {
public:
	DataEntryUrnBox();
	virtual ~DataEntryUrnBox();

public:
	void Read(uint8_t *buf, int32_t len);

public:
	string GetName();
	string GetLocation();

private:
	string m_name;
	string m_location;
};

#endif /* ISOBMFF_DATAENTRYBOX_H_ */
