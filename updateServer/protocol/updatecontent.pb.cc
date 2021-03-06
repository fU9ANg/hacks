// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protocol/updatecontent.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "protocol/updatecontent.pb.h"

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

const ::google::protobuf::Descriptor* updatecontent_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  updatecontent_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_protocol_2fupdatecontent_2eproto() {
  protobuf_AddDesc_protocol_2fupdatecontent_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "protocol/updatecontent.proto");
  GOOGLE_CHECK(file != NULL);
  updatecontent_descriptor_ = file->message_type(0);
  static const int updatecontent_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(updatecontent, xmlcontent_),
  };
  updatecontent_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      updatecontent_descriptor_,
      updatecontent::default_instance_,
      updatecontent_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(updatecontent, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(updatecontent, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(updatecontent));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_protocol_2fupdatecontent_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    updatecontent_descriptor_, &updatecontent::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_protocol_2fupdatecontent_2eproto() {
  delete updatecontent::default_instance_;
  delete updatecontent_reflection_;
}

void protobuf_AddDesc_protocol_2fupdatecontent_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034protocol/updatecontent.proto\"#\n\rupdate"
    "content\022\022\n\nxmlcontent\030\001 \002(\t", 67);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protocol/updatecontent.proto", &protobuf_RegisterTypes);
  updatecontent::default_instance_ = new updatecontent();
  updatecontent::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_protocol_2fupdatecontent_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_protocol_2fupdatecontent_2eproto {
  StaticDescriptorInitializer_protocol_2fupdatecontent_2eproto() {
    protobuf_AddDesc_protocol_2fupdatecontent_2eproto();
  }
} static_descriptor_initializer_protocol_2fupdatecontent_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int updatecontent::kXmlcontentFieldNumber;
#endif  // !_MSC_VER

updatecontent::updatecontent()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void updatecontent::InitAsDefaultInstance() {
}

updatecontent::updatecontent(const updatecontent& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void updatecontent::SharedCtor() {
  _cached_size_ = 0;
  xmlcontent_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

updatecontent::~updatecontent() {
  SharedDtor();
}

void updatecontent::SharedDtor() {
  if (xmlcontent_ != &::google::protobuf::internal::kEmptyString) {
    delete xmlcontent_;
  }
  if (this != default_instance_) {
  }
}

void updatecontent::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* updatecontent::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return updatecontent_descriptor_;
}

const updatecontent& updatecontent::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_protocol_2fupdatecontent_2eproto();
  return *default_instance_;
}

updatecontent* updatecontent::default_instance_ = NULL;

updatecontent* updatecontent::New() const {
  return new updatecontent;
}

void updatecontent::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_xmlcontent()) {
      if (xmlcontent_ != &::google::protobuf::internal::kEmptyString) {
        xmlcontent_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool updatecontent::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string xmlcontent = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_xmlcontent()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->xmlcontent().data(), this->xmlcontent().length(),
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

void updatecontent::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string xmlcontent = 1;
  if (has_xmlcontent()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->xmlcontent().data(), this->xmlcontent().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->xmlcontent(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* updatecontent::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string xmlcontent = 1;
  if (has_xmlcontent()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->xmlcontent().data(), this->xmlcontent().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->xmlcontent(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int updatecontent::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string xmlcontent = 1;
    if (has_xmlcontent()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->xmlcontent());
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

void updatecontent::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const updatecontent* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const updatecontent*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void updatecontent::MergeFrom(const updatecontent& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_xmlcontent()) {
      set_xmlcontent(from.xmlcontent());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void updatecontent::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void updatecontent::CopyFrom(const updatecontent& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool updatecontent::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void updatecontent::Swap(updatecontent* other) {
  if (other != this) {
    std::swap(xmlcontent_, other->xmlcontent_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata updatecontent::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = updatecontent_descriptor_;
  metadata.reflection = updatecontent_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
