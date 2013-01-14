//@COPYRIGHT@//
//
// Copyright (c) 2012, Tomoto S. Washio
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of the Tomoto S. Washio nor the names of his
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL TOMOTO S. WASHIO BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//@COPYRIGHT@//

#ifndef _ABSTRACT_SENSOR_DATA_PROVIDER_H_
#define _ABSTRACT_SENSOR_DATA_PROVIDER_H_

#include "common.h"

#ifdef XU_KINECTSDK

class AbstractSensorDataProvider
{
private:
	static const DWORD TIMEOUT = 1000;

protected:
	INuiSensor* m_pSensor;
	HANDLE m_hNextFrameEvent;
	bool m_isLocked;

public:
	AbstractSensorDataProvider(INuiSensor* pSensor);
	virtual ~AbstractSensorDataProvider() = 0;

	bool waitForNextFrameAndLock();
	void unlock();

protected:
	virtual bool waitForNextFrameAndLockImpl(DWORD timeout) = 0;
	virtual void unlockImpl() = 0;
};

#elif XU_OPENNI2

class AbstractSensorDataProvider
{
protected:
	openni::Device* m_pDevice;

public:
	AbstractSensorDataProvider(openni::Device* pDevice);
	virtual ~AbstractSensorDataProvider() = 0;

	openni::Device* getDevice() { return m_pDevice; }
};

#else // XU_OPENNI

class AbstractSensorDataProvider
{
protected:
	Context* m_pContext;

public:
	AbstractSensorDataProvider(Context* pContext);
	virtual ~AbstractSensorDataProvider() = 0;
};

#endif

#endif
