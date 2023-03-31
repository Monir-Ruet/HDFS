#include <randomaccessfile.h>

using namespace rocksdb;

Status HDFSRandomAccessFile::Read(std::uint64_t offset, size_t n, Slice *result,char *scratch) const{

}

Status HDFSRandomAccessFile::Prefetch(std::uint64_t offset, size_t n){

}

size_t HDFSRandomAccessFile::GetUniqueId(char *id, size_t max_size) const{

}

Status HDFSRandomAccessFile::InvalidateCache(size_t offset, size_t length) {
    
}

Status HDFSRandomAccessFile::ReadObj(std::uint64_t offset, size_t n, Slice *result,
                       char *scratch) const{
                        
}

Status HDFSRandomAccessFile::ReadOffset(std::uint64_t offset, size_t n, Slice *result,
                          char *scratch) const{

}