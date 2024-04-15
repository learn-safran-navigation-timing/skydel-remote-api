
#include "EnablePYCodeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePYCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePYCodeForSV::CmdName = "EnablePYCodeForSV";
    const char* const EnablePYCodeForSV::Documentation = "Enable (or disable) P(Y)-Code for specified satellite.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -----------------------------------------------\n"
      "Signal  string Accepted signal keys: \"L1P\", \"L2P\"\n"
      "SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)\n"
      "Enabled bool   Enable P(Y)-Code if True";
    const char* const EnablePYCodeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnablePYCodeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnablePYCodeForSV);


    EnablePYCodeForSV::EnablePYCodeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    EnablePYCodeForSV::EnablePYCodeForSV(const std::string& signal, int svId, bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
      setEnabled(enabled);
    }

    EnablePYCodeForSVPtr EnablePYCodeForSV::create(const std::string& signal, int svId, bool enabled)
    {
      return std::make_shared<EnablePYCodeForSV>(signal, svId, enabled);
    }

    EnablePYCodeForSVPtr EnablePYCodeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnablePYCodeForSV>(ptr);
    }

    bool EnablePYCodeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnablePYCodeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& EnablePYCodeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId", "Enabled"}; 
      return names; 
    }


    int EnablePYCodeForSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string EnablePYCodeForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void EnablePYCodeForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int EnablePYCodeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void EnablePYCodeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool EnablePYCodeForSV::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnablePYCodeForSV::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
