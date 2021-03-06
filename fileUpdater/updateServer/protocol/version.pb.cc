// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocol/version.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "protocol/version.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* version_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  version_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_protocol_2fversion_2eproto() {
  protobuf_AddDesc_protocol_2fversion_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "protocol/version.proto");
  GOOGLE_CHECK(file != NULL);
  version_descriptor_ = file->message_type(0);
  static const int version_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(version, ver_),
  };
  version_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      version_descriptor_,
      version::default_instance_,
      version_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(version, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(version, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(version));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_protocol_2fversion_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    version_descriptor_, &version::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_protocol_2fversion_2eproto() {
  delete version::default_instance_;
  delete version_reflection_;
}

void protobuf_AddDesc_protocol_2fversion_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026protocol/version.proto\"\026\n\007version\022\013\n\003v"
    "er\030\001 \002(\t", 48);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protocol/version.proto", &protobuf_RegisterTypes);
  version::default_instance_ = new version();
  version::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_protocol_2fversion_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_protocol_2fversion_2eproto {
  StaticDescriptorInitializer_protocol_2fversion_2eproto() {
    protobuf_AddDesc_protocol_2fversion_2eproto();
  }
} static_descriptor_initializer_protocol_2fversion_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int version::kVerFieldNumber;
#endif  // !_MSC_VER

version::version()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void version::InitAsDefaultInstance() {
}

version::version(const version& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void version::SharedCtor() {
  _cached_size_ = 0;
  ver_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

version::~version() {
  SharedDtor();
}

void version::SharedDtor() {
  if (ver_ != &::google::protobuf::internal::kEmptyString) {
    delete ver_;
  }
  if (this != default_instance_) {
  }
}

void version::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* version::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return version_descriptor_;
}

const version& version::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protocol_2fversion_2eproto();
  return *default_instance_;
}

version* version::default_instance_ = NULL;

version* version::New() const {
  return new version;
}

void version::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_ver()) {
      if (ver_ != &::google::protobuf::internal::kEmptyString) {
        ver_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool version::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string ver = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_ver()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->ver().data(), this->ver().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void version::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string ver = 1;
  if (has_ver()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->ver().data(), this->ver().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->ver(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* version::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string ver = 1;
  if (has_ver()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->ver().data(), this->ver().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->ver(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int version::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string ver = 1;
    if (has_ver()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->ver());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void version::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const version* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const version*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void version::MergeFrom(const version& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_ver()) {
      set_ver(from.ver());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void version::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void version::CopyFrom(const version& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool version::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void version::Swap(version* other) {
  if (other != this) {
    std::swap(ver_, other->ver_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata version::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = version_descriptor_;
  metadata.reflection = version_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
