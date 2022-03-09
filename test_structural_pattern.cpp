#include "test_structural_pattern.h"
#include "structural_pattern/decorator.h"
#include "structural_pattern/facade.h"
#include "structural_pattern/proxy.h"
void test_facade() {
  auto test = facade::Facade();
  test.MethodA();
  test.MethodB();
}


void test_decorator() {
  // 普通读写类
  std::shared_ptr<structure::FileDataSource> file_data =
      make_shared<structure::FileDataSource>();
  file_data->ReadData("123");
  file_data->WriteData("123");

  // 加密读写修饰普通读写
  std::shared_ptr<structure::DataSourceDecorator> encry_file =
      std::make_shared<structure::EncryptionDecorator>(file_data);
  encry_file->WriteData("233");
  encry_file->ReadData("233");

  // 压缩读写修饰普通读写
  std::shared_ptr<structure::DataSourceDecorator> compress_file =
      std::make_shared<structure::CompressionDecorator>(file_data);
  compress_file->WriteData("233");
  compress_file->ReadData("233");

  // 压缩 + 普通读写
  std::shared_ptr<structure::DataSourceDecorator> compress_encry_file =
      std::make_shared<structure::CompressionDecorator>(encry_file);
  compress_encry_file->WriteData("123");
  compress_encry_file->ReadData("123");
}

void test_proxy() {
  auto proxy =
      make_unique<structure::Proxy>(std::make_shared<structure::RealObject>());
  proxy->operator1();
  proxy->operator2();
}