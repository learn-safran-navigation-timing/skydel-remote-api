
#include "gen/EnablePYCodeForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnablePYCodeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnablePYCodeForSV::CmdName = "EnablePYCodeForSV";
    const char* const EnablePYCodeForSV::Documentation = "Enable (or disable) P(Y)-Code for specified satellite.";

    REGISTER_COMMAND_FACTORY(EnablePYCodeForSV);


    EnablePYCodeForSV::EnablePYCodeForSV()
      : CommandBase(CmdName)
    {}

    EnablePYCodeForSV::EnablePYCodeForSV(const std::string& signal, int svId, bool enabled)
      : CommandBase(CmdName)
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
