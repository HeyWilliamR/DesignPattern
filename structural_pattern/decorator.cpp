#include "decorator.h"
namespace structure {
void structure::EncryptionDecorator::WriteData(const string &str) {
  auto enc_string = Encry(str);
  DataSourceDecorator::WriteData(enc_string);
}
void EncryptionDecorator::ReadData(const string &str) {
  DataSourceDecorator::ReadData(Decode(str));
}
void CompressionDecorator::WriteData(const string &str) {
  DataSourceDecorator::WriteData(Compress(str));
}
void CompressionDecorator::ReadData(const string &str) {
  DataSourceDecorator::ReadData(DeCompress(str));
}
} // namespace structure