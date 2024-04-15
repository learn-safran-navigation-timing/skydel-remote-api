
#include "SetPps0GpsTime.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPps0GpsTime
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPps0GpsTime::CmdName = "SetPps0GpsTime";
    const char* const SetPps0GpsTime::Documentation = "Set the 0th PPS' date time\n"
      "\n"
      "Name    Type     Description\n"
      "------- -------- --------------------------------------------------------------\n"
      "GpsTime datetime GPS date and time (it is the GPS time expressed in UTC format)";
    const char* const SetPps0GpsTime::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPps0GpsTime);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPps0GpsTime);


    SetPps0GpsTime::SetPps0GpsTime()
      : CommandBase(CmdName, TargetId)
    {}

    SetPps0GpsTime::SetPps0GpsTime(const Sdx::DateTime& gpsTime)
      : CommandBase(CmdName, TargetId)
    {

      setGpsTime(gpsTime);
    }

    SetPps0GpsTimePtr SetPps0GpsTime::create(const Sdx::DateTime& gpsTime)
    {
      return std::make_shared<SetPps0GpsTime>(gpsTime);
    }

    SetPps0GpsTimePtr SetPps0GpsTime::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPps0GpsTime>(ptr);
    }

    bool SetPps0GpsTime::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<Sdx::DateTime>::is_valid(m_values["GpsTime"])
        ;

    }

    std::string SetPps0GpsTime::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPps0GpsTime::fieldNames() const 
    { 
      static const std::vector<std::string> names {"GpsTime"}; 
      return names; 
    }


    int SetPps0GpsTime::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    Sdx::DateTime SetPps0GpsTime::gpsTime() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["GpsTime"]);
    }

    void SetPps0GpsTime::setGpsTime(const Sdx::DateTime& gpsTime)
    {
      m_values.AddMember("GpsTime", parse_json<Sdx::DateTime>::format(gpsTime, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
