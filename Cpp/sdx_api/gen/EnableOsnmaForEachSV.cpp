
#include "EnableOsnmaForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableOsnmaForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableOsnmaForEachSV::CmdName = "EnableOsnmaForEachSV";
    const char* const EnableOsnmaForEachSV::Documentation = "Enable (or disable) OSNMA for each Galileo's satellite individually.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- -------------------------------------------------------------------------------------------------------------\n"
      "Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
    const char* const EnableOsnmaForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableOsnmaForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableOsnmaForEachSV);


    EnableOsnmaForEachSV::EnableOsnmaForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnableOsnmaForEachSV::EnableOsnmaForEachSV(const std::vector<bool>& enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableOsnmaForEachSVPtr EnableOsnmaForEachSV::create(const std::vector<bool>& enabled)
    {
      return std::make_shared<EnableOsnmaForEachSV>(enabled);
    }

    EnableOsnmaForEachSVPtr EnableOsnmaForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableOsnmaForEachSV>(ptr);
    }

    bool EnableOsnmaForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableOsnmaForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableOsnmaForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableOsnmaForEachSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<bool> EnableOsnmaForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnableOsnmaForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
