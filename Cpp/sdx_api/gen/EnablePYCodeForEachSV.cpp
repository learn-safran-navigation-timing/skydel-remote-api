
#include "EnablePYCodeForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePYCodeForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePYCodeForEachSV::CmdName = "EnablePYCodeForEachSV";
    const char* const EnablePYCodeForEachSV::Documentation = "Enable (or disable) P(Y)-Code for each satellite individually.\n"
      "\n"
      "Name    Type       Description\n"
      "------- ---------- ----------------------------------------------------------------------------------------\n"
      "Signal  string     Accepted signal keys: \"L1P\", \"L2P\"\n"
      "Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const EnablePYCodeForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnablePYCodeForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnablePYCodeForEachSV);


    EnablePYCodeForEachSV::EnablePYCodeForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnablePYCodeForEachSV::EnablePYCodeForEachSV(const std::string& signal, const std::vector<bool>& enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    EnablePYCodeForEachSVPtr EnablePYCodeForEachSV::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<EnablePYCodeForEachSV>(signal, enabled);
    }

    EnablePYCodeForEachSVPtr EnablePYCodeForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePYCodeForEachSV>(ptr);
    }

    bool EnablePYCodeForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePYCodeForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnablePYCodeForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "Enabled"}; 
      return names; 
    }


    int EnablePYCodeForEachSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnablePYCodeForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnablePYCodeForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> EnablePYCodeForEachSV::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void EnablePYCodeForEachSV::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
