
#include <hdfsfile.h>
using namespace rocksdb;

std::uint32_t HDFSFILE::GetFileMetaLen(){
    return 10;
}

std::uint32_t HDFSFILE::WriteMetaToBuf(unsigned char *buf, bool update){
    return 0;
}

void HDFSFILE::PrintMetaData(){

}