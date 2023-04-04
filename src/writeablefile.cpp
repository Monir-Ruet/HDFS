#include <writeablefile.h>

using namespace rocksdb;

Status HDFSWritableFile::Append(const Slice &data){
    
    return Status::OK();
}

Status HDFSWritableFile::PositionedAppend(const Slice &data, std::uint64_t offset){
    return Status::OK();
}
Status HDFSWritableFile::Append(const rocksdb::Slice &, const rocksdb::DataVerificationInfo &){
    return Status::OK();
}
Status HDFSWritableFile::PositionedAppend(const rocksdb::Slice &, uint64_t, const rocksdb::DataVerificationInfo &){
    return Status::OK();
}

Status HDFSWritableFile::Truncate(std::uint64_t size){
    return Status::OK();
}

Status HDFSWritableFile::Close(){
    return Status::OK();
}

Status HDFSWritableFile::Flush(){
    return Status::OK();
}

Status HDFSWritableFile::Sync(){
    return Status::OK();
}

Status HDFSWritableFile::Fsync(){
    return Status::OK();
}

Status HDFSWritableFile::InvalidateCache(size_t offset, size_t length){
    return Status::OK();
}

Status HDFSWritableFile::RangeSync(std::uint64_t offset, std::uint64_t nbytes){
    return Status::OK();
}

size_t HDFSWritableFile::GetUniqueId(char* id, size_t max_size) const {
    return 10;
}
void HDFSWritableFile::SetWriteLifeTimeHint(Env::WriteLifeTimeHint hint){

}