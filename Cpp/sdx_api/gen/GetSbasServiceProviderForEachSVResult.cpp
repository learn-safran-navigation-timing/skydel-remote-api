
#include "GetSbasServiceProviderForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceProviderForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceProviderForEachSVResult::CmdName = "GetSbasServiceProviderForEachSVResult";
    const char* const GetSbasServiceProviderForEachSVResult::Documentation = "Result of GetSbasServiceProviderForEachSV.\n"
      "\n"
      "Name             Type         Description\n"
      "---------------- ------------ -----------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "ServiceProviders array string Service provider value to set for each satellite. Zero based index (index 0 => Service provider for SV ID 1, index 1 => Service provider for SV ID 2, etc).";
    const char* const GetSbasServiceProviderForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasServiceProviderForEachSVResult);


    GetSbasServiceProviderForEachSVResult::GetSbasServiceProviderForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasServiceProviderForEachSVResult::GetSbasServiceProviderForEachSVResult(const std::vector<std::string>& serviceProviders)
      : CommandResult(CmdName, TargetId)
    {

      setServiceProviders(serviceProviders);
    }

    GetSbasServiceProviderForEachSVResult::GetSbasServiceProviderForEachSVResult(CommandBasePtr relatedCommand, const std::vector<std::string>& serviceProviders)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setServiceProviders(serviceProviders);
    }


    GetSbasServiceProviderForEachSVResultPtr GetSbasServiceProviderForEachSVResult::create(const std::vector<std::string>& serviceProviders)
    {
      return std::make_shared<GetSbasServiceProviderForEachSVResult>(serviceProviders);
    }

    GetSbasServiceProviderForEachSVResultPtr GetSbasServiceProviderForEachSVResult::create(CommandBasePtr relatedCommand, const std::vector<std::string>& serviceProviders)
    {
      return std::make_shared<GetSbasServiceProviderForEachSVResult>(relatedCommand, serviceProviders);
    }

    GetSbasServiceProviderForEachSVResultPtr GetSbasServiceProviderForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceProviderForEachSVResult>(ptr);
    }

    bool GetSbasServiceProviderForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["ServiceProviders"])
        ;

    }

    std::string GetSbasServiceProviderForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasServiceProviderForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProviders"}; 
      return names; 
    }


    std::vector<std::string> GetSbasServiceProviderForEachSVResult::serviceProviders() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["ServiceProviders"]);
    }

    void GetSbasServiceProviderForEachSVResult::setServiceProviders(const std::vector<std::string>& serviceProviders)
    {
      m_values.AddMember("ServiceProviders", parse_json<std::vector<std::string>>::format(serviceProviders, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
