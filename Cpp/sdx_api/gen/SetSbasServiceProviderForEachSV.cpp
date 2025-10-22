
#include "SetSbasServiceProviderForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSbasServiceProviderForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSbasServiceProviderForEachSV::CmdName = "SetSbasServiceProviderForEachSV";
    const char* const SetSbasServiceProviderForEachSV::Documentation = "Set the service provider of all the SBAS satellites.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ -----------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProviders array string Service provider value to set for each satellite. Zero based index (index 0 => Service provider for SV ID 1, index 1 => Service provider for SV ID 2, etc).";
    const char* const SetSbasServiceProviderForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSbasServiceProviderForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSbasServiceProviderForEachSV);


    SetSbasServiceProviderForEachSV::SetSbasServiceProviderForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetSbasServiceProviderForEachSV::SetSbasServiceProviderForEachSV(const std::vector<std::string>& serviceProviders)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProviders(serviceProviders);
    }

    SetSbasServiceProviderForEachSVPtr SetSbasServiceProviderForEachSV::create(const std::vector<std::string>& serviceProviders)
    {
      return std::make_shared<SetSbasServiceProviderForEachSV>(serviceProviders);
    }

    SetSbasServiceProviderForEachSVPtr SetSbasServiceProviderForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSbasServiceProviderForEachSV>(ptr);
    }

    bool SetSbasServiceProviderForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["ServiceProviders"])
        ;

    }

    std::string SetSbasServiceProviderForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSbasServiceProviderForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProviders"}; 
      return names; 
    }


    int SetSbasServiceProviderForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetSbasServiceProviderForEachSV::serviceProviders() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["ServiceProviders"]);
    }

    void SetSbasServiceProviderForEachSV::setServiceProviders(const std::vector<std::string>& serviceProviders)
    {
      m_values.AddMember("ServiceProviders", parse_json<std::vector<std::string>>::format(serviceProviders, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
