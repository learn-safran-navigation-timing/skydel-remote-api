
#include "GetLogNmeaRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetLogNmeaRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetLogNmeaRate::CmdName = "GetLogNmeaRate";
    const char* const GetLogNmeaRate::Documentation = "Get Rate logging of NMEA data";
    const char* const GetLogNmeaRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetLogNmeaRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetLogNmeaRate);


    GetLogNmeaRate::GetLogNmeaRate()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetLogNmeaRatePtr GetLogNmeaRate::create()
    {
      return std::make_shared<GetLogNmeaRate>();
    }

    GetLogNmeaRatePtr GetLogNmeaRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetLogNmeaRate>(ptr);
    }

    bool GetLogNmeaRate::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetLogNmeaRate::documentation() const { return Documentation; }

    const std::vector<std::string>& GetLogNmeaRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetLogNmeaRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
