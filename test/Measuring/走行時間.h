#ifndef MEASURING_���s����_H
#define MEASURING_���s����_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Clock.h"

namespace Measuring
{
class ���s����
{
private:
	int �v���J�n����;

	ev3api::Clock clock;

public:
	int ���s���Ԃ��擾����();

	void �v���J�n();

	void �v�����Ԃ��擾����();

};

}  // namespace Measuring
#endif
