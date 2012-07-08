// Copyright (c) 2011 Kerem KAT 
// 
// http://dissipatedheat.com/
// Do not hesisate to contact me about usage of the code or to make comments 
// about the code. Your feedback will be appreciated.
// keremkat<@>gmail<.>com
//
// Kodun kullanımı hakkında veya yorum yapmak için benimle iletişim kurmaktan
// çekinmeyiniz. Geri bildirimleriniz değerlendirilecektir.
// keremkat<@>gmail<.>com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to 
// deal in the Software without restriction, including without limitation the 
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or 
// sell copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef FILTERFACTORY_H_
#define FILTERFACTORY_H_

#include "ISingleImageFilter.h"

#if defined(FILTERAPI_EXPORT) // inside DLL
#   define FILTERAPI   __declspec(dllexport)
#else // outside DLL
#   define FILTERAPI   __declspec(dllimport)
#endif  // XYZLIBRARY_EXPORT

#define FILTERENTRY __stdcall

extern "C" FILTERAPI ISingleImageFilter* FILTERENTRY GetCpuInvertFilter();

extern "C" FILTERAPI void FILTERENTRY ReleaseCUDAThread();

#endif // FILTERFACTORY_H_