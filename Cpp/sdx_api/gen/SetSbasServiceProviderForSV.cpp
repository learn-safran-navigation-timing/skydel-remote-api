
#include "SetSbasServiceProviderForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasServiceProviderForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasServiceProviderForSV::CmdName = "SetSbasServiceProviderForSV";
    const char* const SetSbasServiceProviderForSV::Documentation = "Set the service provider of the SBAS satellite.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------------\n"
      "SvId            int    The satellite's SV ID.\n"
      "ServiceProvider string Service provider value, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\" and \"SBAS\".";
    const char* const SetSbasServiceProviderForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasServiceProviderForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasServiceProviderForSV);


    SetSbasServiceProviderForSV::SetSbasServiceProviderForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasServiceProviderForSV::SetSbasServiceProviderForSV(int svId, const std::string& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setServiceProvider(serviceProvider);
    }

    SetSbasServiceProviderForSVPtr SetSbasServiceProviderForSV::create(int svId, const std::string& serviceProvider)
    {
      return std::make_shared<SetSbasServiceProviderForSV>(svId, serviceProvider);
    }

    SetSbasServiceProviderForSVPtr SetSbasServiceProviderForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasServiceProviderForSV>(ptr);
    }

    bool SetSbasServiceProviderForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string SetSbasServiceProviderForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasServiceProviderForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ServiceProvider"}; 
      return names; 
    }


    int SetSbasServiceProviderForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetSbasServiceProviderForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetSbasServiceProviderForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSbasServiceProviderForSV::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void SetSbasServiceProviderForSV::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
