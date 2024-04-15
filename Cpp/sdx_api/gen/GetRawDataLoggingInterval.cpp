
#include "GetRawDataLoggingInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetRawDataLoggingInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetRawDataLoggingInterval::CmdName = "GetRawDataLoggingInterval";
    const char* const GetRawDataLoggingInterval::Documentation = "Get the time interval of the Raw Data logging.";
    const char* const GetRawDataLoggingInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetRawDataLoggingInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetRawDataLoggingInterval);


    GetRawDataLoggingInterval::GetRawDataLoggingInterval()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetRawDataLoggingIntervalPtr GetRawDataLoggingInterval::create()
    {
      return std::make_shared<GetRawDataLoggingInterval>();
    }

    GetRawDataLoggingIntervalPtr GetRawDataLoggingInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetRawDataLoggingInterval>(ptr);
    }

    bool GetRawDataLoggingInterval::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetRawDataLoggingInterval::documentation() const { return Documentation; }

    const std::vector<std::string>& GetRawDataLoggingInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetRawDataLoggingInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
