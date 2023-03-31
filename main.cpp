#include <iostream>
#include <rocksdb/db.h>
#include <hdfs.h>
using namespace std;
#define nl '\n'


int main(){
  rocksdb::HDFS a;
  rocksdb::Options option;
  rocksdb::DB *db;
  option.env = &a;
  option.create_if_missing = true;
  rocksdb::Status s = rocksdb::DB::Open(option, "/tmp/db", &db);
  cout << s.ToString() << nl;
}
