
#include "gen/GetWFAntennaElementOffsetResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetWFAntennaElementOffsetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetWFAntennaElementOffsetResult::CmdName = "GetWFAntennaElementOffsetResult";
    const char* const GetWFAntennaElementOffsetResult::Documentation = "Result of GetWFAntennaElementOffset.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetWFAntennaElementOffsetResult);


    GetWFAntennaElementOffsetResult::GetWFAntennaElementOffsetResult()
      : CommandResult(CmdName)
    {}

    GetWFAntennaElementOffsetResult::GetWFAntennaElementOffsetResult(double x, double y, double z, double yaw, double pitch, double roll, int element)
      : CommandResult(CmdName)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setElement(element);
    }

    GetWFAntennaElementOffsetResult::GetWFAntennaElementOffsetResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, int element)
      : CommandResult(CmdName, relatedCommand)
    {

      setX(x);
      setY(y);
      setZ(z);
      setYaw(yaw);
      setPitch(pitch);
      setRoll(roll);
      setElement(element);
    }


    GetWFAntennaElementOffsetResultPtr GetWFAntennaElementOffsetResult::create(double x, double y, double z, double yaw, double pitch, double roll, int element)
    {
      return std::make_shared<GetWFAntennaElementOffsetResult>(x, y, z, yaw, pitch, roll, element);
    }

    GetWFAntennaElementOffsetResultPtr GetWFAntennaElementOffsetResult::create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, int element)
    {
      return std::make_shared<GetWFAntennaElementOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll, element);
    }

    GetWFAntennaElementOffsetResultPtr GetWFAntennaElementOffsetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetWFAntennaElementOffsetResult>(ptr);
    }

    bool GetWFAntennaElementOffsetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["X"])
          && parse_json<double>::is_valid(m_values["Y"])
          && parse_json<double>::is_valid(m_values["Z"])
          && parse_json<double>::is_valid(m_values["Yaw"])
          && parse_json<double>::is_valid(m_values["Pitch"])
          && parse_json<double>::is_valid(m_values["Roll"])
          && parse_json<int>::is_valid(m_values["Element"])
        ;

    }

    std::string GetWFAntennaElementOffsetResult::documentation() const { return Documentation; }


    double GetWFAntennaElementOffsetResult::x() const
    {
      return parse_json<double>::parse(m_values["X"]);
    }

    void GetWFAntennaElementOffsetResult::setX(double x)
    {
      m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaElementOffsetResult::y() const
    {
      return parse_json<double>::parse(m_values["Y"]);
    }

    void GetWFAntennaElementOffsetResult::setY(double y)
    {
      m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaElementOffsetResult::z() const
    {
      return parse_json<double>::parse(m_values["Z"]);
    }

    void GetWFAntennaElementOffsetResult::setZ(double z)
    {
      m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaElementOffsetResult::yaw() const
    {
      return parse_json<double>::parse(m_values["Yaw"]);
    }

    void GetWFAntennaElementOffsetResult::setYaw(double yaw)
    {
      m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaElementOffsetResult::pitch() const
    {
      return parse_json<double>::parse(m_values["Pitch"]);
    }

    void GetWFAntennaElementOffsetResult::setPitch(double pitch)
    {
      m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetWFAntennaElementOffsetResult::roll() const
    {
      return parse_json<double>::parse(m_values["Roll"]);
    }

    void GetWFAntennaElementOffsetResult::setRoll(double roll)
    {
      m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetWFAntennaElementOffsetResult::element() const
    {
      return parse_json<int>::parse(m_values["Element"]);
    }

    void GetWFAntennaElementOffsetResult::setElement(int element)
    {
      m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
