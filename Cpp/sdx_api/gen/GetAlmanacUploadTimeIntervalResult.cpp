
#include "GetAlmanacUploadTimeIntervalResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAlmanacUploadTimeIntervalResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAlmanacUploadTimeIntervalResult::CmdName = "GetAlmanacUploadTimeIntervalResult";
    const char* const GetAlmanacUploadTimeIntervalResult::Documentation = "Result of GetAlmanacUploadTimeInterval.\n"
      "\n"
      "Name     Type   Description\n"
      "-------- ------ ----------------------------------------------------------\n"
      "System   string Must be \"GPS\"\n"
      "Interval int    Interval duration in sec. Accepted range is [3600..259200]";
    const char* const GetAlmanacUploadTimeIntervalResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAlmanacUploadTimeIntervalResult);


    GetAlmanacUploadTimeIntervalResult::GetAlmanacUploadTimeIntervalResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAlmanacUploadTimeIntervalResult::GetAlmanacUploadTimeIntervalResult(const std::string& system, int interval)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setInterval(interval);
    }

    GetAlmanacUploadTimeIntervalResult::GetAlmanacUploadTimeIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setInterval(interval);
    }


    GetAlmanacUploadTimeIntervalResultPtr GetAlmanacUploadTimeIntervalResult::create(const std::string& system, int interval)
    {
      return std::make_shared<GetAlmanacUploadTimeIntervalResult>(system, interval);
    }

    GetAlmanacUploadTimeIntervalResultPtr GetAlmanacUploadTimeIntervalResult::create(CommandBasePtr relatedCommand, const std::string& system, int interval)
    {
      return std::make_shared<GetAlmanacUploadTimeIntervalResult>(relatedCommand, system, interval);
    }

    GetAlmanacUploadTimeIntervalResultPtr GetAlmanacUploadTimeIntervalResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAlmanacUploadTimeIntervalResult>(ptr);
    }

    bool GetAlmanacUploadTimeIntervalResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Interval"])
        ;

    }

    std::string GetAlmanacUploadTimeIntervalResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAlmanacUploadTimeIntervalResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Interval"}; 
      return names; 
    }


    std::string GetAlmanacUploadTimeIntervalResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAlmanacUploadTimeIntervalResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAlmanacUploadTimeIntervalResult::interval() const
    {
      return parse_json<int>::parse(m_values["Interval"]);
    }

    void GetAlmanacUploadTimeIntervalResult::setInterval(int interval)
    {
      m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
