
/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org
Copyright (c) Microsoft Open Technologies, Inc.
Copyright (c) Microsoft Corporation.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "pch.h"
#include "TimedEventHelper.h"

#include <Windows.h>


namespace microsoftapplicationinsights {

    TimedEventHelper::TimedEventHelper() {
        beginTime = new Windows::Foundation::TimeSpan;
        endTime = new Windows::Foundation::TimeSpan;
        mapData = nullptr;
    }

    TimedEventHelper::~TimedEventHelper() {
        delete beginTime;
        delete endTime;
    }

    void TimedEventHelper::startTiming() {
        beginTime->Duration = GetTickCount64() * NANOSECONDS_PER_MILLISECOND;
    }

    void TimedEventHelper::stopTiming() {
        endTime->Duration = GetTickCount64() * NANOSECONDS_PER_MILLISECOND;
    }

    double TimedEventHelper::elapsedTime() {
        return (endTime->Duration - beginTime->Duration) / NANOSECONDS_PER_MILLISECOND;
    }

    void TimedEventHelper::setMapData(IStringMap mapData) {
        this->mapData = mapData;
    }

    IStringMap TimedEventHelper::getMapData() {
        return mapData;
    }

}
