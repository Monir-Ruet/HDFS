#include <sequentialfile.h>
using namespace rocksdb;
Status HDFSSequentialFile::ReadOffset(uint64_t offset, size_t n, Slice *result, char *scratch,size_t *readLen) const{
}

Status HDFSSequentialFile::Read(size_t n, Slice *result, char *scratch){
}

Status HDFSSequentialFile::PositionedRead(std::uint64_t offset, size_t n, Slice *result,char *scratch){
}

Status HDFSSequentialFile::Skip(std::uint64_t n)
{
}

Status HDFSSequentialFile::InvalidateCache(size_t offset, size_t length)
{
}