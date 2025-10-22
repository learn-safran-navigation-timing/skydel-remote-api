
#include "GetSbasServiceProviderForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceProviderForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceProviderForSV::CmdName = "GetSbasServiceProviderForSV";
    const char* const GetSbasServiceProviderForSV::Documentation = "Get the service provider of the SBAS satellite.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ----------------------\n"
      "SvId int  The satellite's SV ID.";
    const char* const GetSbasServiceProviderForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasServiceProviderForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasServiceProviderForSV);


    GetSbasServiceProviderForSV::GetSbasServiceProviderForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetSbasServiceProviderForSV::GetSbasServiceProviderForSV(int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
    }

    GetSbasServiceProviderForSVPtr GetSbasServiceProviderForSV::create(int svId)
    {
      return std::make_shared<GetSbasServiceProviderForSV>(svId);
    }

    GetSbasServiceProviderForSVPtr GetSbasServiceProviderForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceProviderForSV>(ptr);
    }

    bool GetSbasServiceProviderForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetSbasServiceProviderForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasServiceProviderForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


    int GetSbasServiceProviderForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetSbasServiceProviderForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSbasServiceProviderForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
