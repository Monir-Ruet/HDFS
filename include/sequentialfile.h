/**
 * @author      : Monir (monir81.mk@gmail.com)
 * @file        : sequentialfile
 * @created     : Friday Mar 31, 2023 12:20:13 +06
 */

#ifndef SEQUENTIALFILE_H

#define SEQUENTIALFILE_H

#include <string>
#include <iostream>
#include <map>
#include<hdfs.h>
#include<hdfsfile.h>

namespace rocksdb
{
  class HDFSSequentialFile : public SequentialFile
  {
  private:
    std::string filename_;
    bool use_direct_io_;
    size_t logical_sector_size_;
    std::uint64_t ztl_id;
    HDFSFILE *znsfile;
    HDFS *env_zns;
    uint64_t read_off;

  public:
    HDFSSequentialFile(const std::string &fname, HDFS *zns,const EnvOptions &options): filename_(fname),use_direct_io_(options.use_direct_reads),logical_sector_size_(ZNS_ALIGMENT){
      env_zns = zns;
      read_off = 0;
      znsfile = env_zns->files[fname];
      ztl_id = 0;
    }

    virtual ~HDFSSequentialFile()
    {
    }

    /* ### Implemented at env_zns_io.cc ### */

    Status ReadOffset(uint64_t offset, size_t n, Slice *result, char *scratch,
                      size_t *readLen) const;

    Status Read(size_t n, Slice *result, char *scratch) override;

    Status PositionedRead(std::uint64_t offset, size_t n, Slice *result,
                          char *scratch) override;

    Status Skip(std::uint64_t n) override;

    Status InvalidateCache(size_t offset, size_t length) override;

    /* ### Implemented here ### */

    bool use_direct_io() const override
    {
      return use_direct_io_;
    }

    size_t GetRequiredBufferAlignment() const override
    {
      return logical_sector_size_;
    }
  };
}


#endif /* end of include guard SEQUENTIALFILE_H */

