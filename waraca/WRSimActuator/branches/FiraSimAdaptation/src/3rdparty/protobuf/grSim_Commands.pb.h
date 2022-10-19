// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: grSim_Commands.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_grSim_5fCommands_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_grSim_5fCommands_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_grSim_5fCommands_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_grSim_5fCommands_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_grSim_5fCommands_2eproto;
class grSim_Commands;
struct grSim_CommandsDefaultTypeInternal;
extern grSim_CommandsDefaultTypeInternal _grSim_Commands_default_instance_;
class grSim_Robot_Command;
struct grSim_Robot_CommandDefaultTypeInternal;
extern grSim_Robot_CommandDefaultTypeInternal _grSim_Robot_Command_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::grSim_Commands* Arena::CreateMaybeMessage<::grSim_Commands>(Arena*);
template<> ::grSim_Robot_Command* Arena::CreateMaybeMessage<::grSim_Robot_Command>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class grSim_Robot_Command final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:grSim_Robot_Command) */ {
 public:
  inline grSim_Robot_Command() : grSim_Robot_Command(nullptr) {}
  ~grSim_Robot_Command() override;
  explicit constexpr grSim_Robot_Command(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  grSim_Robot_Command(const grSim_Robot_Command& from);
  grSim_Robot_Command(grSim_Robot_Command&& from) noexcept
    : grSim_Robot_Command() {
    *this = ::std::move(from);
  }

  inline grSim_Robot_Command& operator=(const grSim_Robot_Command& from) {
    CopyFrom(from);
    return *this;
  }
  inline grSim_Robot_Command& operator=(grSim_Robot_Command&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const grSim_Robot_Command& default_instance() {
    return *internal_default_instance();
  }
  static inline const grSim_Robot_Command* internal_default_instance() {
    return reinterpret_cast<const grSim_Robot_Command*>(
               &_grSim_Robot_Command_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(grSim_Robot_Command& a, grSim_Robot_Command& b) {
    a.Swap(&b);
  }
  inline void Swap(grSim_Robot_Command* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(grSim_Robot_Command* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  grSim_Robot_Command* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<grSim_Robot_Command>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const grSim_Robot_Command& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const grSim_Robot_Command& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(grSim_Robot_Command* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "grSim_Robot_Command";
  }
  protected:
  explicit grSim_Robot_Command(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
    kKickspeedxFieldNumber = 2,
    kKickspeedzFieldNumber = 3,
    kVeltangentFieldNumber = 4,
    kVelnormalFieldNumber = 5,
    kVelangularFieldNumber = 6,
    kSpinnerFieldNumber = 7,
    kWheelsspeedFieldNumber = 8,
    kWheel1FieldNumber = 9,
    kWheel2FieldNumber = 10,
    kWheel3FieldNumber = 11,
    kWheel4FieldNumber = 12,
  };
  // required uint32 id = 1;
  bool has_id() const;
  private:
  bool _internal_has_id() const;
  public:
  void clear_id();
  uint32_t id() const;
  void set_id(uint32_t value);
  private:
  uint32_t _internal_id() const;
  void _internal_set_id(uint32_t value);
  public:

  // required float kickspeedx = 2;
  bool has_kickspeedx() const;
  private:
  bool _internal_has_kickspeedx() const;
  public:
  void clear_kickspeedx();
  float kickspeedx() const;
  void set_kickspeedx(float value);
  private:
  float _internal_kickspeedx() const;
  void _internal_set_kickspeedx(float value);
  public:

  // required float kickspeedz = 3;
  bool has_kickspeedz() const;
  private:
  bool _internal_has_kickspeedz() const;
  public:
  void clear_kickspeedz();
  float kickspeedz() const;
  void set_kickspeedz(float value);
  private:
  float _internal_kickspeedz() const;
  void _internal_set_kickspeedz(float value);
  public:

  // required float veltangent = 4;
  bool has_veltangent() const;
  private:
  bool _internal_has_veltangent() const;
  public:
  void clear_veltangent();
  float veltangent() const;
  void set_veltangent(float value);
  private:
  float _internal_veltangent() const;
  void _internal_set_veltangent(float value);
  public:

  // required float velnormal = 5;
  bool has_velnormal() const;
  private:
  bool _internal_has_velnormal() const;
  public:
  void clear_velnormal();
  float velnormal() const;
  void set_velnormal(float value);
  private:
  float _internal_velnormal() const;
  void _internal_set_velnormal(float value);
  public:

  // required float velangular = 6;
  bool has_velangular() const;
  private:
  bool _internal_has_velangular() const;
  public:
  void clear_velangular();
  float velangular() const;
  void set_velangular(float value);
  private:
  float _internal_velangular() const;
  void _internal_set_velangular(float value);
  public:

  // required bool spinner = 7;
  bool has_spinner() const;
  private:
  bool _internal_has_spinner() const;
  public:
  void clear_spinner();
  bool spinner() const;
  void set_spinner(bool value);
  private:
  bool _internal_spinner() const;
  void _internal_set_spinner(bool value);
  public:

  // required bool wheelsspeed = 8;
  bool has_wheelsspeed() const;
  private:
  bool _internal_has_wheelsspeed() const;
  public:
  void clear_wheelsspeed();
  bool wheelsspeed() const;
  void set_wheelsspeed(bool value);
  private:
  bool _internal_wheelsspeed() const;
  void _internal_set_wheelsspeed(bool value);
  public:

  // optional float wheel1 = 9;
  bool has_wheel1() const;
  private:
  bool _internal_has_wheel1() const;
  public:
  void clear_wheel1();
  float wheel1() const;
  void set_wheel1(float value);
  private:
  float _internal_wheel1() const;
  void _internal_set_wheel1(float value);
  public:

  // optional float wheel2 = 10;
  bool has_wheel2() const;
  private:
  bool _internal_has_wheel2() const;
  public:
  void clear_wheel2();
  float wheel2() const;
  void set_wheel2(float value);
  private:
  float _internal_wheel2() const;
  void _internal_set_wheel2(float value);
  public:

  // optional float wheel3 = 11;
  bool has_wheel3() const;
  private:
  bool _internal_has_wheel3() const;
  public:
  void clear_wheel3();
  float wheel3() const;
  void set_wheel3(float value);
  private:
  float _internal_wheel3() const;
  void _internal_set_wheel3(float value);
  public:

  // optional float wheel4 = 12;
  bool has_wheel4() const;
  private:
  bool _internal_has_wheel4() const;
  public:
  void clear_wheel4();
  float wheel4() const;
  void set_wheel4(float value);
  private:
  float _internal_wheel4() const;
  void _internal_set_wheel4(float value);
  public:

  // @@protoc_insertion_point(class_scope:grSim_Robot_Command)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint32_t id_;
  float kickspeedx_;
  float kickspeedz_;
  float veltangent_;
  float velnormal_;
  float velangular_;
  bool spinner_;
  bool wheelsspeed_;
  float wheel1_;
  float wheel2_;
  float wheel3_;
  float wheel4_;
  friend struct ::TableStruct_grSim_5fCommands_2eproto;
};
// -------------------------------------------------------------------

class grSim_Commands final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:grSim_Commands) */ {
 public:
  inline grSim_Commands() : grSim_Commands(nullptr) {}
  ~grSim_Commands() override;
  explicit constexpr grSim_Commands(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  grSim_Commands(const grSim_Commands& from);
  grSim_Commands(grSim_Commands&& from) noexcept
    : grSim_Commands() {
    *this = ::std::move(from);
  }

  inline grSim_Commands& operator=(const grSim_Commands& from) {
    CopyFrom(from);
    return *this;
  }
  inline grSim_Commands& operator=(grSim_Commands&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const grSim_Commands& default_instance() {
    return *internal_default_instance();
  }
  static inline const grSim_Commands* internal_default_instance() {
    return reinterpret_cast<const grSim_Commands*>(
               &_grSim_Commands_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(grSim_Commands& a, grSim_Commands& b) {
    a.Swap(&b);
  }
  inline void Swap(grSim_Commands* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(grSim_Commands* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  grSim_Commands* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<grSim_Commands>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const grSim_Commands& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const grSim_Commands& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(grSim_Commands* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "grSim_Commands";
  }
  protected:
  explicit grSim_Commands(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kRobotCommandsFieldNumber = 3,
    kTimestampFieldNumber = 1,
    kIsteamyellowFieldNumber = 2,
  };
  // repeated .grSim_Robot_Command robot_commands = 3;
  int robot_commands_size() const;
  private:
  int _internal_robot_commands_size() const;
  public:
  void clear_robot_commands();
  ::grSim_Robot_Command* mutable_robot_commands(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::grSim_Robot_Command >*
      mutable_robot_commands();
  private:
  const ::grSim_Robot_Command& _internal_robot_commands(int index) const;
  ::grSim_Robot_Command* _internal_add_robot_commands();
  public:
  const ::grSim_Robot_Command& robot_commands(int index) const;
  ::grSim_Robot_Command* add_robot_commands();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::grSim_Robot_Command >&
      robot_commands() const;

  // required double timestamp = 1;
  bool has_timestamp() const;
  private:
  bool _internal_has_timestamp() const;
  public:
  void clear_timestamp();
  double timestamp() const;
  void set_timestamp(double value);
  private:
  double _internal_timestamp() const;
  void _internal_set_timestamp(double value);
  public:

  // required bool isteamyellow = 2;
  bool has_isteamyellow() const;
  private:
  bool _internal_has_isteamyellow() const;
  public:
  void clear_isteamyellow();
  bool isteamyellow() const;
  void set_isteamyellow(bool value);
  private:
  bool _internal_isteamyellow() const;
  void _internal_set_isteamyellow(bool value);
  public:

  // @@protoc_insertion_point(class_scope:grSim_Commands)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::grSim_Robot_Command > robot_commands_;
  double timestamp_;
  bool isteamyellow_;
  friend struct ::TableStruct_grSim_5fCommands_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// grSim_Robot_Command

// required uint32 id = 1;
inline bool grSim_Robot_Command::_internal_has_id() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_id() const {
  return _internal_has_id();
}
inline void grSim_Robot_Command::clear_id() {
  id_ = 0u;
  _has_bits_[0] &= ~0x00000001u;
}
inline uint32_t grSim_Robot_Command::_internal_id() const {
  return id_;
}
inline uint32_t grSim_Robot_Command::id() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.id)
  return _internal_id();
}
inline void grSim_Robot_Command::_internal_set_id(uint32_t value) {
  _has_bits_[0] |= 0x00000001u;
  id_ = value;
}
inline void grSim_Robot_Command::set_id(uint32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.id)
}

// required float kickspeedx = 2;
inline bool grSim_Robot_Command::_internal_has_kickspeedx() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_kickspeedx() const {
  return _internal_has_kickspeedx();
}
inline void grSim_Robot_Command::clear_kickspeedx() {
  kickspeedx_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline float grSim_Robot_Command::_internal_kickspeedx() const {
  return kickspeedx_;
}
inline float grSim_Robot_Command::kickspeedx() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.kickspeedx)
  return _internal_kickspeedx();
}
inline void grSim_Robot_Command::_internal_set_kickspeedx(float value) {
  _has_bits_[0] |= 0x00000002u;
  kickspeedx_ = value;
}
inline void grSim_Robot_Command::set_kickspeedx(float value) {
  _internal_set_kickspeedx(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.kickspeedx)
}

// required float kickspeedz = 3;
inline bool grSim_Robot_Command::_internal_has_kickspeedz() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_kickspeedz() const {
  return _internal_has_kickspeedz();
}
inline void grSim_Robot_Command::clear_kickspeedz() {
  kickspeedz_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline float grSim_Robot_Command::_internal_kickspeedz() const {
  return kickspeedz_;
}
inline float grSim_Robot_Command::kickspeedz() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.kickspeedz)
  return _internal_kickspeedz();
}
inline void grSim_Robot_Command::_internal_set_kickspeedz(float value) {
  _has_bits_[0] |= 0x00000004u;
  kickspeedz_ = value;
}
inline void grSim_Robot_Command::set_kickspeedz(float value) {
  _internal_set_kickspeedz(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.kickspeedz)
}

// required float veltangent = 4;
inline bool grSim_Robot_Command::_internal_has_veltangent() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_veltangent() const {
  return _internal_has_veltangent();
}
inline void grSim_Robot_Command::clear_veltangent() {
  veltangent_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline float grSim_Robot_Command::_internal_veltangent() const {
  return veltangent_;
}
inline float grSim_Robot_Command::veltangent() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.veltangent)
  return _internal_veltangent();
}
inline void grSim_Robot_Command::_internal_set_veltangent(float value) {
  _has_bits_[0] |= 0x00000008u;
  veltangent_ = value;
}
inline void grSim_Robot_Command::set_veltangent(float value) {
  _internal_set_veltangent(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.veltangent)
}

// required float velnormal = 5;
inline bool grSim_Robot_Command::_internal_has_velnormal() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_velnormal() const {
  return _internal_has_velnormal();
}
inline void grSim_Robot_Command::clear_velnormal() {
  velnormal_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline float grSim_Robot_Command::_internal_velnormal() const {
  return velnormal_;
}
inline float grSim_Robot_Command::velnormal() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.velnormal)
  return _internal_velnormal();
}
inline void grSim_Robot_Command::_internal_set_velnormal(float value) {
  _has_bits_[0] |= 0x00000010u;
  velnormal_ = value;
}
inline void grSim_Robot_Command::set_velnormal(float value) {
  _internal_set_velnormal(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.velnormal)
}

// required float velangular = 6;
inline bool grSim_Robot_Command::_internal_has_velangular() const {
  bool value = (_has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_velangular() const {
  return _internal_has_velangular();
}
inline void grSim_Robot_Command::clear_velangular() {
  velangular_ = 0;
  _has_bits_[0] &= ~0x00000020u;
}
inline float grSim_Robot_Command::_internal_velangular() const {
  return velangular_;
}
inline float grSim_Robot_Command::velangular() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.velangular)
  return _internal_velangular();
}
inline void grSim_Robot_Command::_internal_set_velangular(float value) {
  _has_bits_[0] |= 0x00000020u;
  velangular_ = value;
}
inline void grSim_Robot_Command::set_velangular(float value) {
  _internal_set_velangular(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.velangular)
}

// required bool spinner = 7;
inline bool grSim_Robot_Command::_internal_has_spinner() const {
  bool value = (_has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_spinner() const {
  return _internal_has_spinner();
}
inline void grSim_Robot_Command::clear_spinner() {
  spinner_ = false;
  _has_bits_[0] &= ~0x00000040u;
}
inline bool grSim_Robot_Command::_internal_spinner() const {
  return spinner_;
}
inline bool grSim_Robot_Command::spinner() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.spinner)
  return _internal_spinner();
}
inline void grSim_Robot_Command::_internal_set_spinner(bool value) {
  _has_bits_[0] |= 0x00000040u;
  spinner_ = value;
}
inline void grSim_Robot_Command::set_spinner(bool value) {
  _internal_set_spinner(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.spinner)
}

// required bool wheelsspeed = 8;
inline bool grSim_Robot_Command::_internal_has_wheelsspeed() const {
  bool value = (_has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_wheelsspeed() const {
  return _internal_has_wheelsspeed();
}
inline void grSim_Robot_Command::clear_wheelsspeed() {
  wheelsspeed_ = false;
  _has_bits_[0] &= ~0x00000080u;
}
inline bool grSim_Robot_Command::_internal_wheelsspeed() const {
  return wheelsspeed_;
}
inline bool grSim_Robot_Command::wheelsspeed() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.wheelsspeed)
  return _internal_wheelsspeed();
}
inline void grSim_Robot_Command::_internal_set_wheelsspeed(bool value) {
  _has_bits_[0] |= 0x00000080u;
  wheelsspeed_ = value;
}
inline void grSim_Robot_Command::set_wheelsspeed(bool value) {
  _internal_set_wheelsspeed(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.wheelsspeed)
}

// optional float wheel1 = 9;
inline bool grSim_Robot_Command::_internal_has_wheel1() const {
  bool value = (_has_bits_[0] & 0x00000100u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_wheel1() const {
  return _internal_has_wheel1();
}
inline void grSim_Robot_Command::clear_wheel1() {
  wheel1_ = 0;
  _has_bits_[0] &= ~0x00000100u;
}
inline float grSim_Robot_Command::_internal_wheel1() const {
  return wheel1_;
}
inline float grSim_Robot_Command::wheel1() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.wheel1)
  return _internal_wheel1();
}
inline void grSim_Robot_Command::_internal_set_wheel1(float value) {
  _has_bits_[0] |= 0x00000100u;
  wheel1_ = value;
}
inline void grSim_Robot_Command::set_wheel1(float value) {
  _internal_set_wheel1(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.wheel1)
}

// optional float wheel2 = 10;
inline bool grSim_Robot_Command::_internal_has_wheel2() const {
  bool value = (_has_bits_[0] & 0x00000200u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_wheel2() const {
  return _internal_has_wheel2();
}
inline void grSim_Robot_Command::clear_wheel2() {
  wheel2_ = 0;
  _has_bits_[0] &= ~0x00000200u;
}
inline float grSim_Robot_Command::_internal_wheel2() const {
  return wheel2_;
}
inline float grSim_Robot_Command::wheel2() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.wheel2)
  return _internal_wheel2();
}
inline void grSim_Robot_Command::_internal_set_wheel2(float value) {
  _has_bits_[0] |= 0x00000200u;
  wheel2_ = value;
}
inline void grSim_Robot_Command::set_wheel2(float value) {
  _internal_set_wheel2(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.wheel2)
}

// optional float wheel3 = 11;
inline bool grSim_Robot_Command::_internal_has_wheel3() const {
  bool value = (_has_bits_[0] & 0x00000400u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_wheel3() const {
  return _internal_has_wheel3();
}
inline void grSim_Robot_Command::clear_wheel3() {
  wheel3_ = 0;
  _has_bits_[0] &= ~0x00000400u;
}
inline float grSim_Robot_Command::_internal_wheel3() const {
  return wheel3_;
}
inline float grSim_Robot_Command::wheel3() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.wheel3)
  return _internal_wheel3();
}
inline void grSim_Robot_Command::_internal_set_wheel3(float value) {
  _has_bits_[0] |= 0x00000400u;
  wheel3_ = value;
}
inline void grSim_Robot_Command::set_wheel3(float value) {
  _internal_set_wheel3(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.wheel3)
}

// optional float wheel4 = 12;
inline bool grSim_Robot_Command::_internal_has_wheel4() const {
  bool value = (_has_bits_[0] & 0x00000800u) != 0;
  return value;
}
inline bool grSim_Robot_Command::has_wheel4() const {
  return _internal_has_wheel4();
}
inline void grSim_Robot_Command::clear_wheel4() {
  wheel4_ = 0;
  _has_bits_[0] &= ~0x00000800u;
}
inline float grSim_Robot_Command::_internal_wheel4() const {
  return wheel4_;
}
inline float grSim_Robot_Command::wheel4() const {
  // @@protoc_insertion_point(field_get:grSim_Robot_Command.wheel4)
  return _internal_wheel4();
}
inline void grSim_Robot_Command::_internal_set_wheel4(float value) {
  _has_bits_[0] |= 0x00000800u;
  wheel4_ = value;
}
inline void grSim_Robot_Command::set_wheel4(float value) {
  _internal_set_wheel4(value);
  // @@protoc_insertion_point(field_set:grSim_Robot_Command.wheel4)
}

// -------------------------------------------------------------------

// grSim_Commands

// required double timestamp = 1;
inline bool grSim_Commands::_internal_has_timestamp() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool grSim_Commands::has_timestamp() const {
  return _internal_has_timestamp();
}
inline void grSim_Commands::clear_timestamp() {
  timestamp_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline double grSim_Commands::_internal_timestamp() const {
  return timestamp_;
}
inline double grSim_Commands::timestamp() const {
  // @@protoc_insertion_point(field_get:grSim_Commands.timestamp)
  return _internal_timestamp();
}
inline void grSim_Commands::_internal_set_timestamp(double value) {
  _has_bits_[0] |= 0x00000001u;
  timestamp_ = value;
}
inline void grSim_Commands::set_timestamp(double value) {
  _internal_set_timestamp(value);
  // @@protoc_insertion_point(field_set:grSim_Commands.timestamp)
}

// required bool isteamyellow = 2;
inline bool grSim_Commands::_internal_has_isteamyellow() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool grSim_Commands::has_isteamyellow() const {
  return _internal_has_isteamyellow();
}
inline void grSim_Commands::clear_isteamyellow() {
  isteamyellow_ = false;
  _has_bits_[0] &= ~0x00000002u;
}
inline bool grSim_Commands::_internal_isteamyellow() const {
  return isteamyellow_;
}
inline bool grSim_Commands::isteamyellow() const {
  // @@protoc_insertion_point(field_get:grSim_Commands.isteamyellow)
  return _internal_isteamyellow();
}
inline void grSim_Commands::_internal_set_isteamyellow(bool value) {
  _has_bits_[0] |= 0x00000002u;
  isteamyellow_ = value;
}
inline void grSim_Commands::set_isteamyellow(bool value) {
  _internal_set_isteamyellow(value);
  // @@protoc_insertion_point(field_set:grSim_Commands.isteamyellow)
}

// repeated .grSim_Robot_Command robot_commands = 3;
inline int grSim_Commands::_internal_robot_commands_size() const {
  return robot_commands_.size();
}
inline int grSim_Commands::robot_commands_size() const {
  return _internal_robot_commands_size();
}
inline void grSim_Commands::clear_robot_commands() {
  robot_commands_.Clear();
}
inline ::grSim_Robot_Command* grSim_Commands::mutable_robot_commands(int index) {
  // @@protoc_insertion_point(field_mutable:grSim_Commands.robot_commands)
  return robot_commands_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::grSim_Robot_Command >*
grSim_Commands::mutable_robot_commands() {
  // @@protoc_insertion_point(field_mutable_list:grSim_Commands.robot_commands)
  return &robot_commands_;
}
inline const ::grSim_Robot_Command& grSim_Commands::_internal_robot_commands(int index) const {
  return robot_commands_.Get(index);
}
inline const ::grSim_Robot_Command& grSim_Commands::robot_commands(int index) const {
  // @@protoc_insertion_point(field_get:grSim_Commands.robot_commands)
  return _internal_robot_commands(index);
}
inline ::grSim_Robot_Command* grSim_Commands::_internal_add_robot_commands() {
  return robot_commands_.Add();
}
inline ::grSim_Robot_Command* grSim_Commands::add_robot_commands() {
  ::grSim_Robot_Command* _add = _internal_add_robot_commands();
  // @@protoc_insertion_point(field_add:grSim_Commands.robot_commands)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::grSim_Robot_Command >&
grSim_Commands::robot_commands() const {
  // @@protoc_insertion_point(field_list:grSim_Commands.robot_commands)
  return robot_commands_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_grSim_5fCommands_2eproto
