
#include "SetUdreiForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetUdreiForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetUdreiForEachSV::CmdName = "SetUdreiForEachSV";
    const char* const SetUdreiForEachSV::Documentation = "Set the UDREI value transmitted by SBAS for all satellites of the specified constellation.\n"
      "\n"
      "Name   Type      Description\n"
      "------ --------- --------------------------------------------------------------------------------------------------------------------------\n"
      "System string    \"GPS\" or \"SBAS\".\n"
      "Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 => UDREI for SV ID 2, etc).";
    const char* const SetUdreiForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetUdreiForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetUdreiForEachSV);


    SetUdreiForEachSV::SetUdreiForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetUdreiForEachSV::SetUdreiForEachSV(const std::string& system, const std::vector<int>& udreis)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setUdreis(udreis);
    }

    SetUdreiForEachSVPtr SetUdreiForEachSV::create(const std::string& system, const std::vector<int>& udreis)
    {
      return std::make_shared<SetUdreiForEachSV>(system, udreis);
    }

    SetUdreiForEachSVPtr SetUdreiForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetUdreiForEachSV>(ptr);
    }

    bool SetUdreiForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<int>>::is_valid(m_values["Udreis"])
        ;

    }

    std::string SetUdreiForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetUdreiForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Udreis"}; 
      return names; 
    }


    int SetUdreiForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    std::string SetUdreiForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetUdreiForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> SetUdreiForEachSV::udreis() const
    {
      return parse_json<std::vector<int>>::parse(m_values["Udreis"]);
    }

    void SetUdreiForEachSV::setUdreis(const std::vector<int>& udreis)
    {
      m_values.AddMember("Udreis", parse_json<std::vector<int>>::format(udreis, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
