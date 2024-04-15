
#include "GetLogRawRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLogRawRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLogRawRate::CmdName = "GetLogRawRate";
    const char* const GetLogRawRate::Documentation = "Get Rate logging of raw data";
    const char* const GetLogRawRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetLogRawRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetLogRawRate);


    GetLogRawRate::GetLogRawRate()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetLogRawRatePtr GetLogRawRate::create()
    {
      return std::make_shared<GetLogRawRate>();
    }

    GetLogRawRatePtr GetLogRawRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLogRawRate>(ptr);
    }

    bool GetLogRawRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLogRawRate::documentation() const { return Documentation; }

    const std::vector<std::string>& GetLogRawRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetLogRawRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
