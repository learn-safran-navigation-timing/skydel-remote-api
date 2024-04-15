
#include "IsOsnmaEnabledForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsOsnmaEnabledForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsOsnmaEnabledForSV::CmdName = "IsOsnmaEnabledForSV";
    const char* const IsOsnmaEnabledForSV::Documentation = "Tells if OSNMA is enabled or disabled.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------------------------------------------\n"
      "SvId int  The satellite's SV ID (use 0 for all Galileo's satellites).";
    const char* const IsOsnmaEnabledForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsOsnmaEnabledForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsOsnmaEnabledForSV);


    IsOsnmaEnabledForSV::IsOsnmaEnabledForSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsOsnmaEnabledForSV::IsOsnmaEnabledForSV(int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
    }

    IsOsnmaEnabledForSVPtr IsOsnmaEnabledForSV::create(int svId)
    {
      return std::make_shared<IsOsnmaEnabledForSV>(svId);
    }

    IsOsnmaEnabledForSVPtr IsOsnmaEnabledForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsOsnmaEnabledForSV>(ptr);
    }

    bool IsOsnmaEnabledForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsOsnmaEnabledForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsOsnmaEnabledForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


    int IsOsnmaEnabledForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int IsOsnmaEnabledForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsOsnmaEnabledForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
