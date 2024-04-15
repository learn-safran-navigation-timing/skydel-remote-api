
#include "SetAlmanacUploadTimeInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAlmanacUploadTimeInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAlmanacUploadTimeInterval::CmdName = "SetAlmanacUploadTimeInterval";
    const char* const SetAlmanacUploadTimeInterval::Documentation = "Set almanac upload interval in seconds. After the initial upload set with command \n"
      "SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ ----------------------------------------------------------\n"
      "System   string Must be \"GPS\"\n"
      "Interval int    Interval duration in sec. Accepted range is [3600..259200]";
    const char* const SetAlmanacUploadTimeInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetAlmanacUploadTimeInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetAlmanacUploadTimeInterval);


    SetAlmanacUploadTimeInterval::SetAlmanacUploadTimeInterval()
      : CommandBase(CmdName, TargetId)
    {}

    SetAlmanacUploadTimeInterval::SetAlmanacUploadTimeInterval(const std::string& system, int interval)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setInterval(interval);
    }

    SetAlmanacUploadTimeIntervalPtr SetAlmanacUploadTimeInterval::create(const std::string& system, int interval)
    {
      return std::make_shared<SetAlmanacUploadTimeInterval>(system, interval);
    }

    SetAlmanacUploadTimeIntervalPtr SetAlmanacUploadTimeInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAlmanacUploadTimeInterval>(ptr);
    }

    bool SetAlmanacUploadTimeInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Interval"])
        ;

    }

    std::string SetAlmanacUploadTimeInterval::documentation() const { return Documentation; }

    const std::vector<std::string>& SetAlmanacUploadTimeInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Interval"}; 
      return names; 
    }


    int SetAlmanacUploadTimeInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetAlmanacUploadTimeInterval::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetAlmanacUploadTimeInterval::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetAlmanacUploadTimeInterval::interval() const
    {
      return parse_json<int>::parse(m_values["Interval"]);
    }

    void SetAlmanacUploadTimeInterval::setInterval(int interval)
    {
      m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
