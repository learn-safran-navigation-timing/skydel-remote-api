
#include "GetPowerSbasOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPowerSbasOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPowerSbasOffset::CmdName = "GetPowerSbasOffset";
    const char* const GetPowerSbasOffset::Documentation = "Get power offset default value for the SBAS Service Provider given in argument\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------\n"
      "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"";
    const char* const GetPowerSbasOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPowerSbasOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPowerSbasOffset);


    GetPowerSbasOffset::GetPowerSbasOffset()
      : CommandBase(CmdName, TargetId)
    {}

    GetPowerSbasOffset::GetPowerSbasOffset(const std::string& serviceProvider)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetPowerSbasOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider"}; 
      return names; 
    }


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
