#pragma once

/// �پ��� ������ ����� ��ũ�θ� ������ ���� �������
/// static_assert�� assert�� ������ ������.

#ifdef _DEBUG
//#include <string_view>

#define STATIC_ASSERT(condition, message) \
do \
{ \
	static_assert(condition, message); \
} \
while (false)
#else
#define STATIC_ASSERT(condition, message)
#endif // _DEBUG



#ifdef ASSERT
#undef ASSERT
#endif // ASSERT

#ifdef _DEBUG

#include <intrin.h>

#define ASSERT(condition, message) \
do \
{ \
	if (!(condition)) \
	{ \
		::MessageBox(NULL, L""#message, L"Assertion Failed", MB_OK); \
		__debugbreak(); \
	} \
} \
while (false)

#else

#define ASSERT(condition, message)

#endif