
#include "gen/GetPowerSbasOffset.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerSbasOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerSbasOffset::CmdName = "GetPowerSbasOffset";
    const char* const GetPowerSbasOffset::Documentation = "Get power offset default value for the SBAS Service Provider given in argument";

    REGISTER_COMMAND_FACTORY(GetPowerSbasOffset);


    GetPowerSbasOffset::GetPowerSbasOffset()
      : CommandBase(CmdName)
    {}

    GetPowerSbasOffset::GetPowerSbasOffset(const std::string& serviceProvider)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
    }

    GetPowerSbasOffsetPtr GetPowerSbasOffset::create(const std::string& serviceProvider)
    {
      return std::make_shared<GetPowerSbasOffset>(serviceProvider);
    }

    GetPowerSbasOffsetPtr GetPowerSbasOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPowerSbasOffset>(ptr);
    }

    bool GetPowerSbasOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetPowerSbasOffset::documentation() const { return Documentation; }


    int GetPowerSbasOffset::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPowerSbasOffset::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetPowerSbasOffset::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
