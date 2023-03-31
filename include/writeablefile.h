/**
 * @author      : Monir (monir81.mk@gmail.com)
 * @file        : writeablefile
 * @created     : Friday Mar 31, 2023 12:21:42 +06
 */

#ifndef WRITEABLEFILE_H

#define WRITEABLEFILE_H

#include<hdfs.h>
#include<hdfsfile.h>

namespace rocksdb{
  class HDFSWritableFile : public WritableFile {
 private:
  const std::string filename_;
  const bool        use_direct_io_;
  int               fd_;
  std::uint64_t     filesize_;
  HDFSFILE*          znsfile;
  size_t            logical_sector_size_;
#ifdef ROCKSDB_FALLOCATE_PRESENT
  bool allow_fallocate_;
  bool fallocate_with_keep_size_;
#endif

  char* wcache;
  char* cache_off;

  HDFS*       env_zns;
  std::uint64_t map_off;

 public:
  explicit HDFSWritableFile(const std::string& fname, HDFS* zns,
                           const EnvOptions& options)
      : WritableFile(options),
        filename_(fname),
        use_direct_io_(options.use_direct_writes),
        fd_(0),
        filesize_(0),
        logical_sector_size_(ZNS_ALIGMENT),
        env_zns(zns) {
// #ifdef ROCKSDB_FALLOCATE_PRESENT
//     allow_fallocate_          = options.allow_fallocate;
//     fallocate_with_keep_size_ = options.fallocate_with_keep_size;
// #endif

//     wcache = reinterpret_cast<char*>(zrocks_alloc(ZNS_MAX_BUF));
//     if (!wcache) {
//       std::cout << " ZRocks (alloc) error." << std::endl;
//       cache_off = nullptr;
//     }

//     cache_off = wcache;
//     map_off   = 0;

    // zns->filesMutex.Lock();
    // znsfile = env_zns->files[fname];
    // zns->filesMutex.Unlock();
  }

  virtual ~HDFSWritableFile() {
    // if (wcache)
    //   zrocks_free(wcache);
  }

  /* ### Implemented at env_zns_io.cc ### */

  Status Append(const Slice& data) override;

  Status PositionedAppend(const Slice& data, std::uint64_t offset) override;
  Status Append(const rocksdb::Slice&, const rocksdb::DataVerificationInfo&);
  Status PositionedAppend(const rocksdb::Slice&, uint64_t,
                          const rocksdb::DataVerificationInfo&);

  Status Truncate(std::uint64_t size) override;

  Status Close() override;

  Status Flush() override;

  Status Sync() override;

  Status Fsync() override;

  Status InvalidateCache(size_t offset, size_t length) override;

  void SetWriteLifeTimeHint(Env::WriteLifeTimeHint hint) override;

#ifdef ROCKSDB_FALLOCATE_PRESENT
  Status Allocate(std::uint64_t offset, std::uint64_t len) override;
#endif

  Status RangeSync(std::uint64_t offset, std::uint64_t nbytes) override;

  size_t GetUniqueId(char* id, size_t max_size) const override;

  /* ### Implemented here ### */

  bool IsSyncThreadSafe() const override {
    return true;
  }

  bool use_direct_io() const override {
    return use_direct_io_;
  }

  size_t GetRequiredBufferAlignment() const override {
    return logical_sector_size_;
  }
};
}


#endif /* end of include guard WRITEABLEFILE_H */

