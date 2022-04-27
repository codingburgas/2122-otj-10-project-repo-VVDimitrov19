#pragma once
#include "pch.h"
using namespace std;

namespace pm::type
{
	struct User
	{
		size_t id;
		string firstName;
		string lastName;
		string email;
		uint8_t age;
		string passwordHash;

	};
}