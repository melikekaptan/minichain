// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: block.proto

#include "block.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_transaction_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_TimeStamp_transaction_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_transaction_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_Transaction_transaction_2eproto;
namespace bchain {
class BlockDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Block> _instance;
} _Block_default_instance_;
}  // namespace bchain
static void InitDefaultsscc_info_Block_block_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::bchain::_Block_default_instance_;
    new (ptr) ::bchain::Block();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::bchain::Block::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_Block_block_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_Block_block_2eproto}, {
      &scc_info_Transaction_transaction_2eproto.base,
      &scc_info_TimeStamp_transaction_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_block_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_block_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_block_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_block_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::bchain::Block, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::bchain::Block, id_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, proof_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, previous_hash_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, previous_block_id_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, transactionlist_),
  PROTOBUF_FIELD_OFFSET(::bchain::Block, timestamp_),
  3,
  0,
  1,
  4,
  ~0u,
  2,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::bchain::Block)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::bchain::_Block_default_instance_),
};

const char descriptor_table_protodef_block_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013block.proto\022\006bchain\032\021transaction.proto"
  "\"\250\001\n\005Block\022\n\n\002id\030\001 \001(\003\022\r\n\005proof\030\002 \001(\t\022\025\n"
  "\rprevious_hash\030\003 \001(\t\022\031\n\021previous_block_i"
  "d\030\004 \001(\003\022,\n\017transactionList\030\005 \003(\0132\023.bchai"
  "n.Transaction\022$\n\ttimestamp\030\006 \001(\0132\021.bchai"
  "n.TimeStamp"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_block_2eproto_deps[1] = {
  &::descriptor_table_transaction_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_block_2eproto_sccs[1] = {
  &scc_info_Block_block_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_block_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_block_2eproto = {
  false, false, descriptor_table_protodef_block_2eproto, "block.proto", 211,
  &descriptor_table_block_2eproto_once, descriptor_table_block_2eproto_sccs, descriptor_table_block_2eproto_deps, 1, 1,
  schemas, file_default_instances, TableStruct_block_2eproto::offsets,
  file_level_metadata_block_2eproto, 1, file_level_enum_descriptors_block_2eproto, file_level_service_descriptors_block_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_block_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_block_2eproto)), true);
namespace bchain {

// ===================================================================

void Block::InitAsDefaultInstance() {
  ::bchain::_Block_default_instance_._instance.get_mutable()->timestamp_ = const_cast< ::bchain::TimeStamp*>(
      ::bchain::TimeStamp::internal_default_instance());
}
class Block::_Internal {
 public:
  using HasBits = decltype(std::declval<Block>()._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 8u;
  }
  static void set_has_proof(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_previous_hash(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_previous_block_id(HasBits* has_bits) {
    (*has_bits)[0] |= 16u;
  }
  static const ::bchain::TimeStamp& timestamp(const Block* msg);
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
};

const ::bchain::TimeStamp&
Block::_Internal::timestamp(const Block* msg) {
  return *msg->timestamp_;
}
void Block::clear_transactionlist() {
  transactionlist_.Clear();
}
void Block::clear_timestamp() {
  if (timestamp_ != nullptr) timestamp_->Clear();
  _has_bits_[0] &= ~0x00000004u;
}
Block::Block(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  transactionlist_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:bchain.Block)
}
Block::Block(const Block& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_),
      transactionlist_(from.transactionlist_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  proof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_proof()) {
    proof_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_proof(),
      GetArena());
  }
  previous_hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from._internal_has_previous_hash()) {
    previous_hash_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_previous_hash(),
      GetArena());
  }
  if (from._internal_has_timestamp()) {
    timestamp_ = new ::bchain::TimeStamp(*from.timestamp_);
  } else {
    timestamp_ = nullptr;
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&previous_block_id_) -
    reinterpret_cast<char*>(&id_)) + sizeof(previous_block_id_));
  // @@protoc_insertion_point(copy_constructor:bchain.Block)
}

void Block::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Block_block_2eproto.base);
  proof_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  previous_hash_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&timestamp_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&previous_block_id_) -
      reinterpret_cast<char*>(&timestamp_)) + sizeof(previous_block_id_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:bchain.Block)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Block::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  proof_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  previous_hash_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete timestamp_;
}

void Block::ArenaDtor(void* object) {
  Block* _this = reinterpret_cast< Block* >(object);
  (void)_this;
}
void Block::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Block& Block::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Block_block_2eproto.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:bchain.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  transactionlist_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      proof_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000002u) {
      previous_hash_.ClearNonDefaultToEmpty();
    }
    if (cached_has_bits & 0x00000004u) {
      GOOGLE_DCHECK(timestamp_ != nullptr);
      timestamp_->Clear();
    }
  }
  if (cached_has_bits & 0x00000018u) {
    ::memset(&id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&previous_block_id_) -
        reinterpret_cast<char*>(&id_)) + sizeof(previous_block_id_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Block::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // optional int64 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_id(&has_bits);
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string proof = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_proof();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bchain.Block.proof");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional string previous_hash = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_previous_hash();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          #ifndef NDEBUG
          ::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "bchain.Block.previous_hash");
          #endif  // !NDEBUG
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // optional int64 previous_block_id = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 32)) {
          _Internal::set_has_previous_block_id(&has_bits);
          previous_block_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .bchain.Transaction transactionList = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_transactionlist(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else goto handle_unusual;
        continue;
      // optional .bchain.TimeStamp timestamp = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 50)) {
          ptr = ctx->ParseMessage(_internal_mutable_timestamp(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* Block::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:bchain.Block)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional int64 id = 1;
  if (cached_has_bits & 0x00000008u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_id(), target);
  }

  // optional string proof = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_proof().data(), static_cast<int>(this->_internal_proof().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bchain.Block.proof");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_proof(), target);
  }

  // optional string previous_hash = 3;
  if (cached_has_bits & 0x00000002u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_previous_hash().data(), static_cast<int>(this->_internal_previous_hash().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "bchain.Block.previous_hash");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_previous_hash(), target);
  }

  // optional int64 previous_block_id = 4;
  if (cached_has_bits & 0x00000010u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(4, this->_internal_previous_block_id(), target);
  }

  // repeated .bchain.Transaction transactionList = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_transactionlist_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(5, this->_internal_transactionlist(i), target, stream);
  }

  // optional .bchain.TimeStamp timestamp = 6;
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        6, _Internal::timestamp(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:bchain.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:bchain.Block)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .bchain.Transaction transactionList = 5;
  total_size += 1UL * this->_internal_transactionlist_size();
  for (const auto& msg : this->transactionlist_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    // optional string proof = 2;
    if (cached_has_bits & 0x00000001u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_proof());
    }

    // optional string previous_hash = 3;
    if (cached_has_bits & 0x00000002u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_previous_hash());
    }

    // optional .bchain.TimeStamp timestamp = 6;
    if (cached_has_bits & 0x00000004u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
          *timestamp_);
    }

    // optional int64 id = 1;
    if (cached_has_bits & 0x00000008u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_id());
    }

    // optional int64 previous_block_id = 4;
    if (cached_has_bits & 0x00000010u) {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_previous_block_id());
    }

  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:bchain.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Block>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:bchain.Block)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:bchain.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:bchain.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  transactionlist_.MergeFrom(from.transactionlist_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 0x0000001fu) {
    if (cached_has_bits & 0x00000001u) {
      _internal_set_proof(from._internal_proof());
    }
    if (cached_has_bits & 0x00000002u) {
      _internal_set_previous_hash(from._internal_previous_hash());
    }
    if (cached_has_bits & 0x00000004u) {
      _internal_mutable_timestamp()->::bchain::TimeStamp::MergeFrom(from._internal_timestamp());
    }
    if (cached_has_bits & 0x00000008u) {
      id_ = from.id_;
    }
    if (cached_has_bits & 0x00000010u) {
      previous_block_id_ = from.previous_block_id_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Block::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:bchain.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:bchain.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::InternalSwap(Block* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  transactionlist_.InternalSwap(&other->transactionlist_);
  proof_.Swap(&other->proof_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  previous_hash_.Swap(&other->previous_hash_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Block, previous_block_id_)
      + sizeof(Block::previous_block_id_)
      - PROTOBUF_FIELD_OFFSET(Block, timestamp_)>(
          reinterpret_cast<char*>(&timestamp_),
          reinterpret_cast<char*>(&other->timestamp_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Block::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace bchain
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::bchain::Block* Arena::CreateMaybeMessage< ::bchain::Block >(Arena* arena) {
  return Arena::CreateMessageInternal< ::bchain::Block >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
