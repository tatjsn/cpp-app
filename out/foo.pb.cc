// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: foo.proto

#include "foo.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class FooDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Foo> _instance;
} _Foo_default_instance_;
static void InitDefaultsscc_info_Foo_foo_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::_Foo_default_instance_;
    new (ptr) ::Foo();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Foo::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Foo_foo_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Foo_foo_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_foo_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_foo_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_foo_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_foo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::Foo, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::Foo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::Foo, id_),
  PROTOBUF_FIELD_OFFSET(::Foo, bar_),
  PROTOBUF_FIELD_OFFSET(::Foo, baz_),
  1,
  0,
  2,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 8, sizeof(::Foo)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::_Foo_default_instance_),
};

const char descriptor_table_protodef_foo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\tfoo.proto\"+\n\003Foo\022\n\n\002id\030\001 \002(\005\022\013\n\003bar\030\002 "
  "\002(\t\022\013\n\003baz\030\003 \002(\005"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_foo_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_foo_2eproto_sccs[1] = {
  &scc_info_Foo_foo_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_foo_2eproto_once;
static bool descriptor_table_foo_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_foo_2eproto = {
  &descriptor_table_foo_2eproto_initialized, descriptor_table_protodef_foo_2eproto, "foo.proto", 56,
  &descriptor_table_foo_2eproto_once, descriptor_table_foo_2eproto_sccs, descriptor_table_foo_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_foo_2eproto::offsets,
  file_level_metadata_foo_2eproto, 1, file_level_enum_descriptors_foo_2eproto, file_level_service_descriptors_foo_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_foo_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_foo_2eproto), true);

// ===================================================================

void Foo::InitAsDefaultInstance() {
}
class Foo::_Internal {
 public:
  using HasBits = decltype(std::declval<Foo>()._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_bar(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_baz(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

Foo::Foo()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:Foo)
}
Foo::Foo(const Foo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  bar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_bar()) {
    bar_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.bar_);
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&baz_) -
    reinterpret_cast<char*>(&id_)) + sizeof(baz_));
  // @@protoc_insertion_point(copy_constructor:Foo)
}

void Foo::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Foo_foo_2eproto.base);
  bar_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&baz_) -
      reinterpret_cast<char*>(&id_)) + sizeof(baz_));
}

Foo::~Foo() {
  // @@protoc_insertion_point(destructor:Foo)
  SharedDtor();
}

void Foo::SharedDtor() {
  bar_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Foo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Foo& Foo::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Foo_foo_2eproto.base);
  return *internal_default_instance();
}


void Foo::Clear() {
// @@protoc_insertion_point(message_clear_start:Foo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    bar_.ClearNonDefaultToEmptyNoArena();
  }
  if (cached_has_bits & 0x00000006u) {
    ::memset(&id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&baz_) -
        reinterpret_cast<char*>(&id_)) + sizeof(baz_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

const char* Foo::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required string bar = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_bar();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Foo.bar");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // required int32 baz = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          _Internal::set_has_baz(&has_bits);
          baz_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* Foo::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Foo)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // required string bar = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_bar().data(), static_cast<int>(this->_internal_bar().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "Foo.bar");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_bar(), target);
  }

  // required int32 baz = 3;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_baz(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Foo)
  return target;
}

size_t Foo::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:Foo)
  size_t total_size = 0;

  if (_internal_has_bar()) {
    // required string bar = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_bar());
  }

  if (_internal_has_id()) {
    // required int32 id = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());
  }

  if (_internal_has_baz()) {
    // required int32 baz = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_baz());
  }

  return total_size;
}
size_t Foo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Foo)
  size_t total_size = 0;

  if (((_has_bits_[0] & 0x00000007) ^ 0x00000007) == 0) {  // All required fields are present.
    // required string bar = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_bar());

    // required int32 id = 1;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_id());

    // required int32 baz = 3;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_baz());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Foo::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Foo)
  GOOGLE_DCHECK_NE(&from, this);
  const Foo* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Foo>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Foo)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Foo)
    MergeFrom(*source);
  }
}

void Foo::MergeFrom(const Foo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Foo)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _has_bits_[0] |= 0x00000001u;
      bar_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.bar_);
    }
    if (cached_has_bits & 0x00000002u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000004u) {
      baz_ = from.baz_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Foo::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Foo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Foo::CopyFrom(const Foo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Foo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Foo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  return true;
}

void Foo::InternalSwap(Foo* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  bar_.Swap(&other->bar_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(id_, other->id_);
  swap(baz_, other->baz_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Foo::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Foo* Arena::CreateMaybeMessage< ::Foo >(Arena* arena) {
  return Arena::CreateInternal< ::Foo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
