
#include "SetPowerSbasOffset.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetPowerSbasOffset
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetPowerSbasOffset::CmdName = "SetPowerSbasOffset";
    const char* const SetPowerSbasOffset::Documentation = "Set power offset default value for the SBAS Service Provider given in argument\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------\n"
      "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"\n"
      "Offset          double Offset in dB (negative value will attenuate signal)";
    const char* const SetPowerSbasOffset::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetPowerSbasOffset);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetPowerSbasOffset);


    SetPowerSbasOffset::SetPowerSbasOffset()
      : CommandBase(CmdName, TargetId)
    {}

    SetPowerSbasOffset::SetPowerSbasOffset(const std::string& serviceProvider, double offset)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setOffset(offset);
    }

    SetPowerSbasOffsetPtr SetPowerSbasOffset::create(const std::string& serviceProvider, double offset)
    {
      return std::make_shared<SetPowerSbasOffset>(serviceProvider, offset);
    }

    SetPowerSbasOffsetPtr SetPowerSbasOffset::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetPowerSbasOffset>(ptr);
    }

    bool SetPowerSbasOffset::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<double>::is_valid(m_values["Offset"])
        ;

    }

    std::string SetPowerSbasOffset::documentation() const { return Documentation; }

    const std::vector<std::string>& SetPowerSbasOffset::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "Offset"}; 
      return names; 
    }


    int SetPowerSbasOffset::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string SetPowerSbasOffset::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetPowerSbasOffset::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetPowerSbasOffset::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void SetPowerSbasOffset::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
