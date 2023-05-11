
#include "gen/SetUdreiForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetUdreiForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetUdreiForEachSV::CmdName = "SetUdreiForEachSV";
    const char* const SetUdreiForEachSV::Documentation = "Set the UDREI value transmitted by SBAS for all satellites of the specified constellation.";

    REGISTER_COMMAND_FACTORY(SetUdreiForEachSV);


    SetUdreiForEachSV::SetUdreiForEachSV()
      : CommandBase(CmdName)
    {}

    SetUdreiForEachSV::SetUdreiForEachSV(const std::string& system, const std::vector<int>& udreis)
      : CommandBase(CmdName)
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
