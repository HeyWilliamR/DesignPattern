#ifndef DESIGNPATTERN_STRUCTURAL_PATTERN_DECORATOR_H_
#define DESIGNPATTERN_STRUCTURAL_PATTERN_DECORATOR_H_
#include <iostream>
#include <memory>
#include <string>
using namespace std;
namespace structure {
class DataSource {
public:
  virtual void WriteData(const string &str) = 0;
  virtual void ReadData(const string &str) = 0;
  virtual ~DataSource() = default;
};

class FileDataSource : public DataSource {
public:
  void WriteData(const string &str) override final {
    cout << "ori write data:" << str << endl;
  }
  void ReadData(const string &str) override final {
    cout << "ori read data:" << str << endl;
  }
};

class DataSourceDecorator : public DataSource {
protected:
  shared_ptr<DataSource> data_source_;

public:
  virtual ~DataSourceDecorator() = default;
  explicit DataSourceDecorator(shared_ptr<DataSource> data_source)
      : data_source_(data_source) {}
  void WriteData(const string &str) override { data_source_->WriteData(str); }
  void ReadData(const string &str) override { data_source_->ReadData(str); }
};

class EncryptionDecorator final : public DataSourceDecorator {
public:
  explicit EncryptionDecorator(shared_ptr<DataSource> data_source)
      : DataSourceDecorator(std::move(data_source)) {}
  void WriteData(const string &str) override final;
  void ReadData(const string &str) override final;
  string Encry(const string &str) { return str + " encry"; }
  string Decode(const string &str) { return str + " decode"; }
};

class CompressionDecorator final : public DataSourceDecorator {
public:
  explicit CompressionDecorator(shared_ptr<DataSource> data_source)
      : DataSourceDecorator(std::move(data_source)) {}
  void WriteData(const string &str) override final;
  void ReadData(const string &str) override final;
  string Compress(const string &str) { return str + " compress"; }
  string DeCompress(const string &str) { return str + " decompress"; }
};
} // namespace structure

#endif // DESIGNPATTERN_STRUCTURAL_PATTERN_DECORATOR_H_
