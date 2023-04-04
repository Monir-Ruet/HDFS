/**
 * @author      : Monir (monir81.mk@gmail.com)
 * @file        : randomaccessfile
 * @created     : Friday Mar 31, 2023 12:19:33 +06
 */

#ifndef RANDOMACCESSFILE_H
#define RANDOMACCESSFILE_H

#include<hdfs.h>
#include<hdfsfile.h>

namespace rocksdb{
  class HDFSRandomAccessFile : public RandomAccessFile {
 private:
  std::string   filename_;
  bool          use_direct_io_;
  size_t        logical_sector_size_;
  std::uint64_t uuididx;

  HDFS*  env;
  HDFSFILE* file;

// #if ZNS_PREFETCH
//   char*            prefetch;
//   size_t           prefetch_sz;
//   std::uint64_t    prefetch_off;
//   std::atomic_flag prefetch_lock = ATOMIC_FLAG_INIT;
// #endif

 public:
  HDFSRandomAccessFile(const std::string& fname, HDFS* e,
                      const EnvOptions& options)
      : filename_(fname),
        use_direct_io_(options.use_direct_reads),
        logical_sector_size_(ZNS_ALIGMENT),
        uuididx(0),
        env(e) {
    env->filesMutex.Lock();
    file = env->files[filename_];
    env->filesMutex.Unlock();
  }

  virtual ~HDFSRandomAccessFile() {
    cout<<"Closing RandomAccess\n";
// #if ZNS_PREFETCH
//     zrocks_free(prefetch);
// #endif
  }

  /* ### Implemented at env_zns_io.cc ### */

  Status Read(std::uint64_t offset, size_t n, Slice* result,
              char* scratch) const override;

  Status Prefetch(std::uint64_t offset, size_t n) override;

  size_t GetUniqueId(char* id, size_t max_size) const override;

  Status InvalidateCache(size_t offset, size_t length) override;

  virtual Status ReadObj(std::uint64_t offset, size_t n, Slice* result,
                         char* scratch) const;

  virtual Status ReadOffset(std::uint64_t offset, size_t n, Slice* result,
                            char* scratch) const;

  /* ### Implemented here ### */

  bool use_direct_io() const override {
    return use_direct_io_;
  }

  size_t GetRequiredBufferAlignment() const override {
    return logical_sector_size_;
  }
};
}


#endif /* end of include guard RANDOMACCESSFILE_H */
