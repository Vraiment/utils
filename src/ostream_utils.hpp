/*
Copyright (c) 2017 Vraiment <https://github.com/Vraiment>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef VCPPUTILS_OSTREAM_UTILS_HPP
#define VCPPUTILS_OSTREAM_UTILS_HPP

#include <ostream>
#include <string>

namespace VCppUtils
{
    template <typename InputIterator, typename CharT, typename Traits = std::char_traits<CharT>>
    std::basic_ostream<CharT, Traits>& basic_join(std::basic_ostream<CharT, Traits>& stream, CharT character, InputIterator begin, InputIterator end)
    {
        if (begin != end)
        {
            stream << *begin;
            
            for (++begin; begin != end; ++begin)
            {
                stream << character << *begin;
            }
        }
        
        return stream;
    }
    
    template <typename CharT, typename Traits = std::char_traits<CharT>>
    typename std::basic_ostream<CharT, Traits>::pos_type get_stream_size(std::basic_ostream<CharT, Traits>& stream)
    {
        stream.seekp(0, std::ios::end);
        return stream.tellp();
    }
}

#endif
