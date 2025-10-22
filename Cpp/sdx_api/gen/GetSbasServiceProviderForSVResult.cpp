
#include "GetSbasServiceProviderForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceProviderForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceProviderForSVResult::CmdName = "GetSbasServiceProviderForSVResult";
    const char* const GetSbasServiceProviderForSVResult::Documentation = "Result of GetSbasServiceProviderForSV.\n"
      "\n"
      "Name            Type   Description\n"
      "--------------- ------ ------------------------------------------------------------------------------------\n"
      "SvId            int    The satellite's SV ID.\n"
      "ServiceProvider string Service provider value, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\" and \"SBAS\".";
    const char* const GetSbasServiceProviderForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasServiceProviderForSVResult);


    GetSbasServiceProviderForSVResult::GetSbasServiceProviderForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSbasServiceProviderForSVResult::GetSbasServiceProviderForSVResult(int svId, const std::string& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setServiceProvider(serviceProvider);
    }

    GetSbasServiceProviderForSVResult::GetSbasServiceProviderForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setServiceProvider(serviceProvider);
    }


    GetSbasServiceProviderForSVResultPtr GetSbasServiceProviderForSVResult::create(int svId, const std::string& serviceProvider)
    {
      return std::make_shared<GetSbasServiceProviderForSVResult>(svId, serviceProvider);
    }

    GetSbasServiceProviderForSVResultPtr GetSbasServiceProviderForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::string& serviceProvider)
    {
      return std::make_shared<GetSbasServiceProviderForSVResult>(relatedCommand, svId, serviceProvider);
    }

    GetSbasServiceProviderForSVResultPtr GetSbasServiceProviderForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceProviderForSVResult>(ptr);
    }

    bool GetSbasServiceProviderForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetSbasServiceProviderForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasServiceProviderForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ServiceProvider"}; 
      return names; 
    }


    int GetSbasServiceProviderForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSbasServiceProviderForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSbasServiceProviderForSVResult::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasServiceProviderForSVResult::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
