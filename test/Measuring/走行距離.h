#ifndef MEASURING_���s����_H
#define MEASURING_���s����_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ev3api/Motor.h"
#include "ev3api/int8_t.h"

namespace Measuring
{
class ���s����
{
private:
	int �v���J�n����;

	ev3api::Motor motor;

private:
	void ���s�������v�Z����();

public:
	ev3api::int8_t ���s�������擾����();

	void �v���J�n();

	int �v���������擾����();

};

}  // namespace Measuring
#endif
