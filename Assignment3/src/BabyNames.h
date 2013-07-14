/*
 * BabyNames.h
 *
 *  Created on: Feb 19, 2013
 *      Author: Anthony Varghese, Ricky Mutschlechner
 */

#ifndef BABYNAMES_H_
#define BABYNAMES_H_

namespace assignment3 {

class BabyNames {
public:

	BabyNames();
	BabyNames(const BabyNames& source);
	BabyNames(int sizeOfFile); //alternate constructor
	virtual ~BabyNames();
	BabyNames& operator =(const BabyNames& rhs);
/*	void sortByName();
	void sortByPopularity();
	void sortByYear();*/
	int getDataSize() const;
	void setDataSize(int size);

private:
	LinkedList* data;
	int datasize;
	static const int OUT_OF_BOUNDS = -1;
	friend istream& operator>>(istream& is, BabyNames& bn);
	friend ostream& operator<<(ostream& os, const BabyNames& bn);
};
istream& operator>>(istream& is, BabyNames& bn);
ostream& operator<<(ostream& os, const BabyNames& bn);
int getFileSize();

}

#endif /* BABYNAMES_H_ */
