#include <hdfs.h>
using namespace rocksdb;

Status HDFS::NewSequentialFile(const std::string &f, std::unique_ptr<SequentialFile> *r, const EnvOptions &options){
  if(IsFilePosix(f))
    return target->NewSequentialFile(f, r, options);
  else{
    cout<<__func__<<" "<<f<<'\n';
    return Status::OK();
  }
}
Status HDFS::NewRandomAccessFile(const std::string &f, std::unique_ptr<RandomAccessFile> *r, const EnvOptions &options){
  if(IsFilePosix(f))
    return target->NewRandomAccessFile(f, r, options);
  else{
    cout<<__func__<<" "<<f<<'\n';
    return Status::OK();
  }
}
Status HDFS::NewWritableFile(const std::string &f, std::unique_ptr<WritableFile> *r, const EnvOptions &options){
  return target->NewWritableFile(f, r, options);
}
Status HDFS::ReopenWritableFile(const std::string &fname, std::unique_ptr<WritableFile> *result, const EnvOptions &options){
  return target->ReopenWritableFile(fname, result, options);
}
Status HDFS::ReuseWritableFile(const std::string &fname, const std::string &old_fname, std::unique_ptr<WritableFile> *r, const EnvOptions &options){
  return target->ReuseWritableFile(fname, old_fname, r, options);
}
Status HDFS::NewRandomRWFile(const std::string &fname, std::unique_ptr<RandomRWFile> *result, const EnvOptions &options)
{
  return target->NewRandomRWFile(fname, result, options);
}
Status HDFS::NewMemoryMappedFileBuffer(const std::string &fname, std::unique_ptr<MemoryMappedFileBuffer> *result)
{
  return target->NewMemoryMappedFileBuffer(fname, result);
}
Status HDFS::NewDirectory(const std::string &name, std::unique_ptr<Directory> *result)
{
  return target->NewDirectory(name, result);
}
Status HDFS::FileExists(const std::string &f)
{
  return target->FileExists(f);
}
Status HDFS::GetChildren(const std::string &dir, std::vector<std::string> *r)
{
  return target->GetChildren(dir, r);
}
Status HDFS::GetChildrenFileAttributes(const std::string &dir, std::vector<FileAttributes> *result)
{
  return target->GetChildrenFileAttributes(dir, result);
}
Status HDFS::DeleteFile(const std::string &f)
{
  return target->DeleteFile(f);
}
Status HDFS::Truncate(const std::string &fname, size_t size)
{
  return target->Truncate(fname, size);
}
Status HDFS::CreateDir(const std::string &d)
{
  return target->CreateDir(d);
}
Status HDFS::CreateDirIfMissing(const std::string &d)
{
  return target->CreateDirIfMissing(d);
}
Status HDFS::DeleteDir(const std::string &d)
{
  return target->DeleteDir(d);
}
Status HDFS::GetFileSize(const std::string &f, uint64_t *s)
{
  return target->GetFileSize(f, s);
}
Status HDFS::GetFileModificationTime(const std::string &fname, uint64_t *file_mtime)
{
  return target->GetFileModificationTime(fname, file_mtime);
}
Status HDFS::RenameFile(const std::string &s, const std::string &t)
{
  return target->RenameFile(s, t);
}
Status HDFS::LinkFile(const std::string &s, const std::string &t)
{
  return target->LinkFile(s, t);
}
Status HDFS::NumFileLinks(const std::string &fname, uint64_t *count)
{
  return target->NumFileLinks(fname, count);
}
Status HDFS::AreFilesSame(const std::string &first, const std::string &second, bool *res)
{
  return target->AreFilesSame(first, second, res);
}
Status HDFS::LockFile(const std::string &f, FileLock **l)
{
  return target->LockFile(f, l);
}
Status HDFS::UnlockFile(FileLock *l)
{
  return target->UnlockFile(l);
}
Status HDFS::IsDirectory(const std::string &path, bool *is_dir)
{
  return target->IsDirectory(path, is_dir);
}
Status HDFS::LoadLibrary(const std::string &lib_name, const std::string &search_path, std::shared_ptr<DynamicLibrary> *result)
{
  return target->LoadLibrary(lib_name, search_path, result);
}
int HDFS::UnSchedule(void *tag, Priority pri)
{
  return target->UnSchedule(tag, pri);
}
void HDFS::StartThread(void (*f)(void *), void *a)
{
  return target->StartThread(f, a);
}
void HDFS::WaitForJoin()
{
  return target->WaitForJoin();
}

int HDFS::ReserveThreads(int threads_to_be_reserved, Priority pri)
{
  return target->ReserveThreads(threads_to_be_reserved, pri);
}

int HDFS::ReleaseThreads(int threads_to_be_released, Priority pri)
{
  return target->ReleaseThreads(threads_to_be_released, pri);
}

Status HDFS::GetTestDirectory(std::string *path)
{
  return target->GetTestDirectory(path);
}
Status HDFS::NewLogger(const std::string &fname,
                       std::shared_ptr<Logger> *result)
{
  return target->NewLogger(fname, result);
}
uint64_t HDFS::NowMicros() { return target->NowMicros(); }
uint64_t HDFS::NowNanos() { return target->NowNanos(); }
uint64_t HDFS::NowCPUNanos() { return target->NowCPUNanos(); }

void HDFS::SleepForMicroseconds(int micros)
{
  target->SleepForMicroseconds(micros);
}
Status HDFS::GetHostName(char *name, uint64_t len)
{
  return target->GetHostName(name, len);
}
Status HDFS::GetCurrentTime(int64_t *unix_time)
{
  return target->GetCurrentTime(unix_time);
}
Status HDFS::GetAbsolutePath(const std::string &db_path,
                             std::string *output_path)
{
  return target->GetAbsolutePath(db_path, output_path);
}
void HDFS::SetBackgroundThreads(int num, Priority pri)
{
  return target->SetBackgroundThreads(num, pri);
}
int HDFS::GetBackgroundThreads(Priority pri)
{
  return target->GetBackgroundThreads(pri);
}

Status HDFS::SetAllowNonOwnerAccess(bool allow_non_owner_access)
{
  return target->SetAllowNonOwnerAccess(allow_non_owner_access);
}

void HDFS::IncBackgroundThreadsIfNeeded(int num, Priority pri)
{
  return target->IncBackgroundThreadsIfNeeded(num, pri);
}

void HDFS::LowerThreadPoolIOPriority(Priority pool)
{
  target->LowerThreadPoolIOPriority(pool);
}

void HDFS::LowerThreadPoolCPUPriority(Priority pool)
{
  target->LowerThreadPoolCPUPriority(pool);
}
Status HDFS::LowerThreadPoolCPUPriority(Priority pool, CpuPriority pri)
{
  return target->LowerThreadPoolCPUPriority(pool, pri);
}
std::string HDFS::TimeToString(uint64_t time)
{
  return target->TimeToString(time);
}

Status HDFS::GetThreadList(std::vector<ThreadStatus> *thread_list)
{
  return target->GetThreadList(thread_list);
}

ThreadStatusUpdater* HDFS::GetThreadStatusUpdater() const {
  return target->GetThreadStatusUpdater();
}

uint64_t HDFS::GetThreadID() const { return target->GetThreadID(); }

std::string HDFS::GenerateUniqueId() {
  return target->GenerateUniqueId();
}

EnvOptions HDFS::OptimizeForLogRead(const EnvOptions& env_options) const {
  return target->OptimizeForLogRead(env_options);
}
EnvOptions HDFS::OptimizeForManifestRead(
    const EnvOptions& env_options) const {
  return target->OptimizeForManifestRead(env_options);
}
EnvOptions HDFS::OptimizeForLogWrite(const EnvOptions& env_options,
    const DBOptions& db_options) const {
  return target->OptimizeForLogWrite(env_options, db_options);
}
EnvOptions HDFS::OptimizeForManifestWrite(const EnvOptions& env_options) const {
  return target->OptimizeForManifestWrite(env_options);
}
EnvOptions HDFS::OptimizeForCompactionTableWrite(const EnvOptions& env_options,const ImmutableDBOptions& immutable_ops) const {
  return target->OptimizeForCompactionTableWrite(env_options,immutable_ops);
}
EnvOptions HDFS::OptimizeForCompactionTableRead(const EnvOptions& env_options,const ImmutableDBOptions& db_options) const {
  return target->OptimizeForCompactionTableRead(env_options, db_options);
}
EnvOptions HDFS::OptimizeForBlobFileRead(const EnvOptions& env_options,const ImmutableDBOptions& db_options) const {
  return target->OptimizeForBlobFileRead(env_options, db_options);
}
Status HDFS::GetFreeSpace(const std::string& path, uint64_t* diskfree) {
  // cout<<path<<nl;
  return target->GetFreeSpace(path, diskfree);
}
void HDFS::SanitizeEnvOptions(EnvOptions* env_opts) const {
  target->SanitizeEnvOptions(env_opts);
}
Status HDFS::PrepareOptions(const ConfigOptions& options){
  return Status::NotSupported();
}

bool HDFS::IsFilePosix(const std::string& fname) {
  return (fname.find("uuid") != std::string::npos ||
          fname.find("CURRENT") != std::string::npos ||
          fname.find("IDENTITY") != std::string::npos ||
          fname.find("MANIFEST") != std::string::npos ||
          fname.find("OPTIONS") != std::string::npos ||
          fname.find("LOG") != std::string::npos ||
          fname.find("LOCK") != std::string::npos ||
          fname.find(".dbtmp") != std::string::npos ||
          // fname.find(".log") != std::string::npos ||
          fname.find(".trace") != std::string::npos);
}