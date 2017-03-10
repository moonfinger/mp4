/*
 * Box.h
 *
 *  Created on: Mar 9, 2017
 *      Author: moonfinger
 */

#ifndef ISOBMFF_BOX_H_
#define ISOBMFF_BOX_H_

#include <iostream>
#include <stdint.h>

using namespace std;

class Box {
public:
	Box();
	virtual ~Box();

protected:
	void ReadBoxHeader(uint8_t *buf, int32_t size);

public:
	uint64_t GetSize();
	uint32_t GetType();

	void SetParent(void* parent) { m_parent = parent; }
	void* GetParent() { return m_parent; }

private:
	uint64_t m_size;
	uint32_t m_type;

protected:
	uint8_t* m_ptr;
	int32_t  m_offset;
	void*    m_parent;
};

#endif /* ISOBMFF_BOX_H_ */
