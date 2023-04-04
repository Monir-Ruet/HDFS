/**
 * @author      : Monir (monir81.mk@gmail.com)
 * @file        : hdfsfile
 * @created     : Thursday Mar 30, 2023 17:49:40 +06
 */

#ifndef HDFSFILE_H

#define HDFSFILE_H
#include<bits/stdc++.h>
using namespace std;

namespace rocksdb
{
    class HDFSFILE
    {
    public:
        std::string         name;
        std::string         data;
        size_t              size;
        size_t              before_truncate_size;
        std::uint64_t       uuididx;
        int                 level;
        // std::vector<struct zrocks_map> map;
        std::uint32_t startIndex;

        HDFSFILE(const std::string &fname, int lvl)
            : name(fname), uuididx(0), level(lvl)
        {
            before_truncate_size = 0;
            size = 0;
            startIndex = 0;
        }

        ~HDFSFILE()
        {
        }

        uint32_t GetFileMetaLen();

        uint32_t WriteMetaToBuf(unsigned char *buf, bool update = false);

        void PrintMetaData();
    };
}

#endif /* end of include guard HDFSFILE_H */
