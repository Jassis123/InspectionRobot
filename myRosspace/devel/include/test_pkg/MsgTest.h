// Generated by gencpp from file test_pkg/MsgTest.msg
// DO NOT EDIT!


#ifndef TEST_PKG_MESSAGE_MSGTEST_H
#define TEST_PKG_MESSAGE_MSGTEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test_pkg
{
template <class ContainerAllocator>
struct MsgTest_
{
  typedef MsgTest_<ContainerAllocator> Type;

  MsgTest_()
    : stamp()
    , data(0)  {
    }
  MsgTest_(const ContainerAllocator& _alloc)
    : stamp()
    , data(0)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef int32_t _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::test_pkg::MsgTest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test_pkg::MsgTest_<ContainerAllocator> const> ConstPtr;

}; // struct MsgTest_

typedef ::test_pkg::MsgTest_<std::allocator<void> > MsgTest;

typedef boost::shared_ptr< ::test_pkg::MsgTest > MsgTestPtr;
typedef boost::shared_ptr< ::test_pkg::MsgTest const> MsgTestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test_pkg::MsgTest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test_pkg::MsgTest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::test_pkg::MsgTest_<ContainerAllocator1> & lhs, const ::test_pkg::MsgTest_<ContainerAllocator2> & rhs)
{
  return lhs.stamp == rhs.stamp &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::test_pkg::MsgTest_<ContainerAllocator1> & lhs, const ::test_pkg::MsgTest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace test_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::test_pkg::MsgTest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test_pkg::MsgTest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_pkg::MsgTest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test_pkg::MsgTest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_pkg::MsgTest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test_pkg::MsgTest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test_pkg::MsgTest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bc5a8a0aefee54a11d41536be86744a6";
  }

  static const char* value(const ::test_pkg::MsgTest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbc5a8a0aefee54a1ULL;
  static const uint64_t static_value2 = 0x1d41536be86744a6ULL;
};

template<class ContainerAllocator>
struct DataType< ::test_pkg::MsgTest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test_pkg/MsgTest";
  }

  static const char* value(const ::test_pkg::MsgTest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test_pkg::MsgTest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n"
"int32 data\n"
;
  }

  static const char* value(const ::test_pkg::MsgTest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test_pkg::MsgTest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MsgTest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test_pkg::MsgTest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test_pkg::MsgTest_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "data: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_PKG_MESSAGE_MSGTEST_H
